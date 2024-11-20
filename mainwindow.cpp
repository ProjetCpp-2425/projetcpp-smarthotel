#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Client.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QPainter>
#include <QPdfWriter>
#include <QFileDialog>
#include<QPrinter>
#include <QStandardItemModel>
#include<QSqlError>
#include <QLayoutItem>
#include <QLayout>
#include<iostream>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableclient->setModel(cl.afficher());


    connect(ui->buttonStat, &QPushButton::clicked, this, &MainWindow::changerDePagestatistique);
    connect(ui->accueilbutton, &QPushButton::clicked, this, &MainWindow::on_accueilbutton_clicked);
    connect(ui->buttonhistorique, &QPushButton::clicked, this, &MainWindow::changerDePagehistorique);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changerDePagestatistique()
{
    ui->stackedWidget->setCurrentIndex(1);

    Client client;
    QMap<QString, int> statistiques = client.statistiquesParPays();

    if (statistiques.isEmpty())
    {
        QMessageBox:: information (nullptr,QObject::tr("not ok"),QObject::tr("stat is empty" "click cancel to exit!"),QMessageBox::Cancel);

    }
    int totalClients = 0;
    for (int count : statistiques)
    {
        totalClients += count;
    }



    QPieSeries *series = new QPieSeries();
    QVector<QColor> colors =
    {
        QColor(0, 0, 80),
        QColor(38, 0, 128),
        QColor(76, 0, 179),
        QColor(102, 51, 204),
        QColor(140, 102, 230),
        QColor(179, 170, 255),
    };
    int colorIndex = 0;
    for (auto it = statistiques.begin(); it != statistiques.end(); ++it)
    {
        QPieSlice *slice = series->append(it.key(), it.value());
        double percentage = (static_cast<double>(it.value()) / totalClients) * 100.0;
        slice->setLabel(QString("%1 (%2%)").arg(it.key()).arg(percentage, 0, 'f', 1));
        slice->setLabelVisible(true);
        slice->setBrush(colors[colorIndex % colors.size()]);
        colorIndex++;
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("clients par pays");
    chart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    if (QLayout *existingLayout = ui->stat->layout())
    {
        QLayoutItem *item;
        while ((item = existingLayout->takeAt(0)) != nullptr)
        {
            delete item->widget();
            delete item;
        }
        delete existingLayout;
    }

    QVBoxLayout *layout = new QVBoxLayout(ui->stat);
    layout->addWidget(chartView);
    ui->stat->setLayout(layout);
}

void MainWindow::on_accueilbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::calculerPointsEtDuree(QStandardItemModel* model)
{
    for (int row = 0; row < model->rowCount(); ++row)
    {
        QString date_arrivee = model->item(row, 2)->text().left(10);
        QString date_depart = model->item(row, 3)->text().left(10);

        QDate arrivee = QDate::fromString(date_arrivee, "yyyy-MM-dd");
        QDate depart = QDate::fromString(date_depart, "yyyy-MM-dd");

        qint64 dureeSejour = arrivee.daysTo(depart);
        model->setItem(row, model->columnCount() - 2, new QStandardItem(QString::number(dureeSejour)));

        QString demandesSpeciales = model->item(row, 7)->text();
        int pointsParJour = 50;
        int pointsParDemande = 200;
        int pointsFidelite = (dureeSejour * pointsParJour) +
                             (demandesSpeciales != "aucun" ? pointsParDemande : 0);

        model->setItem(row, model->columnCount() - 1, new QStandardItem(QString::number(pointsFidelite)));
    }
}






void MainWindow::changerDePagehistorique()
{
    ui->stackedWidget->setCurrentIndex(2);

    Client client;
    QSqlQueryModel* sqlModel = client.his_reservation();
    if (!sqlModel) {
        qDebug() << "Erreur : Impossible de récupérer les réservations.";
        return;
    }

    if (auto oldModel = ui->tableHistorique->model()) {
        delete oldModel;
    }

    QStandardItemModel* model = new QStandardItemModel(sqlModel->rowCount(), sqlModel->columnCount() + 2, this);


    for (int col = 0; col < sqlModel->columnCount(); ++col) {
        model->setHeaderData(col, Qt::Horizontal, sqlModel->headerData(col, Qt::Horizontal));
    }
    model->setHeaderData(sqlModel->columnCount(), Qt::Horizontal, "Durée Séjour (jours)");
    model->setHeaderData(sqlModel->columnCount() + 1, Qt::Horizontal, "Points de fidélité");

    for (int row = 0; row < sqlModel->rowCount(); ++row) {
        for (int col = 0; col < sqlModel->columnCount(); ++col) {
            model->setItem(row, col, new QStandardItem(sqlModel->data(sqlModel->index(row, col)).toString()));
        }
    }

    calculerPointsEtDuree(model);

    QMap<QString, int> totalPointsClients;
    for (int row = 0; row < model->rowCount(); ++row) {
        QString clientId = model->data(model->index(row, 4)).toString();
        int pointsFidelite = model->data(model->index(row, sqlModel->columnCount() + 1)).toInt();
        totalPointsClients[clientId] += pointsFidelite;
    }

    for (auto clientId : totalPointsClients.keys()) {
        qDebug() << "Total des points de fidélité pour le client" << clientId << ": " << totalPointsClients[clientId];

        QSqlQuery query;
        query.prepare("SELECT nom, prenom, date_naissance, demande_special, statut, pays, telephone FROM CLIENTS WHERE ID_client = :id");
        query.bindValue(":id", clientId);

        if (query.exec() && query.next()) {
            QString nom = query.value(0).toString();
            QString prenom = query.value(1).toString();
            QDate dateNaissance = query.value(2).toDate();
            QString demandeSpecial = query.value(3).toString();
            QString statut = query.value(4).toString();
            QString pays = query.value(5).toString();
            int telephone = query.value(6).toInt();

            if (!client.modifier(clientId.toInt(), nom, prenom, dateNaissance, demandeSpecial, statut, pays, telephone, totalPointsClients[clientId])) {
                qDebug() << "Erreur lors de la mise à jour des points de fidélité pour le client" << clientId;
            }
        } else {
            qDebug() << "Erreur lors de la récupération des données du client" << clientId << ": " << query.lastError().text();
        }
        ui->tableclient->setModel(cl.afficher());
    }
    ui->tableclient->setModel(client.afficher());
    ui->tableHistorique->setModel(model);
    ui->tableHistorique->resizeColumnsToContents();
    ui->tableHistorique->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


void MainWindow::on_accueilbutton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_valider_clicked()
{
    int ID_client = ui->lineEdit_id->text().toInt();
    if (ID_client <= 0 || ui->lineEdit_id->text().isEmpty() )
    {
        QMessageBox::information(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un CIN"), QMessageBox::Cancel);
        return;
    }

    QString nom = ui->lineEdit_nom->text();
    bool testn = true;
    for (int i = 0; i < nom.length(); ++i)
    {
        if (!nom[i].isLetter() && nom[i] != ' ')
        {
            testn = false;
        }
    }
    if (!testn)
    {
        QMessageBox::information(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un nom valide (lettres uniquement)."), QMessageBox::Cancel);
        return;
    }

    QString prenom = ui->lineEdit_prenom->text();
    bool testp = true;
    for (int i = 0; i < prenom.length(); ++i)
    {
        if (!prenom[i].isLetter() && prenom[i] != ' ')
        {
            testp = false;
        }
    }
    if (!testp)
    {
        QMessageBox::information(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un prénom valide (lettres uniquement)."), QMessageBox::Cancel);
        return;
    }

    QString pays = ui->lineEdit_pays->text();
    bool testpa = true;
    for (int i = 0; i < pays.length(); ++i)
    {
        if (!pays[i].isLetter() && pays[i] != ' ')
        {
            testpa = false;
        }
    }
    if (!testpa)
    {
        QMessageBox::information(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un pays valide (lettres uniquement)."), QMessageBox::Cancel);
        return;
    }

    int telephone = ui->lineEdit_telephone->text().toInt();
    if (telephone == 0 && ui->lineEdit_telephone->text() != "0")
    {
        QMessageBox::information(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un numéro de téléphone valide (entier uniquement)."), QMessageBox::Cancel);
        return;
    }

    int total_points = ui->lineEdit_total->text().toInt();
    if (total_points == 0 && ui->lineEdit_total->text() != "0")
    {
        QMessageBox::information(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un nombre valide de points (entier uniquement)."), QMessageBox::Cancel);
        return;
    }

    Client c(ID_client, nom, prenom, ui->dateEdit->date(), ui->comboBox_dmd->currentText(), ui->comboBox_statut->currentText(), pays, telephone, total_points);
    bool test = c.ajouter();

    if (test)
    {
        ui->tableclient->setModel(cl.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Ajout effectué."), QMessageBox::Cancel);

        ui->lineEdit_id->clear();
        ui->lineEdit_nom->clear();
        ui->lineEdit_prenom->clear();
        ui->dateEdit->setDate(QDate::currentDate());
        ui->comboBox_dmd->setCurrentIndex(0);
        ui->comboBox_statut->setCurrentIndex(0);
        ui->lineEdit_pays->clear();
        ui->lineEdit_telephone->clear();
        ui->lineEdit_total->clear();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("Ajout non effectué.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}


void MainWindow::on_supprimer_clicked()
{
    int id=ui->lineEdit_chercher->text().toInt();
    bool test=cl.supprimer(id);
    if (test)
    {
        QMessageBox:: information (nullptr,QObject::tr("ok"),QObject::tr("suppression effectué\n" "click cancel to exit!"),QMessageBox::Cancel);
        ui->tableclient->setModel(cl.afficher());
    }
}


void MainWindow::on_modifier_clicked()
{
    int id=ui->lineEdit_chercher->text().toInt();
    QString nv_nom= ui ->lineEdit_nom->text();
    QString nv_prenom= ui ->lineEdit_prenom->text();
    QDate nv_date =ui->dateEdit->date();
    QString nv_demande= ui ->comboBox_dmd->currentText();
    QString nv_statut= ui ->comboBox_statut->currentText();
    QString nv_pays= ui ->lineEdit_pays->text();
    int nv_tele=ui-> lineEdit_telephone->text().toInt();
    int nv_total =ui-> lineEdit_total->text().toInt();
    bool test=cl.modifier(id,nv_nom,nv_prenom,nv_date,nv_demande,nv_statut,nv_pays,nv_tele,nv_total);
    if (test)
    {
        QMessageBox:: information (nullptr,QObject::tr("ok"),QObject::tr("modification effectué\n" "click cancel to exit!"),QMessageBox::Cancel);
        ui->tableclient->setModel(cl.afficher());
    }
    else
    {
         QMessageBox:: critical (nullptr,QObject::tr("not ok"),QObject::tr("modification non effectué\n" "click cancel to exit!"),QMessageBox::Cancel);
  }
}

void MainWindow::on_chercher_clicked()
{
    QVariant critere = ui->recherche->currentText();
    QString valeurRecherche = ui->lineEdit_chercher->text();
    Client client;
    if (critere == "id")
    {
        int id = valeurRecherche.toInt();
        client = cl.chercher("id", id);
    }
    else if (critere == "nom")
    {
        client = cl.chercher("nom", valeurRecherche);
    }

    if (client.getID_client() != 0)
    {
        ui->lineEdit_id->setText(QString::number(client.getID_client()));
        ui->lineEdit_nom->setText(client.getnom());
        ui->lineEdit_prenom->setText(client.getprenom());
        ui->dateEdit->setDate(client.getdate_naissance());
        ui->comboBox_dmd->setCurrentText(client.getdemande_special());
        ui->comboBox_statut->setCurrentText(client.getstatut());
        ui->lineEdit_pays->setText(client.getpays());
        ui->lineEdit_telephone->setText(QString::number(client.gettelephone()));
        ui->lineEdit_total->setText(QString::number(client.gettotal_points()));
    }
    else
    {
        QMessageBox::warning(this, "Non trouvé", "Client non trouvé avec cet ID.");
    }
}

void MainWindow::on_trier_clicked()
{
    Client client;
    QSqlQueryModel *model=nullptr;

    if (ui->tri->currentText() == "statut") {
        model = client.trier("statut");
    }
    else if (ui->tri->currentText() == "date_de_naissance") {
        model = client.trier("date_de_naissance");
    }
    else if (ui->tri->currentText() == "total_points") {
        model = client.trier("total_points");
    }
    if (model != nullptr) {
        ui->tableclient->setModel(model);
        ui->tableclient->resizeColumnsToContents();
    }
}


void MainWindow::on_pdf_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export PDF"), QString(), "*.pdf");
    if (!fileName.isEmpty())
    {
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf");
    }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QString html = "<h1>LISTE DES CLIENTS </h1><table border='1'>"
                       "<tr><th>ID_CLIENT</th><th>NOM</th><th>PRENOM</th><th>DEMANDE_SPECIAL</th>"
                       "<th>STATUT</th><th>PAYS</th><th>TELEPHONE</th><th>TOTAL_POINTS</th></tr>";

        QSqlQuery query("SELECT ID_CLIENT, NOM, PRENOM, DEMANDE_SPECIAL, STATUT, PAYS, TELEPHONE, TOTAL_POINTS FROM CLIENTS");
        while (query.next())
        {
            html += "<tr><td>" + query.value("ID_CLIENT").toString() + "</td>";
            html += "<td>" + query.value("NOM").toString() + "</td>";
            html += "<td>" + query.value("PRENOM").toString() + "</td>";
            html += "<td>" + query.value("DEMANDE_SPECIAL").toString() + "</td>";
            html += "<td>" + query.value("STATUT").toString() + "</td>";
            html += "<td>" + query.value("PAYS").toString() + "</td>";
            html += "<td>" + query.value("TELEPHONE").toString() + "</td>";
            html += "<td>" + query.value("TOTAL_POINTS").toString() + "</td></tr>";
        }
        html += "</table>";
        doc.setHtml(html);
        doc.print(&printer);
        QMessageBox::information(this, "Export PDF", "Clients exported to PDF successfully!");
    }
}


void MainWindow::afficherHistorique(QSqlQueryModel *model)
{
    ui->tableHistorique->setModel(model);
}


void MainWindow::on_client_fidele_clicked()
{
    Client client = cl.afficherClientPlusFidele();

    if (client.getID_client() != 0)
    {
        QSqlQueryModel *sqlModel = qobject_cast<QSqlQueryModel *>(ui->tableclient->model());

        if (!sqlModel)
        {
            QMessageBox::warning(this, "Erreur", "Le modèle de la table est vide.");
            qDebug() << "Modèle vide.";
            return;
        }

        QStandardItemModel *standardModel = new QStandardItemModel(this);

        for (int col = 0; col < sqlModel->columnCount(); ++col)
        {
            QString header = sqlModel->headerData(col, Qt::Horizontal).toString();
            standardModel->setHorizontalHeaderItem(col, new QStandardItem(header));
        }

        for (int row = 0; row < sqlModel->rowCount(); ++row)
        {
            QList<QStandardItem *> items;
            for (int col = 0; col < sqlModel->columnCount(); ++col)
            {
                QStandardItem *item = new QStandardItem(sqlModel->index(row, col).data().toString());
                items.append(item);
            }
            standardModel->appendRow(items);
        }

        ui->tableclient->setModel(standardModel);

        for (int row = 0; row < standardModel->rowCount(); ++row)
        {
            if (standardModel->item(row, 0)->text().toInt() == client.getID_client())
            {
                qDebug() << "Client trouvé dans la table à la ligne :" << row;

                for (int col = 0; col < standardModel->columnCount(); ++col)
                {
                    QStandardItem *item = standardModel->item(row, col);
                    if (item)
                    {
                        QBrush backgroundBrush(QColor(172, 44, 103));
                        QBrush textBrush(Qt::white);

                        item->setBackground(backgroundBrush);
                        item->setForeground(textBrush);
                    }
                }

                return;
            }
        }

        qDebug() << "Le client n'a pas été trouvé dans la table.";
    }
    else
    {
        QMessageBox::information(this, "Aucun client", "Aucun client trouvé.");
        qDebug() << "Client avec ID 0 (invalide).";
    }
}


void MainWindow::on_chercher_2_clicked()
{
    QVariant critere = ui->recherche_2->currentText();
    QString valeurRecherche = ui->lineEdit_chercher2->text();

    QSqlQueryModel *sqlModel = new QSqlQueryModel(this);

    QSqlQuery query;
    if (critere == "id")
    {
        int id = valeurRecherche.toInt();


        // Créer la requête SQL avec paramètre
        query.prepare("SELECT r.ID_reservation, r.date_reservation, r.date_arrivé, r.date_depart, "
                   "c.ID_client, c.nom, c.prenom, c.demande_special "
                   "FROM RESERVATIONS r "
                   "LEFT JOIN CLIENTS c ON r.ID_client = c.ID_client "
                   "WHERE c.ID_client = :id");

        query.bindValue(":id", id);
        query.exec();
        sqlModel->setQuery(std::move(query));
    }
    else if (critere == "nom")
    {
        query.prepare("SELECT r.ID_reservation, r.date_reservation, r.date_arrivé, r.date_depart, "
                   "c.ID_client, c.nom, c.prenom, c.demande_special "
                   "FROM RESERVATIONS r "
                   "LEFT JOIN CLIENTS c ON r.ID_client = c.ID_client "
                   "WHERE c.nom LIKE :nom");

        query.bindValue(":nom", "%" + valeurRecherche + "%");
        query.exec();

        sqlModel->setQuery(std::move(query));
    }
    QStandardItemModel* model = new QStandardItemModel(sqlModel->rowCount(), sqlModel->columnCount() + 2, this);

    for (int col = 0; col < sqlModel->columnCount(); ++col) {
        model->setHeaderData(col, Qt::Horizontal, sqlModel->headerData(col, Qt::Horizontal));
    }
    model->setHeaderData(sqlModel->columnCount(), Qt::Horizontal, "Durée Séjour (jours)");
    model->setHeaderData(sqlModel->columnCount() + 1, Qt::Horizontal, "Points de fidélité");

    for (int row = 0; row < sqlModel->rowCount(); ++row) {
        for (int col = 0; col < sqlModel->columnCount(); ++col) {
            model->setItem(row, col, new QStandardItem(sqlModel->data(sqlModel->index(row, col)).toString()));
        }
    }

    calculerPointsEtDuree(model);

    if (model->rowCount() > 0) {
        ui->tableHistorique->setModel(model);
    } else {
        QMessageBox::information(this, "Aucun résultat", "Aucun client trouvé avec les critères spécifiés.");
    }
}

void MainWindow::on_retour_clicked()
{
    QSqlQueryModel *sqlModel = new QSqlQueryModel(this);
    QSqlQuery query;

    // Requête SQL mise à jour pour récupérer les colonnes supplémentaires
    query.prepare("SELECT r.ID_reservation, r.date_reservation, r.date_arrivé, r.date_depart, "
                  "c.ID_client, c.nom, c.prenom, c.demande_special "
                  "FROM RESERVATIONS r "
                  "LEFT JOIN CLIENTS c ON r.ID_client = c.ID_client");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError();
        return;
    }

    sqlModel->setQuery(std::move(query));

    QStandardItemModel* model = new QStandardItemModel(sqlModel->rowCount(), sqlModel->columnCount() + 2, this);

    for (int col = 0; col < sqlModel->columnCount(); ++col) {
        model->setHeaderData(col, Qt::Horizontal, sqlModel->headerData(col, Qt::Horizontal));
    }
    model->setHeaderData(sqlModel->columnCount(), Qt::Horizontal, "Durée Séjour (jours)");
    model->setHeaderData(sqlModel->columnCount() + 1, Qt::Horizontal, "Points de fidélité");

    for (int row = 0; row < sqlModel->rowCount(); ++row) {
        for (int col = 0; col < sqlModel->columnCount(); ++col) {
            model->setItem(row, col, new QStandardItem(sqlModel->data(sqlModel->index(row, col)).toString()));
        }
    }

    calculerPointsEtDuree(model);

    if (model->rowCount() > 0) {
        ui->tableHistorique->setModel(model);
        ui->tableHistorique->resizeColumnsToContents();
    } else {
        QMessageBox::information(this, "Aucune donnée", "Aucune réservation trouvée.");
    }
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QFileDialog>
#include<QSqlError>
#include <QSqlTableModel>
#include<QPrinter>
#include <QStandardItemModel>
#include<QSqlError>
#include <QLayoutItem>
#include <QLayout>



#include "reservation.h"
#include <QDebug>
#include <QVector>
#include <QString>
#include <QStandardPaths>
#include <QTcpSocket>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QTextStream>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrl>
#include <QRandomGenerator>
#include <QSslSocket>
#include <QUrlQuery>
#include <QtCore>
#include <QByteArray>
#include <QUrlQuery>
#include <QDebug>
#include "pdf.h"
#include "email.h"



// stat
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <stdexcept>

//tri
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>

#include <QUrl>
#include <QUrlQuery>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply> // Include this for QNetworkReply
#include <QUrlQuery>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,arduino(),
    tri(new QSqlQueryModel())  // Initialisation ici



{
    ui->setupUi(this);
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    arduino.listAvailablePorts();
    connect(ui->executer, &QPushButton::clicked, this, &MainWindow::on_validerClientButton_clicked);
    connect(arduino.getSerialPort(), &QSerialPort::readyRead, this, &MainWindow::readArduinoData);

    if (arduino.connect() == 0) {
        ui->statuslabel->setText("Arduino connecté sur le port " + arduino.getPortName());
    } else {
        ui->statuslabel->setText("Erreur : Arduino non connecté.");
    }


    connect(reply, &QNetworkReply::finished, this, &MainWindow::onTwilioResponseReceived);


    connect(ui->sortComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_sortComboBox_currentIndexChanged(int)));

     afficherProduitsDansTable();
    afficherSalaireEtMasseSalariale();
    ui->tableClient->setModel(cl.afficher());
    ui->tabemp->setModel(employe.afficher());
    ui->tabres->setModel(reservation.afficher());
    ui->modifier->setVisible(false);
    ui->supprimer->setVisible(false);

    ui->mdp->setEchoMode(QLineEdit::Password);

    searchLineEdit = ui->rechercheres;
    idReservationLineEdit = ui->idr;
    dateReservationDateEdit = ui->dateR;
    dateArriveDateEdit = ui->datear;
    dateDepartDateEdit = ui->datedr;
    typeChambreComboBox = ui->typer;
    statutReservationComboBox = ui->statutr;
    modePaiementComboBox = ui->moder;
    montantLineEdit = ui->montantr;


    validerButton = ui->validerr;
    supprimerButton = ui->supprimerreservation;
    modifierButton = ui->modifierreservation;
    exporterPdf=ui->pdfr;





    connect(ui->sinscrire, &QPushButton::clicked, this, [this]() {
        if (inscrireEmploye()) {
            changerDePageconnexion();
        }
    });
    connect(ui->seconnecter2, &QPushButton::clicked, this, &MainWindow::on_connexionButton_clicked);
    connect(ui->validerclient, &QPushButton::clicked, this, &MainWindow::on_valider_clicked);
    connect(ui->supprimerclient, &QPushButton::clicked, this, &MainWindow::on_supprimer_clicked);
    connect(ui->modifierclient, &QPushButton::clicked, this, &MainWindow::on_modifierclient_clicked);
    connect(ui->rechercherclient, &QPushButton::clicked, this, &MainWindow::on_chercher_clicked );
    connect(ui->trierclient , &QPushButton::clicked, this, &MainWindow::on_trier_clicked);
    connect(ui->pdfclient, &QPushButton::clicked, this, &MainWindow::on_pdf_clicked);
    connect(ui->rechercherhistorique, &QPushButton::clicked, this, &MainWindow::on_chercher_2_clicked );
    connect(ui->retour, &QPushButton::clicked, this, &MainWindow::on_retour_clicked );
    connect(ui->client_fidele, &QPushButton::clicked, this, &MainWindow::on_client_fidele_clicked );


    connect(validerButton, &QPushButton::clicked, this, &MainWindow::on_validerButtonreservation_clicked);
    connect(supprimerButton, &QPushButton::clicked, this, &MainWindow::on_supprimerButtonreservation_clicked);
    connect(modifierButton, &QPushButton::clicked, this, &MainWindow::on_modifierButtonreservation_clicked);
    connect(exporterPdf, &QPushButton::clicked, this, &MainWindow::on_exporterreservation_clicked);
    connect(ui->trires, SIGNAL(currentIndexChanged(int)), this, SLOT(on_triComboBox_currentIndexChanged(int)));
    connect(ui->boutonstatres, &QPushButton::clicked, this, &MainWindow::afficherStatistiquesTypeChambre);
    networkManager = new QNetworkAccessManager(this);
    connect(ui->mail, &QPushButton::clicked, this, &MainWindow::on_email_clicked);
    connect(ui->envoi, &QPushButton::clicked, this, &MainWindow::on_sendVerificationButton_clicked);
    connect(ui->con,&QPushButton::clicked,this,&MainWindow::on_verifyCodeButton_clicked);







    connect(ui->rechercher, &QPushButton::clicked, this, &MainWindow::on_rechercher_clicked);
    connect(ui->recherche, &QLineEdit::textChanged, this, &MainWindow::onRechercheTextChanged);
    connect(ui->recherche, &QLineEdit::textChanged, this, &MainWindow::Rechercheemploye);

    connect(ui->trier, &QPushButton::clicked, this, &MainWindow::on_boutonTrier_clicked);
    connect(ui->pdf, &QPushButton::clicked, this, &MainWindow::exporterListeEmployesPDF);

    connect(ui->boutonsms, &QPushButton::clicked, this, &MainWindow::afficherEmployeesAvecUnAnDeContratRestant);
    connect(ui->envoyer, &QPushButton::clicked, this, &MainWindow::sendRenewalMessages);
    connect(ui->boutonstat, &QPushButton::clicked, this, &MainWindow::afficherStatistiquesPostes);

    connect(ui->valideremp, &QPushButton::clicked, this, &MainWindow::on_ajouterButton_clicked);
    connect(ui->modifier, &QPushButton::clicked, this, &MainWindow::on_modifier_clicked);
    connect(ui->supprimer, &QPushButton::clicked, this, &MainWindow::on_supprimerButton_clicked);



    connect(ui->seconnecter1, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
    connect(ui->mdpoublie, &QPushButton::clicked, this, &MainWindow::changerDePagemdp);
    connect(ui->con, &QPushButton::clicked, this, &MainWindow::changerDePageclient);
    connect(ui->sedeconnecter1, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
    connect(ui->sedeconnecter2, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
    connect(ui->sedeconnecter3, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
    connect(ui->sedeconnecter4, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
    connect(ui->sedeconnecter5, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
    connect(ui->sedeconnecter6, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
    connect(ui->sedeconnecter7, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
    connect(ui->sedeconnecter8, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
    connect(ui->sedeconnecter9, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
    connect(ui->sedeconnecter10, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
    connect(ui->sedeconnecter11, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
    connect(ui->sedeconnecter12, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
    connect(ui->sedeconnecter13, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);

    connect(ui->boutoncalmaint, &QPushButton::clicked, this, &MainWindow::changerDePagecalmaint);
    connect(ui->boutonstat, &QPushButton::clicked, this, &MainWindow::changerDePagestatistique);
    connect(ui->boutonsms, &QPushButton::clicked, this, &MainWindow::changerDePagesms);
    connect(ui->boutonstatclient, &QPushButton::clicked, this, &MainWindow::changerDePagestatclient);
    connect(ui->boutonhisclient, &QPushButton::clicked, this, &MainWindow::changerDePagehisclient);
    connect(ui->sushButton, &QPushButton::clicked, this, &MainWindow::changerDePagestatstock);
    connect(ui->boutonstatres, &QPushButton::clicked, this, &MainWindow::changerDePagestatres);
    connect(ui->boutonstatcal, &QPushButton::clicked, this, &MainWindow::changerDePagestatistique);
    connect(ui->boutoncalcul, &QPushButton::clicked, this, &MainWindow::changerDePagecalcul);
    connect(ui->boutoncalstat, &QPushButton::clicked, this, &MainWindow::changerDePagecalcul);
    connect(ui->acceuilstat, &QPushButton::clicked, this, &MainWindow::changerDePageemploye);
    connect(ui->acceuilsms, &QPushButton::clicked, this, &MainWindow::changerDePageemploye);
    connect(ui->acceuilstatclient, &QPushButton::clicked, this, &MainWindow::changerDePageclient);
    connect(ui->acceuilhisclient, &QPushButton::clicked, this, &MainWindow::changerDePageclient);
    connect(ui->acceuilstatstock, &QPushButton::clicked, this, &MainWindow::changerDePagestock);
    connect(ui->acceuilstatres, &QPushButton::clicked, this, &MainWindow::changerDePagereservation);
    connect(ui->acceuilcal, &QPushButton::clicked, this, &MainWindow::changerDePageemploye);
    connect(ui->acceuilcalmaint, &QPushButton::clicked, this, &MainWindow::changerDePagemaintenance);


    connect(ui->clientemp, &QPushButton::clicked, this, &MainWindow::changerDePageclient);
    connect(ui->clientstat, &QPushButton::clicked, this, &MainWindow::changerDePageclient);
    connect(ui->clientres, &QPushButton::clicked, this, &MainWindow::changerDePageclient);
    connect(ui->clientstock, &QPushButton::clicked, this, &MainWindow::changerDePageclient);
    connect(ui->clientmaint, &QPushButton::clicked, this, &MainWindow::changerDePageclient);


    connect(ui->employeclient, &QPushButton::clicked, this, &MainWindow::changerDePageemploye);
    connect(ui->employeres, &QPushButton::clicked, this, &MainWindow::changerDePageemploye);
    connect(ui->employestock, &QPushButton::clicked, this, &MainWindow::changerDePageemploye);
    connect(ui->employemaint, &QPushButton::clicked, this, &MainWindow::changerDePageemploye);


    connect(ui->reservationclient, &QPushButton::clicked, this, &MainWindow::changerDePagereservation);
    connect(ui->reservationemp, &QPushButton::clicked, this, &MainWindow::changerDePagereservation);
    connect(ui->reservationstock, &QPushButton::clicked, this, &MainWindow::changerDePagereservation);
    connect(ui->reservationmaint, &QPushButton::clicked, this, &MainWindow::changerDePagereservation);
    connect(ui->reservationstat, &QPushButton::clicked, this, &MainWindow::changerDePagereservation);

    connect(ui->stockemp, &QPushButton::clicked, this, &MainWindow::changerDePagestock);
    connect(ui->stockclient, &QPushButton::clicked, this, &MainWindow::changerDePagestock);
    connect(ui->stockres, &QPushButton::clicked, this, &MainWindow::changerDePagestock);
    connect(ui->stockmaint, &QPushButton::clicked, this, &MainWindow::changerDePagestock);
    connect(ui->stockstat, &QPushButton::clicked, this, &MainWindow::changerDePagestock);



    connect(ui->maintenanceclient, &QPushButton::clicked, this, &MainWindow::changerDePagemaintenance);
    connect(ui->maintenanceemp, &QPushButton::clicked, this, &MainWindow::changerDePagemaintenance);
    connect(ui->maintenanceres, &QPushButton::clicked, this, &MainWindow::changerDePagemaintenance);
    connect(ui->maintenancestock, &QPushButton::clicked, this, &MainWindow::changerDePagemaintenance);
    connect(ui->maintenancestat, &QPushButton::clicked, this, &MainWindow::changerDePagemaintenance);




}


MainWindow::~MainWindow()
{
    arduino.disconnect();
    delete ui;
    delete tri; // Libère le modèle SQL trié
}
void MainWindow::changerDePageconnexion()
{

    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::changerDePagemdp()
{

    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::changerDePagestatistique()
{

    ui->stackedWidget->setCurrentIndex(6);
}
void MainWindow::changerDePageemploye()
{

    ui->stackedWidget->setCurrentIndex(5);
}
void MainWindow::changerDePageclient()
{

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::changerDePagestatclient()
{

    ui->stackedWidget->setCurrentIndex(4);
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
             QColor(128, 0, 128),
             QColor(153, 50, 204),
             QColor(186, 85, 211),
             QColor(218, 112, 214),
             QColor(230, 230, 250),
             QColor(138, 43, 226),
             QColor(199, 21, 133),
             QColor(148, 0, 211),
             QColor(221, 160, 221)
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

    if (QLayout *existingLayout = ui->statclient->layout())
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
    ui->statclient->setLayout(layout);
}
void MainWindow::changerDePagereservation()
{

    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::changerDePagestatres()
{

    ui->stackedWidget->setCurrentIndex(8);
}
void MainWindow::changerDePagestock()
{

    ui->stackedWidget->setCurrentIndex(9);
}
void MainWindow::changerDePagestatstock()
{

    ui->stackedWidget->setCurrentIndex(10);
}
void MainWindow::changerDePagemaintenance()
{

    ui->stackedWidget->setCurrentIndex(11);
}
void MainWindow::changerDePagecalmaint()
{

    ui->stackedWidget->setCurrentIndex(12);
}
void MainWindow::changerDePagecalcul()
{

    ui->stackedWidget->setCurrentIndex(13);
}
void MainWindow::changerDePagesms()
{

    ui->stackedWidget->setCurrentIndex(14);
}
void MainWindow::changerDePagehisclient()
{

    ui->stackedWidget->setCurrentIndex(15);
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
        ui->tableClient->setModel(cl.afficher());
    }
    ui->tableClient->setModel(client.afficher());
    ui->tableHistorique->setModel(model);
    ui->tableHistorique->resizeColumnsToContents();
    ui->tableHistorique->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
void MainWindow::onRechercheTextChanged(const QString &text)
{
    bool idFound = false;


    QAbstractItemModel *model = ui->tabemp->model();


    for (int row = 0; row < model->rowCount(); ++row) {
        QModelIndex index = model->index(row, 0);

        if (model->data(index).toString() == text) {
            idFound = true;
            break;
        }
    }


    ui->modifier->setVisible(idFound);
    ui->supprimer->setVisible(idFound);
}

void MainWindow::on_ajouterButton_clicked() {
    Employe e(ui->id->text().toInt(),
              ui->nom->text(),
              ui->prenom->text(),
              ui->salaire->text().toFloat(),
              ui->poste->currentText(),
              ui->telephone->text().toInt(),
              ui->presences->text().toInt(),
              ui->dcontrat->date(),
              ui->fcontrat->date());

    if (e.ajouter()) {
        ui->tabemp->setModel(e.afficher());
        QMessageBox::information(this, "Ajout réussi", "L'employé a été ajouté avec succès.");


        ui->id->clear();
        ui->nom->clear();
        ui->prenom->clear();
        ui->salaire->clear();
        ui->poste->setCurrentIndex(0);
        ui->telephone->clear();
        ui->presences->clear();
        ui->dcontrat->setDate(QDate::currentDate());
        ui->fcontrat->setDate(QDate::currentDate());
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout de l'employé a échoué.");
    }
    afficherSalaireEtMasseSalariale();
    afficherStatistiquesPostes();
    afficherEmployeesAvecUnAnDeContratRestant();
}
void MainWindow::on_modifier_clicked()
{

    int id = ui->id->text().toInt();
    QString nv_nom = ui->nom->text();
    QString nv_prenom = ui->prenom->text();
    float nv_salaire = ui->salaire->text().toFloat();
    QString nv_poste = ui->poste->currentText();
    int nv_telephone = ui->telephone->text().toInt();
    int nv_presences = ui->presences->text().toInt();
    QDate nv_dDate = ui->dcontrat->date();
    QDate nv_fDate = ui->fcontrat->date();


    bool test = employe.modifier(id, nv_nom, nv_prenom, nv_salaire, nv_poste, nv_telephone, nv_presences, nv_dDate, nv_fDate);


    if (test)
    {

        QMessageBox::information(nullptr, QObject::tr("Modification réussie"), QObject::tr("La modification a été effectuée avec succès.\nCliquez sur Annuler pour sortir."), QMessageBox::Cancel);

        ui->tabemp->setModel(employe.afficher());
    }
    else
    {

        QMessageBox::critical(nullptr, QObject::tr("Erreur"), QObject::tr("La modification n'a pas été effectuée.\nCliquez sur Annuler pour sortir."), QMessageBox::Cancel);
    }
    afficherSalaireEtMasseSalariale();
    afficherStatistiquesPostes();
    afficherEmployeesAvecUnAnDeContratRestant();
}

void MainWindow::on_supprimerButton_clicked() {
    int id = ui->recherche->text().toInt();

    if(employe.supprimer(id)) {
        ui->tabemp->setModel(employe.afficher());

        QMessageBox::information(this, "Suppression réussie", "L'employé a été supprimé avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "La suppression de l'employé a échoué.");
    }
    afficherSalaireEtMasseSalariale();
    afficherStatistiquesPostes();
    afficherEmployeesAvecUnAnDeContratRestant();
}
void MainWindow::on_rechercher_clicked()
{
    int id = ui->recherche->text().toInt();
    Employe e = employe.rechercher(id);


    if (e.getIdEmploye() != 0) {

        ui->id->setText(QString::number(e.getIdEmploye()));
        ui->nom->setText(e.getNom());
        ui->prenom->setText(e.getPrenom());
        ui->salaire->setText(QString::number(e.getSalaire()));
        ui->dcontrat->setDate(e.getDDate());
        ui->fcontrat->setDate(e.getFDate());
        ui->poste->setCurrentText(e.getPoste());
        ui->telephone->setText(QString::number(e.getTelephone()));
        ui->presences->setText(QString::number(e.getPresences()));
    } else {
        QMessageBox::warning(this, "Non trouvé", "Employé non trouvé avec cet ID.");
    }
}


void MainWindow::on_boutonTrier_clicked() {
    QString critere;


    if (ui->tri->currentText() == "salaire") {
        critere = "salaire";
    } else if (ui->tri->currentText() == "date debut contrat") {
        critere = "date_debut_contrat";
    }


    Employe employe;
    QSqlQueryModel* model = employe.trier(critere);
    ui->tabemp->setModel(model);
}
void MainWindow::Rechercheemploye() {
    QString text = ui->recherche->text();
    QString critere = ui->rech->currentText();
    Employe employe;

    QSqlQueryModel* model;

    if (text.isEmpty()) {

        model = employe.afficher();
    } else {
        QSqlQuery query;

        if (critere == "id") {
            query.prepare("SELECT ID_EMPLOYE, NOM, PRENOM, TELEPHONE, POSTE, SALAIRE, PRESENCES, D_DATE, F_DATE FROM employes WHERE ID_EMPLOYE = :valeur");
        } else if (critere == "nom") {
            query.prepare("SELECT ID_EMPLOYE, NOM, PRENOM, TELEPHONE, POSTE, SALAIRE, PRESENCES, D_DATE, F_DATE FROM employes WHERE NOM = :valeur");
        }
        query.bindValue(":valeur", text);


        if (query.exec() && query.next() && query.value(0).toInt() > 0) {

            model = new QSqlQueryModel();
            model->setQuery(query);
        } else {

            model = employe.afficher();
        }
    }

    ui->tabemp->setModel(model);
}

void MainWindow::exporterListeEmployesPDF()
{

    QString filePath = QFileDialog::getSaveFileName(this, "Exporter sous PDF", "", "Fichiers PDF (*.pdf)");

    if (filePath.isEmpty()) {
        return;
    }


    if (!filePath.endsWith(".pdf", Qt::CaseInsensitive)) {
        filePath.append(".pdf");
    }

    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A2));
    pdfWriter.setResolution(300);

    QPainter painter;
    if (!painter.begin(&pdfWriter)) {
        QMessageBox::critical(this, "Erreur", "Impossible de créer le fichier PDF.");
        return;
    }


    QFont font;
    font.setFamily("Arial");
    font.setPointSize(10);
    painter.setFont(font);


    painter.drawText(2200, 50, "Liste des Employés");


    int x = 150;
    int y = 120;


    int columnWidth = 500;


    int rowHeight = 110;


    painter.drawText(x, y, "ID");
    painter.drawText(x + columnWidth, y, "Nom");
    painter.drawText(x + 2 * columnWidth, y, "Prénom");
    painter.drawText(x + 3 * columnWidth, y, "Téléphone");
    painter.drawText(x + 4 * columnWidth, y, "Poste");
    painter.drawText(x + 5 * columnWidth, y, "Salaire");
    painter.drawText(x + 6 * columnWidth, y, "Presences");
    painter.drawText(x + 7 * columnWidth, y, "Début Contrat");
    painter.drawText(x + 8 * columnWidth, y, "Fin Contrat");


    y += rowHeight;
    painter.drawLine(x - 10, y, x + 8 * columnWidth, y);

    y += rowHeight;


     QSqlQuery query("SELECT ID_EMPLOYE, NOM, PRENOM, TELEPHONE, POSTE, SALAIRE, PRESENCES, D_DATE, F_DATE FROM employes");
    while (query.next()) {

        int id = query.value(0).toInt();
        QString nom = query.value(1).toString();
        QString prenom = query.value(2).toString();
        float salaire = query.value(5).toFloat();
        QString poste = query.value(4).toString();
        QString telephone = query.value(3).toString();
        int presences = query.value(6).toInt();
        QDate debutContrat = query.value(7).toDate();
        QDate finContrat = query.value(8).toDate();


        painter.drawText(x, y, QString::number(id));
        painter.drawText(x + columnWidth, y, nom);
        painter.drawText(x + 2 * columnWidth, y, prenom);
        painter.drawText(x + 5 * columnWidth, y, QString::number(salaire));
        painter.drawText(x + 4 * columnWidth, y, poste);
        painter.drawText(x + 3 * columnWidth, y, telephone);
        painter.drawText(x + 6 * columnWidth, y, QString::number(presences));
        painter.drawText(x + 7 * columnWidth, y, debutContrat.toString("dd/MM/yyyy"));
        painter.drawText(x + 8 * columnWidth, y, finContrat.toString("dd/MM/yyyy"));


        y += rowHeight;
        painter.drawLine(x - 10, y, x + 8 * columnWidth, y);


    }


    painter.end();


    QMessageBox::information(this, "Exportation réussie", "La liste des employés a été exportée avec succès.");
}

void MainWindow::afficherSalaireEtMasseSalariale() {

    QTableView* tableView = ui->tabsalaire;
    QLabel* masseSalarialeLabel = ui->masse;


    Employe employe;


    QStandardItemModel* model = employe.afficherAvecSalaireBrut(masseSalarialeLabel);


    if (model) {

        tableView->setModel(model);


        tableView->resizeColumnsToContents();


        tableView->resizeRowsToContents();
    } else {

        QMessageBox::warning(this, "Erreur", "Impossible d'afficher les employés.");
    }
}
void MainWindow::afficherStatistiquesPostes() {
    QLayout *layout = ui->stat->layout();
    if (layout) {
        for (int i = layout->count() - 1; i >= 0; --i) {
            QLayoutItem *item = layout->itemAt(i);
            if (item) {
                QWidget *widget = item->widget();
                if (widget) {
                    layout->removeWidget(widget);
                    delete widget;
                }
            }
        }
    }

    Employe employe;
    QMap<QString, int> stats = employe.obtenirStatistiquesPostes();

    int total = 0;
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        total += it.value();
    }

    QPieSeries *series = new QPieSeries();


    QList<QColor> couleursMauves = {
        QColor(128, 0, 128),
        QColor(153, 50, 204),
        QColor(186, 85, 211),
        QColor(218, 112, 214),
        QColor(230, 230, 250),
        QColor(138, 43, 226),
        QColor(199, 21, 133),
        QColor(148, 0, 211),
        QColor(221, 160, 221)
    };

    int indexCouleur = 0;
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        QPieSlice *slice = series->append(it.key(), it.value());
        double percentage = (double)it.value() / total * 100;
        slice->setLabel(QString("%1: %2%").arg(it.key()).arg(QString::number(percentage, 'f', 1)));
        slice->setLabelVisible(true);


        slice->setColor(couleursMauves[indexCouleur % couleursMauves.size()]);
        indexCouleur++;
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des postes");
    chart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    if (!ui->stat->layout()) {
        QVBoxLayout *layout = new QVBoxLayout(ui->stat);
        ui->stat->setLayout(layout);
    }

    ui->stat->layout()->addWidget(chartView);
}

void MainWindow::sendRenewalMessages() {

    Employe employe;


    QList<Employe> employeesWithOneYearLeft = employe.getEmployeesWithOneYearLeft();


    for (const Employe &employee : employeesWithOneYearLeft) {
        QString message = QString("Bonjour %1 %2, il vous reste un an de contrat. "
                                  "Souhaitez-vous renouveler ou modifier votre contrat ?")
                              .arg(employee.getNom())
                              .arg(employee.getPrenom());


        QString numero = "+216" + QString::number(employee.getTelephone());


        employe.sendSMS(numero, message);
    }
}
void MainWindow::afficherEmployeesAvecUnAnDeContratRestant() {

    Employe employe;


    QList<Employe> employeesWithOneYearLeft = employe.getEmployeesWithOneYearLeft();


    QStandardItemModel *model = new QStandardItemModel();


    model->setHorizontalHeaderLabels({"ID", "Nom", "Prénom", "Téléphone", "Poste", "Salaire", "Présences", "Date début", "Date fin"});


    for (const Employe &employee : employeesWithOneYearLeft) {

        QList<QStandardItem *> row;

        row << new QStandardItem(QString::number(employee.getIdEmploye()));
        row << new QStandardItem(employee.getNom());
        row << new QStandardItem(employee.getPrenom());
        row << new QStandardItem(QString::number(employee.getTelephone()));
        row << new QStandardItem(employee.getPoste());
        row << new QStandardItem(QString::number(employee.getSalaire()));
        row << new QStandardItem(QString::number(employee.getPresences()));
        row << new QStandardItem(employee.getDDate().toString("yyyy-MM-dd"));
        row << new QStandardItem(employee.getFDate().toString("yyyy-MM-dd"));


        model->appendRow(row);
    }
    ui->tabsms->resizeColumnsToContents();

    ui->tabsms->setModel(model);
}
bool MainWindow::inscrireEmploye() {
    QString nom = ui->nomi->text();
    QString prenom = ui->prenomi->text();
    QString poste = ui->postei->currentText();
    QString telephone = ui->telephonei->text();
    QString mdp = ui->mdpi->text();


    if (nom.isEmpty() || prenom.isEmpty() || poste.isEmpty() || telephone.isEmpty() || mdp.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return false;
    }
    if (nom.trimmed().isEmpty() || !nom.contains(QRegularExpression("^[A-Za-zéèàôùïë' -]+$"))) {
        QMessageBox::warning(this, "Erreur", "Le nom doit être valide (lettres, espaces et caractères accentués autorisés).");
        return false;
    }

    if (prenom.trimmed().isEmpty() || !prenom.contains(QRegularExpression("^[A-Za-zéèàôùïë' -]+$"))) {
        QMessageBox::warning(this, "Erreur", "Le prénom doit être valide (lettres, espaces et caractères accentués autorisés).");
        return false;
    }


    if (!telephone.startsWith("2") && !telephone.startsWith("3") &&
            !telephone.startsWith("5") && !telephone.startsWith("7") &&
            !telephone.startsWith("9") || telephone.length() != 8) {
        QMessageBox::warning(this, "Erreur", "Le numéro de téléphone doit être valide.");
        return false;
    }

    QRegularExpression regex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d).{6,}$");
    if (!regex.match(mdp).hasMatch()) {
        QMessageBox::warning(this, "Erreur",
                             "Le mot de passe doit contenir au moins 6 caractères, "
                             "incluant une lettre majuscule, une lettre minuscule, et un chiffre.");
        return false;
    }


    Employe employe;
    int idUnique = employe.genererIdUnique();


    if (employe.inscrire(idUnique, nom, prenom, poste, telephone, mdp)) {
        QMessageBox::information(this, "Succès", "Employé inscrit avec succès.");


        QString message = QString("Bienvenue %1 %2 ! Votre ID employé est : %3.")
                              .arg(nom).arg(prenom).arg(idUnique);
        employe.sendSMS("+216" + telephone, message);


        ui->nomi->clear();
        ui->prenomi->clear();
        ui->telephonei->clear();
        ui->mdpi->clear();
        ui->postei->setCurrentIndex(0);

        return true;
    } else {
        QMessageBox::critical(this, "Erreur", "L'inscription a échoué.");
        return false;
    }
}
void MainWindow::on_connexionButton_clicked() {
    QString idText = ui->identifiant->text();
    QString mdpText = ui->mdp->text();


    if (idText.isEmpty() || mdpText.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }


    int id = idText.toInt();


    if (id == 0) {
        QMessageBox::warning(this, "Erreur", "ID invalide.");
        return;
    }


    QSqlQuery query;
    query.prepare("SELECT MDP, POSTE FROM employes WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        QString mdp = query.value(0).toString();
        QString poste = query.value(1).toString();


        if (mdp == mdpText) {

            if (poste == "Responsable RH") {
                changerDePageemploye();
            } else if (poste == "Receptionniste") {
                changerDePageclient();
            } else if (poste == "Responsable reservation ") {
                changerDePagereservation();
            } else if (poste == "Responsable stock") {
                changerDePagestock();
            } else if (poste == "Responsable maintenance") {
                changerDePagemaintenance();
            } else {
                QMessageBox::warning(this, "Accès refusé", "Poste non reconnu.");
            }
        } else {

            QMessageBox::warning(this, "Erreur", "Mot de passe incorrect.");
        }
    } else {

        QMessageBox::warning(this, "Erreur", "ID employé non trouvé.");
    }
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
        ui->tableClient->setModel(cl.afficher());
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
        ui->tableClient->setModel(cl.afficher());
    }
}


void MainWindow::on_modifierclient_clicked()
{
    int id=ui->lineEdit_chercher->text().toInt();
    if (id <= 0 || ui->lineEdit_id->text().isEmpty() )
    {
        QMessageBox::information(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un CIN"), QMessageBox::Cancel);
        return;
    }

    QString nv_nom= ui ->lineEdit_nom->text();
    bool testn = true;
    for (int i = 0; i < nv_nom.length(); ++i)
    {
        if (!nv_nom[i].isLetter() &&nv_nom[i] != ' ')
        {
            testn = false;
        }
    }
    if (!testn)
    {
        QMessageBox::information(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un nom valide (lettres uniquement)."), QMessageBox::Cancel);
        return;
    }

    QString nv_prenom = ui->lineEdit_prenom->text();
    bool testp = true;
    for (int i = 0; i < nv_prenom.length(); ++i)
    {
        if (!nv_prenom[i].isLetter() && nv_prenom[i] != ' ')
        {
            testp = false;
        }
    }
    if (!testp)
    {
        QMessageBox::information(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un prénom valide (lettres uniquement)."), QMessageBox::Cancel);
        return;
    }

    QString nv_pays = ui->lineEdit_pays->text();
    bool testpa = true;
    for (int i = 0; i < nv_pays.length(); ++i)
    {
        if (!nv_pays[i].isLetter() && nv_pays[i] != ' ')
        {
            testpa = false;
        }
    }
    if (!testpa)
    {
        QMessageBox::information(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un pays valide (lettres uniquement)."), QMessageBox::Cancel);
        return;
    }

    int nv_telephone = ui->lineEdit_telephone->text().toInt();
    if (nv_telephone  == 0 && ui->lineEdit_telephone->text() != "0")
    {
        QMessageBox::information(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un numéro de téléphone valide (entier uniquement)."), QMessageBox::Cancel);
        return;
    }

    int nv_total_points = ui->lineEdit_total->text().toInt();
    if (nv_total_points == 0 && ui->lineEdit_total->text() != "0")
    {
        QMessageBox::information(nullptr, QObject::tr("Erreur"), QObject::tr("Veuillez entrer un nombre valide de points (entier uniquement)."), QMessageBox::Cancel);
        return;
    }


    QDate nv_date =ui->dateEdit->date();
    QString nv_demande= ui ->comboBox_dmd->currentText();
    QString nv_statut= ui ->comboBox_statut->currentText();
    bool test=cl.modifier(id,nv_nom,nv_prenom,nv_date,nv_demande,nv_statut,nv_pays,nv_telephone,nv_total_points);
    if (test)
    {
        QMessageBox:: information (nullptr,QObject::tr("ok"),QObject::tr("modification effectué\n" "click cancel to exit!"),QMessageBox::Cancel);
        ui->tableClient->setModel(cl.afficher());
    }
    else
    {
        QMessageBox:: critical (nullptr,QObject::tr("not ok"),QObject::tr("modification non effectué\n" "click cancel to exit!"),QMessageBox::Cancel);
    }
}
void MainWindow::on_chercher_clicked()
{
    QVariant critere = ui->rechercheclient->currentText();
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

    if (ui->triclient->currentText() == "statut") {
        model = client.trier("statut");
    }
    else if (ui->triclient->currentText() == "date_de_naissance") {
        model = client.trier("date_de_naissance");
    }
    else if (ui->triclient->currentText() == "total_points") {
        model = client.trier("total_points");
    }
    if (model != nullptr) {
        ui->tableClient->setModel(model);

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
        QSqlQueryModel *sqlModel = qobject_cast<QSqlQueryModel *>(ui->tableClient->model());

        if (!sqlModel)
        {
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

        ui->tableClient->setModel(standardModel);

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
    QVariant critere = ui->recherchehistorique->currentText();
    QString valeurRecherche = ui->lineEdit_cherche2->text();

    QSqlQueryModel *sqlModel = new QSqlQueryModel(this);

    QSqlQuery query;
    if (critere == "id")
    {
        int id = valeurRecherche.toInt();


        // Créer la requête SQL avec paramètre
        query.prepare("SELECT r.ID_reservation, r.date_reservation, r.date_arrive, r.date_depart, "
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
        query.prepare("SELECT r.ID_reservation, r.date_reservation, r.date_arrive, r.date_depart, "
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
    query.prepare("SELECT r.ID_reservation, r.date_reservation, r.date_arrive, r.date_depart, "
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
void MainWindow::on_validerButtonreservation_clicked()
{
    int idReservation = idReservationLineEdit->text().toInt();
    QDate dateReservation = dateReservationDateEdit->date();
    QDate dateArrive = dateArriveDateEdit->date();
    QDate dateDepart = dateDepartDateEdit->date();
    QString typeChambre = typeChambreComboBox->currentText();
    QString statutReservation = statutReservationComboBox->currentText();
    QString modePaiement = modePaiementComboBox->currentText();
    float montant = montantLineEdit->text().toFloat();
    int idclient = ui->idclientr->text().toInt();

    Reservation reservation(idReservation, dateReservation, dateArrive, dateDepart,
                            typeChambre, statutReservation, modePaiement, montant,idclient);

    if (reservation.ajouter()) {
        ui->tabres->setModel(reservation.afficher());
        reservations.append(reservation);  // Ajout au vecteur de réservations
        QMessageBox::information(this, "Ajout réussi", "La réservation a été ajoutée avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout de la réservation.");
    }
}

void MainWindow::on_supprimerButtonreservation_clicked()
{
    int idReservation = searchLineEdit->text().toInt();


    if (idReservation == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID de réservation valide.");
        return;
    }


    Reservation reservation;
    if (reservation.supprimer(idReservation)) {
        ui->tabres->setModel(reservation.afficher());
        QMessageBox::information(this, "Suppression réussie", "La réservation a été supprimée avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression de la réservation. Vérifiez l'ID.");
    }
}

void MainWindow::on_modifierButtonreservation_clicked()
{

    int idReservation = idReservationLineEdit->text().toInt();
    QDate dateReservation = dateReservationDateEdit->date();
    QDate dateArrive = dateArriveDateEdit->date();
    QDate dateDepart = dateDepartDateEdit->date();
    QString typeChambre = typeChambreComboBox->currentText();
    QString statutReservation = statutReservationComboBox->currentText();
    QString modePaiement = modePaiementComboBox->currentText();
    float montant = montantLineEdit->text().toFloat();
    int idclient = ui->idclientr->text().toInt();


    Reservation reservation(idReservation, dateReservation, dateArrive, dateDepart,
                            typeChambre, statutReservation, modePaiement, montant,idclient);


    if (reservation.modifier(idReservation, dateReservation, dateArrive, dateDepart,
                             typeChambre, statutReservation, modePaiement, montant,idclient)) {
        ui->tabres->setModel(reservation.afficher());
        QMessageBox::information(this, "Modification réussie", "La réservation a été modifiée avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la modification de la réservation.");
    }
}
void MainWindow::afficherres() {

    Reservation reservation;


    QSqlQueryModel *model = reservation.afficher();


    if (model) {

        ui->tabres->setModel(model);
    } else {
        qDebug() << "Erreur : Le modèle de données n'a pas pu être créé.";
    }
}
void MainWindow::on_searchLineEdit_textChanged(const QString &text)
{
    int idReservation = text.toInt();

    if (idReservation != 0) {
        Reservation reservation;
        if (reservation.rechercher(idReservation)) {

            idReservationLineEdit->setText(QString::number(reservation.getIdReservation()));
            dateReservationDateEdit->setDate(reservation.getDateReservation());
            dateArriveDateEdit->setDate(reservation.getDateArrive());
            dateDepartDateEdit->setDate(reservation.getDateDepart());
            typeChambreComboBox->setCurrentText(reservation.getTypeChambre());
            statutReservationComboBox->setCurrentText(reservation.getStatutReservation());
            modePaiementComboBox->setCurrentText(reservation.getModePaiment());
            montantLineEdit->setText(QString::number(reservation.getMontant()));
        } else {
            QMessageBox::warning(this, "Réservation non trouvée", "Aucune réservation trouvée pour cet ID.");
        }
    }
}
void MainWindow::on_exporterreservation_clicked() {

    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), "PDF Files (*.pdf)");
    if (!filePath.isEmpty()) {
        generateReservationTablePdf(reservations, filePath);
    }
}

void MainWindow::on_triComboBox_currentIndexChanged(int index) {
    QString orderBy;


    if (index == 0) {
        orderBy = "ID_RESERVATION";
    } else if (index == 1) {
        orderBy = "DATE_ARRIVE";
    }


    QSqlQueryModel *model = reservation.trierPar(orderBy);
    if (model) {
        ui->tabres->setModel(model);
    } else {
        qDebug() << "Erreur : Le tri n'a pas pu être appliqué.";
    }
}
void MainWindow::afficherStatistiquesTypeChambre() {
    // Requête SQL pour obtenir les statistiques des types de chambres
    QSqlQuery query;
    query.prepare("SELECT TYPE_CHAMBRE, COUNT(*) as Nombre FROM RESERVATIONS GROUP BY TYPE_CHAMBRE");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les données de la base de données : " + query.lastError().text());
        return;
    }

    // Création d'une série pour le graphique
    QPieSeries *series = new QPieSeries();

    // Parcourir les résultats de la requête et remplir la série
    while (query.next()) {
        QString typeChambre = query.value("TYPE_CHAMBRE").toString();
        int count = query.value("Nombre").toInt();
        series->append(typeChambre, count);
    }

    // Configurer les tranches du graphique
    for (auto slice : series->slices()) {
        slice->setLabelVisible(true); // Rendre les étiquettes visibles
        slice->setExploded(false);   // Vous pouvez ajuster cette valeur si vous voulez exploser des tranches
    }

    // Créer et configurer le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des Types de Chambres");

    // Créer et afficher le graphique dans le `QWidget` nommé `omar`
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Ajuster la taille et afficher dans le conteneur `omar`
    chartView->setParent(ui->statres);
    chartView->resize(ui->statres->size());
    chartView->show();
}
void MainWindow::on_email_clicked()
{

    QString destinataire = "ramysnoussi@gmail.com";
    QString objet = "Confirmation de votre réservation";
    QString corps = "Bonjour Rami,\n\nVotre réservation est confirmée.\n\nMerci de votre confiance.";




    envoyerEmail(destinataire, objet, corps);


    QMessageBox::information(this, "Succès", "Email envoyé avec succès.");
}
void MainWindow::envoyerEmail(const QString& destinataire, const QString& sujet, const QString& message) {
    QString smtpServer = "smtp.gmail.com";
    int smtpPort = 465;
    QString from = "aziz228nasri@gmail.com";
    QString password = "paqd yivs yzja uyxa";

    QString emailBody = "From: " + from + "\r\n" +
                        "To: " + destinataire + "\r\n" +
                        "Subject: " + sujet + "\r\n\r\n" +
                        message;

    QSslSocket socket;
    socket.connectToHostEncrypted(smtpServer, smtpPort);
    if (!socket.waitForConnected()) {
        qDebug() << "Erreur de connexion au serveur SMTP:" << socket.errorString();
        return;
    }
    qDebug() << "Connexion réussie au serveur SMTP.";


    if (!socket.waitForReadyRead()) {
        qDebug() << "Erreur lecture du serveur SMTP:" << socket.errorString();
        return;
    }
    qDebug() << "Réponse du serveur:" << socket.readAll();


    socket.write("EHLO localhost\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    qDebug() << "Réponse EHLO:" << socket.readAll();

    socket.write("AUTH LOGIN\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    qDebug() << "Réponse AUTH LOGIN:" << socket.readAll();

    socket.write(QByteArray().append(from.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    qDebug() << "Réponse email (AUTH):" << socket.readAll();

    socket.write(QByteArray().append(password.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    qDebug() << "Réponse mot de passe (AUTH):" << socket.readAll();

    socket.write("MAIL FROM:<" + from.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    qDebug() << "Réponse MAIL FROM:" << socket.readAll();

    socket.write("RCPT TO:<" + destinataire.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    qDebug() << "Réponse RCPT TO:" << socket.readAll();

    socket.write("DATA\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    qDebug() << "Réponse DATA:" << socket.readAll();

    socket.write(emailBody.toUtf8() + "\r\n.\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    qDebug() << "Réponse après envoi du contenu:" << socket.readAll();

    socket.write("QUIT\r\n");
    socket.waitForBytesWritten();
    qDebug() << "Fermeture de la connexion.";

    socket.close();
    qDebug() << "E-mail envoyé avec succès.";
}
void MainWindow::on_sendVerificationButton_clicked() {
    QString userEmail = ui->email->text(); // Lire l'adresse e-mail saisie

    if (userEmail.isEmpty() || !userEmail.contains("@")) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une adresse e-mail valide.");
        return;
    }

    // Générer un code aléatoire
    QString verificationCode = QString::number(QRandomGenerator::global()->bounded(100000, 999999)); // Code à 6 chiffres

    // Préparer le sujet et le contenu de l'e-mail
    QString subject = "Votre code de vérification";
    QString body = QString("Bonjour,\n\nVoici votre code de vérification : %1.\n\nMerci.").arg(verificationCode);

    // Appeler la fonction pour envoyer l'e-mail
    if (envoyerVerificationEmail(userEmail, subject, body)) {
        QMessageBox::information(this, "Succès", "Un e-mail avec un code de vérification a été envoyé.");
        qDebug() << "Code envoyé à l'utilisateur : " << verificationCode; // Affiche le code dans la console pour vérification (optionnel)
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'envoi de l'e-mail.");
    }
}
bool MainWindow::envoyerVerificationEmail(const QString &recipient, const QString &subject, const QString &body) {
    QString smtpServer = "smtp.gmail.com";
    int smtpPort = 465; // Port SSL
    QString senderEmail = "aziz228nasri@gmail.com"; // Remplacez par votre adresse e-mail
    QString appPassword = "paqd yivs yzja uyxa"; // Remplacez par votre mot de passe d'application

    QSslSocket socket;
    socket.connectToHostEncrypted(smtpServer, smtpPort);
    if (!socket.waitForConnected(5000)) {
        qDebug() << "Erreur de connexion au serveur SMTP:" << socket.errorString();
        return false;
    }

    socket.write("EHLO localhost\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.write("AUTH LOGIN\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.write(QByteArray().append(senderEmail.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.write(QByteArray().append(appPassword.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.write("MAIL FROM:<" + senderEmail.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.write("RCPT TO:<" + recipient.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.write("DATA\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    QString emailBody = "From: " + senderEmail + "\r\n"
                                                 "To: " + recipient + "\r\n"
                                      "Subject: " + subject + "\r\n\r\n" +
                        body + "\r\n.\r\n";

    socket.write(emailBody.toUtf8());
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.write("QUIT\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.close();
    return true;
}
void MainWindow::on_verifyCodeButton_clicked() {
    QString enteredCode = ui->code->text();

    if (enteredCode == verificationCode) {
        QMessageBox::information(this, "Vérification réussie", "Code vérifié avec succès !");
        ui->stackedWidget->setCurrentIndex(3);
    } else {
        QMessageBox::information(this, "Vérification échoué", "Code échoué !");
        ui->stackedWidget->setCurrentIndex(2);
    }
}
void MainWindow::on_sendButton_clicked() {
    int id = ui->lineEdit_chercher->text().toInt();

    if (id > 0) {
        if (!QSqlDatabase::database().isOpen()) {
            qDebug() << "Erreur : Connexion à la base de données fermée.";
            ui->statuslabel->setText("Erreur : Connexion à la base de données.");
            return;
        }

        QSqlQuery query;
        query.prepare("SELECT nom, prenom FROM clients WHERE ID_client = :id");
        query.bindValue(":id", id);

        if (query.exec() && query.next()) {
            QString nom = query.value(0).toString();
            QString prenom = query.value(1).toString();

            QString data = "NOM:" + nom + ";" + prenom + "\n";
            if (arduino.sendData(data)) {
                ui->statuslabel->setText("Données envoyées : " + data);
            } else {
                ui->statuslabel->setText("Erreur : Échec de l'envoi des données.");
            }
        } else {
            // ID inexistant
            QString lcdMessage = "ID n'existe pas";
            arduino.sendData(lcdMessage);
            ui->statuslabel->setText("Erreur : ID introuvable.");
        }
    } else {
        ui->statuslabel->setText("Erreur : L'ID est invalide.");
    }
}


void MainWindow::on_validerClientButton_clicked() {
    int id = ui->lineEdit_chercher->text().toInt();

    if (id > 0) {
        if (!QSqlDatabase::database().isOpen()) {
            qDebug() << "Erreur : Connexion à la base de données fermée.";
            ui->statuslabel->setText("Erreur : Connexion à la base de données.");
            return;
        }

        QSqlQuery query;
        query.prepare("SELECT nom, prenom FROM clients WHERE ID_client = :id");
        query.bindValue(":id", id);

        if (query.exec() && query.next()) {
            QString nom = query.value(0).toString();
            QString prenom = query.value(1).toString();

            QString data = "NOM:" + nom + ";" + prenom + "\n";
            if (arduino.sendData(data)) {
                ui->statuslabel->setText("Données envoyées : " + data);

                QSerialPort *serial = arduino.getSerialPort();
                if (serial && serial->canReadLine()) {
                    QString response = serial->readAll().trimmed();
                    if (response == "CLIM:ON") {
                        QSqlQuery updateQuery;
                        updateQuery.prepare("UPDATE clients SET statut = 'en cours' WHERE ID_client = :id");
                        updateQuery.bindValue(":id", id);

                        if (updateQuery.exec()) {
                            ui->statuslabel->setText("Climatisation activée et statut mis à jour.");
                            ui->tableClient->setModel(cl.afficher());
                        } else {
                            qDebug() << "Erreur SQL :" << updateQuery.lastError().text();
                            ui->statuslabel->setText("Erreur : Mise à jour du statut échouée.");
                        }
                    } else if (response == "CLIM:OFF") {
                        ui->statuslabel->setText("Climatisation désactivée.");
                    } else {
                        ui->statuslabel->setText("Données inconnues reçues : " + response);
                    }
                }
            } else {
                ui->statuslabel->setText("Erreur : Échec de l'envoi des données.");
            }
        } else {
            // ID inexistant
            QString lcdMessage = "ID n'existe pas";
            arduino.sendData(lcdMessage);
            ui->statuslabel->setText("Erreur : ID introuvable.");
        }
    } else {
        ui->statuslabel->setText("Erreur : L'ID est invalide.");
    }
}


void MainWindow::readArduinoData() {
    QSerialPort *serial = arduino.getSerialPort();
    if (serial && serial->canReadLine()) {
        QString data = serial->readAll().trimmed();
        qDebug() << "Donnée reçue depuis Arduino :" << data;

        int id = ui->lineEdit_chercher->text().toInt();
        /*if (!id) {
            ui->statuslabel->setText("Erreur : ID invalide.");
            return;
        }*/

        if (data == "CLIM:ON") {
            if (!messageDisplayed) {
                if (!QSqlDatabase::database().isOpen()) {
                    qDebug() << "Erreur : Connexion à la base de données fermée.";
                    ui->statuslabel->setText("Erreur : Connexion à la base de données.");
                    return;
                }

                QSqlQuery query;
                query.prepare("UPDATE clients SET statut = 'en cours' WHERE ID_client = :id");
                query.bindValue(":id", id);

                if (query.exec()) {
                    ui->statuslabel->setText("Climatisation activée. Statut client mis à jour : 'en cours'.");
                    ui->tableClient->setModel(cl.afficher());
                    QMessageBox::information(this, "Climatisation activée",
                                             "La climatisation est activée et le statut du client a été mis à jour.");
                    messageDisplayed = true;
                } else {
                    qDebug() << "Erreur SQL :" << query.lastError().text();
                    QMessageBox::warning(this, "Erreur",
                                         "Impossible de mettre à jour le statut du client : " + query.lastError().text());
                }
            } else {
                qDebug() << "Message déjà affiché, pas de mise à jour supplémentaire.";
            }

        } else if (data == "CLIM:OFF") {
            ui->statuslabel->setText("Climatisation désactivée.");
            messageDisplayed = false;
        } else {
            ui->statuslabel->setText("Données inconnues reçues : " + data);
        }
    }
}




void MainWindow::listPorts() {
    arduino.listAvailablePorts();
}


void MainWindow::on_sushButton_23_clicked()
{
    // Get input values from UI
    int id = ui->lineEdit->text().toInt();
    QString nomProduit = ui->lineEdit_2->text();
    int quantiteDispo = ui->lineEdit_3->text().toInt();
    QDate dateLivraison = ui->dateEdit_2->date();
    QDate dateReapprovisionnement = ui->dateEdit_3->date();
    // Create a Produit object with these values
    Produit produit(id, nomProduit, quantiteDispo, dateLivraison, dateReapprovisionnement);
    // Check if the product already exists in the database
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM stocks WHERE id = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        QMessageBox::warning(this, "Database Error", "Failed to check product existence.");
        return;
    }
    query.next();
    bool exists = query.value(0).toInt() > 0;
    // If the product exists, update it; otherwise, add it
    if (exists) {
        // Update the existing product
        if (produit.modifier(id)) {
            QMessageBox::information(this, "Update Product", "Product updated successfully.");
            afficherProduitsDansTable();
        } else {
            QMessageBox::warning(this, "Update Product", "Failed to update product.");
        }
    } else {
        // Add the new product
        if (produit.ajouter()) {
            QMessageBox::information(this, "Add Product", "Product added successfully.");
            afficherProduitsDansTable();
        } else {
            QMessageBox::warning(this, "Add Product", "Failed to add product.");
        }
    }
    // Optionally, refresh the product display after adding/updating
    // Assuming you have a method to update the view, e.g., displayProducts()
    // displayProducts();
}
void MainWindow::afficherProduitsDansTable() {
    // Déterminer l'ordre de tri depuis sortComboBox
    int sortIndex = ui->sortComboBox->currentIndex();
    QString sortOrder = (sortIndex == 0) ? "ORDER BY quantiteDispo DESC" : "ORDER BY quantiteDispo ASC";

    // Récupérer les données triées via Produit::afficher
    Produit produit(0, "", 0, QDate::currentDate(), QDate::currentDate());
    QSqlQueryModel* queryModel = produit.afficher(sortOrder);

    // Configurer les en-têtes pour le modèle
    queryModel->setHeaderData(0, Qt::Horizontal, "ID");
    queryModel->setHeaderData(1, Qt::Horizontal, "Nom du Produit");
    queryModel->setHeaderData(2, Qt::Horizontal, "Quantité");
    queryModel->setHeaderData(3, Qt::Horizontal, "Date de Livraison");
    queryModel->setHeaderData(4, Qt::Horizontal, "Date de Réapprovisionnement");

    // Appliquer le modèle à la table
    ui->tableslim->setModel(queryModel);

    // Appliquer les couleurs via un délégué
    for (int row = 0; row < queryModel->rowCount(); ++row) {
        int quantity = queryModel->index(row, 2).data().toInt(); // Colonne "Quantité"

        // Vérification des seuils
        if (quantity == 0) {
            ui->tableslim->model()->setData(
                ui->tableslim->model()->index(row, 2),
                QColor(Qt::red),
                Qt::BackgroundRole
                );
        } else if (quantity < 10) {
            ui->tableslim->model()->setData(
                ui->tableslim->model()->index(row, 2),
                QColor(Qt::yellow),
                Qt::BackgroundRole
                );
        }
    }
}
void MainWindow::on_sushButton_21_clicked() {
    afficherProduitsDansTable();
}
void MainWindow::on_sushButton_24_clicked() {
    // Lire l'ID à supprimer depuis le QLineEdit (assurez-vous de nommer votre QLineEdit comme lineEdit_id)
    int id = ui->lineEdit->text().toInt();
    Produit produit(0, "", 0, QDate::currentDate(), QDate::currentDate());
    if (produit.supprimer(id)) {
        // Afficher un message de confirmation
        QMessageBox::information(this, "Suppression", "Le produit a été supprimé avec succès.");
        // Actualiser l'affichage des produits après la suppression
        afficherProduitsDansTable();
    } else {
        // Afficher un message d'erreur si la suppression a échoué
        QMessageBox::warning(this, "Erreur", "Échec de la suppression du produit.");
    }
}
void MainWindow::Rechercher(const QString &searchID)
{
    QSqlQueryModel* model = qobject_cast<QSqlQueryModel*>(ui->tableslim->model());  // Récupérer le modèle attaché à la QTableView
    if (!model) {
        QMessageBox::warning(this, "Erreur", "Modèle de données non valide.");
        return;
    }

    int rowCount = model->rowCount();
    bool productFound = false;  // Indicateur pour vérifier si le produit a été trouvé

    // Parcourir chaque ligne du modèle pour chercher l'ID du produit
    for (int i = 0; i < rowCount; ++i) {
        QString id = model->index(i, 0).data().toString();  // Supposons que l'ID est dans la 1ère colonne (index 0)

        // Vérifier si l'ID correspond à celui recherché
        if (id == searchID) {
            productFound = true;

            // Sélectionner la ligne correspondante
            ui->tableslim->selectRow(i);

            // Afficher les détails du produit trouvé
            QString productName = model->index(i, 1).data().toString();  // Nom du produit dans la 2ème colonne (index 1)
            QString quantity = model->index(i, 2).data().toString();  // Quantité dans la 3ème colonne (index 2)
            QString deliveryDate = model->index(i, 3).data().toString();  // Date de livraison dans la 4ème colonne (index 3)
            QString restockDate = model->index(i, 4).data().toString();  // Date de réapprovisionnement dans la 5ème colonne (index 4)

            // Affichage des informations dans une boîte de message
            QMessageBox::information(this, "Produit trouvé",
                                     "ID: " + searchID + "\nNom: " + productName +
                                         "\nQuantité disponible: " + quantity +
                                         "\nDate de livraison: " + deliveryDate +
                                         "\nDate de réapprovisionnement: " + restockDate);
            return;
        }
    }

    // Si le produit n'a pas été trouvé, afficher un message d'erreur
    if (!productFound) {
        QMessageBox::warning(this, "Produit introuvable", "Aucun produit trouvé avec l'ID " + searchID);
    }
}

void MainWindow::on_sushButton_28_clicked()
{
    // Récupérer l'ID de produit depuis le QLineEdit
    QString searchID = ui->recherchesalim->text();  // lineEdit_7 contient l'ID du produit

    // Vérifier si l'ID est vide
    if (searchID.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID de produit.");
        return;
    }

    // Appeler la méthode Rechercher avec l'ID de produit
    Rechercher(searchID);
}
void MainWindow::afficherStatistiques()
{
    QSqlQuery query;
    query.prepare("SELECT nomProduit, quantiteDispo FROM stocks");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la récupération des données : " + query.lastError().text());
        return;
    }

    QPieSeries *series = new QPieSeries(this);
    while (query.next()) {
        QString nomProduit = query.value(0).toString();
        int quantiteDispo = query.value(1).toInt();
        series->append(nomProduit, quantiteDispo);
    }

    if (series->slices().isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Aucune donnée disponible pour les statistiques.");
        delete series; // Prevent memory leak
        return;
    }

    // Customize colors
    QList<QColor> customColors = {
        QColor("#ff6f61"), // Warm red
        QColor("#6a9fb5"), // Soft blue
        QColor("#77dd77"), // Light green
        QColor("#fdfd96"), // Yellow
        QColor("#ffb347"), // Orange
        QColor("#836953"), // Brown
        QColor("#b19cd9"), // Lavender
        QColor("#ff6961"), // Pastel red
        QColor("#aec6cf"), // Pastel blue
        QColor("#f49ac2")  // Pastel pink
    };

    int colorIndex = 0;
    for (auto slice : series->slices()) {
        slice->setBrush(customColors[colorIndex % customColors.size()]);
        colorIndex++;
        slice->setLabel(QString("%1 (%2)").arg(slice->label()).arg(slice->value())); // Set slice labels
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des Produits");
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);

    QWidget *statsPage = ui->stat_2;
    if (!statsPage) {
        QMessageBox::critical(this, "Erreur", "Le widget 'stat' n'est pas initialisé.");
        return;
    }

    if (statsPage->layout()) {
        QLayout *oldLayout = statsPage->layout();
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    QVBoxLayout *layout = new QVBoxLayout(statsPage);
    layout->addWidget(chartView);
    statsPage->setLayout(layout);
}
void MainWindow::on_sushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
    afficherStatistiques();               // Display statistics

}
void MainWindow::on_sushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}
void MainWindow::on_sortComboBox_currentIndexChanged() {
    afficherProduitsDansTable(); // Refresh table when sorting changes
}
void MainWindow::on_sushButton_22_clicked() {
    try {
        // Étape 1 : Choisir le chemin du fichier
        QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le fichier PDF", QDir::homePath(), "Documents (*.pdf)");

        // Vérifier si l'utilisateur a annulé l'opération
        if (filePath.isEmpty()) {
            QMessageBox::warning(this, "Exportation annulée", "Aucun fichier sélectionné.");
            return;
        }

        // Forcer l'ajout de l'extension .pdf si elle est manquante
        if (!filePath.endsWith(".pdf", Qt::CaseInsensitive)) {
            filePath += ".pdf";
        }

        qDebug() << "Chemin sélectionné pour le fichier PDF:" << filePath;

        // Vérifier l'initialisation de la table
        if (!ui->tableslim || !ui->tableslim->model()) {
            QMessageBox::critical(this, "Erreur", "Table ou modèle non initialisé.");
            return;
        }

        QAbstractItemModel *model = ui->tableslim->model();

        // Étape 2 : Créer un objet QPrinter
        QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filePath);

        // Créer un QPageLayout pour définir l'orientation en paysage
        QPageLayout pageLayout(QPageSize::A4, QPageLayout::Landscape, QMarginsF(10, 10, 10, 10));
        printer.setPageLayout(pageLayout);

        // Créer un QPainter pour dessiner sur le PDF
        QPainter painter;
        if (!painter.begin(&printer)) {
            QMessageBox::critical(this, "Erreur d'accès", "Impossible de commencer l'écriture dans le fichier PDF.");
            return;
        }

        // Étape 3 : Dessiner le contenu du tableau sur le PDF
        const int tableMargin = 20;   // Marge autour du tableau
        const int rowHeight = 500;   // Hauteur des lignes
        const int colWidth = 2500;   // Largeur des colonnes
        const int titleSpacing = 1500; // Espace après le titre
        const int lineThickness = 1; // Épaisseur des lignes

        int currentY = tableMargin;

        // Dessiner le titre
        painter.setFont(QFont("Arial", 16, QFont::Bold));  // Titre plus grand
        painter.drawText(0, currentY, "Liste des Produits");
        currentY += titleSpacing;  // Espace après le titre

        // Dessiner les en-têtes du tableau
        painter.setFont(QFont("Arial", 12, QFont::Bold));  // En-têtes plus grands
        int currentX = tableMargin;

        for (int col = 0; col < model->columnCount(); ++col) {
            QString headerText = model->headerData(col, Qt::Horizontal).toString();
            painter.drawText(currentX, currentY, headerText);
            currentX += colWidth;
        }
        currentY += rowHeight;  // Espacement après les en-têtes

        // Dessiner les données du tableau
        painter.setFont(QFont("Arial", 12));  // Données plus grandes
        for (int row = 0; row < model->rowCount(); ++row) {
            currentX = tableMargin;
            for (int col = 0; col < model->columnCount(); ++col) {
                QString cellText = model->index(row, col).data().toString();
                painter.drawText(currentX, currentY, cellText);
                currentX += colWidth;
            }
            currentY += rowHeight;  // Passer à la ligne suivante
        }

        // Terminer l'écriture du fichier PDF
        painter.end();

        // Étape 4 : Vérification si le fichier a bien été créé
        if (QFile::exists(filePath)) {
            QMessageBox::information(this, "Exportation réussie", "Le fichier PDF a été enregistré avec succès :\n" + filePath);
        } else {
            QMessageBox::critical(this, "Erreur", "Le fichier PDF n'a pas été créé.");
        }

    } catch (std::exception &e) {
        QMessageBox::critical(this, "Exception", "Une erreur inattendue est survenue : " + QString::fromStdString(e.what()));
    } catch (...) {
        QMessageBox::critical(this, "Erreur inconnue", "Une erreur inconnue est survenue.");
    }
}
void MainWindow::on_sushButton_whatsapp_clicked() {
    QString criticalProducts;
    QString lowStockProducts;

    // Récupérer le modèle associé au QTableView
    QAbstractItemModel* model = ui->tableslim->model();
    if (!model) {
        qDebug() << "Le modèle est null.";
        return;
    }

    // Parcourir les lignes du modèle
    for (int row = 0; row < model->rowCount(); ++row) {
        // Accéder à la quantité (colonne 2) et au nom du produit (colonne 1)
        QModelIndex quantityIndex = model->index(row, 2);
        QModelIndex productNameIndex = model->index(row, 1);

        int quantity = model->data(quantityIndex).toInt();
        QString productName = model->data(productNameIndex).toString();

        // Vérification des seuils de stock
        if (quantity == 0) {
            criticalProducts += productName + " (Stock: 0)\n";
        } else if (quantity < 10) {
            lowStockProducts += productName + " (Stock: " + QString::number(quantity) + ")\n";
        }
    }

    // Envoi de la notification WhatsApp
    sendWhatsAppNotification(criticalProducts, lowStockProducts);
}

void MainWindow::sendWhatsAppNotification(const QString& criticalProducts, const QString& lowStockProducts) {


    // Prepare the message content
    QString message = "Stock Alerts as of " + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + ":\n\n";
    if (!criticalProducts.isEmpty()) {
        message += "Critical Stock:\n" + criticalProducts + "\n";
    }
    if (!lowStockProducts.isEmpty()) {
        message += "Low Stock:\n" + lowStockProducts + "\n";
    }

    // Create API URL
    QUrl apiUrl("https://api.twilio.com/2010-04-01/Accounts/" + accountSID + "/Messages.json");

    // Initialize QNetworkRequest
    QNetworkRequest request(apiUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Prepare POST data
    QByteArray data;
    data.append("From=" + QUrl::toPercentEncoding(fromWhatsApp) + "&");
    data.append("To=" + QUrl::toPercentEncoding(toWhatsApp) + "&");
    data.append("Body=" + QUrl::toPercentEncoding(message));

    // Add basic authentication
    QByteArray auth = accountSID.toUtf8() + ":" + authToken.toUtf8();
    request.setRawHeader("Authorization", "Basic " + auth.toBase64());

    // Debugging: Log the request
    qDebug() << "API URL:" << apiUrl.toString();
    qDebug() << "POST Data:" << data;

    // Send request
    QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);
    QNetworkReply* reply = networkManager->post(request, data);

    // Handle response
    connect(reply, &QNetworkReply::finished, this, &MainWindow::onTwilioResponseReceived);
}

void MainWindow::onTwilioResponseReceived() {
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if (reply) {
        if (reply->error() == QNetworkReply::NoError) {
            QString response = reply->readAll();
            qDebug() << "Message envoyé avec succès: " << response;
            QMessageBox::information(this, "Succès", "Le Message a été envoyé avec succès.");
        } else {
            QString errorResponse = reply->readAll();
            qDebug() << "Erreur d'envoi du SMS: " << errorResponse;
            QMessageBox::critical(this, "Erreur", "L'envoi du SMS a échoué: " + errorResponse);
        }
        reply->deleteLater();
    }
}
void MainWindow::on_sushButton_25_clicked()
{
    QMessageBox::information(this, "Information", "La SESSION EST EXPIREE");
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QFileDialog>
#include<QSqlError>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)


{
    ui->setupUi(this);

    afficherSalaireEtMasseSalariale();

    ui->tabemp->setModel(employe.afficher());
    ui->modifier->setVisible(false);
    ui->supprimer->setVisible(false);

    ui->mdp->setEchoMode(QLineEdit::Password);





    connect(ui->sinscrire, &QPushButton::clicked, this, [this]() {
        if (inscrireEmploye()) {
            changerDePageconnexion();
        }
    });
    connect(ui->seconnecter2, &QPushButton::clicked, this, &MainWindow::on_connexionButton_clicked);


    connect(ui->rechercher, &QPushButton::clicked, this, &MainWindow::on_rechercher_clicked);
    connect(ui->recherche, &QLineEdit::textChanged, this, &MainWindow::onRechercheTextChanged);
    connect(ui->recherche, &QLineEdit::textChanged, this, &MainWindow::Rechercheemploye);

    connect(ui->trier, &QPushButton::clicked, this, &MainWindow::on_boutonTrier_clicked);
    connect(ui->pdf, &QPushButton::clicked, this, &MainWindow::exporterListeEmployesPDF);

    connect(ui->boutonsms, &QPushButton::clicked, this, &MainWindow::afficherEmployeesAvecUnAnDeContratRestant);
    connect(ui->envoyer, &QPushButton::clicked, this, &MainWindow::sendRenewalMessages);
    connect(ui->boutonstat, &QPushButton::clicked, this, &MainWindow::afficherStatistiquesPostes);

    connect(ui->valider, &QPushButton::clicked, this, &MainWindow::on_ajouterButton_clicked);
    connect(ui->modifier, &QPushButton::clicked, this, &MainWindow::on_modifier_clicked);
    connect(ui->supprimer, &QPushButton::clicked, this, &MainWindow::on_supprimerButton_clicked);



    connect(ui->seconnecter1, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
    connect(ui->mdpoublie, &QPushButton::clicked, this, &MainWindow::changerDePagemdp);
    connect(ui->envoi, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
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
    connect(ui->boutonstatstock, &QPushButton::clicked, this, &MainWindow::changerDePagestatstock);
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
    delete ui;
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

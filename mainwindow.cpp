#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    ui->tabemp->setModel(employe.afficher());
    ui->modifier->setVisible(false);
    ui->supprimer->setVisible(false);

    ui->mdp->setEchoMode(QLineEdit::Password);





    connect(ui->rechercher, &QPushButton::clicked, this, &MainWindow::on_rechercher_clicked);
    connect(ui->recherche, &QLineEdit::textChanged, this, &MainWindow::onRechercheTextChanged);



    connect(ui->valider, &QPushButton::clicked, this, &MainWindow::on_ajouterButton_clicked);
    connect(ui->modifier, &QPushButton::clicked, this, &MainWindow::on_modifier_clicked);
    connect(ui->supprimer, &QPushButton::clicked, this, &MainWindow::on_supprimerButton_clicked);



    connect(ui->seconnecter1, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
    connect(ui->sinscrire, &QPushButton::clicked, this, &MainWindow::changerDePageconnexion);
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


    connect(ui->boutoncalmaint, &QPushButton::clicked, this, &MainWindow::changerDePagecalmaint);
    connect(ui->boutonstat, &QPushButton::clicked, this, &MainWindow::changerDePagestatistique);
    connect(ui->boutonstatclient, &QPushButton::clicked, this, &MainWindow::changerDePagestatclient);
    connect(ui->boutonhisclient, &QPushButton::clicked, this, &MainWindow::changerDePagehisclient);
    connect(ui->boutonstatstock, &QPushButton::clicked, this, &MainWindow::changerDePagestatstock);
    connect(ui->seconnecter2, &QPushButton::clicked, this, &MainWindow::changerDePageclient);
    connect(ui->boutonstatres, &QPushButton::clicked, this, &MainWindow::changerDePagestatres);
    connect(ui->boutonstatcal, &QPushButton::clicked, this, &MainWindow::changerDePagestatistique);
    connect(ui->boutoncalcul, &QPushButton::clicked, this, &MainWindow::changerDePagecalcul);
    connect(ui->boutoncalstat, &QPushButton::clicked, this, &MainWindow::changerDePagecalcul);
    connect(ui->acceuilstat, &QPushButton::clicked, this, &MainWindow::changerDePageemploye);
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
void MainWindow::changerDePagehisclient()
{

    ui->stackedWidget->setCurrentIndex(14);
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
}

void MainWindow::on_supprimerButton_clicked() {
    int id = ui->recherche->text().toInt();

    if(employe.supprimer(id)) {
        ui->tabemp->setModel(employe.afficher());

        QMessageBox::information(this, "Suppression réussie", "L'employé a été supprimé avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "La suppression de l'employé a échoué.");
    }
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






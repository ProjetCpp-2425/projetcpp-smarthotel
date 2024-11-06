#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Client.h"
#include <QMessageBox>
#include <QSqlTableModel>
#include <QRegularExpression>
#include <QSqlQuery>
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
}


void MainWindow::on_accueilbutton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::changerDePagehistorique()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_accueilbutton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_valider_clicked()
{
    int ID_client = ui->lineEdit_id->text().toInt();
    if (ID_client == 0 && ui->lineEdit_id->text() != "0")
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
    int id = ui->lineEdit_chercher->text().toInt(); // Récupérer l'ID du champ de recherche
    Client client = cl.chercher(id); // Appeler la méthode de recherche

    // Vérifier si le client a été trouvé
   // if (client.getID_client() != 0)
    //{ // Supposons que 0 n'est pas un ID valide
        // Remplir les QLineEdit et autres widgets avec les attributs du client
        ui->lineEdit_id->setText(QString::number(client.getID_client()));
        ui->lineEdit_nom->setText(client.getnom());
        ui->lineEdit_prenom->setText(client.getprenom());
        ui->dateEdit->setDate(client.getdate_naissance());
        ui->comboBox_dmd->setCurrentText(client.getdemande_special());
        ui->comboBox_statut->setCurrentText(client.getstatut());
        ui->lineEdit_pays->setText(client.getpays());
        ui->lineEdit_telephone->setText(QString::number(client.gettelephone()));
        ui->lineEdit_total->setText(QString::number(client.gettotal_points()));
   // } else
   // {
        //QMessageBox::warning(this, "Non trouvé", "Client non trouvé avec cet ID.");
    //}
}






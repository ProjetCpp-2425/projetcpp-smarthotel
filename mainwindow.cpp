#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservation.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab->setModel(reservation.afficher());
    searchLineEdit = ui->id_12;
    idReservationLineEdit = ui->id_9;
    dateReservationDateEdit = ui->dateR;
    dateArriveDateEdit = ui->dateEdit_13;
    dateDepartDateEdit = ui->dateEdit_13;
    typeChambreComboBox = ui->type;
    statutReservationComboBox = ui->statut;
    modePaiementComboBox = ui->mode;
    montantLineEdit = ui->id_11;


    validerButton = ui->valid;
    supprimerButton = ui->supprimer_5;
    modifierButton = ui->modifier_5;


    connect(validerButton, &QPushButton::clicked, this, &MainWindow::on_validerButton_clicked);
    connect(supprimerButton, &QPushButton::clicked, this, &MainWindow::on_supprimerButton_clicked);
    connect(modifierButton, &QPushButton::clicked, this, &MainWindow::on_modifierButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_validerButton_clicked()
{

    int idReservation = idReservationLineEdit->text().toInt();
    QDate dateReservation = dateReservationDateEdit->date();
    QDate dateArrive = dateArriveDateEdit->date();
    QDate dateDepart = dateDepartDateEdit->date();
    QString typeChambre = typeChambreComboBox->currentText();
    QString statutReservation = statutReservationComboBox->currentText();
    QString modePaiement = modePaiementComboBox->currentText();
    float montant = montantLineEdit->text().toFloat();


    Reservation reservation(idReservation, dateReservation, dateArrive, dateDepart,
                            typeChambre, statutReservation, modePaiement, montant);


    if (reservation.ajouter()) {
        ui->tab->setModel(reservation.afficher());
        QMessageBox::information(this, "Ajout réussi", "La réservation a été ajoutée avec succès.");

    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout de la réservation.");
    }
}

void MainWindow::on_supprimerButton_clicked()
{
    int idReservation = searchLineEdit->text().toInt();


    if (idReservation == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID de réservation valide.");
        return;
    }


    Reservation reservation;
    if (reservation.supprimer(idReservation)) {
        ui->tab->setModel(reservation.afficher());
        QMessageBox::information(this, "Suppression réussie", "La réservation a été supprimée avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression de la réservation. Vérifiez l'ID.");
    }
}

void MainWindow::on_modifierButton_clicked()
{

    int idReservation = idReservationLineEdit->text().toInt();
    QDate dateReservation = dateReservationDateEdit->date();
    QDate dateArrive = dateArriveDateEdit->date();
    QDate dateDepart = dateDepartDateEdit->date();
    QString typeChambre = typeChambreComboBox->currentText();
    QString statutReservation = statutReservationComboBox->currentText();
    QString modePaiement = modePaiementComboBox->currentText();
    float montant = montantLineEdit->text().toFloat();


    Reservation reservation(idReservation, dateReservation, dateArrive, dateDepart,
                            typeChambre, statutReservation, modePaiement, montant);


    if (reservation.modifier(idReservation, dateReservation, dateArrive, dateDepart,
                             typeChambre, statutReservation, modePaiement, montant)) {
        ui->tab->setModel(reservation.afficher());
        QMessageBox::information(this, "Modification réussie", "La réservation a été modifiée avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la modification de la réservation.");
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
void MainWindow::afficher() {

    Reservation reservation;


    QSqlQueryModel *model = reservation.afficher();


    if (model) {

        ui->tab->setModel(model);
    } else {
        qDebug() << "Erreur : Le modèle de données n'a pas pu être créé.";
    }
}

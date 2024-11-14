#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservation.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QVector>
#include <QString>
#include <QStandardPaths>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include "pdf.h"


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
    exporterPdf=ui->pdf_16;


    connect(validerButton, &QPushButton::clicked, this, &MainWindow::on_validerButton_clicked);
    connect(supprimerButton, &QPushButton::clicked, this, &MainWindow::on_supprimerButton_clicked);
    connect(modifierButton, &QPushButton::clicked, this, &MainWindow::on_modifierButton_clicked);
    connect(exporterPdf, &QPushButton::clicked, this, &MainWindow::on_exporter_clicked);
    connect(ui->comboBox_5, SIGNAL(currentIndexChanged(int)), this, SLOT(on_triComboBox_currentIndexChanged(int)));
   // connect(ui->boutonstatres, &QPushButton::clicked, this, &MainWindow::afficherStatistiquesTypeChambre);


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
        reservations.append(reservation);  // Ajout au vecteur de réservations
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
void MainWindow::on_exporter_clicked() {

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
        orderBy = "DATE_ARRIVEE";
    }


    QSqlQueryModel *model = reservation.trierPar(orderBy);
    if (model) {
        ui->tab->setModel(model);
    } else {
        qDebug() << "Erreur : Le tri n'a pas pu être appliqué.";
    }
}
//void MainWindow::afficherStatistiquesTypeChambre() {
  //  QtCharts::QPieSeries *series = new QtCharts::QPieSeries();

    // Exemples de données. Remplace par des données de ta base de données.
   // int simpleCount = 30; // Nombre de chambres simples
    //int doubleCount = 50; // Nombre de chambres doubles
    //int suiteCount = 20;  // Nombre de suites

    // Ajout des données dans le graphique
    //series->append("Simple", simpleCount);
    //series->append("Double", doubleCount);
    //series->append("Suite", suiteCount);

    // Rendre les parts interactives
    //for (auto slice : series->slices()) {
      //  slice->setLabelVisible(true);
        //slice->setExploded();
    //}

    // Création du graphique
    //QtCharts::QChart *chart = new QtCharts::QChart();
    //chart->addSeries(series);
    //chart->setTitle("Répartition des Types de Chambres");

    // Affichage dans un QChartView
    //QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    //chartView->setRenderHint(QPainter::Antialiasing);

    // Ajouter le graphique à l'interface (par exemple, dans un layout)
    //ui->->addWidget(chartView); // Assure-toi que tu as un layout nommé 'layoutStatistiques' dans ton fichier .ui
//}

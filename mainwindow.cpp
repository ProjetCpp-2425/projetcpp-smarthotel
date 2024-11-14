
#include "mainwindow.h"
#include "qsqlerror.h"
#include "ui_mainwindow.h"
#include "QSqlQueryModel"
#include "QTableView"
#include "maintenance.h"
#include "qmessagebox.h"
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QFileInfo>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(Mtmp.afficher());
    // Connexion du signal du QComboBox pour appliquer le tri
    connect(ui->comboBox_34, SIGNAL(currentTextChanged(QString)), this, SLOT(onComboBoxPriorityChanged(QString)));
    this->setStyleSheet("QLineEdit { color : white; }");
    connect(ui->pushButton_43,SIGNAL(clicked()), this, SLOT(on_pushButton_43_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_39_clicked(){
    int ID_MAINTENANCE = ui->lineEdit_85->text().toInt();
    int NUM_CHAMBRE_CONCERNEE = ui->lineEdit_86->text().toInt();
    QString TYPE_MAINTENANCE = ui->comboBox_40->currentText();
    QDate DATE_DEBUT = ui->dateEdit_12->date();
    QDate DATE_FIN = ui->dateEdit_11->date();
    QString ETAT_MAINTENANCE = ui->comboBox_36->currentText();
    QString PRIORITE = ui->comboBox_41->currentText();

    if ( NUM_CHAMBRE_CONCERNEE== 0 || TYPE_MAINTENANCE.isEmpty() || ETAT_MAINTENANCE .isEmpty()) {
        QMessageBox::warning(this, tr("Champs manquants"), tr("Veuillez remplir tous les champs."));
        return;
    }

   Mtmp= Maintenance (ID_MAINTENANCE, NUM_CHAMBRE_CONCERNEE, TYPE_MAINTENANCE, DATE_DEBUT,  DATE_FIN, ETAT_MAINTENANCE,PRIORITE);
    bool test = Mtmp.ajouter();

    if (test) {
        loadMaintenanceData();  // Refresh table view with updated data
        QMessageBox::information(this, tr("OK"), tr("Ajout effectué\nCliquez sur Annuler pour quitter."));
    } else {
        QMessageBox::critical(this, tr("Not OK"), tr("L'ajout a échoué\nCliquez sur Annuler pour quitter."));
    }
}



void MainWindow::on_pushButton_38_clicked()
{
    int id_maintenance = ui->lineEdit_85->text().toInt();
    bool test = Mtmp.supprimer(id_maintenance);

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Suppression effectuée\n"
                                             "Cliquez sur Annuler pour quitter."),
                                 QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectuée\n"
                                          "Cliquez sur Annuler pour quitter."),
                              QMessageBox::Cancel);
    }
}


void MainWindow::loadMaintenanceData()
{
    QSqlQueryModel *model = Mtmp.afficher();  // Reload the model with afficher()

    if (!model->query().isActive()) {
        qDebug() << "Failed to load data:" << model->query().lastError();
    } else {
        qDebug() << "Data loaded successfully in loadMaintenanceData";
    }

    ui->tableView_2->setModel(model);
    ui->tableView_2->resizeColumnsToContents();  // Adjust column width to fit contents
}

void MainWindow::on_pushButton_2_clicked() {
    int ID_MAINTENANCE = ui->lineEdit_85->text().toInt();
    int NUM_CHAMBRE_CONCERNEE = ui->lineEdit_86->text().toInt();
    QString TYPE_MAINTENANCE = ui->comboBox_40->currentText();
    QDate DATE_DEBUT = ui->dateEdit_12->date();
    QDate DATE_FIN = ui->dateEdit_11 ->date();
    QString ETAT_MAINTENANCE = ui->comboBox_36->currentText();
    QString PRIORITE = ui->comboBox_41->currentText();

    if ( NUM_CHAMBRE_CONCERNEE== 0 || TYPE_MAINTENANCE.isEmpty() || ETAT_MAINTENANCE .isEmpty() || PRIORITE .isEmpty()) {
        QMessageBox::warning(this, tr("Champs manquants"), tr("Veuillez remplir tous les champs."));
        return;
    }

    Mtmp= Maintenance (ID_MAINTENANCE, NUM_CHAMBRE_CONCERNEE, TYPE_MAINTENANCE, DATE_DEBUT,  DATE_FIN, ETAT_MAINTENANCE,PRIORITE);
    bool test = Mtmp.modifier();

    if (test) {
        loadMaintenanceData();
        QMessageBox::information(this, tr("Modification effectuée"), tr("Maintenance modifiée avec succès."));
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Échec de la modification."));
    }
}

void MainWindow::on_comboBox_34_currentTextChanged(const QString &priorite)
{
    // Vérifier si l'utilisateur a sélectionné une priorité
    if (priorite.isEmpty()) {
        QMessageBox::warning(this, tr("Erreur de sélection"), tr("Veuillez sélectionner une priorité valide."));
        return;
    }

    // Appeler la fonction pour trier les maintenances par priorité
    QSqlQueryModel *model = Mtmp.trierParPriorite(priorite);

    // Vérifier si la recherche a trouvé des résultats
    if (model->rowCount() > 0) {
        ui->tableView_2->setModel(model);  // Afficher les résultats dans le QTableView
        ui->tableView_2->resizeColumnsToContents();  // Ajuster les colonnes à la taille des données
        QMessageBox::information(this, tr("Tri"), tr("Maintenance triée par priorité."));
    } else {
        QMessageBox::warning(this, tr("Non trouvé"), tr("Aucune maintenance trouvée pour cette priorité."));
    }

}
void MainWindow::on_pushButton_40_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export PDF"), QString(), "*.pdf");
    if (!fileName.isEmpty()) {
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QString html = "<h1>Maintenance List</h1><table border='1'><tr><th>ID_MAINTENANCE</th><th>NUM_CHAMBRE_CONCERNEE</th><th>TYPE_MAINTENANCE</th><th>DATE_DEBUT</th><th>DATE_FIN</th><th>ETAT_MAINTENANCE</th><th>PRIORITE</th></tr>";

        QSqlQuery query("SELECT ID_MAINTENANCE, NUM_CHAMBRE_CONCERNEE, TYPE_MAINTENANCE, DATE_DEBUT, DATE_FIN, ETAT_MAINTENANCE, PRIORITE FROM MAINTENANCES");
        while (query.next()) {
           //String dateDebut = query.value("DATE_DEBUT").toDate().toString("yyyy-MM-dd");
           //String dateFin = query.value("DATE_FIN").toDate().toString("yyyy-MM-dd");
             html += "<tr><td>" + query.value("ID_MAINTENANCE").toString() + "</td>";
            html += "<td>" + query.value("NUM_CHAMBRE_CONCERNEE").toString() + "</td>";
            html += "<td>" + query.value("TYPE_MAINTENANCE").toString() + "</td>";
            html += "<td>" + query.value("DATE_DEBUT").toString() + "</td>";
            html += "<td>" + query.value("DATE_FIN").toString() + "</td>";
            html += "<td>" + query.value("ETAT_MAINTENANCE").toString() + "</td>";
            html += "<td>" + query.value("PRIORITE").toString() + "</td></tr>";
        }
        html += "</table>";
        doc.setHtml(html);
        doc.print(&printer);

        QMessageBox::information(this, "Export PDF", "MAINTENANCE exported to PDF successfully!");
    }
}
void MainWindow::on_pushButton_43_clicked()
{
    // Récupérer l'ID de maintenance saisi par l'utilisateur
    int ID_MAINTENANCE= ui->lineEdit_87->text().toInt();

    // Vérifier si l'ID est valide (non nul)
    if (ID_MAINTENANCE == 0) {
        QMessageBox::warning(this, tr("ID Invalide"), tr("Veuillez entrer un ID valide."));
        return;
    }

    // Appeler la fonction pour rechercher la maintenance par ID
    QSqlQueryModel *model = Mtmp.rechercherParID(ID_MAINTENANCE);

    // Vérifier si la recherche a trouvé des résultats
    if (model->rowCount() > 0) {
        ui->tableView_2->setModel(model); // Afficher les résultats dans le QTableView
        ui->tableView_2->resizeColumnsToContents();  // Ajuster les colonnes à la taille des données
        QMessageBox::information(this, tr("Recherche"), tr("Maintenance trouvée."));
    } else {
        QMessageBox::warning(this, tr("Non trouvé"), tr("Aucune maintenance trouvée pour cet ID."));
    }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include "produit.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_21_clicked() {
    afficherProduitsDansTable();
}

void MainWindow::afficherProduitsDansTable() {
    Produit produit(0, "", 0, QDate::currentDate(), QDate::currentDate());
    QSqlQueryModel* model = produit.afficher();

    ui->tableWidget_2->setRowCount(model->rowCount());
    ui->tableWidget_2->setColumnCount(model->columnCount());

    // Définir les en-têtes des colonnes, si besoin
    ui->tableWidget_2->setHorizontalHeaderLabels({"ID", "Nom du Produit", "Quantité", "Date de Livraison", "Date de Réapprovisionnement"});

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QString data = model->index(row, col).data().toString();
            ui->tableWidget_2->setItem(row, col, new QTableWidgetItem(data));
        }
    }
}
void MainWindow::on_pushButton_23_clicked()
{
    // Get input values from UI
    int id = ui->lineEdit->text().toInt();
    QString nomProduit = ui->lineEdit_2->text();
    int quantiteDispo = ui->lineEdit_3->text().toInt();
    QDate dateLivraison = ui->dateEdit->date();
    QDate dateReapprovisionnement = ui->dateEdit_2->date();

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
        } else {
            QMessageBox::warning(this, "Update Product", "Failed to update product.");
        }
    } else {
        // Add the new product
        if (produit.ajouter()) {
            QMessageBox::information(this, "Add Product", "Product added successfully.");
        } else {
            QMessageBox::warning(this, "Add Product", "Failed to add product.");
        }
    }

    // Optionally, refresh the product display after adding/updating
    // Assuming you have a method to update the view, e.g., displayProducts()
    // displayProducts();
}

void MainWindow::on_pushButton_24_clicked() {
    // Lire l'ID à supprimer depuis le QLineEdit (assurez-vous de nommer votre QLineEdit comme `lineEdit_id`)
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
// Implementation des slots
void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::information(this, "Information", "Succès");
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_pushButton_25_clicked()
{
    QMessageBox::information(this, "Information", "La SESSION EST EXPIREE");
}

void MainWindow::on_pushButton_26_clicked()
{
    QMessageBox::information(this, "Information", "l'Alerte est envoyée");
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    // Code de dessin ici
    Q_UNUSED(event); // Pour éviter l'avertissement sur le paramètre inutilisé
}

void MainWindow::on_stackedWidget_currentChanged(int arg1)
{

}


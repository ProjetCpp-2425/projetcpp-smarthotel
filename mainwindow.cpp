#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include "produit.h"
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QDebug>
#include <QFile>
#include <QMessageBox>


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
    Q_UNUSED(arg1);
}




void MainWindow::on_pushButton_22_clicked() {
    try {
        // Étape 1 : Choisir le chemin du fichier
        QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le fichier HTML", QDir::homePath(), "Documents (*.html)");

        // Vérifier si l'utilisateur a annulé l'opération
        if (filePath.isEmpty()) {
            QMessageBox::warning(this, "Exportation annulée", "Aucun fichier sélectionné.");
            return;
        }

        // Forcer l'ajout de l'extension .html si elle est manquante
        if (!filePath.endsWith(".html", Qt::CaseInsensitive)) {
            filePath += ".html";
        }

        qDebug() << "Chemin sélectionné pour le fichier HTML:" << filePath;

        // Vérifier l'initialisation de tableWidget_2
        if (!ui->tableWidget_2) {
            QMessageBox::critical(this, "Erreur", "Tableau non initialisé.");
            return;
        }

        // Étape 2 : Préparer le contenu HTML
        QString html = "<html><head><meta charset='utf-8'><title>Liste des Produits</title></head><body>";
        html += "<h2 style='text-align: center;'>Liste des Produits</h2>";
        html += "<table border='1' cellspacing='0' cellpadding='4' style='width: 100%; text-align: center;'>";
        html += "<tr>";

        // Ajouter les en-têtes
        for (int col = 0; col < ui->tableWidget_2->columnCount(); ++col) {
            QTableWidgetItem* headerItem = ui->tableWidget_2->horizontalHeaderItem(col);
            if (!headerItem) {
                qDebug() << "En-tête vide pour la colonne" << col;
                html += "<th></th>";
            } else {
                html += "<th>" + headerItem->text() + "</th>";
            }
        }
        html += "</tr>";

        // Ajouter les lignes de données
        for (int row = 0; row < ui->tableWidget_2->rowCount(); ++row) {
            html += "<tr>";
            for (int col = 0; col < ui->tableWidget_2->columnCount(); ++col) {
                QTableWidgetItem *item = ui->tableWidget_2->item(row, col);
                html += "<td>" + (item ? item->text() : "") + "</td>";
            }
            html += "</tr>";
        }
        html += "</table></body></html>";

        // Étape 3 : Écrire dans le fichier HTML
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::critical(this, "Erreur d'accès", "Impossible d'écrire dans le fichier sélectionné : " + file.errorString());
            return;
        }

        QTextStream out(&file);
        out << html;
        file.close();

        // Étape 4 : Vérification si le fichier a bien été créé
        if (QFile::exists(filePath)) {
            QMessageBox::information(this, "Exportation réussie", "Le fichier HTML a été enregistré avec succès :\n" + filePath);
        } else {
            QMessageBox::critical(this, "Erreur", "Le fichier HTML n'a pas été créé.");
        }

    } catch (std::exception& e) {
        QMessageBox::critical(this, "Exception", "Une erreur inattendue est survenue : " + QString::fromStdString(e.what()));
    } catch (...) {
        QMessageBox::critical(this, "Erreur inconnue", "Une erreur inconnue est survenue.");
    }
}

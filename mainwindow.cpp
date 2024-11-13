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
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QTableWidgetItem>
#include <QTextDocument>


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

        // Vérifier l'initialisation de tableWidget_2
        if (!ui->tableWidget_2) {
            QMessageBox::critical(this, "Erreur", "Tableau non initialisé.");
            return;
        }

        // Étape 2 : Créer un objet QPrinter
        QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filePath);

        // Créer un QPainter pour dessiner sur le PDF
        QPainter painter;
        if (!painter.begin(&printer)) {
            QMessageBox::critical(this, "Erreur d'accès", "Impossible de commencer l'écriture dans le fichier PDF.");
            return;
        }

        // Étape 3 : Dessiner le contenu du tableau sur le PDF
        const int tableMargin = 10;        // Marge autour du tableau
        const int rowHeight = 1000;         // Hauteur des lignes
        const int colWidth = 2000;         // Largeur des colonnes
        const int titleSpacing = 2000;      // Espace après le titre
        const int lineThickness = 10;      // Épaisseur des lignes

        int currentY = tableMargin;

        // Dessiner le titre
        painter.setFont(QFont("Arial", 16, QFont::Bold));  // Titre plus grand
        painter.drawText(0, currentY, "Liste des Produits");
        currentY += titleSpacing;  // Espace après le titre

        // Dessiner les en-têtes du tableau
        painter.setFont(QFont("Arial", 12, QFont::Bold));  // En-têtes plus grands
        int currentX = tableMargin;

        // Dessiner les lignes des en-têtes
        for (int col = 0; col < ui->tableWidget_2->columnCount(); ++col) {
            QTableWidgetItem* headerItem = ui->tableWidget_2->horizontalHeaderItem(col);
            if (!headerItem) {
                qDebug() << "En-tête vide pour la colonne" << col;
                painter.drawText(currentX, currentY, "");  // Dessiner une cellule vide pour les en-têtes manquants
            } else {
                painter.drawText(currentX, currentY, headerItem->text());
            }
            currentX += colWidth;
        }
        currentY += rowHeight;  // Espacement après les en-têtes

        // Dessiner les lignes séparatrices entre les en-têtes et les données
        currentX = tableMargin;
        for (int col = 0; col < ui->tableWidget_2->columnCount(); ++col) {
            painter.drawLine(currentX, currentY, currentX, currentY + rowHeight);  // Lignes verticales
            currentX += colWidth;
        }
        painter.drawLine(tableMargin, currentY, currentX, currentY); // Ligne horizontale sous les en-têtes
        currentY += lineThickness;  // Espacement sous les lignes

        // Dessiner les données du tableau
        painter.setFont(QFont("Arial", 12));  // Données plus grandes
        for (int row = 0; row < ui->tableWidget_2->rowCount(); ++row) {
            currentX = tableMargin;
            for (int col = 0; col < ui->tableWidget_2->columnCount(); ++col) {
                QTableWidgetItem *item = ui->tableWidget_2->item(row, col);
                painter.drawText(currentX, currentY, item ? item->text() : "");
                currentX += colWidth;

                // Dessiner les lignes verticales après chaque colonne
                painter.drawLine(currentX, currentY - rowHeight, currentX, currentY);
            }

            // Dessiner une ligne horizontale après chaque ligne de données
            painter.drawLine(tableMargin, currentY, currentX, currentY);

            currentY += rowHeight;  // Passer à la ligne suivante
        }

        // Dessiner une ligne en bas de la table
        currentX = tableMargin;
        for (int col = 0; col < ui->tableWidget_2->columnCount(); ++col) {
            currentX += colWidth;
        }
        painter.drawLine(tableMargin, currentY, currentX, currentY);  // Ligne horizontale en bas de la table

        // Terminer l'écriture du fichier PDF
        painter.end();

        // Étape 4 : Vérification si le fichier a bien été créé
        if (QFile::exists(filePath)) {
            QMessageBox::information(this, "Exportation réussie", "Le fichier PDF a été enregistré avec succès :\n" + filePath);
        } else {
            QMessageBox::critical(this, "Erreur", "Le fichier PDF n'a pas été créé.");
        }

    } catch (std::exception& e) {
        QMessageBox::critical(this, "Exception", "Une erreur inattendue est survenue : " + QString::fromStdString(e.what()));
    } catch (...) {
        QMessageBox::critical(this, "Erreur inconnue", "Une erreur inconnue est survenue.");
    }
}

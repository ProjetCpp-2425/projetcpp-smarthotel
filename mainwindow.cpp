#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include "produit.h"
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QFile>
#include <QTableWidgetItem>
// stat
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <stdexcept>
//tri
#include <QSqlQueryModel>
#include <QSqlError>

// Constructeur
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tri(new QSqlQueryModel())  // Initialisation ici
{
    ui->setupUi(this);

    // Connexion du signal du comboBox pour le tri
    connect(ui->sortComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(on_sortComboBox_currentIndexChanged(int)));
}

// Destructeur
MainWindow::~MainWindow()
{
    delete ui;  // Libère l'interface utilisateur
    delete tri; // Libère le modèle SQL trié
}

// Le slot pour gérer le changement de tri dans le comboBox

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


//pdf

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

        // Créer un QPageLayout pour définir l'orientation en paysage
        QPageLayout pageLayout(QPageSize::A4, QPageLayout::Landscape, QMarginsF(0, 0, 0, 0));
        printer.setPageLayout(pageLayout);

        // Créer un QPainter pour dessiner sur le PDF
        QPainter painter;
        if (!painter.begin(&printer)) {
            QMessageBox::critical(this, "Erreur d'accès", "Impossible de commencer l'écriture dans le fichier PDF.");
            return;
        }

        // Étape 3 : Dessiner le contenu du tableau sur le PDF
        const int tableMargin = 20;        // Marge autour du tableau
        const int rowHeight = 500;         // Hauteur des lignes
        const int colWidth = 2500;         // Largeur des colonnes
        const int titleSpacing = 1500;      // Espace après le titre
        const int lineThickness = 1;      // Épaisseur des lignes

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
//stat



void MainWindow::on_pushButton_27_clicked()
{
    try {
        // 1. Vérification des en-têtes de colonne
        qDebug() << "Vérification des en-têtes de colonne...";
        for (int i = 0; i < ui->tableWidget_2->columnCount(); ++i) {
            QString columnName = ui->tableWidget_2->horizontalHeaderItem(i)->text();
            qDebug() << "Nom de la colonne " << i << ":" << columnName;
        }

        // 2. Créer une série pour le graphique en camembert
        qDebug() << "Création de la série QPieSeries...";
        QPieSeries *series = new QPieSeries();
        if (!series) {
            throw std::runtime_error("Erreur lors de la création de la série.");
        }

        // 3. Vérification du nombre de lignes dans le tableau
        int rowCount = ui->tableWidget_2->rowCount();
        qDebug() << "Nombre de lignes dans le tableau:" << rowCount;

        bool dataFound = false; // Indicateur pour vérifier si des données valides ont été trouvées

        // 4. Vérification des indices des colonnes "Nom de produit" et "Quantité disponible"
        int productNameCol = -1;
        int quantityCol = -1;

        qDebug() << "Recherche des colonnes 'Nom de produit' et 'Quantité disponible'...";
        for (int i = 0; i < ui->tableWidget_2->columnCount(); ++i) {
            QString columnName = ui->tableWidget_2->horizontalHeaderItem(i)->text();
            qDebug() << "Colonne" << i << ":" << columnName;
            if (columnName == "Nom de produit") {
                productNameCol = i;
            }
            if (columnName == "Quantité disponible") {
                quantityCol = i;
            }
        }

        // Si l'une des colonnes n'est pas trouvée, afficher un message d'erreur et arrêter la fonction
        if (productNameCol == -1 || quantityCol == -1) {
            throw std::runtime_error("Les colonnes 'Nom de produit' ou 'Quantité disponible' n'ont pas été trouvées.");
        }

        // 5. Parcourir les lignes pour extraire les données
        for (int i = 0; i < rowCount; ++i) {
            QTableWidgetItem *productItem = ui->tableWidget_2->item(i, productNameCol);
            QTableWidgetItem *quantityItem = ui->tableWidget_2->item(i, quantityCol);

            // Vérifier si les éléments sont valides
            if (!productItem || !quantityItem) {
                qDebug() << "Données manquantes à la ligne" << i;
                continue; // Ignorer cette ligne si les données sont manquantes
            }

            QString productName = productItem->text();
            QString quantityText = quantityItem->text();

            // 6. Convertir la quantité en entier
            bool ok;
            int quantity = quantityText.toInt(&ok);
            qDebug() << "Nom du produit:" << productName << ", Quantité text:" << quantityText;

            if (!ok) {
                qDebug() << "Erreur de conversion à la ligne" << i;
                continue; // Ignorer cette ligne si la conversion échoue
            }

            // Si la quantité est positive, ajouter à la série
            if (quantity > 0) {
                series->append(productName, quantity);
                dataFound = true;
            }
        }

        // Si aucune donnée valide n'a été trouvée, afficher un message d'avertissement
        if (!dataFound) {
            qDebug() << "Aucune donnée valide trouvée.";
            QMessageBox::warning(this, "Attention", "Aucune donnée valide trouvée pour le graphique.");
            return;
        }

        // 7. Créer le graphique
        qDebug() << "Création du graphique...";
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Répartition des quantités");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        // 8. Créer une vue pour le graphique
        qDebug() << "Création de la vue du graphique...";
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        // 9. Afficher le graphique dans une nouvelle fenêtre
        qDebug() << "Affichage du graphique...";
        QMainWindow *chartWindow = new QMainWindow();
        chartWindow->setCentralWidget(chartView);
        chartWindow->resize(600, 400);
        chartWindow->show();

    } catch (const std::exception &e) {
        // Afficher l'exception si une erreur se produit
        qDebug() << "Erreur capturée : " << e.what();
        QMessageBox::critical(this, "Erreur", e.what());
    }
}



// Définition du slot on_pushButton_28_clicked()
void MainWindow::on_pushButton_28_clicked()
{
    // Récupérer l'ID de produit depuis le QLineEdit
    QString searchID = ui->lineEdit_7->text();  // lineEdit_7 contient l'ID du produit

    // Vérifier si l'ID est vide
    if (searchID.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID de produit.");
        return;
    }

    // Appeler la méthode Rechercher avec l'ID de produit
    Rechercher(searchID);
}

// Définition de la fonction Rechercher
void MainWindow::Rechercher(const QString &searchID)
{
    int rowCount = ui->tableWidget_2->rowCount();
    bool productFound = false;  // Indicateur pour vérifier si le produit a été trouvé

    // Parcourir chaque ligne du tableau pour chercher l'ID du produit
    for (int i = 0; i < rowCount; ++i) {
        QTableWidgetItem *idItem = ui->tableWidget_2->item(i, 0);  // Supposons que l'ID du produit est dans la 1ère colonne (index 0)

        // Vérifier si l'élément d'ID est valide et correspond à l'ID recherché
        if (idItem && idItem->text() == searchID) {
            productFound = true;

            // Sélectionner la ligne correspondante
            ui->tableWidget_2->selectRow(i);

            // Afficher les détails du produit trouvé
            QString productName = ui->tableWidget_2->item(i, 1)->text();  // Nom du produit dans la 2ème colonne (index 1)
            QString quantity = ui->tableWidget_2->item(i, 2)->text();  // Quantité dans la 3ème colonne (index 2)
            QString deliveryDate = ui->tableWidget_2->item(i, 3)->text();  // Date de livraison dans la 4ème colonne (index 3)
            QString restockDate = ui->tableWidget_2->item(i, 4)->text();  // Date de réapprovisionnement dans la 5ème colonne (index 4)

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
void MainWindow::on_sortComboBox_currentIndexChanged(int index)
{
    QString queryStr;

    // Déterminer si l'ordre de tri est ascendant ou descendant
    bool isAscendant = (index == 0);  // 0 : Ascendant, 1 : Descendant

    // Créer la requête SQL selon l'option choisie
    if (isAscendant) {
        // Tri Ascendant par Quantité disponible
        queryStr = "SELECT ID_PRODUIT, NOM_PRODUIT, QUANTITE_DISPONIBLE, DATE_LIVRAISON, DATE_REAPPROVISIONNEMENT "
                   "FROM PRODUITS ORDER BY QUANTITE_DISPONIBLE ASC";
    } else {
        // Tri Descendant par Quantité disponible
        queryStr = "SELECT ID_PRODUIT, NOM_PRODUIT, QUANTITE_DISPONIBLE, DATE_LIVRAISON, DATE_REAPPROVISIONNEMENT "
                   "FROM PRODUITS ORDER BY QUANTITE_DISPONIBLE DESC";
    }

    // Log de la requête SQL pour vérification
    qDebug() << "Requête SQL : " << queryStr;

    // Exécuter la requête sur le modèle
    tri->setQuery(queryStr);

    // Vérifier si une erreur est survenue lors de l'exécution de la requête
    if (tri->lastError().isValid()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << tri->lastError().text();
        return;
    }

    // Si aucun résultat n'est retourné
    if (tri->rowCount() == 0) {
        qDebug() << "Aucun résultat trouvé";
        return;
    }

    // Mettre à jour le nombre de lignes et de colonnes dans le QTableWidget
    ui->tableWidget_2->setRowCount(tri->rowCount());  // Met à jour le nombre de lignes
    ui->tableWidget_2->setColumnCount(tri->columnCount());  // Met à jour le nombre de colonnes

    // Définir les en-têtes de colonnes pour le tableau
    ui->tableWidget_2->setHorizontalHeaderLabels({"ID Produit", "Nom de produit", "Quantité disponible", "Date de livraison", "Date de réapprovisionnement"});

    // Remplir le QTableWidget avec les données
    for (int row = 0; row < tri->rowCount(); ++row) {
        for (int col = 0; col < tri->columnCount(); ++col) {
            QString data = tri->index(row, col).data().toString();
            qDebug() << "Ligne " << row << " Col " << col << ": " << data;  // Afficher chaque donnée pour débogage
            ui->tableWidget_2->setItem(row, col, new QTableWidgetItem(data));  // Met à jour la cellule du tableau
        }
    }

    // Forcer la mise à jour de l'affichage
    ui->tableWidget_2->repaint();
}

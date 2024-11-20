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
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>

// Constructeur
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tri(new QSqlQueryModel())  // Initialisation ici
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    // Connexion du signal du comboBox pour le tri
    connect(ui->sortComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_sortComboBox_currentIndexChanged(int)));

}

// Destructeur
MainWindow::~MainWindow()
{
    delete ui;  // Libère l'interface utilisateur
    delete tri; // Libère le modèle SQL trié
}

// Le slot pour gérer le changement de tri dans le comboBox
void MainWindow::on_sortComboBox_currentIndexChanged() {
    afficherProduitsDansTable(); // Refresh table when sorting changes
}

void MainWindow::on_pushButton_21_clicked() {
    afficherProduitsDansTable();
}
void MainWindow::afficherProduitsDansTable() {
    // Determine sort order from sortComboBox
    int sortIndex = ui->sortComboBox->currentIndex();
    QString sortOrder = (sortIndex == 0) ? "ORDER BY quantiteDispo DESC" : "ORDER BY quantiteDispo ASC";

    // Fetch sorted data from Produit::afficher
    Produit produit(0, "", 0, QDate::currentDate(), QDate::currentDate());
    QSqlQueryModel* model = produit.afficher(sortOrder);

    // Update table widget
    ui->tableWidget_2->setRowCount(model->rowCount());
    ui->tableWidget_2->setColumnCount(model->columnCount());

    // Define headers
    ui->tableWidget_2->setHorizontalHeaderLabels({"ID", "Nom du Produit", "Quantité", "Date de Livraison", "Date de Réapprovisionnement"});

    // Track alert conditions
    bool hasCriticalAlerts = false;
    bool hasLowStockNotifications = false;
    QString criticalProducts;
    QString lowStockProducts;

    // Populate table with data and check alerts
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QString data = model->index(row, col).data().toString();
            ui->tableWidget_2->setItem(row, col, new QTableWidgetItem(data));
        }

        // Check stock quantity for alerts
        int quantity = model->index(row, 2).data().toInt(); // Assuming "Quantité" is in the 3rd column
        QString productName = model->index(row, 1).data().toString(); // Assuming "Nom du Produit" is in the 2nd column

        if (quantity == 0) {
            hasCriticalAlerts = true;
            criticalProducts += productName + "\n";
        } else if (quantity < 10) {
            hasLowStockNotifications = true;
            lowStockProducts += productName + "\n";
        }
    }

    // Display alerts
    if (hasCriticalAlerts) {
        QMessageBox::critical(this, "Alertes Critiques", "Les produits suivants sont en rupture de stock :\n" + criticalProducts);
    }
    if (hasLowStockNotifications) {
        QMessageBox::warning(this, "Stock Faible", "Les produits suivants ont un stock inférieur à 10 :\n" + lowStockProducts);
    }

    delete model; // Free memory
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
    afficherStatistiques();               // Display statistics

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
//recherche


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

//stat
void MainWindow::on_pushButton_27_clicked()
{
    // Récupérer les données de la base de données
    QSqlQuery query;
    query.prepare("SELECT nom_produit, quantite_disponible FROM ma_table");  // Adapte cette requête à ta table
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la récupération des données : " + query.lastError().text());
        return;
    }

    // Mettre à jour les données du graphique
}

void MainWindow::afficherStatistiques()
{
    QSqlQuery query;
    query.prepare("SELECT nomProduit, quantiteDispo FROM stocks");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la récupération des données : " + query.lastError().text());
        return;
    }

    QPieSeries *series = new QPieSeries(this);
    while (query.next()) {
        QString nomProduit = query.value(0).toString();
        int quantiteDispo = query.value(1).toInt();
        series->append(nomProduit, quantiteDispo);
    }

    if (series->slices().isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Aucune donnée disponible pour les statistiques.");
        delete series; // Prevent memory leak
        return;
    }

    // Customize colors
    QList<QColor> customColors = {
        QColor("#ff6f61"), // Warm red
        QColor("#6a9fb5"), // Soft blue
        QColor("#77dd77"), // Light green
        QColor("#fdfd96"), // Yellow
        QColor("#ffb347"), // Orange
        QColor("#836953"), // Brown
        QColor("#b19cd9"), // Lavender
        QColor("#ff6961"), // Pastel red
        QColor("#aec6cf"), // Pastel blue
        QColor("#f49ac2")  // Pastel pink
    };

    int colorIndex = 0;
    for (auto slice : series->slices()) {
        slice->setBrush(customColors[colorIndex % customColors.size()]);
        colorIndex++;
        slice->setLabel(QString("%1 (%2)").arg(slice->label()).arg(slice->value())); // Set slice labels
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des Produits");
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);

    QWidget *statsPage = ui->stat;
    if (!statsPage) {
        QMessageBox::critical(this, "Erreur", "Le widget 'stat' n'est pas initialisé.");
        return;
    }

    if (statsPage->layout()) {
        QLayout *oldLayout = statsPage->layout();
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    QVBoxLayout *layout = new QVBoxLayout(statsPage);
    layout->addWidget(chartView);
    statsPage->setLayout(layout);
}




#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QSqlQueryModel>  // Ajoutez ceci si vous utilisez des modèles SQL

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override; // Ajout de `override`

private slots:
    void afficherProduitsDansTable();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_23_clicked();
    void on_pushButton_25_clicked();
    void on_pushButton_26_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_24_clicked();
    void on_pushButton_22_clicked(); // Slot pour exporter en PDF
    void on_pushButton_27_clicked();

    // Ajouter d'autres slots si nécessaire
    void on_stackedWidget_currentChanged(int arg1);
    void on_pushButton_28_clicked();  // Slot pour la recherche du produit

    // Déclaration du slot pour gérer le changement d'index du QComboBox
    void on_sortComboBox_currentIndexChanged(int index);  // <- Ajoutez cette ligne ici

private:
    Ui::MainWindow *ui;

    // Déclarez la méthode Rechercher ici
    void Rechercher(const QString &searchID);  // Déclaration de la fonction Rechercher

    // Déclarez 'tri' comme membre de la classe MainWindow
    QSqlQueryModel* tri;  // Déclarez le modèle SQL ici
};

#endif // MAINWINDOW_H

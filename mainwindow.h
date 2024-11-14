#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QComboBox>
#include <QVector>
#include "reservation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_validerButton_clicked();      // Fonction pour ajouter une réservation
    void on_supprimerButton_clicked();    // Fonction pour supprimer une réservation
    void on_modifierButton_clicked();     // Fonction pour modifier une réservation
    void on_exporter_clicked();           // Fonction pour exporter les réservations en PDF
    void on_searchLineEdit_textChanged(const QString &text); // Fonction de recherche
    void afficher();
    void on_triComboBox_currentIndexChanged(int index);
    //void afficherStatistiquesTypeChambre();
        // Fonction pour afficher les réservations

private:
    Ui::MainWindow *ui;
    Reservation reservation;
    QVector<Reservation> reservations;    // Vecteur pour stocker les réservations ajoutées

    // Champs de l'interface
    QLineEdit *searchLineEdit;
    QLineEdit *idReservationLineEdit;
    QDateEdit *dateReservationDateEdit;
    QDateEdit *dateArriveDateEdit;
    QDateEdit *dateDepartDateEdit;
    QComboBox *typeChambreComboBox;
    QComboBox *statutReservationComboBox;
    QComboBox *modePaiementComboBox;
    QLineEdit *montantLineEdit;

    // Boutons
    QPushButton *validerButton;
    QPushButton *supprimerButton;
    QPushButton *modifierButton;
    QPushButton *exporterPdf;
};

#endif // MAINWINDOW_H

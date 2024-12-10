#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QComboBox>
#include <QNetworkAccessManager>
#include <QRandomGenerator>
#include <QNetworkReply>
#include <QVector>
#include "reservation.h"
#include "arduino1.h"
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
    void afficherStatistiquesTypeChambre();
    void envoyerEmail(const QString& destinataire, const QString& sujet, const QString& message);
    void on_email_clicked();
    void on_sendVerificationButton_clicked();
    bool envoyerVerificationEmail(const QString &recipient, const QString &subject, const QString &body);
    void on_verifyCodeButton_clicked();
    void onCardRead(QString uid);

        // Fonction pour afficher les réservations



private:
    Ui::MainWindow *ui;
    Reservation reservation;
    QVector<Reservation> reservations;    // Vecteur pour stocker les réservations ajoutées

    // Champs de l'interface
    QLineEdit *searchLineEdit;
    QLineEdit *idReservationLineEdit;
    QLineEdit *uidcarteline;
    QDateEdit *dateReservationDateEdit;
    QDateEdit *dateArriveDateEdit;
    QDateEdit *dateDepartDateEdit;
    QComboBox *typeChambreComboBox;
    QComboBox *statutReservationComboBox;
    QComboBox *modePaiementComboBox;
    QLineEdit *montantLineEdit;
    ArduinoManager *arduinoManager;
    QSerialPort *serial;
    QString dataBuffer;

    // Boutons
    QPushButton *validerButton;
    QPushButton *supprimerButton;
    QPushButton *modifierButton;
    QPushButton *exporterPdf;
    QNetworkAccessManager *networkManager;
    QString verificationCode;
};
#endif // MAINWINDOW_H



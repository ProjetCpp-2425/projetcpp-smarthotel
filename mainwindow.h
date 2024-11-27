#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include "client.h"
#include "reservation.h"
#include <QSqlQueryModel>
#include <QLabel>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QComboBox>
#include <QNetworkAccessManager>
#include <QRandomGenerator>
#include <QNetworkReply>
#include <QVector>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Employe employe;
     QLabel *masse;
     Client cl;
     Reservation reservation;
     QVector<Reservation> reservations;


     QLineEdit *searchLineEdit;
     QLineEdit *idReservationLineEdit;
     QDateEdit *dateReservationDateEdit;
     QDateEdit *dateArriveDateEdit;
     QDateEdit *dateDepartDateEdit;
     QComboBox *typeChambreComboBox;
     QComboBox *statutReservationComboBox;
     QComboBox *modePaiementComboBox;
     QLineEdit *montantLineEdit;


     QPushButton *validerButton;
     QPushButton *supprimerButton;
     QPushButton *modifierButton;
     QPushButton *exporterPdf;
     QNetworkAccessManager *networkManager;
     QString verificationCode;
private slots:
     void on_valider_clicked();
     void on_supprimer_clicked();
     void on_modifierclient_clicked();
     void on_chercher_clicked();
     void on_trier_clicked();
     void on_pdf_clicked();
     void afficherHistorique(QSqlQueryModel *model);

     void on_client_fidele_clicked();

     void on_chercher_2_clicked();


     void on_retour_clicked();
     void calculerPointsEtDuree(QStandardItemModel* sqlModel);

 private slots:
    void on_validerButtonreservation_clicked();
     void on_supprimerButtonreservation_clicked();
     void on_modifierButtonreservation_clicked();
    void afficherres();
     void on_searchLineEdit_textChanged(const QString &text);
     void on_exporterreservation_clicked();
     void on_triComboBox_currentIndexChanged(int index);
     void afficherStatistiquesTypeChambre();
     void envoyerEmail(const QString& destinataire, const QString& sujet, const QString& message);
     void on_email_clicked();
     void on_sendVerificationButton_clicked();
     bool envoyerVerificationEmail(const QString &recipient, const QString &subject, const QString &body);
     void on_verifyCodeButton_clicked();





private slots:
    void onRechercheTextChanged(const QString &text);
private slots:
    void changerDePagestatistique();
    void changerDePagesms();
    void changerDePagestatclient();
    void changerDePagestatres();
    void changerDePagecalmaint();
    void changerDePageconnexion();
    void changerDePagestatstock();
    void changerDePagemdp();
private slots:
    void changerDePagecalcul();
    void changerDePagehisclient();
private slots:
    void changerDePageemploye();
private slots:
    void changerDePageclient();
private slots:
    void changerDePagereservation();
private slots:
    void changerDePagestock();
private slots:
    void changerDePagemaintenance();
private slots:
    void on_ajouterButton_clicked();
    void on_modifier_clicked();
    void on_supprimerButton_clicked();
    void on_rechercher_clicked();
    void on_boutonTrier_clicked();
    void Rechercheemploye();
    void exporterListeEmployesPDF();
    void afficherSalaireEtMasseSalariale();
    void afficherStatistiquesPostes();
    void sendRenewalMessages();
    void afficherEmployeesAvecUnAnDeContratRestant();
    bool inscrireEmploye();
    void on_connexionButton_clicked();
};


#endif

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "arduino.h"
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


#include "produit.h"
#include <QTableWidgetItem>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>



#include "maintenance.h"
#include <QtCharts>


#include <QtCharts/QLineSeries>
#include <QSqlQuery>
#pragma once
#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

#include "arduino1.h"


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

    void sendWhatsAppNotification(const QString& criticalProducts, const QString& lowStockProducts);
    void onTwilioResponseReceived();




private slots:
    void afficherStatistiques();
    void afficherProduitsDansTable();
    void on_sushButton_clicked();
    void on_sushButton_19_clicked();
    void on_sushButton_23_clicked();
    void on_sushButton_25_clicked();
    void on_sushButton_21_clicked();
    void on_sushButton_24_clicked();
    void on_sushButton_22_clicked(); // Slot pour exporter en PDF
    void on_sushButton_whatsapp_clicked();

    // Ajouter d'autres slots si nécessaire

    void on_sushButton_28_clicked();  // Slot pour la recherche du produit


    void on_sortComboBox_currentIndexChanged();  // <- Ajoutez cette ligne ici

    //void onCardRead(QString uid);


private slots:

    void on_pushButton_39_clicked();
    void on_pushButton_38_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_40_clicked();
    void on_pushButton_43_clicked();
    void on_comboBox_34_currentTextChanged(const QString &priorite);
    /*void on_pushButton_57_clicked();
    void on_acceuilcalmaint_clicked();
    void on_acceuilcalmaint_2_clicked();
    void on_pushButton_111_clicked();
    void on_acceuilcalmaint_3_clicked();*/
    void on_pushButton_stat_clicked();
    /*void chargerMaintenancesDansCalendrier();

    void chargerRappelsDansTableau();
    void ajouterOuModifierRappel(int idMaintenance);
    void afficherRappelsPourDate(const QDate &date);*/


private:
    bool messageDisplayed = false;


private:
    Ui::MainWindow *ui;
    Employe employe;
     QLabel *masse;
     Client cl;
     Reservation reservation;
     QVector<Reservation> reservations;
    Arduino arduino;
     ArduinoManager *arduinoManager;
     QSerialPort *serial;


    Maintenance Mtmp;
    void loadMaintenanceData();
    QStandardItemModel *model;
    QTimer *timer;
    QTimer *timerRappels;
    QTableWidget *tableRappels;
    void afficherMaintenancesPourDate(const QDate &date);
    void configurerMiseAJourAutomatique();


    void Rechercher(const QString &searchID);  // Déclaration de la fonction Rechercher

    // Déclarez 'tri' comme membre de la classe MainWindow
    QSqlQueryModel* tri;  // Déclarez le modèle SQL ici

     QLineEdit *searchLineEdit;
     QLineEdit *idReservationLineEdit;
     QDateEdit *dateReservationDateEdit;
     QDateEdit *dateArriveDateEdit;
     QDateEdit *dateDepartDateEdit;
     QComboBox *typeChambreComboBox;
     QComboBox *statutReservationComboBox;
     QComboBox *modePaiementComboBox;
     QLineEdit *montantLineEdit;
     QLineEdit *uidcarteline;


     QPushButton *validerButton;
     QPushButton *supprimerButton;
     QPushButton *modifierButton;
     QPushButton *exporterPdf;
     QNetworkAccessManager *networkManager;
     QString verificationCode;
 private slots:
      void on_sendButton_clicked();
     void on_validerClientButton_clicked();
      void readArduinoData();
     void listPorts();
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
    void changerDePagestatmaintenance();
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


namespace qrcodegen {

class QrSegment final {

public: class Mode final {

    public: static const Mode NUMERIC;
    public: static const Mode ALPHANUMERIC;
    public: static const Mode BYTE;
    public: static const Mode KANJI;
    public: static const Mode ECI;

    private: int modeBits;

    private: int numBitsCharCount[3];

    private: Mode(int mode, int cc0, int cc1, int cc2);


    public: int getModeBits() const;


    public: int numCharCountBits(int ver) const;

    };



public: static QrSegment makeBytes(const std::vector<std::uint8_t> &data);


public: static QrSegment makeNumeric(const char *digits);


public: static QrSegment makeAlphanumeric(const char *text);


public: static std::vector<QrSegment> makeSegments(const char *text);


public: static QrSegment makeEci(long assignVal);


public: static bool isNumeric(const char *text);


public: static bool isAlphanumeric(const char *text);


private: const Mode *mode;


private: int numChars;

private: std::vector<bool> data;



public: QrSegment(const Mode &md, int numCh, const std::vector<bool> &dt);


public: QrSegment(const Mode &md, int numCh, std::vector<bool> &&dt);



public: const Mode &getMode() const;


public: int getNumChars() const;



public: const std::vector<bool> &getData() const;


public: static int getTotalBits(const std::vector<QrSegment> &segs, int version);


private: static const char *ALPHANUMERIC_CHARSET;

};



class QrCode final {


public: enum class Ecc {
        LOW = 0 ,
        MEDIUM  ,
        QUARTILE,
        HIGH    ,
    };

private: static int getFormatBits(Ecc ecl);


public: static QrCode encodeText(const char *text, Ecc ecl);


public: static QrCode encodeBinary(const std::vector<std::uint8_t> &data, Ecc ecl);


public: static QrCode encodeSegments(const std::vector<QrSegment> &segs, Ecc ecl,
                                 int minVersion=1, int maxVersion=40, int mask=-1, bool boostEcl=true);  // All optional parameters


private: int version;

private: int size;
private: Ecc errorCorrectionLevel;

private: int mask;


private: std::vector<std::vector<bool> > modules;
private: std::vector<std::vector<bool> > isFunction;


public: QrCode(int ver, Ecc ecl, const std::vector<std::uint8_t> &dataCodewords, int msk);


public: int getVersion() const;

public: int getSize() const;

public: Ecc getErrorCorrectionLevel() const;

public: int getMask() const;

public: bool getModule(int x, int y) const;

private: void drawFunctionPatterns();

private: void drawFormatBits(int msk);

private: void drawVersion();

private: void drawFinderPattern(int x, int y);

private: void drawAlignmentPattern(int x, int y);

private: void setFunctionModule(int x, int y, bool isDark);

private: bool module(int x, int y) const;

private: std::vector<std::uint8_t> addEccAndInterleave(const std::vector<std::uint8_t> &data) const;

private: void drawCodewords(const std::vector<std::uint8_t> &data);

private: void applyMask(int msk);

private: long getPenaltyScore() const;

private: std::vector<int> getAlignmentPatternPositions() const;

private: static int getNumRawDataModules(int ver);

private: static int getNumDataCodewords(int ver, Ecc ecl);

private: static std::vector<std::uint8_t> reedSolomonComputeDivisor(int degree);
private: static std::vector<std::uint8_t> reedSolomonComputeRemainder(const std::vector<std::uint8_t> &data, const std::vector<std::uint8_t> &divisor);

private: static std::uint8_t reedSolomonMultiply(std::uint8_t x, std::uint8_t y);

private: int finderPenaltyCountPatterns(const std::array<int,7> &runHistory) const;
private: int finderPenaltyTerminateAndCount(bool currentRunColor, int currentRunLength, std::array<int,7> &runHistory) const;

private: void finderPenaltyAddHistory(int currentRunLength, std::array<int,7> &runHistory) const;

private: static bool getBit(long x, int i);

public: static constexpr int MIN_VERSION =  1;

public: static constexpr int MAX_VERSION = 40;


private: static const int PENALTY_N1;
private: static const int PENALTY_N2;
private: static const int PENALTY_N3;
private: static const int PENALTY_N4;


private: static const std::int8_t ECC_CODEWORDS_PER_BLOCK[4][41];
private: static const std::int8_t NUM_ERROR_CORRECTION_BLOCKS[4][41];

};



class data_too_long : public std::length_error {

public: explicit data_too_long(const std::string &msg);

};

class BitBuffer final : public std::vector<bool> {


public: BitBuffer();


public: void appendBits(std::uint32_t val, int len);

};

}


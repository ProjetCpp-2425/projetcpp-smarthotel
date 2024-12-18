/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_maintenance;
    QWidget *widget_10;
    QPushButton *clientmaint;
    QPushButton *employemaint;
    QPushButton *reservationmaint;
    QPushButton *stockmaint;
    QPushButton *maintenance;
    QPushButton *sedeconnecter9;
    QLabel *label_log;
    QLabel *label_main1;
    QPushButton *pushButton_supprimer_maintenance;
    QComboBox *comboBox_tri_maintenance;
    QPushButton *pushButton_ajouter_maintenance;
    QPushButton *pushButton_modifier_maintenance;
    QPushButton *pushButton_exporter_maintenance;
    QPushButton *pushButton_stat2_maintenance;
    QPushButton *pushButton_calendrier;
    QWidget *widget_138;
    QComboBox *comboBox_etat_maintenance;
    QLabel *label_621;
    QLabel *label_609;
    QLabel *label_604;
    QLabel *label_605;
    QLabel *label_613;
    QLabel *label_622;
    QLineEdit *lineEdit_id_maintenance;
    QLineEdit *lineEdit_num_chambre;
    QComboBox *comboBox_type_maintenance;
    QComboBox *comboBox_priorite;
    QLabel *label_638;
    QLineEdit *lineEdit_id_emplye;
    QLabel *label_1259;
    QDateEdit *dateEdit_date_debut;
    QDateEdit *dateEdit_date_fin;
    QLineEdit *lineEdit_description_rappel;
    QDateTimeEdit *date_rappel;
    QLabel *label_624;
    QLabel *label_625;
    QTableView *tableView_maintenance;
    QLineEdit *lineEdit_id_maintenance_2;
    QPushButton *pushButton_recherche_maintenance;
    QLineEdit *lineEdit_96;
    QPushButton *pushButton_QRC;
    QLabel *qr_code;
    QLabel *label_qrc2;
    QLabel *label_ca;
    QLabel *label_sta;
    QLabel *label_pdf2;
    QLabel *label_chercher;
    QLineEdit *lineEdit_description_rappel_2;
    QPushButton *btnGoToArduino;
    QLabel *label_securite;
    QWidget *page_statistique_maintenance;
    QWidget *widget_144;
    QPushButton *clientmaint_18;
    QPushButton *employemaint_18;
    QPushButton *reservationmaint_18;
    QPushButton *stockmaint_18;
    QPushButton *maintenance_18;
    QPushButton *sedeconnecter10_2;
    QLabel *label_logo;
    QLabel *label_main2;
    QLabel *label_620;
    QPushButton *pushButton_stat_maintenance;
    QPushButton *pushButton_162;
    QPushButton *pushButton_163;
    QPushButton *acceuilmaintenance_2;
    QPushButton *pushButton_112;
    QWidget *graphicsView_41;
    QLabel *label_stat;
    QLabel *label_pdf;
    QLabel *label_stat_2;
    QLabel *label_calendrier;
    QLabel *label_qrc;
    QGraphicsView *graphic;
    QWidget *page_calendrier;
    QPushButton *pushButtonAfficherMaintenances_2;
    QPushButton *pushButton_45;
    QPushButton *pushButton_46;
    QPushButton *btnAjouterRappel;
    QWidget *widget_139;
    QPushButton *clientmaint_17;
    QPushButton *employemaint_17;
    QPushButton *reservationmaint_17;
    QPushButton *stockmaint_17;
    QPushButton *maintenance_17;
    QLabel *label_logoo;
    QPushButton *sedeconnecter10;
    QLabel *label_main3;
    QLabel *label_616;
    QPushButton *acceuilmaintenance;
    QPushButton *pushButton_114;
    QCalendarWidget *calendarWidget;
    QLabel *label_cal;
    QLabel *label_qrc1;
    QLabel *label_call;
    QLabel *label_state;
    QLabel *label_pdf1;
    QTableWidget *commandesTableWidget;
    QLabel *labelMessage;
    QTableWidget *tableRappels;
    QWidget *pageArduino;
    QPushButton *btnRetourPage15;
    QLabel *labelNumChambre;
    QLineEdit *lineEditNumChambre;
    QPushButton *pushButton_afficher_arduino;
    QLabel *labelMessage_2;
    QLabel *label_623;
    QWidget *widget_11;
    QPushButton *clientmaint_2;
    QPushButton *employemaint_2;
    QPushButton *reservationmaint_2;
    QPushButton *stockmaint_2;
    QPushButton *maintenance_2;
    QPushButton *sedeconnecter9_2;
    QLabel *label_log_2;
    QLabel *label_main1_2;
    QLabel *label_securitee;
    QTableWidget *tableWidgetAlerts;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1390, 783);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setEnabled(true);
        stackedWidget->setGeometry(QRect(10, 0, 1371, 741));
        QFont font;
        font.setPointSize(12);
        stackedWidget->setFont(font);
        stackedWidget->setStyleSheet(QString::fromUtf8(" \n"
"background-color: rgb(255, 255, 255);"));
        page_maintenance = new QWidget();
        page_maintenance->setObjectName("page_maintenance");
        widget_10 = new QWidget(page_maintenance);
        widget_10->setObjectName("widget_10");
        widget_10->setGeometry(QRect(-40, 0, 1411, 91));
        widget_10->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 80);"));
        clientmaint = new QPushButton(widget_10);
        clientmaint->setObjectName("clientmaint");
        clientmaint->setGeometry(QRect(100, 20, 151, 51));
        clientmaint->setStyleSheet(QString::fromUtf8(" font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        employemaint = new QPushButton(widget_10);
        employemaint->setObjectName("employemaint");
        employemaint->setGeometry(QRect(310, 20, 161, 51));
        employemaint->setStyleSheet(QString::fromUtf8(" font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        reservationmaint = new QPushButton(widget_10);
        reservationmaint->setObjectName("reservationmaint");
        reservationmaint->setGeometry(QRect(510, 20, 161, 51));
        reservationmaint->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        stockmaint = new QPushButton(widget_10);
        stockmaint->setObjectName("stockmaint");
        stockmaint->setGeometry(QRect(710, 20, 171, 51));
        stockmaint->setStyleSheet(QString::fromUtf8(" font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        maintenance = new QPushButton(widget_10);
        maintenance->setObjectName("maintenance");
        maintenance->setGeometry(QRect(920, 20, 201, 51));
        maintenance->setStyleSheet(QString::fromUtf8(" color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(83, 89, 86);\n"
" \n"
" \n"
"border-radius:10px;"));
        sedeconnecter9 = new QPushButton(widget_10);
        sedeconnecter9->setObjectName("sedeconnecter9");
        sedeconnecter9->setGeometry(QRect(1190, 70, 131, 21));
        sedeconnecter9->setStyleSheet(QString::fromUtf8("color: rgb(172, 44, 103);\n"
"text-decoration: underline;\n"
"font: 700 9pt \"Segoe UI\";\n"
"background-color:transparent;"));
        label_log = new QLabel(widget_10);
        label_log->setObjectName("label_log");
        label_log->setGeometry(QRect(1200, 0, 101, 71));
        label_log->setScaledContents(true);
        label_main1 = new QLabel(widget_10);
        label_main1->setObjectName("label_main1");
        label_main1->setGeometry(QRect(930, 30, 41, 31));
        label_main1->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        pushButton_supprimer_maintenance = new QPushButton(page_maintenance);
        pushButton_supprimer_maintenance->setObjectName("pushButton_supprimer_maintenance");
        pushButton_supprimer_maintenance->setGeometry(QRect(1230, 110, 121, 41));
        pushButton_supprimer_maintenance->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"text-decoration: underline;\n"
"font: 10pt \"Segoe UI\";\n"
"background-color: rgb(172, 44, 103);"));
        comboBox_tri_maintenance = new QComboBox(page_maintenance);
        comboBox_tri_maintenance->addItem(QString());
        comboBox_tri_maintenance->addItem(QString());
        comboBox_tri_maintenance->addItem(QString());
        comboBox_tri_maintenance->setObjectName("comboBox_tri_maintenance");
        comboBox_tri_maintenance->setGeometry(QRect(650, 130, 131, 26));
        comboBox_tri_maintenance->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
""));
        pushButton_ajouter_maintenance = new QPushButton(page_maintenance);
        pushButton_ajouter_maintenance->setObjectName("pushButton_ajouter_maintenance");
        pushButton_ajouter_maintenance->setGeometry(QRect(40, 90, 241, 41));
        pushButton_ajouter_maintenance->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(83, 89, 86);\n"
"color: rgb(209, 196, 233);\n"
"font: 12pt \"Segoe UI\";"));
        pushButton_modifier_maintenance = new QPushButton(page_maintenance);
        pushButton_modifier_maintenance->setObjectName("pushButton_modifier_maintenance");
        pushButton_modifier_maintenance->setGeometry(QRect(1100, 110, 121, 41));
        pushButton_modifier_maintenance->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"text-decoration: underline;\n"
"font: 10pt \"Segoe UI\";\n"
"background-color: rgb(172, 44, 103);"));
        pushButton_exporter_maintenance = new QPushButton(page_maintenance);
        pushButton_exporter_maintenance->setObjectName("pushButton_exporter_maintenance");
        pushButton_exporter_maintenance->setGeometry(QRect(1220, 660, 141, 41));
        pushButton_exporter_maintenance->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"border-radius:10px;\n"
"color: rgb(0, 0, 0);\n"
"font: 700 10pt \"Segoe UI\";"));
        pushButton_stat2_maintenance = new QPushButton(page_maintenance);
        pushButton_stat2_maintenance->setObjectName("pushButton_stat2_maintenance");
        pushButton_stat2_maintenance->setGeometry(QRect(1090, 660, 121, 41));
        pushButton_stat2_maintenance->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"border-radius:10px;\n"
"color: rgb(0, 0, 0);\n"
"font: 700 10pt \"Segoe UI\";"));
        pushButton_calendrier = new QPushButton(page_maintenance);
        pushButton_calendrier->setObjectName("pushButton_calendrier");
        pushButton_calendrier->setGeometry(QRect(970, 660, 111, 41));
        pushButton_calendrier->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"border-radius:10px;\n"
"color: rgb(0, 0, 0);\n"
"font: 700 10pt \"Segoe UI\";"));
        widget_138 = new QWidget(page_maintenance);
        widget_138->setObjectName("widget_138");
        widget_138->setGeometry(QRect(30, 130, 291, 581));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("MingLiU_HKSCS-ExtB")});
        widget_138->setFont(font1);
        widget_138->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"border-radius:20px;"));
        comboBox_etat_maintenance = new QComboBox(widget_138);
        comboBox_etat_maintenance->addItem(QString());
        comboBox_etat_maintenance->addItem(QString());
        comboBox_etat_maintenance->addItem(QString());
        comboBox_etat_maintenance->setObjectName("comboBox_etat_maintenance");
        comboBox_etat_maintenance->setGeometry(QRect(40, 370, 211, 31));
        comboBox_etat_maintenance->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color:rgb(0,0,80);"));
        label_621 = new QLabel(widget_138);
        label_621->setObjectName("label_621");
        label_621->setGeometry(QRect(40, 350, 181, 20));
        label_621->setStyleSheet(QString::fromUtf8("font: 11pt \"Segoe UI\";color: rgb(0, 0, 81); background-color:transparent;"));
        label_609 = new QLabel(widget_138);
        label_609->setObjectName("label_609");
        label_609->setGeometry(QRect(40, 290, 191, 21));
        label_609->setStyleSheet(QString::fromUtf8("font: 11pt \"Segoe UI\";color: rgb(0, 0, 81); background-color:transparent;"));
        label_604 = new QLabel(widget_138);
        label_604->setObjectName("label_604");
        label_604->setGeometry(QRect(40, 10, 191, 20));
        label_604->setStyleSheet(QString::fromUtf8("font: 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 81);\n"
"background-color:transparent;"));
        label_605 = new QLabel(widget_138);
        label_605->setObjectName("label_605");
        label_605->setGeometry(QRect(40, 110, 201, 20));
        label_605->setStyleSheet(QString::fromUtf8("font: 11pt \"Segoe UI\";color: rgb(0, 0, 81); background-color:transparent;"));
        label_613 = new QLabel(widget_138);
        label_613->setObjectName("label_613");
        label_613->setGeometry(QRect(40, 160, 241, 31));
        label_613->setStyleSheet(QString::fromUtf8("font: 11pt \"Segoe UI\";color: rgb(0, 0, 81); background-color:transparent;"));
        label_622 = new QLabel(widget_138);
        label_622->setObjectName("label_622");
        label_622->setGeometry(QRect(40, 230, 191, 20));
        label_622->setStyleSheet(QString::fromUtf8("font: 11pt \"Segoe UI\";color: rgb(0, 0, 81); background-color:transparent;"));
        lineEdit_id_maintenance = new QLineEdit(widget_138);
        lineEdit_id_maintenance->setObjectName("lineEdit_id_maintenance");
        lineEdit_id_maintenance->setGeometry(QRect(40, 30, 211, 26));
        lineEdit_id_maintenance->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 81);\n"
""));
        lineEdit_num_chambre = new QLineEdit(widget_138);
        lineEdit_num_chambre->setObjectName("lineEdit_num_chambre");
        lineEdit_num_chambre->setGeometry(QRect(40, 130, 211, 26));
        lineEdit_num_chambre->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 81);\n"
""));
        comboBox_type_maintenance = new QComboBox(widget_138);
        comboBox_type_maintenance->addItem(QString());
        comboBox_type_maintenance->addItem(QString());
        comboBox_type_maintenance->addItem(QString());
        comboBox_type_maintenance->setObjectName("comboBox_type_maintenance");
        comboBox_type_maintenance->setGeometry(QRect(40, 190, 211, 31));
        comboBox_type_maintenance->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color:rgb(0,0,80);"));
        comboBox_priorite = new QComboBox(widget_138);
        comboBox_priorite->addItem(QString());
        comboBox_priorite->addItem(QString());
        comboBox_priorite->addItem(QString());
        comboBox_priorite->setObjectName("comboBox_priorite");
        comboBox_priorite->setGeometry(QRect(40, 430, 211, 31));
        comboBox_priorite->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color:rgb(0,0,80);"));
        label_638 = new QLabel(widget_138);
        label_638->setObjectName("label_638");
        label_638->setGeometry(QRect(40, 410, 181, 20));
        label_638->setStyleSheet(QString::fromUtf8("font: 11pt \"Segoe UI\";color: rgb(0, 0, 81); background-color:transparent;"));
        lineEdit_id_emplye = new QLineEdit(widget_138);
        lineEdit_id_emplye->setObjectName("lineEdit_id_emplye");
        lineEdit_id_emplye->setGeometry(QRect(40, 80, 211, 26));
        lineEdit_id_emplye->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 81);\n"
""));
        label_1259 = new QLabel(widget_138);
        label_1259->setObjectName("label_1259");
        label_1259->setGeometry(QRect(40, 60, 131, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(false);
        label_1259->setFont(font2);
        label_1259->setStyleSheet(QString::fromUtf8("font: 11pt \"Segoe UI\";\n"
""));
        dateEdit_date_debut = new QDateEdit(widget_138);
        dateEdit_date_debut->setObjectName("dateEdit_date_debut");
        dateEdit_date_debut->setGeometry(QRect(40, 250, 211, 26));
        dateEdit_date_debut->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color:rgb(0,0,80);"));
        dateEdit_date_fin = new QDateEdit(widget_138);
        dateEdit_date_fin->setObjectName("dateEdit_date_fin");
        dateEdit_date_fin->setGeometry(QRect(40, 310, 211, 26));
        dateEdit_date_fin->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color:rgb(0,0,80);"));
        lineEdit_description_rappel = new QLineEdit(widget_138);
        lineEdit_description_rappel->setObjectName("lineEdit_description_rappel");
        lineEdit_description_rappel->setGeometry(QRect(40, 540, 211, 26));
        lineEdit_description_rappel->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 81);\n"
""));
        date_rappel = new QDateTimeEdit(widget_138);
        date_rappel->setObjectName("date_rappel");
        date_rappel->setGeometry(QRect(40, 490, 211, 26));
        date_rappel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255); background-color:rgb(0,0,80);"));
        label_624 = new QLabel(widget_138);
        label_624->setObjectName("label_624");
        label_624->setGeometry(QRect(40, 470, 191, 20));
        label_624->setStyleSheet(QString::fromUtf8("font: 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 81);\n"
"background-color:transparent;"));
        label_625 = new QLabel(widget_138);
        label_625->setObjectName("label_625");
        label_625->setGeometry(QRect(40, 520, 191, 20));
        label_625->setStyleSheet(QString::fromUtf8("font: 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 81);\n"
"background-color:transparent;"));
        tableView_maintenance = new QTableView(page_maintenance);
        tableView_maintenance->setObjectName("tableView_maintenance");
        tableView_maintenance->setGeometry(QRect(350, 220, 1021, 201));
        lineEdit_id_maintenance_2 = new QLineEdit(page_maintenance);
        lineEdit_id_maintenance_2->setObjectName("lineEdit_id_maintenance_2");
        lineEdit_id_maintenance_2->setGeometry(QRect(660, 100, 121, 26));
        lineEdit_id_maintenance_2->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"\n"
""));
        pushButton_recherche_maintenance = new QPushButton(page_maintenance);
        pushButton_recherche_maintenance->setObjectName("pushButton_recherche_maintenance");
        pushButton_recherche_maintenance->setGeometry(QRect(400, 100, 251, 29));
        pushButton_recherche_maintenance->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(83, 89, 86);\n"
"color: rgb(209, 196, 233);\n"
"font: 12pt \"Segoe UI\";"));
        lineEdit_96 = new QLineEdit(page_maintenance);
        lineEdit_96->setObjectName("lineEdit_96");
        lineEdit_96->setGeometry(QRect(530, 130, 111, 31));
        lineEdit_96->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(255, 255, 255);\n"
"background-color: rgb(83, 89, 86);\n"
"color: rgb(209, 196, 233);\n"
"font: 12pt \"Segoe UI\";"));
        pushButton_QRC = new QPushButton(page_maintenance);
        pushButton_QRC->setObjectName("pushButton_QRC");
        pushButton_QRC->setGeometry(QRect(740, 660, 121, 41));
        pushButton_QRC->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"border-radius:10px;\n"
"color: rgb(0, 0, 0);\n"
"font: 700 10pt \"Segoe UI\";"));
        qr_code = new QLabel(page_maintenance);
        qr_code->setObjectName("qr_code");
        qr_code->setGeometry(QRect(340, 390, 381, 281));
        label_qrc2 = new QLabel(page_maintenance);
        label_qrc2->setObjectName("label_qrc2");
        label_qrc2->setGeometry(QRect(740, 580, 121, 81));
        label_qrc2->setScaledContents(true);
        label_ca = new QLabel(page_maintenance);
        label_ca->setObjectName("label_ca");
        label_ca->setGeometry(QRect(980, 590, 91, 61));
        label_ca->setScaledContents(true);
        label_sta = new QLabel(page_maintenance);
        label_sta->setObjectName("label_sta");
        label_sta->setGeometry(QRect(1100, 590, 111, 61));
        label_sta->setScaledContents(true);
        label_pdf2 = new QLabel(page_maintenance);
        label_pdf2->setObjectName("label_pdf2");
        label_pdf2->setGeometry(QRect(1230, 590, 121, 61));
        label_pdf2->setScaledContents(true);
        label_chercher = new QLabel(page_maintenance);
        label_chercher->setObjectName("label_chercher");
        label_chercher->setGeometry(QRect(350, 100, 51, 31));
        label_chercher->setScaledContents(true);
        lineEdit_description_rappel_2 = new QLineEdit(page_maintenance);
        lineEdit_description_rappel_2->setObjectName("lineEdit_description_rappel_2");
        lineEdit_description_rappel_2->setGeometry(QRect(790, 100, 121, 26));
        lineEdit_description_rappel_2->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"\n"
""));
        btnGoToArduino = new QPushButton(page_maintenance);
        btnGoToArduino->setObjectName("btnGoToArduino");
        btnGoToArduino->setGeometry(QRect(870, 660, 91, 41));
        btnGoToArduino->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"border-radius:10px;\n"
"color: rgb(0, 0, 0);\n"
"font: 700 10pt \"Segoe UI\";"));
        label_securite = new QLabel(page_maintenance);
        label_securite->setObjectName("label_securite");
        label_securite->setGeometry(QRect(870, 599, 91, 61));
        stackedWidget->addWidget(page_maintenance);
        pushButton_supprimer_maintenance->raise();
        comboBox_tri_maintenance->raise();
        pushButton_stat2_maintenance->raise();
        widget_138->raise();
        widget_10->raise();
        pushButton_modifier_maintenance->raise();
        pushButton_ajouter_maintenance->raise();
        pushButton_exporter_maintenance->raise();
        pushButton_calendrier->raise();
        tableView_maintenance->raise();
        lineEdit_id_maintenance_2->raise();
        pushButton_recherche_maintenance->raise();
        lineEdit_96->raise();
        pushButton_QRC->raise();
        qr_code->raise();
        label_qrc2->raise();
        label_ca->raise();
        label_sta->raise();
        label_pdf2->raise();
        label_chercher->raise();
        lineEdit_description_rappel_2->raise();
        btnGoToArduino->raise();
        label_securite->raise();
        page_statistique_maintenance = new QWidget();
        page_statistique_maintenance->setObjectName("page_statistique_maintenance");
        widget_144 = new QWidget(page_statistique_maintenance);
        widget_144->setObjectName("widget_144");
        widget_144->setGeometry(QRect(-20, 0, 1391, 91));
        widget_144->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 80);"));
        clientmaint_18 = new QPushButton(widget_144);
        clientmaint_18->setObjectName("clientmaint_18");
        clientmaint_18->setGeometry(QRect(100, 20, 151, 51));
        clientmaint_18->setStyleSheet(QString::fromUtf8(" font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        employemaint_18 = new QPushButton(widget_144);
        employemaint_18->setObjectName("employemaint_18");
        employemaint_18->setGeometry(QRect(300, 20, 161, 51));
        employemaint_18->setStyleSheet(QString::fromUtf8(" font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        reservationmaint_18 = new QPushButton(widget_144);
        reservationmaint_18->setObjectName("reservationmaint_18");
        reservationmaint_18->setGeometry(QRect(510, 18, 161, 51));
        reservationmaint_18->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        stockmaint_18 = new QPushButton(widget_144);
        stockmaint_18->setObjectName("stockmaint_18");
        stockmaint_18->setGeometry(QRect(720, 20, 161, 51));
        stockmaint_18->setStyleSheet(QString::fromUtf8(" font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        maintenance_18 = new QPushButton(widget_144);
        maintenance_18->setObjectName("maintenance_18");
        maintenance_18->setGeometry(QRect(920, 18, 181, 51));
        maintenance_18->setStyleSheet(QString::fromUtf8(" color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(83, 89, 86);\n"
" \n"
" \n"
"border-radius:10px;"));
        sedeconnecter10_2 = new QPushButton(widget_144);
        sedeconnecter10_2->setObjectName("sedeconnecter10_2");
        sedeconnecter10_2->setGeometry(QRect(1140, 70, 131, 29));
        sedeconnecter10_2->setStyleSheet(QString::fromUtf8("color: rgb(172, 44, 103);\n"
"text-decoration: underline;\n"
"font: 700 9pt \"Segoe UI\";\n"
"background-color:transparent;"));
        label_logo = new QLabel(widget_144);
        label_logo->setObjectName("label_logo");
        label_logo->setGeometry(QRect(1140, 10, 121, 61));
        label_logo->setScaledContents(true);
        label_main2 = new QLabel(widget_144);
        label_main2->setObjectName("label_main2");
        label_main2->setGeometry(QRect(930, 30, 31, 31));
        label_main2->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        label_620 = new QLabel(page_statistique_maintenance);
        label_620->setObjectName("label_620");
        label_620->setGeometry(QRect(20, 120, 221, 511));
        label_620->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"color: transparent;\n"
"border-radius:20px;"));
        pushButton_stat_maintenance = new QPushButton(page_statistique_maintenance);
        pushButton_stat_maintenance->setObjectName("pushButton_stat_maintenance");
        pushButton_stat_maintenance->setGeometry(QRect(1010, 640, 151, 41));
        pushButton_stat_maintenance->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"text-decoration: underline;\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";\n"
"background-color: rgb(83, 89, 86);\n"
"border-radius:10px;\n"
"font: 700 10pt \"Segoe UI\";"));
        pushButton_162 = new QPushButton(page_statistique_maintenance);
        pushButton_162->setObjectName("pushButton_162");
        pushButton_162->setGeometry(QRect(840, 640, 151, 41));
        pushButton_162->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"text-decoration: underline;\n"
"font: 9pt \"Segoe UI\";\n"
"border-radius:10px;\n"
"color: rgb(0, 0, 0);\n"
"font: 700 10pt \"Segoe UI\";"));
        pushButton_163 = new QPushButton(page_statistique_maintenance);
        pushButton_163->setObjectName("pushButton_163");
        pushButton_163->setGeometry(QRect(1180, 640, 151, 41));
        pushButton_163->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"text-decoration: underline;\n"
"font: 9pt \"Segoe UI\";\n"
"border-radius:10px;\n"
"color: rgb(0, 0, 0);\n"
"font: 700 10pt \"Segoe UI\";"));
        acceuilmaintenance_2 = new QPushButton(page_statistique_maintenance);
        acceuilmaintenance_2->setObjectName("acceuilmaintenance_2");
        acceuilmaintenance_2->setGeometry(QRect(1090, 140, 181, 41));
        acceuilmaintenance_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 11pt \"Segoe UI\";\n"
"text-decoration: underline;\n"
"background-color: rgb(172, 44, 103);\n"
"border-radius:10px;"));
        pushButton_112 = new QPushButton(page_statistique_maintenance);
        pushButton_112->setObjectName("pushButton_112");
        pushButton_112->setGeometry(QRect(670, 640, 151, 41));
        pushButton_112->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"border-radius:10px;\n"
"color: rgb(0, 0, 0);\n"
"font: 700 10pt \"Segoe UI\";"));
        graphicsView_41 = new QWidget(page_statistique_maintenance);
        graphicsView_41->setObjectName("graphicsView_41");
        graphicsView_41->setGeometry(QRect(1330, 140, 20, 221));
        label_stat = new QLabel(page_statistique_maintenance);
        label_stat->setObjectName("label_stat");
        label_stat->setGeometry(QRect(30, 260, 201, 191));
        label_stat->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        label_stat->setScaledContents(true);
        label_pdf = new QLabel(page_statistique_maintenance);
        label_pdf->setObjectName("label_pdf");
        label_pdf->setGeometry(QRect(1200, 550, 121, 81));
        label_stat_2 = new QLabel(page_statistique_maintenance);
        label_stat_2->setObjectName("label_stat_2");
        label_stat_2->setGeometry(QRect(1020, 550, 141, 81));
        label_calendrier = new QLabel(page_statistique_maintenance);
        label_calendrier->setObjectName("label_calendrier");
        label_calendrier->setGeometry(QRect(850, 560, 131, 81));
        label_qrc = new QLabel(page_statistique_maintenance);
        label_qrc->setObjectName("label_qrc");
        label_qrc->setGeometry(QRect(680, 550, 131, 81));
        label_qrc->setScaledContents(true);
        graphic = new QGraphicsView(page_statistique_maintenance);
        graphic->setObjectName("graphic");
        graphic->setGeometry(QRect(380, 140, 571, 361));
        stackedWidget->addWidget(page_statistique_maintenance);
        page_calendrier = new QWidget();
        page_calendrier->setObjectName("page_calendrier");
        pushButtonAfficherMaintenances_2 = new QPushButton(page_calendrier);
        pushButtonAfficherMaintenances_2->setObjectName("pushButtonAfficherMaintenances_2");
        pushButtonAfficherMaintenances_2->setGeometry(QRect(870, 650, 151, 41));
        pushButtonAfficherMaintenances_2->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"text-decoration: underline;\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"Segoe UI\";\n"
"background-color: rgb(83, 89, 86);\n"
"border-radius:10px;\n"
"font: 700 10pt \"Segoe UI\";"));
        pushButton_45 = new QPushButton(page_calendrier);
        pushButton_45->setObjectName("pushButton_45");
        pushButton_45->setGeometry(QRect(1040, 650, 151, 41));
        pushButton_45->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"color: rgb(255, 255, 255);\n"
"text-decoration: underline;\n"
"font: 11pt \"Segoe UI\";\n"
"border-radius:10px;\n"
"color: rgb(0, 0, 0);\n"
"font: 700 10pt \"Segoe UI\";"));
        pushButton_46 = new QPushButton(page_calendrier);
        pushButton_46->setObjectName("pushButton_46");
        pushButton_46->setGeometry(QRect(1200, 650, 151, 41));
        pushButton_46->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"text-decoration: underline;\n"
"font: 9pt \"Segoe UI\";\n"
"border-radius:10px;\n"
"color: rgb(0, 0, 0);\n"
"font: 700 10pt \"Segoe UI\";"));
        btnAjouterRappel = new QPushButton(page_calendrier);
        btnAjouterRappel->setObjectName("btnAjouterRappel");
        btnAjouterRappel->setGeometry(QRect(290, 460, 241, 41));
        btnAjouterRappel->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Segoe UI\";\n"
"border-radius:10px;"));
        widget_139 = new QWidget(page_calendrier);
        widget_139->setObjectName("widget_139");
        widget_139->setGeometry(QRect(-50, 0, 1431, 91));
        widget_139->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 80);"));
        clientmaint_17 = new QPushButton(widget_139);
        clientmaint_17->setObjectName("clientmaint_17");
        clientmaint_17->setGeometry(QRect(100, 18, 151, 51));
        clientmaint_17->setStyleSheet(QString::fromUtf8(" font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        employemaint_17 = new QPushButton(widget_139);
        employemaint_17->setObjectName("employemaint_17");
        employemaint_17->setGeometry(QRect(300, 18, 161, 51));
        employemaint_17->setStyleSheet(QString::fromUtf8(" font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        reservationmaint_17 = new QPushButton(widget_139);
        reservationmaint_17->setObjectName("reservationmaint_17");
        reservationmaint_17->setGeometry(QRect(510, 18, 161, 51));
        reservationmaint_17->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        stockmaint_17 = new QPushButton(widget_139);
        stockmaint_17->setObjectName("stockmaint_17");
        stockmaint_17->setGeometry(QRect(720, 18, 161, 51));
        stockmaint_17->setStyleSheet(QString::fromUtf8(" font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        maintenance_17 = new QPushButton(widget_139);
        maintenance_17->setObjectName("maintenance_17");
        maintenance_17->setGeometry(QRect(920, 20, 181, 51));
        maintenance_17->setStyleSheet(QString::fromUtf8(" color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(83, 89, 86);\n"
" \n"
" \n"
"border-radius:10px;"));
        label_logoo = new QLabel(widget_139);
        label_logoo->setObjectName("label_logoo");
        label_logoo->setGeometry(QRect(1170, 0, 121, 61));
        label_logoo->setScaledContents(true);
        sedeconnecter10 = new QPushButton(widget_139);
        sedeconnecter10->setObjectName("sedeconnecter10");
        sedeconnecter10->setGeometry(QRect(1170, 60, 131, 29));
        sedeconnecter10->setStyleSheet(QString::fromUtf8("color: rgb(172, 44, 103);\n"
"text-decoration: underline;\n"
"font: 700 9pt \"Segoe UI\";\n"
"background-color:transparent;"));
        label_main3 = new QLabel(widget_139);
        label_main3->setObjectName("label_main3");
        label_main3->setGeometry(QRect(930, 30, 31, 31));
        label_main3->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        label_616 = new QLabel(page_calendrier);
        label_616->setObjectName("label_616");
        label_616->setGeometry(QRect(10, 110, 221, 511));
        label_616->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"color: transparent;\n"
"border-radius:20px;"));
        acceuilmaintenance = new QPushButton(page_calendrier);
        acceuilmaintenance->setObjectName("acceuilmaintenance");
        acceuilmaintenance->setGeometry(QRect(1130, 110, 181, 41));
        acceuilmaintenance->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 11pt \"Segoe UI\";\n"
"text-decoration: underline;\n"
"background-color: rgb(172, 44, 103);\n"
"border-radius:10px;"));
        pushButton_114 = new QPushButton(page_calendrier);
        pushButton_114->setObjectName("pushButton_114");
        pushButton_114->setGeometry(QRect(700, 650, 151, 41));
        pushButton_114->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"border-radius:10px;\n"
"color: rgb(0, 0, 0);\n"
"font: 700 10pt \"Segoe UI\";"));
        calendarWidget = new QCalendarWidget(page_calendrier);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(260, 90, 571, 231));
        label_cal = new QLabel(page_calendrier);
        label_cal->setObjectName("label_cal");
        label_cal->setGeometry(QRect(20, 240, 201, 211));
        label_cal->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        label_cal->setScaledContents(true);
        label_qrc1 = new QLabel(page_calendrier);
        label_qrc1->setObjectName("label_qrc1");
        label_qrc1->setGeometry(QRect(720, 580, 121, 71));
        label_qrc1->setScaledContents(true);
        label_call = new QLabel(page_calendrier);
        label_call->setObjectName("label_call");
        label_call->setGeometry(QRect(880, 580, 131, 71));
        label_state = new QLabel(page_calendrier);
        label_state->setObjectName("label_state");
        label_state->setGeometry(QRect(1070, 580, 121, 71));
        label_pdf1 = new QLabel(page_calendrier);
        label_pdf1->setObjectName("label_pdf1");
        label_pdf1->setGeometry(QRect(1220, 560, 121, 81));
        commandesTableWidget = new QTableWidget(page_calendrier);
        if (commandesTableWidget->columnCount() < 8)
            commandesTableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        commandesTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        commandesTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        commandesTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        commandesTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        commandesTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        commandesTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        commandesTableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        commandesTableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (commandesTableWidget->rowCount() < 2)
            commandesTableWidget->setRowCount(2);
        commandesTableWidget->setObjectName("commandesTableWidget");
        commandesTableWidget->setGeometry(QRect(240, 340, 1031, 111));
        labelMessage = new QLabel(page_calendrier);
        labelMessage->setObjectName("labelMessage");
        labelMessage->setGeometry(QRect(1040, 180, 291, 121));
        tableRappels = new QTableWidget(page_calendrier);
        if (tableRappels->columnCount() < 3)
            tableRappels->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableRappels->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableRappels->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableRappels->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        if (tableRappels->rowCount() < 2)
            tableRappels->setRowCount(2);
        tableRappels->setObjectName("tableRappels");
        tableRappels->setGeometry(QRect(270, 510, 401, 151));
        stackedWidget->addWidget(page_calendrier);
        pageArduino = new QWidget();
        pageArduino->setObjectName("pageArduino");
        btnRetourPage15 = new QPushButton(pageArduino);
        btnRetourPage15->setObjectName("btnRetourPage15");
        btnRetourPage15->setGeometry(QRect(1100, 180, 181, 41));
        btnRetourPage15->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 11pt \"Segoe UI\";\n"
"text-decoration: underline;\n"
"background-color: rgb(172, 44, 103);\n"
"border-radius:10px;"));
        labelNumChambre = new QLabel(pageArduino);
        labelNumChambre->setObjectName("labelNumChambre");
        labelNumChambre->setGeometry(QRect(450, 190, 431, 51));
        lineEditNumChambre = new QLineEdit(pageArduino);
        lineEditNumChambre->setObjectName("lineEditNumChambre");
        lineEditNumChambre->setGeometry(QRect(490, 290, 301, 31));
        lineEditNumChambre->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
""));
        pushButton_afficher_arduino = new QPushButton(pageArduino);
        pushButton_afficher_arduino->setObjectName("pushButton_afficher_arduino");
        pushButton_afficher_arduino->setGeometry(QRect(540, 370, 181, 41));
        pushButton_afficher_arduino->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: rgb(83, 89, 86);\n"
"color: rgb(209, 196, 233);\n"
"font: 16pt \"Segoe UI\";\n"
""));
        labelMessage_2 = new QLabel(pageArduino);
        labelMessage_2->setObjectName("labelMessage_2");
        labelMessage_2->setGeometry(QRect(410, 470, 441, 51));
        labelMessage_2->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
""));
        label_623 = new QLabel(pageArduino);
        label_623->setObjectName("label_623");
        label_623->setGeometry(QRect(90, 130, 221, 511));
        label_623->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"color: transparent;\n"
"border-radius:20px;"));
        widget_11 = new QWidget(pageArduino);
        widget_11->setObjectName("widget_11");
        widget_11->setGeometry(QRect(0, 0, 1411, 91));
        widget_11->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 80);"));
        clientmaint_2 = new QPushButton(widget_11);
        clientmaint_2->setObjectName("clientmaint_2");
        clientmaint_2->setGeometry(QRect(100, 20, 151, 51));
        clientmaint_2->setStyleSheet(QString::fromUtf8(" font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        employemaint_2 = new QPushButton(widget_11);
        employemaint_2->setObjectName("employemaint_2");
        employemaint_2->setGeometry(QRect(310, 20, 161, 51));
        employemaint_2->setStyleSheet(QString::fromUtf8(" font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        reservationmaint_2 = new QPushButton(widget_11);
        reservationmaint_2->setObjectName("reservationmaint_2");
        reservationmaint_2->setGeometry(QRect(510, 20, 161, 51));
        reservationmaint_2->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        stockmaint_2 = new QPushButton(widget_11);
        stockmaint_2->setObjectName("stockmaint_2");
        stockmaint_2->setGeometry(QRect(710, 20, 171, 51));
        stockmaint_2->setStyleSheet(QString::fromUtf8(" font: 700 10pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        maintenance_2 = new QPushButton(widget_11);
        maintenance_2->setObjectName("maintenance_2");
        maintenance_2->setGeometry(QRect(920, 20, 201, 51));
        maintenance_2->setStyleSheet(QString::fromUtf8(" color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(83, 89, 86);\n"
" \n"
" \n"
"border-radius:10px;"));
        sedeconnecter9_2 = new QPushButton(widget_11);
        sedeconnecter9_2->setObjectName("sedeconnecter9_2");
        sedeconnecter9_2->setGeometry(QRect(1190, 70, 131, 21));
        sedeconnecter9_2->setStyleSheet(QString::fromUtf8("color: rgb(172, 44, 103);\n"
"text-decoration: underline;\n"
"font: 700 9pt \"Segoe UI\";\n"
"background-color:transparent;"));
        label_log_2 = new QLabel(widget_11);
        label_log_2->setObjectName("label_log_2");
        label_log_2->setGeometry(QRect(1200, 0, 101, 71));
        label_log_2->setScaledContents(true);
        label_main1_2 = new QLabel(widget_11);
        label_main1_2->setObjectName("label_main1_2");
        label_main1_2->setGeometry(QRect(930, 30, 41, 31));
        label_main1_2->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        label_securitee = new QLabel(pageArduino);
        label_securitee->setObjectName("label_securitee");
        label_securitee->setGeometry(QRect(100, 270, 201, 181));
        label_securitee->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        tableWidgetAlerts = new QTableWidget(pageArduino);
        if (tableWidgetAlerts->columnCount() < 3)
            tableWidgetAlerts->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidgetAlerts->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidgetAlerts->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidgetAlerts->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        if (tableWidgetAlerts->rowCount() < 5)
            tableWidgetAlerts->setRowCount(5);
        tableWidgetAlerts->setObjectName("tableWidgetAlerts");
        tableWidgetAlerts->setGeometry(QRect(930, 340, 401, 331));
        stackedWidget->addWidget(pageArduino);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1390, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        clientmaint->setText(QCoreApplication::translate("MainWindow", "client", nullptr));
        employemaint->setText(QCoreApplication::translate("MainWindow", "employ\303\251", nullptr));
        reservationmaint->setText(QCoreApplication::translate("MainWindow", "reservation", nullptr));
        stockmaint->setText(QCoreApplication::translate("MainWindow", "stock", nullptr));
        maintenance->setText(QCoreApplication::translate("MainWindow", "   maintenance", nullptr));
        sedeconnecter9->setText(QCoreApplication::translate("MainWindow", "se d\303\251connecter", nullptr));
        label_log->setText(QString());
        label_main1->setText(QString());
        pushButton_supprimer_maintenance->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        comboBox_tri_maintenance->setItemText(0, QCoreApplication::translate("MainWindow", "urgente", nullptr));
        comboBox_tri_maintenance->setItemText(1, QCoreApplication::translate("MainWindow", "normale", nullptr));
        comboBox_tri_maintenance->setItemText(2, QCoreApplication::translate("MainWindow", "basse", nullptr));

        pushButton_ajouter_maintenance->setText(QCoreApplication::translate("MainWindow", "Ajouter une demande", nullptr));
        pushButton_modifier_maintenance->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        pushButton_exporter_maintenance->setText(QCoreApplication::translate("MainWindow", "exporter en PDF", nullptr));
        pushButton_stat2_maintenance->setText(QCoreApplication::translate("MainWindow", "statistiques", nullptr));
        pushButton_calendrier->setText(QCoreApplication::translate("MainWindow", "calendrier", nullptr));
        comboBox_etat_maintenance->setItemText(0, QCoreApplication::translate("MainWindow", "en cours", nullptr));
        comboBox_etat_maintenance->setItemText(1, QCoreApplication::translate("MainWindow", "en attente", nullptr));
        comboBox_etat_maintenance->setItemText(2, QCoreApplication::translate("MainWindow", "termin\303\251", nullptr));

        label_621->setText(QCoreApplication::translate("MainWindow", "Etat de maintenance", nullptr));
        label_609->setText(QCoreApplication::translate("MainWindow", "Date pr\303\251vue de fin", nullptr));
        label_604->setText(QCoreApplication::translate("MainWindow", "ID de maintenance", nullptr));
        label_605->setText(QCoreApplication::translate("MainWindow", "Num Chambre concern\303\251e", nullptr));
        label_613->setText(QCoreApplication::translate("MainWindow", "Type de maintenance", nullptr));
        label_622->setText(QCoreApplication::translate("MainWindow", "Date de d\303\251but", nullptr));
        comboBox_type_maintenance->setItemText(0, QCoreApplication::translate("MainWindow", "corrective", nullptr));
        comboBox_type_maintenance->setItemText(1, QCoreApplication::translate("MainWindow", "esth\303\251tique", nullptr));
        comboBox_type_maintenance->setItemText(2, QCoreApplication::translate("MainWindow", "pr\303\251ventive", nullptr));

        comboBox_priorite->setItemText(0, QCoreApplication::translate("MainWindow", "urgente", nullptr));
        comboBox_priorite->setItemText(1, QCoreApplication::translate("MainWindow", "normale", nullptr));
        comboBox_priorite->setItemText(2, QCoreApplication::translate("MainWindow", "basse", nullptr));

        label_638->setText(QCoreApplication::translate("MainWindow", "Priorite", nullptr));
        label_1259->setText(QCoreApplication::translate("MainWindow", "ID de employe", nullptr));
        label_624->setText(QCoreApplication::translate("MainWindow", "Date de rappel", nullptr));
        label_625->setText(QCoreApplication::translate("MainWindow", "Description de rappel", nullptr));
        pushButton_recherche_maintenance->setText(QCoreApplication::translate("MainWindow", "Rechercher une demande:", nullptr));
        lineEdit_96->setText(QCoreApplication::translate("MainWindow", "    Tri par:", nullptr));
        pushButton_QRC->setText(QCoreApplication::translate("MainWindow", "QRC", nullptr));
        qr_code->setText(QString());
        label_qrc2->setText(QString());
        label_ca->setText(QString());
        label_sta->setText(QString());
        label_pdf2->setText(QString());
        label_chercher->setText(QString());
        btnGoToArduino->setText(QCoreApplication::translate("MainWindow", "s\303\251curit\303\251", nullptr));
        label_securite->setText(QString());
        clientmaint_18->setText(QCoreApplication::translate("MainWindow", "client", nullptr));
        employemaint_18->setText(QCoreApplication::translate("MainWindow", "employ\303\251", nullptr));
        reservationmaint_18->setText(QCoreApplication::translate("MainWindow", "reservation", nullptr));
        stockmaint_18->setText(QCoreApplication::translate("MainWindow", "stock", nullptr));
        maintenance_18->setText(QCoreApplication::translate("MainWindow", "    maintenance", nullptr));
        sedeconnecter10_2->setText(QCoreApplication::translate("MainWindow", "se d\303\251connecter", nullptr));
        label_logo->setText(QString());
        label_main2->setText(QString());
        label_620->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_stat_maintenance->setText(QCoreApplication::translate("MainWindow", "statistiques", nullptr));
        pushButton_162->setText(QCoreApplication::translate("MainWindow", "calendrier", nullptr));
        pushButton_163->setText(QCoreApplication::translate("MainWindow", "exporter en PDF", nullptr));
        acceuilmaintenance_2->setText(QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        pushButton_112->setText(QCoreApplication::translate("MainWindow", "QRC", nullptr));
        label_stat->setText(QString());
        label_pdf->setText(QString());
        label_stat_2->setText(QString());
        label_calendrier->setText(QString());
        label_qrc->setText(QString());
        pushButtonAfficherMaintenances_2->setText(QCoreApplication::translate("MainWindow", "calendrier", nullptr));
        pushButton_45->setText(QCoreApplication::translate("MainWindow", "statistiques", nullptr));
        pushButton_46->setText(QCoreApplication::translate("MainWindow", "exporter en PDF", nullptr));
        btnAjouterRappel->setText(QCoreApplication::translate("MainWindow", "Rappels et notifications", nullptr));
        clientmaint_17->setText(QCoreApplication::translate("MainWindow", "client", nullptr));
        employemaint_17->setText(QCoreApplication::translate("MainWindow", "employ\303\251", nullptr));
        reservationmaint_17->setText(QCoreApplication::translate("MainWindow", "reservation", nullptr));
        stockmaint_17->setText(QCoreApplication::translate("MainWindow", "stock", nullptr));
        maintenance_17->setText(QCoreApplication::translate("MainWindow", "   maintenance", nullptr));
        label_logoo->setText(QString());
        sedeconnecter10->setText(QCoreApplication::translate("MainWindow", "se d\303\251connecter", nullptr));
        label_main3->setText(QString());
        label_616->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        acceuilmaintenance->setText(QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        pushButton_114->setText(QCoreApplication::translate("MainWindow", "QRC", nullptr));
        label_cal->setText(QString());
        label_qrc1->setText(QString());
        label_call->setText(QString());
        label_state->setText(QString());
        label_pdf1->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = commandesTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID_MAINTENANCE", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = commandesTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "ID_EMPLOYE", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = commandesTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "NUM_CHAMBRE_CONCERNEE", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = commandesTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "TYPE_MAINTENANCE", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = commandesTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "DATE_DEBUT", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = commandesTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "DATE_FIN", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = commandesTableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "ETAT_MAINTENANCE", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = commandesTableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "PRIORITE", nullptr));
        labelMessage->setText(QString());
        QTableWidgetItem *___qtablewidgetitem8 = tableRappels->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "ID_MAINTENANCE", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableRappels->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "DATE_RAPPEL", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableRappels->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "DESCRIPTION_RAPPEL", nullptr));
        btnRetourPage15->setText(QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        labelNumChambre->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Entrerz le num\303\251ro de chambre</span></p></body></html>", nullptr));
        pushButton_afficher_arduino->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        labelMessage_2->setText(QString());
        label_623->setText(QString());
        clientmaint_2->setText(QCoreApplication::translate("MainWindow", "client", nullptr));
        employemaint_2->setText(QCoreApplication::translate("MainWindow", "employ\303\251", nullptr));
        reservationmaint_2->setText(QCoreApplication::translate("MainWindow", "reservation", nullptr));
        stockmaint_2->setText(QCoreApplication::translate("MainWindow", "stock", nullptr));
        maintenance_2->setText(QCoreApplication::translate("MainWindow", "   maintenance", nullptr));
        sedeconnecter9_2->setText(QCoreApplication::translate("MainWindow", "se d\303\251connecter", nullptr));
        label_log_2->setText(QString());
        label_main1_2->setText(QString());
        label_securitee->setText(QString());
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetAlerts->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "NUM_CHAMBRE_CONCERNEE", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetAlerts->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "ALERT_FLAME", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetAlerts->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "ALERT_DESCRIPTION", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *pageClient;
    QLabel *label_18;
    QPushButton *modifier;
    QPushButton *supprimer;
    QGraphicsView *graphicsView_2;
    QLineEdit *lineEdit_14;
    QLabel *label;
    QTableWidget *tableclient;
    QWidget *widget_2;
    QLabel *label_10;
    QLineEdit *lineEdit_5;
    QLabel *label_13;
    QLineEdit *lineEdit_9;
    QLabel *label_17;
    QPushButton *pushButton_2;
    QLabel *label_14;
    QLineEdit *lineEdit_7;
    QLabel *label_19;
    QLineEdit *lineEdit_12;
    QLabel *label_15;
    QDateEdit *dateEdit;
    QComboBox *comboBox;
    QLabel *label_20;
    QComboBox *comboBox_3;
    QLabel *label_21;
    QLineEdit *lineEdit_13;
    QGraphicsView *graphicsView;
    QWidget *widget;
    QLabel *logo_2;
    QLabel *label_3;
    QLabel *label_6;
    QGraphicsView *graphicsView_3;
    QPushButton *pushButton;
    QGraphicsView *graphicsView_5;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QLineEdit *ajouterclient;
    QGraphicsView *graphicsView_4;
    QPushButton *buttonStat;
    QComboBox *comboBox_2;
    QPushButton *buttonhistorique;
    QPushButton *buttonexporter;
    QWidget *pageStat;
    QGraphicsView *graphicsView_6;
    QPushButton *accueilbutton;
    QWidget *widget_3;
    QLabel *logo_3;
    QLabel *label_4;
    QLabel *label_7;
    QGraphicsView *graphicsView_7;
    QPushButton *pushButton_4;
    QGraphicsView *graphicsView_8;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QGraphicsView *graphicsView_14;
    QWidget *pagehistorique;
    QWidget *widget_4;
    QLabel *logo_4;
    QLabel *label_5;
    QLabel *label_8;
    QGraphicsView *graphicsView_9;
    QPushButton *pushButton_3;
    QGraphicsView *graphicsView_10;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QTableWidget *tableclient_2;
    QLabel *label_2;
    QPushButton *accueilbutton_2;
    QLabel *label_12;
    QLineEdit *lineEdit_15;
    QGraphicsView *graphicsView_12;
    QGraphicsView *graphicsView_13;
    QPushButton *buttonexporter_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(971, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 971, 551));
        pageClient = new QWidget();
        pageClient->setObjectName("pageClient");
        label_18 = new QLabel(pageClient);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(230, 160, 181, 16));
        label_18->setStyleSheet(QString::fromUtf8(" \n"
"color: rgb(0, 0, 0);\n"
"font: 700 11pt \"Segoe UI\";\n"
"background-color:transparent;"));
        modifier = new QPushButton(pageClient);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(680, 130, 91, 21));
        modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(172, 44, 103);\n"
"border-radius:10px;\n"
"font: 700 10pt \"Segoe UI\";\n"
""));
        supprimer = new QPushButton(pageClient);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(790, 130, 91, 21));
        supprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(172, 44, 103);\n"
"\n"
"font: 700 10pt \"Segoe UI\";\n"
"border-radius:10px;"));
        graphicsView_2 = new QGraphicsView(pageClient);
        graphicsView_2->setObjectName("graphicsView_2");
        graphicsView_2->setGeometry(QRect(320, 460, 71, 51));
        graphicsView_2->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/malek 2/interfaceclientttttttttttttttttttt/461186877_2244204025964463_8596233747044438081_n.png);"));
        lineEdit_14 = new QLineEdit(pageClient);
        lineEdit_14->setObjectName("lineEdit_14");
        lineEdit_14->setGeometry(QRect(510, 130, 131, 21));
        lineEdit_14->setStyleSheet(QString::fromUtf8(" \n"
"background-color: rgb(179, 170, 255);"));
        label = new QLabel(pageClient);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 130, 281, 20));
        label->setStyleSheet(QString::fromUtf8("background:transparent; \n"
" \n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
" "));
        tableclient = new QTableWidget(pageClient);
        if (tableclient->columnCount() < 8)
            tableclient->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableclient->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableclient->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableclient->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableclient->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableclient->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableclient->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableclient->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableclient->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableclient->rowCount() < 7)
            tableclient->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableclient->setItem(4, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableclient->setItem(4, 1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableclient->setItem(4, 2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableclient->setItem(4, 4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableclient->setItem(4, 5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableclient->setItem(4, 7, __qtablewidgetitem13);
        tableclient->setObjectName("tableclient");
        tableclient->setGeometry(QRect(190, 190, 761, 251));
        tableclient->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"color: rgb(0, 0, 0);\n"
"\n"
""));
        widget_2 = new QWidget(pageClient);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 120, 171, 391));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"border-radius:20px;"));
        label_10 = new QLabel(widget_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(40, 170, 91, 20));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 81);\n"
"font: 8pt \"Segoe UI\";"));
        lineEdit_5 = new QLineEdit(widget_2);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(30, 190, 121, 21));
        lineEdit_5->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 81);\n"
"color: rgb(255, 255, 255);"));
        label_13 = new QLabel(widget_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 210, 131, 20));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 81);\n"
"font: 8pt \"Segoe UI\";"));
        lineEdit_9 = new QLineEdit(widget_2);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(30, 320, 121, 21));
        lineEdit_9->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 81);\n"
"color: rgb(255, 255, 255);"));
        label_17 = new QLabel(widget_2);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(50, 300, 91, 16));
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 81);\n"
"font: 8pt \"Segoe UI\";"));
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 350, 91, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 81);\n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"border-radius:0px"));
        label_14 = new QLabel(widget_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(80, 80, 41, 16));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 81);\n"
"font: 8pt \"Segoe UI\";"));
        lineEdit_7 = new QLineEdit(widget_2);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(30, 100, 121, 21));
        lineEdit_7->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 81);\n"
"color: rgb(255, 255, 255);"));
        label_19 = new QLabel(widget_2);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(50, 40, 101, 20));
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 81);\n"
"font: 8pt \"Segoe UI\";"));
        lineEdit_12 = new QLineEdit(widget_2);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setGeometry(QRect(30, 60, 121, 21));
        lineEdit_12->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 81);\n"
"color: rgb(255, 255, 255);"));
        label_15 = new QLabel(widget_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(40, 130, 111, 16));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 81);\n"
"font: 8pt \"Segoe UI\";"));
        dateEdit = new QDateEdit(widget_2);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(30, 150, 121, 21));
        dateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 81);\n"
"color: rgb(255, 255, 255);\n"
""));
        comboBox = new QComboBox(widget_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(30, 230, 121, 21));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 81);\n"
"color: rgb(255, 255, 255);"));
        label_20 = new QLabel(widget_2);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(70, 260, 81, 16));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 81);\n"
"font: 8pt \"Segoe UI\";"));
        comboBox_3 = new QComboBox(widget_2);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(30, 280, 121, 21));
        comboBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 81);\n"
"color: rgb(255, 255, 255);"));
        label_21 = new QLabel(widget_2);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(60, 0, 101, 20));
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 81);\n"
"font: 8pt \"Segoe UI\";"));
        lineEdit_13 = new QLineEdit(widget_2);
        lineEdit_13->setObjectName("lineEdit_13");
        lineEdit_13->setGeometry(QRect(30, 20, 121, 21));
        lineEdit_13->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 81);\n"
"color: rgb(255, 255, 255);"));
        graphicsView = new QGraphicsView(pageClient);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(810, 460, 61, 51));
        graphicsView->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/malek 2/interfaceclientttttttttttttttttttt/460331069_3877861322443925_3262239950708236396_n.png);"));
        widget = new QWidget(pageClient);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 971, 91));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 80);"));
        logo_2 = new QLabel(widget);
        logo_2->setObjectName("logo_2");
        logo_2->setGeometry(QRect(1110, 10, 111, 91));
        logo_2->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/458173198_3712111305708768_706402164083404556_n-removebg-preview.png")));
        logo_2->setScaledContents(true);
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 30, 31, 31));
        label_3->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/pngtree-admin-rolls-glyph-black-icon-png-image_691507-removebg-preview.png")));
        label_3->setScaledContents(true);
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(750, 60, 121, 21));
        label_6->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"text-decoration: underline;\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt \"Segoe UI\";\n"
"color: rgb(172, 44, 103);\n"
""));
        graphicsView_3 = new QGraphicsView(widget);
        graphicsView_3->setObjectName("graphicsView_3");
        graphicsView_3->setGeometry(QRect(860, 10, 71, 61));
        graphicsView_3->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/malek 2/interfaceclientttttttttttttttttttt/logo-removebg-preview.png);"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 30, 151, 21));
        pushButton->setStyleSheet(QString::fromUtf8("  \n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(83, 89, 86);\n"
"border-radius:10px;\n"
""));
        graphicsView_5 = new QGraphicsView(widget);
        graphicsView_5->setObjectName("graphicsView_5");
        graphicsView_5->setGeometry(QRect(40, 30, 31, 21));
        graphicsView_5->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/malek 2/interfaceclientttttttttttttttttttt/client-removebg-preview.png);\n"
"background:transparent;"));
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(200, 30, 151, 21));
        pushButton_5->setStyleSheet(QString::fromUtf8(" \n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;\n"
""));
        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(370, 30, 151, 21));
        pushButton_6->setStyleSheet(QString::fromUtf8(" \n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;\n"
""));
        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(540, 30, 151, 21));
        pushButton_7->setStyleSheet(QString::fromUtf8(" \n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;\n"
""));
        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(710, 30, 151, 21));
        pushButton_8->setStyleSheet(QString::fromUtf8(" \n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;\n"
""));
        ajouterclient = new QLineEdit(pageClient);
        ajouterclient->setObjectName("ajouterclient");
        ajouterclient->setGeometry(QRect(0, 100, 131, 21));
        ajouterclient->setStyleSheet(QString::fromUtf8(" \n"
" \n"
"color: rgb(209, 196, 233);\n"
"font: 700 11pt \"Segoe UI\";\n"
"background-color: rgb(83, 89, 86);\n"
"border-radius:10px;"));
        graphicsView_4 = new QGraphicsView(pageClient);
        graphicsView_4->setObjectName("graphicsView_4");
        graphicsView_4->setGeometry(QRect(670, 470, 71, 41));
        graphicsView_4->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/malek 2/interfaceclientttttttttttttttttttt/historique.png);\n"
""));
        buttonStat = new QPushButton(pageClient);
        buttonStat->setObjectName("buttonStat");
        buttonStat->setGeometry(QRect(790, 510, 111, 21));
        buttonStat->setStyleSheet(QString::fromUtf8("font: 9pt \"Segoe UI\";\n"
"color: rgb(0, 0, 80);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        comboBox_2 = new QComboBox(pageClient);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(410, 160, 121, 21));
        comboBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 170, 255);\n"
"\n"
"color: rgb(255, 255, 255);\n"
""));
        buttonhistorique = new QPushButton(pageClient);
        buttonhistorique->setObjectName("buttonhistorique");
        buttonhistorique->setGeometry(QRect(650, 510, 111, 21));
        buttonhistorique->setStyleSheet(QString::fromUtf8("font: 9pt \"Segoe UI\";\n"
"color: rgb(0, 0, 80);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        buttonexporter = new QPushButton(pageClient);
        buttonexporter->setObjectName("buttonexporter");
        buttonexporter->setGeometry(QRect(300, 510, 111, 21));
        buttonexporter->setStyleSheet(QString::fromUtf8("font: 9pt \"Segoe UI\";\n"
"color: rgb(0, 0, 80);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        stackedWidget->addWidget(pageClient);
        pageStat = new QWidget();
        pageStat->setObjectName("pageStat");
        graphicsView_6 = new QGraphicsView(pageStat);
        graphicsView_6->setObjectName("graphicsView_6");
        graphicsView_6->setGeometry(QRect(30, 120, 621, 441));
        graphicsView_6->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/malek 2/interfaceclientttttttttttttttttttt/Cream_Blue_Clean___Professional_Pie_Charts_Election_Social_Issues_Instagram_Post-removebg-preview.png);"));
        accueilbutton = new QPushButton(pageStat);
        accueilbutton->setObjectName("accueilbutton");
        accueilbutton->setGeometry(QRect(750, 510, 141, 21));
        accueilbutton->setStyleSheet(QString::fromUtf8("font: 9pt \"Segoe UI\";\n"
"color: rgb(0, 0, 80);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        widget_3 = new QWidget(pageStat);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 0, 971, 91));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 80);"));
        logo_3 = new QLabel(widget_3);
        logo_3->setObjectName("logo_3");
        logo_3->setGeometry(QRect(1110, 10, 111, 91));
        logo_3->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/458173198_3712111305708768_706402164083404556_n-removebg-preview.png")));
        logo_3->setScaledContents(true);
        label_4 = new QLabel(widget_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 30, 31, 31));
        label_4->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/pngtree-admin-rolls-glyph-black-icon-png-image_691507-removebg-preview.png")));
        label_4->setScaledContents(true);
        label_7 = new QLabel(widget_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(750, 60, 121, 21));
        label_7->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"text-decoration: underline;\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt \"Segoe UI\";\n"
"color: rgb(172, 44, 103);\n"
""));
        graphicsView_7 = new QGraphicsView(widget_3);
        graphicsView_7->setObjectName("graphicsView_7");
        graphicsView_7->setGeometry(QRect(860, 10, 71, 61));
        graphicsView_7->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/malek 2/interfaceclientttttttttttttttttttt/logo-removebg-preview.png);"));
        pushButton_4 = new QPushButton(widget_3);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(20, 30, 151, 21));
        pushButton_4->setStyleSheet(QString::fromUtf8("  \n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(83, 89, 86);\n"
"border-radius:10px;\n"
""));
        graphicsView_8 = new QGraphicsView(widget_3);
        graphicsView_8->setObjectName("graphicsView_8");
        graphicsView_8->setGeometry(QRect(40, 30, 31, 21));
        graphicsView_8->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/malek 2/interfaceclientttttttttttttttttttt/client-removebg-preview.png);\n"
"\n"
"background:transparent;"));
        pushButton_13 = new QPushButton(widget_3);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(200, 30, 151, 21));
        pushButton_13->setStyleSheet(QString::fromUtf8(" \n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;\n"
""));
        pushButton_14 = new QPushButton(widget_3);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(370, 30, 151, 21));
        pushButton_14->setStyleSheet(QString::fromUtf8(" \n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;\n"
""));
        pushButton_15 = new QPushButton(widget_3);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(540, 30, 151, 21));
        pushButton_15->setStyleSheet(QString::fromUtf8(" \n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;\n"
""));
        pushButton_16 = new QPushButton(widget_3);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(710, 30, 151, 21));
        pushButton_16->setStyleSheet(QString::fromUtf8(" \n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;\n"
""));
        graphicsView_14 = new QGraphicsView(pageStat);
        graphicsView_14->setObjectName("graphicsView_14");
        graphicsView_14->setGeometry(QRect(810, 480, 31, 31));
        graphicsView_14->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/malek 2/interfaceclientttttttttttttttttttt/home-removebg-preview.png);"));
        stackedWidget->addWidget(pageStat);
        pagehistorique = new QWidget();
        pagehistorique->setObjectName("pagehistorique");
        widget_4 = new QWidget(pagehistorique);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(0, 0, 971, 91));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 80);"));
        logo_4 = new QLabel(widget_4);
        logo_4->setObjectName("logo_4");
        logo_4->setGeometry(QRect(1110, 10, 111, 91));
        logo_4->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/458173198_3712111305708768_706402164083404556_n-removebg-preview.png")));
        logo_4->setScaledContents(true);
        label_5 = new QLabel(widget_4);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 30, 31, 31));
        label_5->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/pngtree-admin-rolls-glyph-black-icon-png-image_691507-removebg-preview.png")));
        label_5->setScaledContents(true);
        label_8 = new QLabel(widget_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(750, 60, 121, 21));
        label_8->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
"text-decoration: underline;\n"
"font: 9pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"font: 10pt \"Segoe UI\";\n"
"color: rgb(172, 44, 103);\n"
""));
        graphicsView_9 = new QGraphicsView(widget_4);
        graphicsView_9->setObjectName("graphicsView_9");
        graphicsView_9->setGeometry(QRect(860, 10, 71, 61));
        graphicsView_9->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/malek 2/interfaceclientttttttttttttttttttt/logo-removebg-preview.png);"));
        pushButton_3 = new QPushButton(widget_4);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 30, 151, 21));
        pushButton_3->setStyleSheet(QString::fromUtf8("  \n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(83, 89, 86);\n"
"border-radius:10px;\n"
""));
        graphicsView_10 = new QGraphicsView(widget_4);
        graphicsView_10->setObjectName("graphicsView_10");
        graphicsView_10->setGeometry(QRect(40, 30, 31, 21));
        graphicsView_10->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/malek 2/interfaceclientttttttttttttttttttt/client-removebg-preview.png);\n"
"background:transparent;"));
        pushButton_9 = new QPushButton(widget_4);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(200, 30, 151, 21));
        pushButton_9->setStyleSheet(QString::fromUtf8(" \n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;\n"
""));
        pushButton_10 = new QPushButton(widget_4);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(370, 30, 151, 21));
        pushButton_10->setStyleSheet(QString::fromUtf8(" \n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;\n"
""));
        pushButton_11 = new QPushButton(widget_4);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(540, 30, 151, 21));
        pushButton_11->setStyleSheet(QString::fromUtf8(" \n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;\n"
""));
        pushButton_12 = new QPushButton(widget_4);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(710, 30, 151, 21));
        pushButton_12->setStyleSheet(QString::fromUtf8(" \n"
"color: rgb(255, 255, 255);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;\n"
""));
        tableclient_2 = new QTableWidget(pagehistorique);
        if (tableclient_2->columnCount() < 9)
            tableclient_2->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableclient_2->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableclient_2->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableclient_2->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableclient_2->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableclient_2->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableclient_2->setHorizontalHeaderItem(5, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableclient_2->setHorizontalHeaderItem(6, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableclient_2->setHorizontalHeaderItem(7, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableclient_2->setHorizontalHeaderItem(8, __qtablewidgetitem22);
        if (tableclient_2->rowCount() < 7)
            tableclient_2->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableclient_2->setItem(4, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableclient_2->setItem(4, 1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableclient_2->setItem(4, 2, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableclient_2->setItem(4, 4, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableclient_2->setItem(4, 5, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableclient_2->setItem(4, 8, __qtablewidgetitem28);
        tableclient_2->setObjectName("tableclient_2");
        tableclient_2->setGeometry(QRect(40, 190, 911, 261));
        tableclient_2->setStyleSheet(QString::fromUtf8("background-color: rgb(209, 196, 233);\n"
"color: rgb(0, 0, 0);\n"
"\n"
""));
        label_2 = new QLabel(pagehistorique);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 149, 281, 31));
        label_2->setStyleSheet(QString::fromUtf8("background:transparent; \n"
" \n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
" "));
        accueilbutton_2 = new QPushButton(pagehistorique);
        accueilbutton_2->setObjectName("accueilbutton_2");
        accueilbutton_2->setGeometry(QRect(770, 500, 141, 21));
        accueilbutton_2->setStyleSheet(QString::fromUtf8("font: 9pt \"Segoe UI\";\n"
"color: rgb(0, 0, 80);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        label_12 = new QLabel(pagehistorique);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(60, 120, 321, 20));
        label_12->setStyleSheet(QString::fromUtf8("background:transparent; \n"
" \n"
"font: 700 11pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
" "));
        lineEdit_15 = new QLineEdit(pagehistorique);
        lineEdit_15->setObjectName("lineEdit_15");
        lineEdit_15->setGeometry(QRect(370, 120, 131, 21));
        lineEdit_15->setStyleSheet(QString::fromUtf8(" \n"
"background-color: rgb(179, 170, 255);"));
        graphicsView_12 = new QGraphicsView(pagehistorique);
        graphicsView_12->setObjectName("graphicsView_12");
        graphicsView_12->setGeometry(QRect(820, 470, 31, 31));
        graphicsView_12->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/malek 2/interfaceclientttttttttttttttttttt/home-removebg-preview.png);"));
        graphicsView_13 = new QGraphicsView(pagehistorique);
        graphicsView_13->setObjectName("graphicsView_13");
        graphicsView_13->setGeometry(QRect(330, 450, 71, 51));
        graphicsView_13->setStyleSheet(QString::fromUtf8("border-image: url(:/Desktop/malek 2/interfaceclientttttttttttttttttttt/461186877_2244204025964463_8596233747044438081_n.png);"));
        buttonexporter_2 = new QPushButton(pagehistorique);
        buttonexporter_2->setObjectName("buttonexporter_2");
        buttonexporter_2->setGeometry(QRect(310, 500, 111, 21));
        buttonexporter_2->setStyleSheet(QString::fromUtf8("font: 9pt \"Segoe UI\";\n"
"color: rgb(0, 0, 80);\n"
"font: 700 10pt \"Segoe UI\";\n"
"background-color: rgb(179, 170, 255);\n"
" \n"
" \n"
"border-radius:10px;"));
        stackedWidget->addWidget(pagehistorique);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 971, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "TRIER LES CLIENTS PAR :", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        supprimer->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "RECHERCHER UN CLIENT PAR SON ID :", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableclient->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID client", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableclient->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "nom complet", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableclient->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "pays", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableclient->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "date naissance", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableclient->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "telephone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableclient->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "demandes", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableclient->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableclient->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "total points", nullptr));

        const bool __sortingEnabled = tableclient->isSortingEnabled();
        tableclient->setSortingEnabled(false);
        tableclient->setSortingEnabled(__sortingEnabled);

        label_10->setText(QCoreApplication::translate("MainWindow", "     TELEPHONE", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "DEMANDES SPECIAUX", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "TOTAL POINTS", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "valider", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "PAYS", nullptr));
        lineEdit_7->setText(QString());
        label_19->setText(QCoreApplication::translate("MainWindow", "NOM COMPLET", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "DATE DE NAISSANCE", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "guide ", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "transport prive", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "excursion ", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Repas special ", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "aucun", nullptr));

        label_20->setText(QCoreApplication::translate("MainWindow", "STATUT", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "en attente", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "en cours", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "termin\303\251", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("MainWindow", "rejet\303\251", nullptr));

        label_21->setText(QCoreApplication::translate("MainWindow", "ID CLIENT ", nullptr));
        logo_2->setText(QString());
        label_3->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "se deconnecter", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "client", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "employe", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "reservation", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "stock", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "maintenance", nullptr));
        ajouterclient->setText(QCoreApplication::translate("MainWindow", "  Ajouter un client", nullptr));
        buttonStat->setText(QCoreApplication::translate("MainWindow", "statistique", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "date de naissance", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "total points", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "statut", nullptr));

        buttonhistorique->setText(QCoreApplication::translate("MainWindow", "historique", nullptr));
        buttonexporter->setText(QCoreApplication::translate("MainWindow", "exporter en PDF", nullptr));
        accueilbutton->setText(QCoreApplication::translate("MainWindow", "Accueil", nullptr));
        logo_3->setText(QString());
        label_4->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "se deconnecter", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "client", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "employe", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "reservation", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "stock", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "maintenance", nullptr));
        logo_4->setText(QString());
        label_5->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "se deconnecter", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "client", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "employe", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "reservation", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "stock", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "maintenance", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableclient_2->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "ID reservation", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableclient_2->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "ID client", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableclient_2->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "nom complet", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableclient_2->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "date reservation", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableclient_2->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "duree sejour", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableclient_2->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableclient_2->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "demande spacial", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableclient_2->horizontalHeaderItem(7);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "montant", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableclient_2->horizontalHeaderItem(8);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "points gagnes", nullptr));

        const bool __sortingEnabled1 = tableclient_2->isSortingEnabled();
        tableclient_2->setSortingEnabled(false);
        tableclient_2->setSortingEnabled(__sortingEnabled1);

        label_2->setText(QCoreApplication::translate("MainWindow", "historique des reservations :", nullptr));
        accueilbutton_2->setText(QCoreApplication::translate("MainWindow", "Accueil", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "RECHERCHER UN CLIENT PAR ID CLIENT :", nullptr));
        buttonexporter_2->setText(QCoreApplication::translate("MainWindow", "exporter en PDF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

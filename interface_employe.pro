QT       += core gui sql

QT       += core gui

QT += charts
QT += network
QT +=printsupport
QT += serialport

RESOURCES += resources.qrc
QT += core gui widgets charts
QT += core gui widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    arduino1.cpp \
    client.cpp \
    connection.cpp \
    email.cpp \
    employe.cpp \
    main.cpp \
    maintenance.cpp \
    mainwindow.cpp \
    pdf.cpp \
    produit.cpp \
    reservation.cpp

HEADERS += \
    arduino.h \
    arduino1.h \
    client.h \
    connection.h \
    email.h \
    employe.h \
    maintenance.h \
    mainwindow.h \
    pdf.h \
    produit.h \
    reservation.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagess.qrc

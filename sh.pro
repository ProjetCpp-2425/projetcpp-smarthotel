QT       += core gui sql
QT       += core gui
QT += widgets printsupport
QT += widgets charts
QT += network
QT += core network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    email.cpp \
    main.cpp \
    mainwindow.cpp \
    pdf.cpp \
    reservation.cpp \


HEADERS += \
    connection.h \
    email.h \
    mainwindow.h \
    pdf.h \
    reservation.h \



FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../../461268050_1910908796097430_573549776139727012_n.png \
    ../../../SmtpClient-for-Qt-2.0.zip \
    460331069_3877861322443925_3262239950708236396_n.png \
    461186877_2244204025964463_8596233747044438081_n.png \
    461268050_1910908796097430_573549776139727012_n.png \
    Git-2.47.0-64-bit.exe \
    sh.pro.user \
    system.sql

RESOURCES += \
    rami.qrc \
    rami.qrc

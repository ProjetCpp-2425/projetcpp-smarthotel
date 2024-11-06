#include "mainwindow.h"
#include <QApplication>
#include "connection.h"
#include <QMessageBox>
#include "Client.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection cn;
    bool test=cn.createconnect();
    MainWindow w;
    if(test)
    {
        w.show();
        QMessageBox:: information (nullptr,QObject::tr("database is open"),QObject::tr("connection effectué\n" "click cancel to exit!"),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox:: critical (nullptr,QObject::tr("database is not open"),QObject::tr("connection non effectué\n" "click cancel to exit!"),QMessageBox::Cancel);
    }
    return a.exec();
}

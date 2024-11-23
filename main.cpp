#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool connected = c.createconnect();

    if (!connected) {
        QMessageBox::critical(nullptr, QObject::tr("Database Connection"),
                              QObject::tr("Failed to connect to the database. Exiting..."));
        return -1;
    }

    MainWindow w;
    w.show();
    return a.exec();
}

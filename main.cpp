#include "mainwindow.h"
#include <QApplication>
#include "connection.h"
#include <QMessageBox>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Connection conn;
    if (!conn.createconnect()) {
            QMessageBox::critical(nullptr, "Database Connection", "Failed to connect to the database.");
            return -1;  // Exit if the connection fails
        }
    MainWindow w;

    w.show();
    return a.exec();
}

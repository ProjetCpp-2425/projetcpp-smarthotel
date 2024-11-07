#include "connection.h"
#include <QMessageBox>

#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "connection.h"
#include <QMessageBox>
#include <QSqlError>

Connection::Connection() {}

bool Connection::createconnect() {
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName("salim");  // Updated database name
    db.setUserName("salim");      // Username
    db.setPassword("malek");      // Password

    if (db.open()) {
        test = true;
        QMessageBox::information(nullptr, "Database Connection", "Connected successfully to Oracle XE.");
    } else {
        QMessageBox::critical(nullptr, "Database Connection", "Connection failed: " + db.lastError().text());
    }

    return test;
}

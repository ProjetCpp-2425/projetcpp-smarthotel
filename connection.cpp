#include "connection.h"

bool Connection::createconnect()
{bool test=false;
db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("SmartHotel_Project");//inserer le nom de la source de données
db.setUserName("SmartHotel");//inserer nom de l'utilisateur
db.setPassword("malek");//inserer mot de passe de cet utilisateur


if (db.open())
    test=true;


    return  test;
}

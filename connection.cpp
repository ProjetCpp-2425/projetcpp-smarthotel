#include "connection.h"

Connection::Connection(){}

bool Connection::createconnection()
{
db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("SmartHotel_project");//inserer le nom de la source de données
db.setUserName("SmartHotel");//inserer nom de l'utilisateur
db.setPassword("malek");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
return test;
}

void Connection::closeConnection(){ db.close();}

#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("SmartHotel_Project");
db.setUserName("SmartHotel");
db.setPassword("malek");

if (db.open())
test=true;





    return  test;
}

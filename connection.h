#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlQuery>

class Connection
{
    QSqlDatabase db;
public:
    Connection(){}
    bool createconnect();
    void closeconnection(){db.close();}

};

#endif // CONNECTION_H

#ifndef CLIENT_H
#define CLIENT_H

#include <QAbstractItemModel>
#include<Qstring>
#include <QDateTime>
class Client : public QAbstractItemModel
{
    Q_OBJECT

private:
    int ID_client;
    QString nom_complet;
    QString pays;
    QDate date ;
    int telephone;
    QString demande;
    QString statut ;
    int total_points;

public:
    Client();
    Client(int,QString,QDate,QString,int,QString,QString,int);

    int getID_client(){return ID_client ;}
    void setID_client(int newID){ID_client=newID;}
    QString getnom_complet(){return nom_complet ;}
    void setnom_complet(QString newnom){nom_complet=newnom;}
    QString getdemande(){return demande ;}
    void setdemande(QString newdemande){demande=newdemande;}
    QString getstatut(){return statut ;}
    void setstatut(QString newstatut){statut=newstatut;}
    int gettotal_points(){return total_points;}
    void settotal_points(int newtotal){total_points=newtotal;}

    bool ajouter();
    void afficher();

};

#endif // CLIENT_H

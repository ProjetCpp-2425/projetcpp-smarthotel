#ifndef CLIENT_H
#define CLIENT_H

#include<Qstring>
#include <QDate>
#include<QSqlQueryModel>
#include<QSqlQuery>
class Client
{
private:
    int ID_client;
    QString nom;
    QString prenom;
    QDate date_naissance ;
    QString demande_special;
    QString statut ;
    QString pays;
    int telephone;
    int total_points;

public:
    Client();
    Client(int,QString,QString,QDate,QString,QString,QString,int,int);

    int getID_client(){return ID_client ;}
    void setID_client(int newID){ID_client=newID;}
    QString getnom(){return nom ;}
    void setnom(QString newnom){nom=newnom;}
    QString getprenom(){return prenom ;}
    void setprenom(QString newprenom){prenom=newprenom;}
    QDate getdate_naissance(){return date_naissance ;}
    void setdate_naissance(QDate newdate){date_naissance=newdate;}
    QString getdemande_special(){return demande_special ;}
    void setdemande_special(QString newdemande){demande_special=newdemande;}
    QString getstatut(){return statut ;}
    void setstatut(QString newstatut){statut=newstatut;}
    QString getpays(){return pays ;}
    void setpays(QString newpays){pays=newpays;}
    int gettelephone(){return telephone ;}
    void settelephone(int newtele){telephone=newtele;}
    int gettotal_points(){return total_points;}
    void settotal_points(int newtotal){total_points=newtotal;}

    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer (int id);
    bool modifier(int,QString &,QString &,QDate &,QString &,QString &,QString &,int &,int &);
    Client chercher(int id);

};

#endif // CLIENT_H

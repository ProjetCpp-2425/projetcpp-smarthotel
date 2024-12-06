#ifndef MAINTENANCE_H
#define MAINTENANCE_H
#include "qdatetime.h"
#include <QTableView>
#include<QString>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QDate>
#include <QTextCharFormat>
#include <QSqlQueryModel>
#include <QAbstractItemModel>
#include <QMap>
class Maintenance
{
    int ID_MAINTENANCE;
    QString ID_EMPLOYE;
    int NUM_CHAMBRE_CONCERNEE;
    QString TYPE_MAINTENANCE;
    QDate DATE_DEBUT;
    QDate DATE_FIN;
    QString ETAT_MAINTENANCE;
    QString PRIORITE;
    QDateTime DATE_RAPPEL;
    QString DESCRIPTION_RAPPEL;

public:
    Maintenance(){}
    Maintenance(int,QString,int, QString, QDate , QDate, QString ,QString,QDateTime,QString );
    QSqlQueryModel* rechercherParID(int ID_MAINTENANCE);
    QSqlQueryModel* rechercherParDescription(const QString &description);

    QSqlQueryModel* trierParPriorite(const QString &priorite);  // Méthode pour trier par priorité
    bool existe(int id);
    QMap<QDate, QTextCharFormat> getHighlightedDates(QAbstractItemModel *model);

    int getID_maintenance(){return ID_MAINTENANCE;}
    QString getID_EMPLOYE(){return ID_EMPLOYE;}
    int getNUM_chambre_concernee(){return NUM_CHAMBRE_CONCERNEE ;}
    QString getType_maintenance(){return TYPE_MAINTENANCE;;}
    QDate getDate_debut(){return DATE_DEBUT;}
    QDate getDate_fin(){return  DATE_FIN;}
    QString getEtat_maintenance(){return ETAT_MAINTENANCE;}
    QString getPriorite(){return PRIORITE;}
    QDateTime getDATE_Rappel(){return DATE_RAPPEL;}
    QString getDESCRIPTION_Rappel(){return DESCRIPTION_RAPPEL;}

    void setID_maintenance(int id){this->ID_MAINTENANCE=id;};
    void setID_EMPLOYE(QString Employe){ID_EMPLOYE=Employe;};

    void setNum_chambre_concernee(int num){this->NUM_CHAMBRE_CONCERNEE=num;}
    void setType_maintenance(class QString type){TYPE_MAINTENANCE=type;}
    void setDate_Debut(QDate d_b){DATE_DEBUT=d_b;}
    void setDate_Fin(QDate d_f){DATE_FIN=d_f;}
    void setEtat_maintenance(QString etat){ETAT_MAINTENANCE=etat;}
    void setPriorite(QString Priorite){PRIORITE=Priorite;}
    void setDATE_Rappel(QDateTime d_R){DATE_RAPPEL = d_R;}
    void setDESCRIPTION_Rappel(QString d_r){DESCRIPTION_RAPPEL=d_r;}

    bool ajouter();
    bool supprimer(int ID_MAINTENANCE);
    bool modifier();
    QSqlQueryModel* afficher();
};

#endif // MAINTENANCE_H

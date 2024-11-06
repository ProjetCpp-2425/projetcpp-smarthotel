#include "Client.h"
#include<QString>
#include "mainwindow.h"
#include "QSqlQuery"
#include<QSqlQueryModel>
#include<connection.h>
#include <QMessageBox>

Client:: Client()
{
    ID_client=0;
    nom="";
    prenom="";
    demande_special="";
    statut="en attente" ;
    pays="";
    telephone=0;
    total_points=0;
}
Client :: Client(int ID,QString nom,QString prenom,QDate date,QString demande ,QString statut,QString pays,int tele,int total)
{
    ID_client = ID ;
    this ->nom=nom;
    this ->prenom=prenom;
    date_naissance = date ;
    demande_special= demande ;
    this -> statut = statut ;
    this -> pays=pays;
    telephone = tele ;
    total_points=total;
}

bool Client :: ajouter()
{
    QSqlQuery query;
    QString CIN=QString::number(ID_client) ;
    QString tele=QString::number(telephone) ;
    QString total=QString::number(total_points) ;
    query.prepare("INSERT INTO CLIENTS (ID_client, nom,prenom, date_naissance, demande_special, statut, pays, telephone, total_points) "
                  "VALUES (:ID_client, :nom,:prenom, :date_naissance, :demande_special, :statut, :pays, :telephone, :total_points)");
    query.bindValue(":ID_client",CIN);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date_naissance",date_naissance);
    query.bindValue(":demande_special",demande_special);
    query.bindValue(":statut",statut);
    query.bindValue(":pays",pays);
    query.bindValue(":telephone",tele);
    query.bindValue(":total_points",total);


    return query.exec();

}
QSqlQueryModel * Client :: afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel ();
    model ->setQuery("select * from CLIENTS ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_client"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("demande_special"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("statut"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("pays"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("telephone"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("total_points"));

    return model;
}

bool Client :: supprimer(int id)
{
    QSqlQuery query;
    QString CIN=QString::number(id) ;
    query.prepare(" delete from CLIENTS where ID_client=:id");
    query.bindValue(":id",CIN);

   // return query.exec();
    if (query.exec())
    {
        if (query.numRowsAffected() == 0)
        {
            QMessageBox::information(nullptr, "Suppression", "L'ID n'existe pas");
            return false;
        } else
            return true;
    }
    return false;
}

bool Client :: modifier (int id,QString &nv_nom ,QString &nv_prenom,QDate &nv_date,QString &nv_demande,QString &nv_statut,QString &nv_pays,int &nv_tele,int &nv_total)
{
    QSqlQuery query;
    QString CIN=QString::number(id) ;
    query.prepare(" update CLIENTS set nom= :nom, prenom= :prenom, date_naissance= :date_naissance, demande_special= :demande_special, statut= :statut, pays= :pays, telephone= :telephone, total_points= :total_points where ID_client=:id");
    query.bindValue(":id",CIN);
    query.bindValue(":nom",nv_nom);
    query.bindValue(":prenom",nv_prenom);
    query.bindValue(":date_naissance",nv_date);
    query.bindValue(":demande_special",nv_demande);
    query.bindValue(":statut",nv_statut);
    query.bindValue(":pays",nv_pays);
    query.bindValue(":telephone",nv_tele);
    query.bindValue(":total_points",nv_total);

    return query.exec();

}
Client Client::chercher(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTS WHERE ID_client = :id");
    query.bindValue(":id", id);

    if (query.exec())
    {
        if (query.next()) {
            // Créer un objet Client avec les données récupérées
            Client client;
            client.ID_client= query.value("ID_client").toInt();
            client.nom = query.value("nom").toString();
            client.prenom = query.value("prenom").toString();
            client.date_naissance = query.value("date_naissance").toDate();
            client.demande_special = query.value("demande_special").toString();
            client.statut = query.value("statut").toString();
            client.pays = query.value("pays").toString();
            client.telephone = query.value("telephone").toInt();
            client.total_points = query.value("total_points").toInt();

            return client; // Retourner le client trouvé
        }
    }
    return Client(); // Retourner un client vide si non trouvé

}


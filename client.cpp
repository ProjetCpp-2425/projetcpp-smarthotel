#include "Client.h"
#include<QString>
#include "mainwindow.h"
#include "QSqlQuery"
#include<QSqlQueryModel>
#include <QMap>
#include <QStandardItemModel>
#include<connection.h>
#include <QMessageBox>
#include<QSqlError>
#include <QDebug>
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
bool Client::supprimer(int id)
{
    QSqlQuery query;
    QString CIN = QString::number(id);

    query.prepare("DELETE FROM RESERVATIONS WHERE ID_client = :id");
    query.bindValue(":id", CIN);
    if (!query.exec()) {
        QMessageBox::information(nullptr, "Suppression", "Erreur lors de la suppression des réservations liées.");
        return false;
    }

    query.prepare("DELETE FROM CLIENTS WHERE ID_client = :id");
    query.bindValue(":id", CIN);
    if (query.exec()) {
        if (query.numRowsAffected() == 0) {
            QMessageBox::information(nullptr, "Suppression", "L'ID n'existe pas");
            return false;
        } else {
            return true;
        }
    }
    return false;
}


bool Client :: modifier (int id, const QString &nv_nom ,const QString &nv_prenom,const QDate &nv_date,const QString &nv_demande,const QString &nv_statut,const QString &nv_pays,const int &nv_tele,const int &nv_total)
{
    QSqlQuery query;
    query.prepare(" update CLIENTS set nom= :nom, prenom= :prenom, date_naissance= :date_naissance, demande_special= :demande_special, statut= :statut, pays= :pays, telephone= :telephone, total_points= :total_points where ID_client=:id");
    query.bindValue(":id",id);
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
Client Client::chercher(const QString& critere, const QVariant& valeurRecherche)
{
    QSqlQuery query;
    if (critere== "id")
    {
        query.prepare("SELECT * FROM CLIENTS WHERE ID_client = :id");
        query.bindValue(":id", valeurRecherche);
    }
    else if (critere == "nom")
    {
        query.prepare("SELECT * FROM CLIENTS WHERE nom = :nom");
        query.bindValue(":nom", valeurRecherche);
    }
    if (query.exec())
    {
        if (query.next())
        {
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
            return client;
        }
    }
    return Client();

}
QSqlQueryModel* Client::trier(const QString& critere)
{
    QSqlQueryModel *model = new QSqlQueryModel ();
    QString queryStr;

    if (critere == "statut") {
        queryStr = R"(
            SELECT * FROM CLIENTS ORDER BY CASE STATUT
                WHEN 'en attente' THEN 1
                WHEN 'en cours' THEN 2
                WHEN 'termine' THEN 3
                WHEN 'rejete' THEN 4
                ELSE 5
            END ASC
        )";
    }
    else if (critere == "date_de_naissance") {
        queryStr = R"(
            SELECT * FROM CLIENTS ORDER BY DATE_NAISSANCE DESC
        )";
    }
    else if (critere == "total_points") {
        queryStr = R"(
            SELECT * FROM CLIENTS ORDER BY TOTAL_POINTS DESC
        )";
    }
    model->setQuery(queryStr);
    return model;
}

QMap<QString, int> Client::statistiquesParPays()
{
    QMap<QString, int> statistiques;
    QSqlQuery query;
    query.prepare("SELECT pays, COUNT(*) AS nombre_clients FROM CLIENTS GROUP BY pays");

    if (query.exec())
    {
        while (query.next())
        {
            QString pays = query.value(0).toString();
            int nombre_clients = query.value(1).toInt();
            statistiques.insert(pays, nombre_clients);
        }
    }
    return statistiques;
}

QSqlQueryModel* Client::his_reservation()
{
    QSqlQuery query;

    query.prepare("SELECT r.ID_reservation, r.date_reservation, r.date_arrivé, r.date_depart, "
                  "c.ID_client, c.nom, c.prenom, c.demande_special "
                  "FROM RESERVATIONS r "
                  "LEFT JOIN CLIENTS c ON r.ID_client = c.ID_client");

    if (!query.exec())
    {
        QMessageBox::information(nullptr, "Erreur", "Erreur lors de la récupération des réservations.");
        return nullptr;
    }

    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(std::move(query));

    if (model->rowCount() == 0)
    {
        QMessageBox::information(nullptr, "Aucune réservation", "Aucune réservation trouvée pour ce client");
    }

    return model;
}

Client Client::afficherClientPlusFidele()
{
    QSqlQuery query;
    QString sql =
        "SELECT * FROM CLIENTS "
        "WHERE total_points = (SELECT MAX(total_points) FROM CLIENTS)";

    query.prepare(sql);

    if (!query.exec())
    {
        qDebug() << "Erreur lors de la recherche du client le plus fidèle:" << query.lastError().text();
    }
    else
    {
        if (query.next())
        {
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
            return client;
        }
        else
        {
            qDebug() << "Aucun client trouvé.";
        }
    }
    return Client();
}

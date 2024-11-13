#include "maintenance.h"
#include <QString>
#include <QSqlError>
#include <QDebug>

Maintenance::Maintenance(int ID_MAINTENANCE ,int NUM_CHAMBRE_CONCERNEE, QString TYPE_MAINTENANCE, QDate DATE_DEBUT, QDate DATE_FIN, QString ETAT_MAINTENANCE,QString PRIORITE){
    this->ID_MAINTENANCE = ID_MAINTENANCE;
    this-> NUM_CHAMBRE_CONCERNEE=NUM_CHAMBRE_CONCERNEE;
    this-> TYPE_MAINTENANCE= TYPE_MAINTENANCE;
    this-> DATE_DEBUT =  DATE_DEBUT;
    this->DATE_FIN =DATE_FIN;
    this->ETAT_MAINTENANCE=ETAT_MAINTENANCE ;
    this->PRIORITE=PRIORITE ;

}
    bool Maintenance::ajouter() {
        QSqlQuery query;
        query.prepare("INSERT INTO MAINTENANCES (ID_MAINTENANCE, NUM_CHAMBRE_CONCERNEE, TYPE_MAINTENANCE, DATE_DEBUT, DATE_FIN, ETAT_MAINTENANCE,PRIORITE) "
                      "VALUES (:ID_MAINTENANCE, :NUM_CHAMBRE_CONCERNEE, :TYPE_MAINTENANCE, :DATE_DEBUT, :DATE_FIN, :ETAT_MAINTENANCE, :PRIORITE)");

        query.bindValue(":ID_MAINTENANCE", ID_MAINTENANCE);
        query.bindValue(":NUM_CHAMBRE_CONCERNEE",NUM_CHAMBRE_CONCERNEE );
        query.bindValue(":TYPE_MAINTENANCE", TYPE_MAINTENANCE);
        query.bindValue(":DATE_DEBUT",DATE_DEBUT);
        query.bindValue(":DATE_FIN", DATE_FIN);
        query.bindValue(":ETAT_MAINTENANCE", ETAT_MAINTENANCE);
        query.bindValue(":PRIORITE", PRIORITE);

        if (query.exec()) {
            return true;
        } else {
            qDebug() << "Erreur SQL : " << query.lastError().text();
            return false;
        }
    }

    QSqlQueryModel* Maintenance::afficher() {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM MAINTENANCES");  // Ensure table name matches your database

        // Check if the query was successful
        if (!model->query().isActive()) {
            qDebug() << "Failed to execute afficher query:" << model->query().lastError();
        } else {
            qDebug() << "afficher query executed successfully";
        }

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_maintenance"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("num_chambre_concernee"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_maintenance"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_debut"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_fin"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("etat_maintenance"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Priorite"));

        return model;
    }


bool Maintenance::supprimer(int id_maintenance) {
    QSqlQuery query;
    QString res=QString::number(id_maintenance);
    query.prepare("DELETE FROM MAINTENANCES WHERE ID_MAINTENANCE = :id_maintenance");
    query.bindValue(":id_maintenance", res);
    return query.exec();
}


bool Maintenance::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE MAINTENANCES SET "
                  "NUM_CHAMBRE_CONCERNEE = :NUM_CHAMBRE_CONCERNEE, "
                  "TYPE_MAINTENANCE = :TYPE_MAINTENANCE, "
                  "DATE_DEBUT = :DATE_DEBUT, "
                  "DATE_FIN = :DATE_FIN, "
                  "ETAT_MAINTENANCE = :ETAT_MAINTENANCE, "
                  "PRIORITE = :PRIORITE "
                  "WHERE ID_MAINTENANCE = :ID_MAINTENANCE");
    query.bindValue(":ID_MAINTENANCE", ID_MAINTENANCE);
    query.bindValue(":NUM_CHAMBRE_CONCERNEE",NUM_CHAMBRE_CONCERNEE );
    query.bindValue(":TYPE_MAINTENANCE", TYPE_MAINTENANCE);
    query.bindValue(":DATE_DEBUT",DATE_DEBUT);
    query.bindValue(":DATE_FIN", DATE_FIN);
    query.bindValue(":ETAT_MAINTENANCE", ETAT_MAINTENANCE);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de la maintenance:" << query.lastError().text();
        return false;
    }
    return true;
}



QSqlQueryModel* Maintenance::trierParPriorite(const QString &priorite)
{
    // Créer un modèle pour afficher les résultats triés
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Préparer la requête SQL pour trier les maintenances par PRIORITE
    query.prepare("SELECT ID_MAINTENANCE, NUM_CHAMBRE_CONCERNEE, TYPE_MAINTENANCE, DATE_DEBUT, DATE_FIN, ETAT_MAINTENANCE, PRIORITE "
                  "FROM MAINTENANCES WHERE PRIORITE = :priorite ORDER BY PRIORITE ASC");
    query.bindValue(":priorite", priorite);

    // Exécuter la requête
    if (query.exec()) {
        model->setQuery(query);  // Charger les résultats dans le modèle
    } else {
        qDebug() << "Error while sorting by PRIORITE:" << query.lastError();  // Afficher l'erreur si la requête échoue
    }

    return model;  // Retourner le modèle avec les résultats triés

}
QSqlQueryModel* Maintenance::rechercherParID(int ID_MAINTENANCE)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Préparer la requête SQL pour chercher par ID_MAINTENANCE
    query.prepare("SELECT ID_MAINTENANCE, NUM_CHAMBRE_CONCERNEE, TYPE_MAINTENANCE, DATE_DEBUT, DATE_FIN, ETAT_MAINTENANCE, PRIORITE "
                  "FROM MAINTENANCES WHERE ID_MAINTENANCE = :id_maintenance");
    query.bindValue(":id_maintenance", ID_MAINTENANCE);

    // Exécuter la requête
    if (query.exec()) {
        model->setQuery(query);  // Charger les résultats dans le modèle
    } else {
        qDebug() << "Error while searching by ID:" << query.lastError();  // Afficher l'erreur si la requête échoue
    }

    return model;  // Retourner le modèle avec les résultats
}


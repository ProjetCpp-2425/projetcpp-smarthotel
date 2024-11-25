#include "maintenance.h"
#include <QString>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QTextCharFormat>
#include <QColor>

Maintenance::Maintenance(int ID_MAINTENANCE , QString ID_EMPLOYE, int NUM_CHAMBRE_CONCERNEE, QString TYPE_MAINTENANCE, QDate DATE_DEBUT, QDate DATE_FIN, QString ETAT_MAINTENANCE, QString PRIORITE){
    this->ID_MAINTENANCE = ID_MAINTENANCE;
    this-> ID_EMPLOYE= ID_EMPLOYE;
    this-> NUM_CHAMBRE_CONCERNEE=NUM_CHAMBRE_CONCERNEE;
    this-> TYPE_MAINTENANCE= TYPE_MAINTENANCE;
    this-> DATE_DEBUT =  DATE_DEBUT;
    this->DATE_FIN =DATE_FIN;
    this->ETAT_MAINTENANCE=ETAT_MAINTENANCE ;
    this->PRIORITE=PRIORITE ;

}
bool Maintenance::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO MAINTENANCES (ID_MAINTENANCE, ID_EMPLOYE, NUM_CHAMBRE_CONCERNEE, TYPE_MAINTENANCE, DATE_DEBUT, DATE_FIN, ETAT_MAINTENANCE, PRIORITE) "
                  "VALUES (:id_maintenance, :id_employe, :num_chambre, :type_maintenance, :date_debut, :date_fin, :etat_maintenance, :priorite)");
    query.bindValue(":id_maintenance", ID_MAINTENANCE);
    query.bindValue(":id_employe", ID_EMPLOYE);
    query.bindValue(":num_chambre", NUM_CHAMBRE_CONCERNEE);
    query.bindValue(":type_maintenance", TYPE_MAINTENANCE);
    query.bindValue(":date_debut", DATE_DEBUT); // Conversion en chaîne
    query.bindValue(":date_fin", DATE_FIN);      // Conversion en chaîne
    query.bindValue(":etat_maintenance", ETAT_MAINTENANCE);
    query.bindValue(":priorite", PRIORITE);

    return query.exec();
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
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_employe"));

        model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_chambre_concernee"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_maintenance"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_debut"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_fin"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("etat_maintenance"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Priorite"));

        return model;
    }


bool Maintenance::supprimer(int id_maintenance) {
    QSqlQuery query;
    QString res=QString::number(id_maintenance);
    query.prepare("DELETE FROM MAINTENANCES WHERE ID_MAINTENANCE = :id_maintenance");
    query.bindValue(":id_maintenance", res);
    return query.exec();
}

bool Maintenance::existe(int id) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM MAINTENANCES WHERE ID_MAINTENANCE = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}

bool Maintenance::modifier() {
    QSqlQuery query;

    // Préparer la requête SQL pour modifier les informations d'une maintenance spécifique
    query.prepare("UPDATE MAINTENANCES SET "
                  "ID_EMPLOYE = :ID_EMPLOYE, "
                  "NUM_CHAMBRE_CONCERNEE = :NUM_CHAMBRE_CONCERNEE, "
                  "TYPE_MAINTENANCE = :TYPE_MAINTENANCE, "
                  "DATE_DEBUT = :DATE_DEBUT, "
                  "DATE_FIN = :DATE_FIN, "
                  "ETAT_MAINTENANCE = :ETAT_MAINTENANCE, "
                  "PRIORITE = :PRIORITE "
                  "WHERE ID_MAINTENANCE = :ID_MAINTENANCE");

    // Lier les nouvelles valeurs aux placeholders dans la requête
    query.bindValue(":ID_MAINTENANCE", ID_MAINTENANCE);  // ID de la maintenance à modifier
    query.bindValue(":ID_EMPLOYE", ID_EMPLOYE);
    query.bindValue(":NUM_CHAMBRE_CONCERNEE", NUM_CHAMBRE_CONCERNEE);
    query.bindValue(":TYPE_MAINTENANCE", TYPE_MAINTENANCE);
    query.bindValue(":DATE_DEBUT", DATE_DEBUT);
    query.bindValue(":DATE_FIN", DATE_FIN);
    query.bindValue(":ETAT_MAINTENANCE", ETAT_MAINTENANCE);
    query.bindValue(":PRIORITE", PRIORITE);

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de la maintenance:" << query.lastError().text();
        return false;  // Retourner false si une erreur se produit
    }

    return true;  // Retourner true si la mise à jour a réussi
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



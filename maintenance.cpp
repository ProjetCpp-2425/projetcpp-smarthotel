#include "maintenance.h"
#include <QString>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QTextCharFormat>
#include <QColor>

Maintenance::Maintenance(int ID_MAINTENANCE , QString ID_EMPLOYE, int NUM_CHAMBRE_CONCERNEE, QString TYPE_MAINTENANCE, QDate DATE_DEBUT, QDate DATE_FIN, QString ETAT_MAINTENANCE, QString PRIORITE, QDateTime DATE_RAPPEL, QString DESCRIPTION_RAPPEL) {
    this->ID_MAINTENANCE = ID_MAINTENANCE;
    this-> ID_EMPLOYE= ID_EMPLOYE;
    this-> NUM_CHAMBRE_CONCERNEE=NUM_CHAMBRE_CONCERNEE;
    this-> TYPE_MAINTENANCE= TYPE_MAINTENANCE;
    this-> DATE_DEBUT =  DATE_DEBUT;
    this->DATE_FIN =DATE_FIN;
    this->ETAT_MAINTENANCE=ETAT_MAINTENANCE ;
    this->PRIORITE=PRIORITE ;
    this->DATE_RAPPEL = DATE_RAPPEL; // Initialiser le rappel
    this->DESCRIPTION_RAPPEL = DESCRIPTION_RAPPEL; // Initialiser la description
}
bool Maintenance::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO MAINTENANCES (ID_MAINTENANCE, ID_EMPLOYE, NUM_CHAMBRE_CONCERNEE, TYPE_MAINTENANCE, DATE_DEBUT, DATE_FIN, ETAT_MAINTENANCE, PRIORITE,DATE_RAPPEL,DESCRIPTION_RAPPEL) "
                  "VALUES (:id_maintenance, :id_employe, :num_chambre, :type_maintenance, :date_debut, :date_fin, :etat_maintenance, :priorite, :date_rappel, :description_rappel)");
    query.bindValue(":id_maintenance", ID_MAINTENANCE);
    query.bindValue(":id_employe", ID_EMPLOYE);
    query.bindValue(":num_chambre", NUM_CHAMBRE_CONCERNEE);
    query.bindValue(":type_maintenance", TYPE_MAINTENANCE);
    query.bindValue(":date_debut", DATE_DEBUT);
    query.bindValue(":date_fin", DATE_FIN);
    query.bindValue(":etat_maintenance", ETAT_MAINTENANCE);
    query.bindValue(":priorite", PRIORITE);
    query.bindValue(":date_rappel",DATE_RAPPEL);
    query.bindValue(":description_rappel",DESCRIPTION_RAPPEL);

    return query.exec();
}


    QSqlQueryModel* Maintenance::afficher() {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM MAINTENANCES");  // Ensure table name matches your database
        if (!model->query().isActive()) {
            qDebug() << "Failed to execute afficher query:" << model->query().lastError();
        } else {
            qDebug() << "afficher query executed successfully";
        }

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_maintenance"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_employe"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_chambre"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_maintenance"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_debut"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_fin"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("etat_maintenance"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("priorite"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("date_rappel"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("description_rappel"));


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
    query.prepare("UPDATE MAINTENANCES SET "
                  "ID_EMPLOYE = :ID_EMPLOYE, "
                  "NUM_CHAMBRE_CONCERNEE = :NUM_CHAMBRE_CONCERNEE, "
                  "TYPE_MAINTENANCE = :TYPE_MAINTENANCE, "
                  "DATE_DEBUT = :DATE_DEBUT, "
                  "DATE_FIN = :DATE_FIN, "
                  "ETAT_MAINTENANCE = :ETAT_MAINTENANCE, "
                  "PRIORITE = :PRIORITE "
                  "WHERE ID_MAINTENANCE = :ID_MAINTENANCE");
    query.bindValue(":ID_MAINTENANCE", ID_MAINTENANCE);  // ID de la maintenance à modifier
    query.bindValue(":ID_EMPLOYE", ID_EMPLOYE);
    query.bindValue(":NUM_CHAMBRE_CONCERNEE", NUM_CHAMBRE_CONCERNEE);
    query.bindValue(":TYPE_MAINTENANCE", TYPE_MAINTENANCE);
    query.bindValue(":DATE_DEBUT", DATE_DEBUT);
    query.bindValue(":DATE_FIN", DATE_FIN);
    query.bindValue(":ETAT_MAINTENANCE", ETAT_MAINTENANCE);
    query.bindValue(":PRIORITE", PRIORITE);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de la maintenance:" << query.lastError().text();
        return false;  // Retourner false si une erreur se produit
    }

    return true;  // Retourner true si la mise à jour a réussi
}




QSqlQueryModel* Maintenance::trierParPriorite(const QString &priorite)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID_MAINTENANCE, NUM_CHAMBRE_CONCERNEE, TYPE_MAINTENANCE, DATE_DEBUT, DATE_FIN, ETAT_MAINTENANCE, PRIORITE "
                  "FROM MAINTENANCES WHERE PRIORITE = :priorite ORDER BY PRIORITE ASC");
    query.bindValue(":priorite", priorite);

    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Error while sorting by PRIORITE:" << query.lastError();
    }

    return model;

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
        model->setQuery(query);
    } else {
        qDebug() << "Error while searching by ID:" << query.lastError();  // Afficher l'erreur si la requête échoue
    }

    return model;  // Retourner le modèle avec les résultats
}

QSqlQueryModel* Maintenance::rechercherParDescription(const QString &description)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID_MAINTENANCE, NUM_CHAMBRE_CONCERNEE, TYPE_MAINTENANCE, DATE_DEBUT, DATE_FIN, ETAT_MAINTENANCE, PRIORITE "
                  "FROM MAINTENANCES WHERE DESCRIPTION_RAPPEL LIKE :description");
    query.bindValue(":description", "%" + description + "%");

    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Error while searching by description:" << query.lastError();
    }

    return model;
}

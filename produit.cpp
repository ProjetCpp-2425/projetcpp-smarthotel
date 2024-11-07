#include "produit.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>

Produit::Produit(int id, QString nom, int quantite, QDate livraison, QDate reapprovisionnement)
    : id(id), nomProduit(nom), quantiteDispo(quantite), dateLivraison(livraison), dateReapprovisionnement(reapprovisionnement) {}

bool Produit::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO stocks (id, nomProduit, quantiteDispo, dateLivraison, dateReapprovisionnement) "
                  "VALUES (:id, :nom, :quantite, :livraison, :reapprovisionnement)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nomProduit);
    query.bindValue(":quantite", quantiteDispo);
    query.bindValue(":livraison", dateLivraison);
    query.bindValue(":reapprovisionnement", dateReapprovisionnement);
    return query.exec();
}

bool Produit::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM stocks WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();
}

QSqlQueryModel* Produit::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM stocks");
    return model;
}

bool Produit::modifier(int id) {
    QSqlQuery query;
    query.prepare("UPDATE stocks SET nomProduit = :nom, quantiteDispo = :quantite, "
                  "dateLivraison = :livraison, dateReapprovisionnement = :reapprovisionnement WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nomProduit);
    query.bindValue(":quantite", quantiteDispo);
    query.bindValue(":livraison", dateLivraison);
    query.bindValue(":reapprovisionnement", dateReapprovisionnement);
    return query.exec();
}

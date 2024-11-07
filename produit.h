// produit.h
#ifndef PRODUIT_H
#define PRODUIT_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Produit {
private:
    int id;
    QString nomProduit;
    int quantiteDispo;
    QDate dateLivraison;
    QDate dateReapprovisionnement;

public:
    Produit(); // Constructeur par défaut
    Produit(int id, QString nom, int quantite, QDate livraison, QDate reapprovisionnement);
    bool ajouter();   // Create
    bool supprimer(int id);  // Delete
    static QSqlQueryModel* afficher();  // Read
    bool modifier(int id);  // Update

    // Getters and setters as needed
};

#endif

#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employe {
public:

    Employe();

    Employe(int ID_EMPLOYE, QString NOM, QString PRENOM, float SALAIRE,
                     QString POSTE, int TELEPHONE, int PRESENCES,
            QDate D_DATE, QDate F_DATE);


    bool ajouter();
    bool modifier(int ID_EMPLOYE, QString NOM, QString PRENOM, float SALAIRE,
                  QString POSTE, int TELEPHONE, int PRESENCES,
                  QDate D_DATE, QDate F_DATE);
    bool supprimer(int id);
    QSqlQueryModel *afficher();
    Employe rechercher(int id);


    QString getNom() const;
    QString getPrenom() const;
    float getSalaire() const;
    QString getPoste() const;
    int getTelephone() const;
    int getPresences() const;
    QDate getDDate() const;
    QDate getFDate() const;
    int getIdEmploye() const;

    // Setters
    void setNom(const QString &nom);
    void setPrenom(const QString &prenom);
    void setSalaire(float salaire);
    void setPoste(const QString &poste);
    void setTelephone(int telephone);
    void setPresences(int presences);
    void setDDate(const QDate &d_date);
    void setFDate(const QDate &f_date);
    void setIdEmploye(int id_employe);

private:
    int ID_EMPLOYE;
    QString NOM;
    QString PRENOM;
    float SALAIRE;
    QString POSTE;
    int TELEPHONE;
    int PRESENCES;
    QDate D_DATE;
    QDate F_DATE;
};

#endif


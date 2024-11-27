#ifndef RESERVATION_H
#define RESERVATION_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Reservation {
public:

    Reservation();
    Reservation(int ID_RESERVATION, QDate DATE_RESERVATION, QDate DATE_ARRIVE, QDate DATE_DEPART,
                QString TYPE_CHAMBRE, QString STATUT_RESERVATION, QString MODE_PAIMENT,
                float MONTANT,int ID_CLIENT);


    bool ajouter();
    bool modifier(int ID_RESERVATION, QDate DATE_RESERVATION, QDate DATE_ARRIVE, QDate DATE_DEPART,
                  QString TYPE_CHAMBRE, QString STATUT_RESERVATION, QString MODE_PAIMENT,
                  float MONTANT,int ID_CLIENT);
    bool supprimer(int id);
    QSqlQueryModel* afficher();
    bool rechercher(int id);


    int getIdReservation() const;
    QDate getDateReservation() const;
    QDate getDateArrive() const;
    QDate getDateDepart() const;
    QString getTypeChambre() const;
    QString getStatutReservation() const;
    QString getModePaiment() const;
    float getMontant() const;
    int getIdclient() const;

    void setIdReservation(int id_reservation);
    void setDateReservation(const QDate &date_reservation);
    void setDateArrive(const QDate &date_arrive);
    void setDateDepart(const QDate &date_depart);
    void setTypeChambre(const QString &type_chambre);
    void setStatutReservation(const QString &statut_reservation);
    void setModePaiment(const QString &mode_paiment);
    void setMontant(float montant);
    void setIDclient(int id_client);
    QSqlQueryModel* trierPar(const QString &critere);
    QMap<QString, int> obtenirStatistiquesTypeChambre();

private:
    int ID_RESERVATION;
    QDate DATE_RESERVATION;
    QDate DATE_ARRIVE;
    QDate DATE_DEPART;
    QString TYPE_CHAMBRE;
    QString STATUT_RESERVATION;
    QString MODE_PAIMENT;
    float MONTANT;
    int ID_CLIENT;
};

#endif

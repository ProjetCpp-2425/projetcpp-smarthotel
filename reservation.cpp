#include "reservation.h"
#include "connection.h"
#include <QMessageBox>
#include <QtWidgets>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>

Reservation::Reservation() {}

Reservation::Reservation(int ID_RESERVATION, QDate DATE_RESERVATION, QDate DATE_ARRIVE,
                         QDate DATE_DEPART, QString TYPE_CHAMBRE, QString STATUT_RESERVATION,
                         QString MODE_PAIMENT, float MONTANT,int ID_CLIENT , QString UID_CARTE)
    : ID_RESERVATION(ID_RESERVATION), DATE_RESERVATION(DATE_RESERVATION), DATE_ARRIVE(DATE_ARRIVE),
    DATE_DEPART(DATE_DEPART), TYPE_CHAMBRE(TYPE_CHAMBRE), STATUT_RESERVATION(STATUT_RESERVATION),
    MODE_PAIMENT(MODE_PAIMENT), MONTANT(MONTANT) , ID_CLIENT(ID_CLIENT) ,UID_CARTE(UID_CARTE) {}



int Reservation::getIdReservation() const { return ID_RESERVATION; }
QDate Reservation::getDateReservation() const { return DATE_RESERVATION; }
QDate Reservation::getDateArrive() const { return DATE_ARRIVE; }
QDate Reservation::getDateDepart() const { return DATE_DEPART; }
QString Reservation::getTypeChambre() const { return TYPE_CHAMBRE; }
QString Reservation::getStatutReservation() const { return STATUT_RESERVATION; }
QString Reservation::getModePaiment() const { return MODE_PAIMENT; }
float Reservation::getMontant() const { return MONTANT; }
int Reservation::getIdclient() const { return ID_CLIENT; }
QString Reservation::getUidcarte() const { return UID_CARTE; }

void Reservation::setIdReservation(int id_reservation) { ID_RESERVATION = id_reservation; }
void Reservation::setDateReservation(const QDate &date_reservation) { DATE_RESERVATION = date_reservation; }
void Reservation::setDateArrive(const QDate &date_arrive) { DATE_ARRIVE = date_arrive; }
void Reservation::setDateDepart(const QDate &date_depart) { DATE_DEPART = date_depart; }
void Reservation::setTypeChambre(const QString &type_chambre) { TYPE_CHAMBRE = type_chambre; }
void Reservation::setStatutReservation(const QString &statut_reservation) { STATUT_RESERVATION = statut_reservation; }
void Reservation::setModePaiment(const QString &mode_paiment) { MODE_PAIMENT = mode_paiment; }
void Reservation::setMontant(float montant) { MONTANT = montant; }
void Reservation::setIDclient(int id_client) { ID_CLIENT = id_client; }
void Reservation::setUidcarte(QString uid) { UID_CARTE = uid; }

bool Reservation::ajouter() {
    QSqlQuery query;
    if (ID_RESERVATION <= 0) {
        QMessageBox::warning(nullptr, "Erreur", "L'ID_RESERVATION doit être un nombre positif.");
        return false;
    }


    if (MONTANT <= 0) {
        QMessageBox::warning(nullptr, "Erreur", "Le montant doit être un nombre positif.");
        return false;
    }


    query.prepare("INSERT INTO RESERVATIONS (\"ID_RESERVATION\", \"DATE_RESERVATION\", \"DATE_ARRIVE\", \"DATE_DEPART\", "
                  "\"TYPE_CHAMBRE\", \"STATUT_RESERVATION\", \"MODE_PAIMENT\", \"MONTANT\" ,\"ID_CLIENT\" ,\"UID_CARTE\") "
                  "VALUES (:ID_RESERVATION, TO_DATE(:DATE_RESERVATION, 'YYYY-MM-DD'), "
                  "TO_DATE(:DATE_ARRIVE, 'YYYY-MM-DD'), TO_DATE(:DATE_DEPART, 'YYYY-MM-DD'), "
                  ":TYPE_CHAMBRE, :STATUT_RESERVATION, :MODE_PAIMENT, :MONTANT ,:ID_CLIENT , :UID_CARTE)");


    query.bindValue(":ID_RESERVATION", ID_RESERVATION);
    query.bindValue(":DATE_RESERVATION", DATE_RESERVATION.toString("yyyy-MM-dd"));
    query.bindValue(":DATE_ARRIVE", DATE_ARRIVE.toString("yyyy-MM-dd"));
    query.bindValue(":DATE_DEPART", DATE_DEPART.toString("yyyy-MM-dd"));
    query.bindValue(":TYPE_CHAMBRE", TYPE_CHAMBRE);
    query.bindValue(":STATUT_RESERVATION", STATUT_RESERVATION);
    query.bindValue(":MODE_PAIMENT", MODE_PAIMENT);
    query.bindValue(":MONTANT", MONTANT);
    query.bindValue(":ID_CLIENT", ID_CLIENT);
    query.bindValue(":UID_CARTE", UID_CARTE);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'insertion de la réservation : " << query.lastError().text();
        return false;
    }

    return true;
}



bool Reservation::modifier(int ID_RESERVATION, QDate DATE_RESERVATION, QDate DATE_ARRIVE, QDate DATE_DEPART,
                           QString TYPE_CHAMBRE, QString STATUT_RESERVATION, QString MODE_PAIMENT,
                           float MONTANT , int ID_CLIENT ,  QString UID_CARTE) {
    QSqlQuery query;
    if (ID_RESERVATION <= 0) {
        QMessageBox::warning(nullptr, "Erreur", "L'ID_RESERVATION doit être un nombre positif.");
        return false;
    }


    if (MONTANT <= 0) {
        QMessageBox::warning(nullptr, "Erreur", "Le montant doit être un nombre positif.");
        return false;
    }


    query.prepare("UPDATE RESERVATIONS SET "
                  "\"DATE_RESERVATION\" = TO_DATE(:DATE_RESERVATION, 'YYYY-MM-DD'), "
                  "\"DATE_ARRIVE\" = TO_DATE(:DATE_ARRIVE, 'YYYY-MM-DD'), "
                  "\"DATE_DEPART\" = TO_DATE(:DATE_DEPART, 'YYYY-MM-DD'), "
                  "\"TYPE_CHAMBRE\" = :TYPE_CHAMBRE, "
                  "\"STATUT_RESERVATION\" = :STATUT_RESERVATION, "
                  "\"MODE_PAIMENT\" = :MODE_PAIMENT, "
                  "\"MONTANT\" = :MONTANT ,"
                  "\"UID_CARTE\" = :UID_CARTE ,"
                  "WHERE \"ID_RESERVATION\" = :ID_RESERVATION");


    query.bindValue(":ID_RESERVATION", ID_RESERVATION);
    query.bindValue(":DATE_RESERVATION", DATE_RESERVATION.toString("yyyy-MM-dd"));
    query.bindValue(":DATE_ARRIVE", DATE_ARRIVE.toString("yyyy-MM-dd"));
    query.bindValue(":DATE_DEPART", DATE_DEPART.toString("yyyy-MM-dd"));
    query.bindValue(":TYPE_CHAMBRE", TYPE_CHAMBRE);
    query.bindValue(":STATUT_RESERVATION", STATUT_RESERVATION);
    query.bindValue(":MODE_PAIMENT", MODE_PAIMENT);
    query.bindValue(":MONTANT", MONTANT);
    query.bindValue(":ID_CLIENT", ID_CLIENT);
    query.bindValue(":UID_CARTE", UID_CARTE);



    if (!query.exec()) {
        qDebug() << "Erreur lors de la mise à jour de la réservation : " << query.lastError().text();
        return false;
    }

    return true;
}



bool Reservation::supprimer(int ID_RESERVATION) {
    QSqlQuery query;
    query.prepare("DELETE FROM RESERVATIONS WHERE ID_RESERVATION=:ID_RESERVATION");
    query.bindValue(":ID_RESERVATION", ID_RESERVATION);

    return query.exec();
}

QSqlQueryModel* Reservation::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM RESERVATIONS");
    return model;
}

bool Reservation::rechercher(int ID_RESERVATION) {
    QSqlQuery query;
    query.prepare("SELECT * FROM RESERVATIONS WHERE ID_RESERVATION = :ID_RESERVATION");
    query.bindValue(":ID_RESERVATION", ID_RESERVATION);

    if(query.exec() && query.next()) {
        DATE_RESERVATION = query.value("DATE_RESERVATION").toDate();
        DATE_ARRIVE = query.value("DATE_ARRIVE").toDate();
        DATE_DEPART = query.value("DATE_DEPART").toDate();
        TYPE_CHAMBRE = query.value("TYPE_CHAMBRE").toString();
        STATUT_RESERVATION = query.value("STATUT_RESERVATION").toString();
        MODE_PAIMENT = query.value("MODE_PAIMENT").toString();
        MONTANT = query.value("MONTANT").toInt();
        return true;
    }
    return false;
}
QSqlQueryModel* Reservation::trierPar(const QString &critere) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QString query = QString("SELECT * FROM reservations ORDER BY %1").arg(critere);
    model->setQuery(query);

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors du tri :" << model->lastError();
        return nullptr;
    }

    return model;
}
QMap<QString, int> Reservation::obtenirStatistiquesTypeChambre() {
    QMap<QString, int> statistiques;
    QSqlQuery query("SELECT TYPE_CHAMBRE, COUNT(*) FROM reservations GROUP BY TYPE_CHAMBRE");

    while (query.next()) {
        QString typeChambre = query.value(0).toString();
        int count = query.value(1).toInt();
        statistiques[typeChambre] = count;
    }

    return statistiques;
}

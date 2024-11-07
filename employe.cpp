#include "employe.h"
#include<QSqlError>
Employe::Employe() {

    ID_EMPLOYE=0;
    NOM="";
    PRENOM="";
    SALAIRE=0;
    POSTE="Receptionniste";
    TELEPHONE=0;
    PRESENCES=0;



}


Employe::Employe(int ID_EMPLOYE, QString NOM, QString PRENOM, float SALAIRE,
                 QString POSTE, int TELEPHONE, int PRESENCES,
                 QDate D_DATE, QDate F_DATE)
    : ID_EMPLOYE(ID_EMPLOYE), NOM(NOM), PRENOM(PRENOM), SALAIRE(SALAIRE), POSTE(POSTE),
    TELEPHONE(TELEPHONE), PRESENCES(PRESENCES), D_DATE(D_DATE),
    F_DATE(F_DATE) {}

QString Employe::getNom() const { return NOM; }
QString Employe::getPrenom() const { return PRENOM; }
float Employe::getSalaire() const { return SALAIRE; }
QString Employe::getPoste() const { return POSTE; }
int Employe::getTelephone() const { return TELEPHONE; }
int Employe::getPresences() const { return PRESENCES; }
QDate Employe::getDDate() const { return D_DATE; }
QDate Employe::getFDate() const { return F_DATE; }
int Employe::getIdEmploye() const { return ID_EMPLOYE; }

// Setters
void Employe::setNom(const QString &nom) { NOM = nom; }
void Employe::setPrenom(const QString &prenom) { PRENOM = prenom; }
void Employe::setSalaire(float salaire) { SALAIRE = salaire; }
void Employe::setPoste(const QString &poste) { POSTE = poste; }
void Employe::setTelephone(int telephone) { TELEPHONE = telephone; }
void Employe::setPresences(int presences) { PRESENCES = presences; }
void Employe::setDDate(const QDate &d_date) { D_DATE = d_date; }
void Employe::setFDate(const QDate &f_date) { F_DATE = f_date; }
void Employe::setIdEmploye(int id_employe) { ID_EMPLOYE = id_employe; }


bool Employe::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYES (ID_EMPLOYE, NOM, PRENOM , SALAIRE , POSTE , TELEPHONE , PRESENCES , D_DATE , F_DATE) "
                  "VALUES  (:ID_EMPLOYE, :NOM, :PRENOM , :SALAIRE , :POSTE , :TELEPHONE , :PRESENCES , :D_DATE , :F_DATE) ");
    query.bindValue(":ID_EMPLOYE", ID_EMPLOYE);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM );
    query.bindValue(":SALAIRE", SALAIRE);
    query.bindValue(":POSTE", POSTE);
    query.bindValue(":TELEPHONE", TELEPHONE);
    query.bindValue(":PRESENCES", PRESENCES);
    query.bindValue(":D_DATE", D_DATE);
    query.bindValue(":F_DATE", F_DATE);




    return query.exec();
}

bool Employe::modifier(int ID_EMPLOYE, QString NOM, QString PRENOM, float SALAIRE,
                       QString POSTE, int TELEPHONE, int PRESENCES,
                       QDate D_DATE, QDate F_DATE) {
    QSqlQuery query;
    query.prepare("UPDATE employes SET NOM=:NOM, PRENOM=:PRENOM, SALAIRE=:SALAIRE, POSTE=:POSTE, TELEPHONE=:TELEPHONE, PRESENCES=:PRESENCES , D_DATE=:D_DATE, F_DATE=:F_DATE "
                  "WHERE ID_EMPLOYE=:ID_EMPLOYE");
    query.bindValue(":ID_EMPLOYE", ID_EMPLOYE);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM );
    query.bindValue(":SALAIRE", SALAIRE);
    query.bindValue(":POSTE", POSTE);
    query.bindValue(":TELEPHONE", TELEPHONE);
    query.bindValue(":PRESENCES", PRESENCES);
    query.bindValue(":D_DATE", D_DATE);
    query.bindValue(":F_DATE", F_DATE);




    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de l'employé:" << query.lastError().text();
        return false;
    }

    return query.exec();
}

bool Employe::supprimer(int ID_EMPLOYE) {
    QSqlQuery query;
    query.prepare("DELETE FROM employes WHERE ID_EMPLOYE=:ID_EMPLOYE");
    query.bindValue(":ID_EMPLOYE", ID_EMPLOYE);

    return query.exec();
}




QSqlQueryModel *Employe::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYES");
    return model;
}
Employe Employe::rechercher(int ID_EMPLOYE) {
    QSqlQuery query;
    query.prepare("SELECT * FROM employes WHERE ID_EMPLOYE = :ID_EMPLOYE");
    query.bindValue(":ID_EMPLOYE", ID_EMPLOYE);

    if (query.exec() && query.next()) {

        this->ID_EMPLOYE = query.value("ID_EMPLOYE").toInt();
        this->NOM = query.value("NOM").toString();
        this->PRENOM = query.value("PRENOM").toString();
        this->SALAIRE = query.value("SALAIRE").toFloat();
        this->POSTE = query.value("POSTE").toString();
        this->TELEPHONE = query.value("TELEPHONE").toInt();
        this->PRESENCES = query.value("PRESENCES").toInt();
        this->D_DATE = query.value("D_DATE").toDate();
        this->F_DATE = query.value("F_DATE").toDate();

        return *this;
    }

    return Employe();
}




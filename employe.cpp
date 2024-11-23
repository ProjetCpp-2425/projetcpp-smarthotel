#include "employe.h"
#include<QSqlError>
#include <QMessageBox>
#include <QDate>
#include <QRandomGenerator>


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
    if (ID_EMPLOYE>9999 || ID_EMPLOYE<1000 ) {
        QMessageBox::warning(nullptr, "Erreur", "L'ID de l'employé doit être composer de 4 chiffres.");
        return false;
    }
    int premierChiffre = TELEPHONE / 10000000;
    if ((TELEPHONE > 99999999 || TELEPHONE < 10000000) ||
        !(premierChiffre == 2 || premierChiffre == 3 || premierChiffre == 5 || premierChiffre == 7 || premierChiffre == 9)) {
        QMessageBox::warning(nullptr, "Erreur", "Le numéro de téléphone doit être composé de 8 chiffres et commencer par 2, 3, 5, 7, ou 9.");
        return false;
    }
    if (SALAIRE>10000 || SALAIRE<1000 ) {
        QMessageBox::warning(nullptr, "Erreur", "Le salaire doit être entre 1000 et 10000.");
        return false;
    }
    for (int i = 0; i < NOM.length(); ++i) {
        QChar ch = NOM[i];

        if (!ch.isLetter() && !ch.isSpace()) {
            QMessageBox::warning(nullptr, "Erreur", "Le nom doit contenir uniquement des lettres et des espaces.");
            return false;
        }
    }


    for (int i = 0; i < PRENOM.length(); ++i) {
        QChar ch = PRENOM[i];

        if (!ch.isLetter() && !ch.isSpace()) {
            QMessageBox::warning(nullptr, "Erreur", "Le prénom doit contenir uniquement des lettres et des espaces.");
            return false;
        }
    }


    if (POSTE.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "Le poste de l'employé ne peut pas être vide.");
        return false;
    }


    if (PRESENCES < 0 || PRESENCES > 30) {
        QMessageBox::warning(nullptr, "Erreur", "Les présences de l'employé doivent être entre 0 et 30.");
        return false;
    }


    if (D_DATE.isNull() || F_DATE.isNull()) {
        QMessageBox::warning(nullptr, "Erreur", "Les dates de début et de fin de contrat ne peuvent pas être vides.");
        return false;
    } else if (D_DATE > F_DATE) {
        QMessageBox::warning(nullptr, "Erreur", "La date de début de contrat doit être antérieure à la date de fin de contrat.");
        return false;
    }





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
    if (ID_EMPLOYE>9999 || ID_EMPLOYE<1000 ) {
        QMessageBox::warning(nullptr, "Erreur", "L'ID de l'employé doit être composer de 4 chiffres.");
        return false;
    }
    int premierChiffre = TELEPHONE / 10000000;
    if ((TELEPHONE > 99999999 || TELEPHONE < 10000000) ||
        !(premierChiffre == 2 || premierChiffre == 3 || premierChiffre == 5 || premierChiffre == 7 || premierChiffre == 9)) {
        QMessageBox::warning(nullptr, "Erreur", "Le numéro de téléphone doit être composé de 8 chiffres et commencer par 2, 3, 5, 7, ou 9.");
        return false;
    }
    if (SALAIRE>10000 || SALAIRE<1000 ) {
        QMessageBox::warning(nullptr, "Erreur", "Le salaire doit être entre 1000 et 10000.");
        return false;
    }
    for (int i = 0; i < NOM.length(); ++i) {
        QChar ch = NOM[i];

        if (!ch.isLetter() && !ch.isSpace()) {
            QMessageBox::warning(nullptr, "Erreur", "Le nom doit contenir uniquement des lettres et des espaces.");
            return false;
        }
    }


    for (int i = 0; i < PRENOM.length(); ++i) {
        QChar ch = PRENOM[i];

        if (!ch.isLetter() && !ch.isSpace()) {
            QMessageBox::warning(nullptr, "Erreur", "Le prénom doit contenir uniquement des lettres et des espaces.");
            return false;
        }
    }



    if (POSTE.isEmpty()) {
        QMessageBox::warning(nullptr, "Erreur", "Le poste de l'employé ne peut pas être vide.");
        return false;
    }


    if (PRESENCES < 0 || PRESENCES > 30) {
        QMessageBox::warning(nullptr, "Erreur", "Les présences de l'employé doivent être entre 0 et 30.");
        return false;
    }


    if (D_DATE.isNull() || F_DATE.isNull()) {
        QMessageBox::warning(nullptr, "Erreur", "Les dates de début et de fin de contrat ne peuvent pas être vides.");
        return false;
    } else if (D_DATE > F_DATE) {
        QMessageBox::warning(nullptr, "Erreur", "La date de début de contrat doit être antérieure à la date de fin de contrat.");
        return false;
    }





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




QSqlQueryModel* Employe::afficher() {
    QSqlQuery query("SELECT ID_EMPLOYE, NOM, PRENOM, TELEPHONE, POSTE, SALAIRE, PRESENCES, D_DATE, F_DATE FROM employes");
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery(query);
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
QSqlQueryModel* Employe::trier(QString critere) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    if (critere == "salaire") {
        query.prepare("SELECT ID_EMPLOYE, NOM, PRENOM, SALAIRE, TELEPHONE, POSTE, PRESENCES, D_DATE,F_DATE FROM employes ORDER BY SALAIRE ASC");
    } else if (critere == "date_debut_contrat") {
        query.prepare("SELECT ID_EMPLOYE, NOM, PRENOM, SALAIRE, TELEPHONE, POSTE, PRESENCES, D_DATE,F_DATE FROM employes ORDER BY d_date ASC");
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Critère de tri invalide.");
        return nullptr;
    }

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur", "Échec du tri des employés.");
        return nullptr;
    }

    model->setQuery(query);
    return model;
}

QSqlQueryModel* Employe::rechercheremploye(const QString& critere, const QString& valeur) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    if (critere == "id") {

        query.prepare("SELECT * FROM employes WHERE ID_EMPLOYE = :valeur");
    } else if (critere == "nom") {

        query.prepare("SELECT * FROM employes WHERE NOM = :valeur");
    }
    query.bindValue(":valeur", valeur);

    if (!query.exec()) {
        qDebug() << "Erreur de requête SQL: " << query.lastError().text();
        return nullptr;
    }

    model->setQuery(query);
    return model;
}
QStandardItemModel* Employe::afficherAvecSalaireBrut(QLabel* masseSalarialeLabel) {
    QStandardItemModel* model = new QStandardItemModel();


    QSqlQuery query;
    query.prepare("SELECT ID_EMPLOYE, NOM, PRENOM, SALAIRE, POSTE, TELEPHONE, PRESENCES FROM EMPLOYES");

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur", "Échec de la récupération des employés.");
        return nullptr;
    }


    model->setHorizontalHeaderLabels({"ID_EMPLOYE", "NOM", "PRENOM", "SALAIRE", "POSTE", "TELEPHONE", "PRESENCES", "SALAIRE BRUT"});


    float masseSalarialeTotale = 0;
    int nombreEmployes = 0;


    while (query.next()) {
        int idEmploye = query.value("ID_EMPLOYE").toInt();
        QString nom = query.value("NOM").toString();
        QString prenom = query.value("PRENOM").toString();
        float salaire = query.value("SALAIRE").toFloat();
        QString poste = query.value("POSTE").toString();
        int telephone = query.value("TELEPHONE").toInt();
        int presences = query.value("PRESENCES").toInt();


        float salaireBrut = (salaire / 30.0f) * presences;


        QList<QStandardItem*> rowItems;
        rowItems << new QStandardItem(QString::number(idEmploye))
                 << new QStandardItem(nom)
                 << new QStandardItem(prenom)
                 << new QStandardItem(QString::number(salaire))
                 << new QStandardItem(poste)
                 << new QStandardItem(QString::number(telephone))
                 << new QStandardItem(QString::number(presences))
                 << new QStandardItem(QString::number(salaireBrut));


        model->appendRow(rowItems);


        masseSalarialeTotale += salaireBrut;
        nombreEmployes++;
    }


    float masseSalarialeMoyenne = 0;
    if (nombreEmployes > 0) {
        masseSalarialeMoyenne = masseSalarialeTotale / nombreEmployes;
    }


    masseSalarialeLabel->setText(  QString::number(masseSalarialeMoyenne, 'f', 2) + " dt");

    return model;
}
QMap<QString, int> Employe::obtenirStatistiquesPostes() {
    QMap<QString, int> statistiques;
    QSqlQuery query("SELECT poste, COUNT(*) FROM employes GROUP BY poste");

    while (query.next()) {
        QString poste = query.value(0).toString();
        int nombre = query.value(1).toInt();
        statistiques[poste] = nombre;
    }

    return statistiques;
}
QList<Employe> Employe::getEmployeesWithOneYearLeft() {
    QList<Employe> employeesWithOneYearLeft;
    QSqlQuery query;


    QDate oneYearFromNow = QDate::currentDate().addYears(1);


    query.prepare(" SELECT ID_EMPLOYE, NOM, PRENOM,TELEPHONE, POSTE, SALAIRE,  PRESENCES,D_DATE,F_DATE "
                  "FROM EMPLOYES "
                  "WHERE F_DATE <= :oneYearFromNow");
    query.bindValue(":oneYearFromNow", oneYearFromNow);


    if (query.exec()) {
        while (query.next()) {
            Employe employee;
            employee.ID_EMPLOYE = query.value("ID_EMPLOYE").toInt();
            employee.NOM= query.value("NOM").toString();
            employee.PRENOM = query.value("PRENOM").toString();
            employee.TELEPHONE = query.value("TELEPHONE").toInt();
            employee.POSTE = query.value("POSTE").toString();
            employee.SALAIRE = query.value("SALAIRE").toDouble();
            employee.PRESENCES = query.value("PRESENCES").toInt();
            employee.D_DATE = query.value("D_DATE").toDate();
            employee.F_DATE = query.value("F_DATE").toDate();

            employeesWithOneYearLeft.append(employee);
        }
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
    }

    return employeesWithOneYearLeft;
}
void Employe::sendSMS(const QString &telephone, const QString &message) {

    QUrl url("https://api.twilio.com/2010-04-01/Accounts/" + accountSID + "/Messages.json");


    QUrlQuery postData;
    postData.addQueryItem("To", telephone);
    postData.addQueryItem("From", fromPhoneNumber);
    postData.addQueryItem("Body", message);


    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");


    QByteArray auth = (accountSID + ":" + authToken).toUtf8().toBase64();
    request.setRawHeader("Authorization", "Basic " + auth);


    QNetworkAccessManager manager;
    QEventLoop loop;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);

    QNetworkReply *reply = manager.post(request, postData.query().toUtf8());
    loop.exec();


    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "SMS envoyé avec succès à" << telephone;
    } else {
        qDebug() << "Erreur lors de l'envoi du SMS:" << reply->errorString();
    }
    reply->deleteLater();
}
int Employe::genererIdUnique() {
    int id;
    QSqlQuery query;

    do {

        id = QRandomGenerator::global()->bounded(1000, 10000);


        query.prepare("SELECT COUNT(*) FROM employes WHERE ID_EMPLOYE = :id");
        query.bindValue(":id", id);
        query.exec();
    } while (query.next() && query.value(0).toInt() > 0);

    return id;
}
bool Employe::inscrire(int ID_EMPLOYE, const QString& NOM, const QString& PRENOM,
                       const QString& POSTE, const QString& TELEPHONE, const QString& MDP) {
    QSqlQuery query;
    query.prepare("INSERT INTO employes (ID_EMPLOYE, NOM, PRENOM, POSTE, TELEPHONE, MDP, SALAIRE, PRESENCES, D_DATE, F_DATE) "
                  "VALUES (:ID_EMPLOYE, :NOM, :PRENOM, :POSTE, :TELEPHONE, :MDP, :SALAIRE, :PRESENCES, :D_DATE, :F_DATE)");
    query.bindValue(":ID_EMPLOYE", ID_EMPLOYE);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":POSTE", POSTE);
    query.bindValue(":TELEPHONE", TELEPHONE);
    query.bindValue(":MDP", MDP);
    query.bindValue(":SALAIRE", 1000);
    query.bindValue(":PRESENCES", 0);
    query.bindValue(":D_DATE", QDate::currentDate());
    query.bindValue(":F_DATE", QDate::currentDate().addYears(1));

    return query.exec();
}




#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QLabel>
#include <QMap>
#include <QStandardItemModel>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QAuthenticator>
#include <QEventLoop>




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
    QSqlQueryModel* trier(QString critere);
    QSqlQueryModel* rechercheremploye(const QString& critere, const QString& valeur);
    QStandardItemModel* afficherAvecSalaireBrut(QLabel* masseSalarialeLabel);
    QMap<QString, int> obtenirStatistiquesPostes();
    bool hasOneYearLeft() const;
    QList<Employe> getEmployeesWithOneYearLeft();
    void sendSMS(const QString &telephone, const QString &message);
    int genererIdUnique();
    bool inscrire(int id, const QString& nom, const QString& prenom,
                  const QString& poste, const QString& telephone, const QString& mdp);


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


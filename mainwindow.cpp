#include "mainwindow.h"
#include "qsqlerror.h"
#include "ui_mainwindow.h"
#include "reservation.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QVector>
#include <QString>
#include <QStandardPaths>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QTcpSocket>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QTextStream>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QUrl>
#include <QRandomGenerator>
#include <QSslSocket>
#include <QUrlQuery>
#include <QtCore>
#include <QByteArray>
#include <QUrlQuery>
#include <QDebug>
#include "pdf.h"
#include "email.h"
#include "arduino1.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    arduinoManager(new ArduinoManager(this))
{

    ui->setupUi(this);
    ui->tab->setModel(reservation.afficher());
    searchLineEdit = ui->id_12;
    uidcarteline=ui->uid;
    idReservationLineEdit = ui->id_9;
    dateReservationDateEdit = ui->dateR;
    dateArriveDateEdit = ui->dateEdit_13;
    dateDepartDateEdit = ui->dateEdit_13;
    typeChambreComboBox = ui->type;
    statutReservationComboBox = ui->statut;
    modePaiementComboBox = ui->mode;
    montantLineEdit = ui->id_11;


    validerButton = ui->valid;
    supprimerButton = ui->supprimer_5;
    modifierButton = ui->modifier_5;
    exporterPdf=ui->pdf_16;


    connect(validerButton, &QPushButton::clicked, this, &MainWindow::on_validerButton_clicked);
    connect(supprimerButton, &QPushButton::clicked, this, &MainWindow::on_supprimerButton_clicked);
    connect(modifierButton, &QPushButton::clicked, this, &MainWindow::on_modifierButton_clicked);
    connect(exporterPdf, &QPushButton::clicked, this, &MainWindow::on_exporter_clicked);
    connect(ui->comboBox_5, SIGNAL(currentIndexChanged(int)), this, SLOT(on_triComboBox_currentIndexChanged(int)));
    connect(ui->boutonstatres, &QPushButton::clicked, this, &MainWindow::afficherStatistiquesTypeChambre);
    networkManager = new QNetworkAccessManager(this);
    connect(ui->mail, &QPushButton::clicked, this, &MainWindow::on_email_clicked);
    connect(ui->envoi, &QPushButton::clicked, this, &MainWindow::on_sendVerificationButton_clicked);
    connect(ui->con,&QPushButton::clicked,this,&MainWindow::on_verifyCodeButton_clicked);
    connect(arduinoManager, &ArduinoManager::cardRead, this, &MainWindow::onCardRead);


    if (!arduinoManager->connectToArduino("COM3")) { // Remplacez "COM3" par le port série d'Arduino
        QMessageBox::warning(this, "Erreur", "Impossible de se connecter à Arduino.");
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_validerButton_clicked()
{
    int idReservation = idReservationLineEdit->text().toInt();
    QDate dateReservation = dateReservationDateEdit->date();
    QDate dateArrive = dateArriveDateEdit->date();
    QDate dateDepart = dateDepartDateEdit->date();
    QString typeChambre = typeChambreComboBox->currentText();
    QString statutReservation = statutReservationComboBox->currentText();
    QString modePaiement = modePaiementComboBox->currentText();
    float montant = montantLineEdit->text().toFloat();
    QString uidcarte = uidcarteline->text();

    Reservation reservation(idReservation, dateReservation, dateArrive, dateDepart,
                            typeChambre, statutReservation, modePaiement, montant, uidcarte);

    if (reservation.ajouter()) {
        ui->tab->setModel(reservation.afficher());
        reservations.append(reservation);  // Ajout au vecteur de réservations
        QMessageBox::information(this, "Ajout réussi", "La réservation a été ajoutée avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout de la réservation.");
    }
}

void MainWindow::on_supprimerButton_clicked()
{
    int idReservation = searchLineEdit->text().toInt();


    if (idReservation == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID de réservation valide.");
        return;
    }


    Reservation reservation;
    if (reservation.supprimer(idReservation)) {
        ui->tab->setModel(reservation.afficher());
        QMessageBox::information(this, "Suppression réussie", "La réservation a été supprimée avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression de la réservation. Vérifiez l'ID.");
    }
}

void MainWindow::on_modifierButton_clicked()
{

    int idReservation = idReservationLineEdit->text().toInt();
    QDate dateReservation = dateReservationDateEdit->date();
    QDate dateArrive = dateArriveDateEdit->date();
    QDate dateDepart = dateDepartDateEdit->date();
    QString typeChambre = typeChambreComboBox->currentText();
    QString statutReservation = statutReservationComboBox->currentText();
    QString modePaiement = modePaiementComboBox->currentText();
    float montant = montantLineEdit->text().toFloat();
    QString uidcarte = uidcarteline->text();

    Reservation reservation(idReservation, dateReservation, dateArrive, dateDepart,
                            typeChambre, statutReservation, modePaiement, montant,uidcarte);


    if (reservation.modifier(idReservation, dateReservation, dateArrive, dateDepart,
                             typeChambre, statutReservation, modePaiement, montant)) {
        ui->tab->setModel(reservation.afficher());
        QMessageBox::information(this, "Modification réussie", "La réservation a été modifiée avec succès.");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la modification de la réservation.");
    }
}

void MainWindow::on_searchLineEdit_textChanged(const QString &text)
{
    int idReservation = text.toInt();

    if (idReservation != 0) {
        Reservation reservation;
        if (reservation.rechercher(idReservation)) {

            idReservationLineEdit->setText(QString::number(reservation.getIdReservation()));
            dateReservationDateEdit->setDate(reservation.getDateReservation());
            dateArriveDateEdit->setDate(reservation.getDateArrive());
            dateDepartDateEdit->setDate(reservation.getDateDepart());
            typeChambreComboBox->setCurrentText(reservation.getTypeChambre());
            statutReservationComboBox->setCurrentText(reservation.getStatutReservation());
            modePaiementComboBox->setCurrentText(reservation.getModePaiment());
            montantLineEdit->setText(QString::number(reservation.getMontant()));
        } else {
            QMessageBox::warning(this, "Réservation non trouvée", "Aucune réservation trouvée pour cet ID.");
        }
    }
}
void MainWindow::afficher() {

    Reservation reservation;


    QSqlQueryModel *model = reservation.afficher();


    if (model) {

        ui->tab->setModel(model);
    } else {
        qDebug() << "Erreur : Le modèle de données n'a pas pu être créé.";
    }
}
void MainWindow::on_exporter_clicked() {

    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), "PDF Files (*.pdf)");
    if (!filePath.isEmpty()) {
        generateReservationTablePdf(reservations, filePath);
    }
}

void MainWindow::on_triComboBox_currentIndexChanged(int index) {
    QString orderBy;


    if (index == 0) {
        orderBy = "ID_RESERVATION";
    } else if (index == 1) {
        orderBy = "DATE_ARRIVEE";
    }


    QSqlQueryModel *model = reservation.trierPar(orderBy);
    if (model) {
        ui->tab->setModel(model);
    } else {
        qDebug() << "Erreur : Le tri n'a pas pu être appliqué.";
    }
}
void MainWindow::afficherStatistiquesTypeChambre() {
    // Requête SQL pour obtenir les statistiques des types de chambres
    QSqlQuery query;
    query.prepare("SELECT TYPE_CHAMBRE, COUNT(*) as Nombre FROM RESERVATIONS GROUP BY TYPE_CHAMBRE");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les données de la base de données : " + query.lastError().text());
        return;
    }

    // Création d'une série pour le graphique
    QPieSeries *series = new QPieSeries();

    // Parcourir les résultats de la requête et remplir la série
    while (query.next()) {
        QString typeChambre = query.value("TYPE_CHAMBRE").toString();
        int count = query.value("Nombre").toInt();
        series->append(typeChambre, count);
    }

    // Configurer les tranches du graphique
    for (auto slice : series->slices()) {
        slice->setLabelVisible(true); // Rendre les étiquettes visibles
        slice->setExploded(false);   // Vous pouvez ajuster cette valeur si vous voulez exploser des tranches
    }

    // Créer et configurer le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des Types de Chambres");

    // Créer et afficher le graphique dans le `QWidget` nommé `omar`
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Ajuster la taille et afficher dans le conteneur `omar`
    chartView->setParent(ui->omar);
    chartView->resize(ui->omar->size());
    chartView->show();
}

void MainWindow::on_email_clicked()
{

    QString destinataire = "ramysnoussi@gmail.com";
    QString objet = "Confirmation de votre réservation";
    QString corps = "Bonjour Rami,\n\nVotre réservation est confirmée.\n\nMerci de votre confiance.";




    envoyerEmail(destinataire, objet, corps);


    QMessageBox::information(this, "Succès", "Email envoyé avec succès.");
}

void MainWindow::envoyerEmail(const QString& destinataire, const QString& sujet, const QString& message) {
    QString smtpServer = "smtp.gmail.com";
    int smtpPort = 465;
    QString from = "aziz228nasri@gmail.com";
    QString password = "paqd yivs yzja uyxa";

    QString emailBody = "From: " + from + "\r\n" +
                        "To: " + destinataire + "\r\n" +
                        "Subject: " + sujet + "\r\n\r\n" +
                        message;

    QSslSocket socket;
    socket.connectToHostEncrypted(smtpServer, smtpPort);
    if (!socket.waitForConnected()) {
        qDebug() << "Erreur de connexion au serveur SMTP:" << socket.errorString();
        return;
    }
    qDebug() << "Connexion réussie au serveur SMTP.";


    if (!socket.waitForReadyRead()) {
        qDebug() << "Erreur lecture du serveur SMTP:" << socket.errorString();
        return;
    }
    qDebug() << "Réponse du serveur:" << socket.readAll();


    socket.write("EHLO localhost\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    qDebug() << "Réponse EHLO:" << socket.readAll();

    socket.write("AUTH LOGIN\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    qDebug() << "Réponse AUTH LOGIN:" << socket.readAll();

    socket.write(QByteArray().append(from.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    qDebug() << "Réponse email (AUTH):" << socket.readAll();

    socket.write(QByteArray().append(password.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    qDebug() << "Réponse mot de passe (AUTH):" << socket.readAll();

    socket.write("MAIL FROM:<" + from.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    qDebug() << "Réponse MAIL FROM:" << socket.readAll();

    socket.write("RCPT TO:<" + destinataire.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    qDebug() << "Réponse RCPT TO:" << socket.readAll();

    socket.write("DATA\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    qDebug() << "Réponse DATA:" << socket.readAll();

    socket.write(emailBody.toUtf8() + "\r\n.\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    qDebug() << "Réponse après envoi du contenu:" << socket.readAll();

    socket.write("QUIT\r\n");
    socket.waitForBytesWritten();
    qDebug() << "Fermeture de la connexion.";

    socket.close();
    qDebug() << "E-mail envoyé avec succès.";
}
void MainWindow::on_sendVerificationButton_clicked() {
    QString userEmail = ui->oub->text(); // Lire l'adresse e-mail saisie

    if (userEmail.isEmpty() || !userEmail.contains("@")) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une adresse e-mail valide.");
        return;
    }

    // Générer un code aléatoire
    verificationCode = QString::number(QRandomGenerator::global()->bounded(100000, 999999)); // Code à 6 chiffres

    // Préparer le sujet et le contenu de l'e-mail
    QString subject = "Votre code de vérification";
    QString body = QString("Bonjour,\n\nVoici votre code de vérification : %1.\n\nMerci.").arg(verificationCode);

    // Appeler la fonction pour envoyer l'e-mail
    if (envoyerVerificationEmail(userEmail, subject, body)) {
        QMessageBox::information(this, "Succès", "Un e-mail avec un code de vérification a été envoyé.");
        qDebug() << "Code envoyé à l'utilisateur : " << verificationCode; // Affiche le code dans la console pour vérification (optionnel)
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'envoi de l'e-mail.");
    }
}
bool MainWindow::envoyerVerificationEmail(const QString &recipient, const QString &subject, const QString &body) {
    QString smtpServer = "smtp.gmail.com";
    int smtpPort = 465; // Port SSL
    QString senderEmail = "aziz228nasri@gmail.com"; // Remplacez par votre adresse e-mail
    QString appPassword = "paqd yivs yzja uyxa"; // Remplacez par votre mot de passe d'application

    QSslSocket socket;
    socket.connectToHostEncrypted(smtpServer, smtpPort);
    if (!socket.waitForConnected(5000)) {
        qDebug() << "Erreur de connexion au serveur SMTP:" << socket.errorString();
        return false;
    }

    socket.write("EHLO localhost\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.write("AUTH LOGIN\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.write(QByteArray().append(senderEmail.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.write(QByteArray().append(appPassword.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.write("MAIL FROM:<" + senderEmail.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.write("RCPT TO:<" + recipient.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.write("DATA\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    QString emailBody = "From: " + senderEmail + "\r\n"
                                                 "To: " + recipient + "\r\n"
                                      "Subject: " + subject + "\r\n\r\n" +
                        body + "\r\n.\r\n";

    socket.write(emailBody.toUtf8());
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.write("QUIT\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.close();
    return true;
}
void MainWindow::on_verifyCodeButton_clicked() {
    QString enteredCode = ui->mp->text().trimmed(); // Éliminer les espaces inutiles

    if (enteredCode.trimmed() == verificationCode.trimmed()) {
        QMessageBox::information(this, "Vérification réussie", "Code vérifié avec succès !");
        ui->stackedWidget->setCurrentIndex(10);
        qDebug() << "Code entre : " << enteredCode;// Passer à l'écran suivant
    } else {
        qDebug() << "Code entre : " << enteredCode;
        QMessageBox::warning(this, "Erreur", "Le code n'est pas correct !");
    }
}
void MainWindow::onCardRead(QString uid)
{
    qDebug() << "UID reçu depuis Arduino :" << uid;

    // Vérifiez si l'UID est présent dans la base de données
    QSqlQuery query;
    query.prepare("SELECT \"DATE_DEPART\" FROM \"RESERVATIONS\" WHERE \"UID_CARTE\" = :uid");
    query.bindValue(":uid", uid);
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        return;
    }

    if (query.next()) {
        QDateTime departureDate = query.value(0).toDateTime();
        QDateTime currentDate = QDateTime::currentDateTime();

        qDebug() << "Date de départ :" << departureDate;
        qDebug() << "Date actuelle :" << currentDate;

        if (!departureDate.isValid()) {
            qDebug() << "Date de départ invalide.";

            return;
        }

        // Comparer les dates
        if (currentDate > departureDate) {
            QString message= "Refuse";
            arduinoManager->sendResponseToArduino(message);
            qDebug() << "Accès refusé : Date dépassée.";
            QMessageBox::information(this, "erreur", "Date dépassée");

        } else {
            QString message= "verifie";
            arduinoManager->sendResponseToArduino(message);
            qDebug() << "Accès vérifié.";
            QMessageBox::information(this, "verifie", "Accès vérifié.");

        }
    } else {
        QString message= "inconnu";
        arduinoManager->sendResponseToArduino(message);
        qDebug() << "UID non trouvé dans la base.";

    }
}

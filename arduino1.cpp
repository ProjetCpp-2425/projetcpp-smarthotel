#include "arduino1.h".h"
#include <QSerialPort>
#include <QDebug>

ArduinoManager::ArduinoManager(QObject *parent) : QObject(parent), serialPort(new QSerialPort(this))
{
    // Connecter le signal readyRead au slot de traitement des données
    connect(serialPort, &QSerialPort::readyRead, this, &ArduinoManager::onDataReceived);
}

bool ArduinoManager::connectToArduino(const QString &portName, int baudRate)
{
    if (serialPort->isOpen()) {
        serialPort->close();
    }

    serialPort->setPortName(portName);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (!serialPort->open(QIODevice::ReadWrite)) {
        qWarning() << "Erreur : Impossible de se connecter à Arduino :" << serialPort->errorString();
        return false;
    }

    qDebug() << "Connecté à Arduino sur le port" << portName;
    return true;
}

void ArduinoManager::disconnectFromArduino()
{
    if (serialPort->isOpen()) {
        serialPort->close();
        qDebug() << "Déconnecté d'Arduino.";
    }
}

bool ArduinoManager::isConnected() const
{
    return serialPort->isOpen();
}

void ArduinoManager::onDataReceived() {
    QByteArray data = serialPort->readAll();
    QString receivedData = QString::fromUtf8(data).trimmed();
    static QString uidBuffer;  // Tampon pour accumuler les fragments

    qDebug() << "Fragment reçu : " << receivedData;

    // Ajouter les fragments reçus au tampon
    uidBuffer += receivedData;

    // Vérifier si l'UID complet est reçu (par exemple "23:7:3:35")
    if (uidBuffer.contains("UID:")) {
        // Extraire l'UID de la chaîne (supposons que l'UID commence après "UID:")
        QString uid = uidBuffer.section("UID:", 1, 1);  // Extraire la chaîne après "UID:"

        // Nettoyer l'UID en enlevant les espaces superflus
        uid = uid.simplified();

        // Remplacer les espaces ou autres caractères inutiles par des ":"
        uid.replace(" ", ":");

        // Vérifier que l'UID est bien formé
        if (uid.split(":").size() == 4) {
            // Afficher l'UID dans le bon format
            qDebug() << "UID complet reçu : " << uid;

            // Émettre le signal avec l'UID
            emit cardRead(uid);

            // Afficher l'UID sur un écran LCD si nécessaire
            // Par exemple : ui->lcdDisplay->display(uid); // Assurez-vous d'avoir un LCD configuré dans votre interface Qt

            // Réinitialiser le tampon après traitement
            uidBuffer.clear();
        } else {
            qDebug() << "UID invalide reçu : " << uid;
            // Vous pouvez émettre un signal d'erreur ou gérer l'UID invalide ici
        }
    }
}


void ArduinoManager::sendResponseToArduino(const QString &response)
{
    if (serialPort->isOpen()) {
        serialPort->write(response.toUtf8());
        // Forcer l'écriture

    }
}

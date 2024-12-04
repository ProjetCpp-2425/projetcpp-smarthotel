#include "arduino.h"
#include <QDebug>
Arduino::Arduino() {
    serial = new QSerialPort();
    portName = "";
}

int Arduino::connect() {
    // Détection automatique du port
    portName = autoDetectPort();

    if (portName.isEmpty()) {
        qDebug() << "Erreur : Aucun port Arduino détecté.";
        return 1;
    }

    serial->setPortName(portName);
    if (serial->open(QIODevice::ReadWrite)) {
        serial->setBaudRate(QSerialPort::Baud9600);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        qDebug() << "Connecté à : " << portName;
        return 0; // Connexion réussie
    } else {
        qDebug() << "Erreur : Impossible de se connecter au port série.";
        return 1; // Échec de la connexion
    }
}

QString Arduino::autoDetectPort() {
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.description().contains("Arduino")) { // Vérifie la description
            return info.portName();
        }
    }
    return ""; // Aucun port correspondant trouvé
}



int Arduino::disconnect() {
    if (serial->isOpen()) {
        serial->close();
        return 0; // Déconnexion réussie
    }
    return 1; // Erreur lors de la déconnexion
}

bool Arduino::sendData(const QString &data) {
    if (serial->isWritable()) {
        qDebug() << "Envoi des données :" << data;
        serial->write(data.toUtf8());
        return true;
    } else {
        qDebug() << "Erreur : Port série non prêt pour l'écriture.";
        qDebug() << "Statut du port série :" << serial->errorString();
        return false;
    }
}


QString Arduino::getPortName() {
    return portName;
}

QSerialPort *Arduino::getSerialPort() {
    return serial; // Retourner le pointeur vers le port série
}
void Arduino::listAvailablePorts() {
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Port trouvé :" << info.portName() << " (" << info.description() << ")";
    }
}

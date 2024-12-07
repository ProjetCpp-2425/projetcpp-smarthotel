#include "arduino.h"
#include <QDebug>
Arduino::Arduino() {
    serial = new QSerialPort();
    portName = "";
}

int Arduino::connect() {

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
        return 0;
    } else {
        qDebug() << "Erreur : Impossible de se connecter au port série.";
        return 1;
    }
}

QString Arduino::autoDetectPort() {
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.description().contains("Arduino")) {
            return info.portName();
        }
    }
    return "";
}



int Arduino::disconnect() {
    if (serial->isOpen()) {
        serial->close();
        return 0;
    }
    return 1;
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
    return serial;
}
void Arduino::listAvailablePorts() {
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        qDebug() << "Port trouvé :" << info.portName() << " (" << info.description() << ")";
    }
}

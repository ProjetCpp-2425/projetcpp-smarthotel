#ifndef ARDUINO_H
#define ARDUINO_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>

class Arduino {
public:
    Arduino();
    int connect();
    int disconnect();
    bool sendData(const QString &data);
    QString getPortName();
    QSerialPort *getSerialPort();
    void listAvailablePorts();
    QString autoDetectPort();

private:
    QSerialPort *serial;
    QString portName;
    static const quint16 vendorId = 0x2341;
    static const quint16 productId = 0x0043;
};

#endif

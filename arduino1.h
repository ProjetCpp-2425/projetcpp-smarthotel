#ifndef ARDUINO1_H
#define ARDUINO1_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDateTime>

class ArduinoManager : public QObject
{
    Q_OBJECT
public:
    explicit ArduinoManager(QObject *parent = nullptr);

    // Méthodes pour initialiser et contrôler Arduino
    bool connectToArduino(const QString &portName, int baudRate = QSerialPort::Baud9600);
    void disconnectFromArduino();
    bool isConnected() const;
    void sendResponseToArduino(const QString &response);

signals:
    // Signal pour notifier les données reçues
    void cardRead(const QString &uid);



private slots:
    void onDataReceived();

private:
    QSerialPort *serialPort;
    QSerialPort *arduino;
    QSerialPort *serial;
    QString dataBuffer;
    // Objet pour gérer le port série
};


#endif // ARDUINO1_H

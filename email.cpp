#include "email.h"
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
#include <QSslSocket>
#include <QUrlQuery>
#include <QtCore>
#include <QByteArray>
#include <QUrlQuery>
#include <QDebug>

mailer::mailer()
{
}
int mailer::sendEmail(QString dist, QString obj, QString bdy)
{
    qDebug() << "sslLibraryBuildVersionString:" << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "sslLibraryVersionNumber:" << QSslSocket::sslLibraryVersionNumber();
    qDebug() << "supportsSsl:" << QSslSocket::supportsSsl();
    qDebug() << QCoreApplication::libraryPaths();

    // SMTP server information
    QString smtpServer = "smtp.gmail.com";
    int smtpPort = 465;  // Adjust this based on your SMTP server configuration
    QString username = "ramysnoussi@gmail.com"; // Remplacez par votre adresse Gmail
    QString password = "tikf sbte cbjs yvxc"; // Mot de passe d'application Gmail

    // Sender and recipient information
    QString from = "ramysnoussi@gmail.com"; // Votre adresse email
    QString to = dist; // Email du destinataire
    QString subject = obj; // Objet de l'email
    QString body = bdy; // Corps de l'email

    // Create a TCP socket
    QSslSocket socket;
    // Connect to the SMTP server
    socket.connectToHostEncrypted(smtpServer, smtpPort);
    if (!socket.waitForConnected()) {
        qDebug() << "Error connecting to the server:" << socket.errorString();
        return -1;
    }

    // Send HELO
    socket.write("HELO localhost\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    // Send the authentication information
    socket.write("AUTH LOGIN\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    socket.write(QByteArray().append(username.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();
    socket.write(QByteArray().append(password.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    // Send MAIL FROM
    socket.write("MAIL FROM:<" + from.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    // Send RCPT TO
    socket.write("RCPT TO:<" + to.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    // Send DATA
    socket.write("DATA\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    // Send the email content
    socket.write("From: " + from.toUtf8() + "\r\n");
    socket.write("To: " + to.toUtf8() + "\r\n");
    socket.write("Subject: " + subject.toUtf8() + "\r\n");
    socket.write("\r\n");  // Empty line before the body
    socket.write(body.toUtf8() + "\r\n");
    socket.write(".\r\n");  // End of email content
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    // Send QUIT
    socket.write("QUIT\r\n");
    socket.waitForBytesWritten();
    socket.waitForReadyRead();

    socket.close();
    qDebug() << "Email sent successfully.";
    return 0;
}

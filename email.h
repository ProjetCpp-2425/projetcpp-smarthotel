#ifndef EMAIL_H
#define EMAIL_H

#include <QString>

#include <QString>
class mailer
{
public:
    mailer();
    mailer(QString, QString, QString);
    static int sendEmail(QString, QString, QString);


    static int sendEmailWithAttachment(QString dist, QString obj, QString bdy);

private:
    QString destinataire;
    QString object, body;
};

#endif // EMAIL_H

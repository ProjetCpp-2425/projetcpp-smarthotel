#ifndef PDF_H
#define PDF_H

#include <QString>
#include <QVector>


class Reservation; // Déclaration avant l'utilisation

void generateReservationTablePdf(const QVector<Reservation>& reservations, const QString& filePath);

#endif // PDF_H

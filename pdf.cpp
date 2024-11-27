#include "pdf.h"
#include <QPdfWriter>
#include <QPainter>
#include <QFont>
#include <QTableView>
#include <QAbstractItemModel>
#include "reservation.h"

void generateReservationTablePdf(const QVector<Reservation>& reservations, const QString& filePath) {
    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize::A2);
    pdfWriter.setTitle("Tableau des Réservations");

    QPainter painter(&pdfWriter);
    painter.setFont(QFont("Arial", 12, QFont::Bold));

    int x = 50;
    int y = 100;
    int rowHeight = 400;
    int columnWidth = 2300;

    // En-têtes du tableau
    QStringList headers = {"ID Réservation", "Date Réservation", "Date Arrivée", "Date Départ", "Type Chambre", "Statut Réservation", "Mode Paiement", "Montant"};
    for (int i = 0; i < headers.size(); ++i) {
        painter.drawText(x + i * columnWidth, y, headers[i]);
    }

    // Ligne de séparation des en-têtes
    y += rowHeight;
    painter.setPen(Qt::black);
    painter.drawLine(x, y, x + headers.size() * columnWidth, y);

    // Contenu du tableau
    painter.setFont(QFont("Arial", 10, QFont::Normal));
    for (const Reservation& reservation : reservations) {
        painter.drawText(x, y, QString::number(reservation.getIdReservation()));
        painter.drawText(x + columnWidth, y, reservation.getDateReservation().toString("yyyy-MM-dd"));
        painter.drawText(x + 2 * columnWidth, y, reservation.getDateArrive().toString("yyyy-MM-dd"));
        painter.drawText(x + 3 * columnWidth, y, reservation.getDateDepart().toString("yyyy-MM-dd"));
        painter.drawText(x + 4 * columnWidth, y, reservation.getTypeChambre());
        painter.drawText(x + 5 * columnWidth, y, reservation.getStatutReservation());
        painter.drawText(x + 6 * columnWidth, y, reservation.getModePaiment());
        painter.drawText(x + 7 * columnWidth, y, QString::number(reservation.getMontant(), 'f', 2));

        y += rowHeight;


        painter.drawLine(x, y, x + headers.size() * columnWidth, y);


        if (y > pdfWriter.height() - 100) {
            pdfWriter.newPage();
            y = 100;
        }
    }

    painter.end();
}

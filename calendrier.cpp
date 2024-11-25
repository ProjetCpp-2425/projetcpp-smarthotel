#include "Calendrier.h"
#include <QPainter>
#include <QDate>

Calendrier::Calendrier(QWidget *parent) : QCalendarWidget(parent)
{
    // Optionally, connect signals or other initializations
}



void Calendrier::paintSpecialDates(QPainter *painter, const QRect &rect, const QDate &date) const
{
    // Define your special dates and their corresponding colors
    QColor color;
    if (date.dayOfWeek() == Qt::Sunday) {
        color = QColor(255, 0, 0);  // Red for Sundays
    } else if (date.dayOfWeek() == Qt::Monday) {
        color = QColor(128, 0, 128);  // Purple for Mondays
    } else if (date == QDate::currentDate()) {
        color = QColor(0, 0, 255);  // Blue for the current date
    } else {
        return;  // No color change for other dates
    }

    painter->save();
    painter->setBrush(color);
    painter->setPen(Qt::NoPen);  // Remove border for colored cells
    painter->drawRect(rect);  // Color the entire cell
    painter->restore();
}
void Calendrier::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{
    QCalendarWidget::paintCell(painter, rect, date);  // Base class paint method
    paintSpecialDates(painter, rect, date);          // Custom painting logic
}

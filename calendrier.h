#ifndef CALENDRIER_H
#define CALENDRIER_H

#include <QCalendarWidget>
#include <QMap>
#include <QCalendarWidget>
#include <QPainter>
#include <QColor>
class Calendrier : public QCalendarWidget
{
    Q_OBJECT

public:
    Calendrier(QWidget *parent = nullptr);

    void setDateAttributes(const QDate& date, const QString& color, const QString& attributes);

signals:
    void dateSelected(const QString& attributes);

private slots:
    void onDateSelected();

private:
    QMap<QDate, QPair<QString, QString>> dateAttributes;
protected:
    void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const ;

private:
    void paintSpecialDates(QPainter *painter, const QRect &rect, const QDate &date) const;
};


#endif // CALENDRIER_H

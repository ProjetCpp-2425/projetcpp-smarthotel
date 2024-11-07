#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QDateEdit>
#include <QComboBox>
#include "reservation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_validerButton_clicked();
    void on_supprimerButton_clicked();
    void on_modifierButton_clicked();
    void on_searchLineEdit_textChanged(const QString &text);
    void afficher();
private:
    Ui::MainWindow *ui;
    Reservation reservation;


    QLineEdit *searchLineEdit;
    QLineEdit *idReservationLineEdit;
    QDateEdit *dateReservationDateEdit;
    QDateEdit *dateArriveDateEdit;
    QDateEdit *dateDepartDateEdit;
    QComboBox *typeChambreComboBox;
    QComboBox *statutReservationComboBox;
    QComboBox *modePaiementComboBox;
    QLineEdit *montantLineEdit;


    QPushButton *validerButton;
    QPushButton *supprimerButton;
    QPushButton *modifierButton;
};

#endif

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include <QSqlQueryModel>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Employe employe;


private slots:
    void onRechercheTextChanged(const QString &text);
private slots:
    void changerDePagestatistique();
    void changerDePagestatclient();
    void changerDePagestatres();
    void changerDePagecalmaint();
    void changerDePageconnexion();
    void changerDePagestatstock();
    void changerDePagemdp();
private slots:
    void changerDePagecalcul();
    void changerDePagehisclient();
private slots:
    void changerDePageemploye();
private slots:
    void changerDePageclient();
private slots:
    void changerDePagereservation();
private slots:
    void changerDePagestock();
private slots:
    void changerDePagemaintenance();
private slots:
    void on_ajouterButton_clicked();
    void on_modifier_clicked();
    void on_supprimerButton_clicked();
    void on_rechercher_clicked();

};


#endif

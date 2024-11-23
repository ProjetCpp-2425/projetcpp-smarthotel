#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include <QSqlQueryModel>
#include <QLabel>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QVBoxLayout>



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
     QLabel *masse;



private slots:
    void onRechercheTextChanged(const QString &text);
private slots:
    void changerDePagestatistique();
    void changerDePagesms();
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
    void on_boutonTrier_clicked();
    void Rechercheemploye();
    void exporterListeEmployesPDF();
    void afficherSalaireEtMasseSalariale();
    void afficherStatistiquesPostes();
    void sendRenewalMessages();
    void afficherEmployeesAvecUnAnDeContratRestant();
    bool inscrireEmploye();
    void on_connexionButton_clicked();

};


#endif

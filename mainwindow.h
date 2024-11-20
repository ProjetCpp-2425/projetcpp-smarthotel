#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<connection.h>
#include"Client.h"
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
private slots:
    void changerDePagestatistique();

    void on_accueilbutton_clicked();

    void changerDePagehistorique();
    void on_accueilbutton_2_clicked();
    void on_valider_clicked();
    void on_supprimer_clicked();
    void on_modifier_clicked();
    void on_chercher_clicked();
    void on_trier_clicked();
    void on_pdf_clicked();
    void afficherHistorique(QSqlQueryModel *model);

    void on_client_fidele_clicked();

    void on_chercher_2_clicked();


    void on_retour_clicked();
    void calculerPointsEtDuree(QStandardItemModel* sqlModel);

private:
    Ui::MainWindow *ui;
    Client cl;

};
#endif // MAINWINDOW_H

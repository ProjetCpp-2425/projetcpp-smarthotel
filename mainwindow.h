#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "maintenance.h"
#include <QMainWindow>

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

    void on_pushButton_39_clicked();
    void on_pushButton_38_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_40_clicked();
    void on_pushButton_43_clicked();
    void on_comboBox_34_currentTextChanged(const QString &priorite);

private:
    Ui::MainWindow *ui;
    Maintenance Mtmp;
    void loadMaintenanceData();
};

#endif // MAINWINDOW_H

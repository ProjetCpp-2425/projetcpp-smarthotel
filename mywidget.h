#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);

private slots:
    void onTextChanged(const QString &text);

private:
    QLineEdit *recherche;  // Nom du QLineEdit
    QPushButton *modifier; // Nom du QPushButton
    QVBoxLayout *layout;
};

#endif // MYWIDGET_H

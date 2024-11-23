#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    recherche = new QLineEdit(this);       // Nom de la ligne de texte est "recherche"
    modifier = new QPushButton("Modifier", this); // Nom du bouton est "modifier"

    // Le bouton "modifier" est invisible au début
    modifier->setVisible(false);

    layout = new QVBoxLayout(this);
    layout->addWidget(recherche);
    layout->addWidget(modifier);
    setLayout(layout);

    // Connexion du signal textChanged pour mettre à jour la visibilité du bouton
    connect(recherche, &QLineEdit::textChanged, this, &MyWidget::onTextChanged);
}

void MyWidget::onTextChanged(const QString &text)
{
    // Si du texte est saisi, afficher le bouton "modifier"
    modifier->setVisible(!text.isEmpty());
}

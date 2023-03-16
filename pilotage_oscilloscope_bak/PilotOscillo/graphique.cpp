#include "graphique.h"
#include "ui_graphique.h"

Graphique::Graphique(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Graphique)
{
    ui->setupUi(this);
}

Graphique::~Graphique()
{
    delete ui;
}

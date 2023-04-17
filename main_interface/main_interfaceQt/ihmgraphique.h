#ifndef IHMGRAPHIQUE_H
#define IHMGRAPHIQUE_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCharts>

class IhmGraphique : public QMainWindow
{
    Q_OBJECT

public:
    IhmGraphique(QWidget *parent = 0, double coef);
    ~IhmGraphique();

private:
    QChartView *graphique; // un widget pour afficher un graphe
    QChart *graphe; // la représentation d'un graphe
    QLineSeries *courbe; // les données
};

#endif // IHMGRAPHIQUE_H

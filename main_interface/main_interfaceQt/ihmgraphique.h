#ifndef IHMGRAPHIQUE_H
#define IHMGRAPHIQUE_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCharts>

class IhmGraphique : public QMainWindow
{
    Q_OBJECT

public:
    IhmGraphique(QWidget *parent, double frequence[], double coef[]);
    ~IhmGraphique();

private:
    QChartView *graphique; // un widget pour afficher un graphe
    QChart *graphe; // la représentation d'un graphe
    QLineSeries *courbe; // les données
    QMap<int, QString> map;
};

#endif // IHMGRAPHIQUE_H

// = ( QMap<double, QString>() )

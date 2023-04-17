#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include <QWidget>
#include <QtWidgets>
#include <QtCharts>

class graphique : public QWidget
{
    Q_OBJECT
public:
    explicit graphique(QWidget *parent = nullptr);

signals:

public slots:

private:
    QChartView *graphique; // un widget pour afficher un graphe
    QChart *graphe; // la représentation d'un graphe
    QLineSeries *courbe; // les données
};

#endif // GRAPHIQUE_H

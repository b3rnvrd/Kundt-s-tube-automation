#ifndef IHMGRAPHIQUE_H
#define IHMGRAPHIQUE_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtCharts>

class IhmGraphique : public QMainWindow
{
    Q_OBJECT

public:
    IhmGraphique(QWidget *parent);
    ~IhmGraphique();

public slots:
    void dessinerGraphique(double frequences[], double coefs[]);
    void clearGraph(double frequences[]);

private:
    QChartView *graphique; // un widget pour afficher un graphe
    QChart *graphe; // la représentation d'un graphe
    QLineSeries *courbe; // les données
    QMap<int, QString> map;
};

#endif // IHMGRAPHIQUE_H

#include "ihmgraphique.h"

IhmGraphique::IhmGraphique(QWidget *parent, double frequence[13], double coef[13])
    : QMainWindow(parent)
{
    courbe = new QLineSeries();
    //*courbe << QPointF(200, 0.9993) << QPointF(250, 0.9651) << QPointF(315, 0.5411) << QPointF(400, 0.5100) << QPointF(500, 0.6530) << QPointF(630, 0.6274) << QPointF(800, 0.7204) << QPointF(1000, 0.6274)<< QPointF(1250, 0.5285)<< QPointF(1600, 0.4931)<< QPointF(2000, 0.6627)<< QPointF(2500, 0.5226)<< QPointF(3150, 0.4523);
    for(int i = 0; i < 13; i++)
    {
        *courbe << QPointF(frequence[i], coef[i]);
    }
    QPen pen(0x059605);
    pen.setColor("orange");
    pen.setWidth(3);
    pen.setStyle(Qt::DashLine);
    courbe->setPen(pen);

    // Le graphe
    graphe = new QChart();
    QString nom = "";
    graphe->addSeries(courbe);
    graphe->setTitle("Coefficient d'absorption du liege" + nom + " en fonction de la fréquence");
    // Légende
    graphe->legend()->hide();
    graphe->legend()->setAlignment(Qt::AlignBottom);

    // axe abscisses
    QValueAxis *axeX = new QValueAxis;
    axeX->setTickCount(13);
    axeX->setRange(200, 3150);
    axeX->setLabelFormat("%i");
    axeX->setTitleText("Fréquence");
    graphe->addAxis(axeX, Qt::AlignBottom);
    courbe->attachAxis(axeX);

    // axe ordonnées
    QValueAxis *axeY = new QValueAxis;
    axeY->setRange(0, 1);
    axeY->setLabelFormat("%.1f");
    axeY->setTitleText(QString::fromUtf8("Coefficient d'absorption"));
    graphe->addAxis(axeY, Qt::AlignLeft);
    courbe->setPointsVisible(true);
    //courbe->setPointLabelsFormat("@yPoint");
    //courbe->setPointLabelsVisible(true);
    courbe->attachAxis(axeY);

    // Le widget
    graphique = new QChartView(graphe);
    graphique->setRenderHint(QPainter::Antialiasing);

    setCentralWidget(graphique);
    resize(640, 480);
}

IhmGraphique::~IhmGraphique()
{

}


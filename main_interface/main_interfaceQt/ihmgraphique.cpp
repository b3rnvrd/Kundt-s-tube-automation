#include "ihmgraphique.h"

IhmGraphique::IhmGraphique(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Graphique mesures");
}

IhmGraphique::~IhmGraphique()
{

}

void IhmGraphique::dessinerGraphique(double frequences[13], double coefs[13])
{
    QMap<double, double> mesures;
    courbe = new QLineSeries();
    for(int i =0; i < 13; i++){
        mesures.insert(frequences[i],coefs[i]);
    }
    for(auto i = mesures.begin(), end = mesures.end(); i != end; i++)
    {
        *courbe << QPointF(i.key(),i.value());
        qDebug() << i.key() << i.value();
    }



    //*courbe << QPointF(200, 0.9993) << QPointF(250, 0.9651) << QPointF(315, 0.5411) << QPointF(400, 0.5100) << QPointF(500, 0.6530) << QPointF(630, 0.6274) << QPointF(800, 0.7204) << QPointF(1000, 0.6274)<< QPointF(1250, 0.5285)<< QPointF(1600, 0.4931)<< QPointF(2000, 0.6627)<< QPointF(2500, 0.5226)<< QPointF(3150, 0.4523);
    QPen pen(0x059605);
    pen.setColor("blue");
    pen.setWidth(3);
    pen.setStyle(Qt::DashLine);
    courbe->setPen(pen);

    // Le graphe
    graphe = new QChart();
    graphe->addSeries(courbe);
    graphe->setTitle("Coefficient d'absorption en fonction de la fréquence");
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

void IhmGraphique::clearGraph(double frequences[13])
{
    for(int i = 0; i < 13; i++)
        *courbe << QPointF(frequences[i],0);
}

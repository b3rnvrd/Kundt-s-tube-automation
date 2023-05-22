#include "ihmgraphique.h"

IhmGraphique::IhmGraphique(QWidget *parent)
    : QMainWindow(parent)
{
        courbe = new QLineSeries();
        *courbe << QPointF(200, 0.0198) << QPointF(250, 0.0158) << QPointF(315, 0.0126) << QPointF(400, 0.0100) << QPointF(500, 0.0080) << QPointF(630, 0.0063) << QPointF(800, 0.0050) << QPointF(1000, 0.0040)<< QPointF(1250, 0.0032)<< QPointF(1600, 0.0025)<< QPointF(2000, 0.0020)<< QPointF(2500, 0.0016)<< QPointF(3150, 0.0013);
        QPen pen(0x059605);
        pen.setColor("orange");
        pen.setWidth(3);
        pen.setStyle(Qt::DashLine);
        courbe->setPen(pen);

        // Le graphe
        graphe = new QChart();
        QString nom = "";
        graphe->addSeries(courbe);
        graphe->setTitle("Coefficient d'absorption du " + nom + " en fonction de la fréquence");
        // Légende
        graphe->legend()->hide();
        graphe->legend()->setAlignment(Qt::AlignBottom);

        // Les axes
        // Par défaut
        //graphe->createDefaultAxes();
        //graphe->axes(Qt::Horizontal).first()->setRange(0, 20);
        //graphe->axes(Qt::Vertical).first()->setRange(0, 10);

        // exemple avec un QValueAxis
        /*QValueAxis *axeX = new QValueAxis;
        axeX->setTickCount(10);
        axeX->setLabelFormat("%i");
        graphe->addAxis(axeX, Qt::AlignBottom);
        courbe->attachAxis(axeX);*/

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
        axeY->setRange(0, 0.1);
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

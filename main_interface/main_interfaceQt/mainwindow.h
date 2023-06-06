#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <visa.h>
#include "seriallink.h"
#include "ihmgraphique.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ViSession osc;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    char buf[256] = {0};
    double freq = 200, ampli, coef, tensionPos, pmax = 0, pmin = 10, pmesure, frequences[13], coefficients[13], previousCoef = 0;
    int etat = 0, incrementGraph = 0;
    QTimer *timer;
    QMap < double, QString> coef_par_freq;

private slots:

    void on_actionBase_de_donnees_triggered();

    void on_BtnStart_clicked();

    void on_BtnStop_clicked();

    void on_pushButtonGraphique_clicked();

    void on_pushButtonCoefficient_clicked();

    void on_pushButtonPort_clicked();

    void on_spinBoxPort_valueChanged();

    void on_comboBoxFreq_currentTextChanged(const QString &arg1);

    void on_actionRelancerConnexionOscillo_triggered();

    void on_pushButtonResetGraphique_clicked();

    void on_pushButton_clicked();

private:
    bool vers_la_droite = true,vers_la_gauche = false;
    Ui::MainWindow *ui;
    seriallink *arduino;
    IhmGraphique *graph;
    double checkPosition();
    double mesureTension();
    double movePosition(bool vers_la_droite, short limite_tension);
    double checkToMovePosition(bool vers_la_droite);
    void etatMachine();
};

#endif // MAINWINDOW_H

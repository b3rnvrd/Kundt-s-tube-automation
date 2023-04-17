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
    double freq, ampli, coef, tensionPos;
    int etat = 0;
    QTimer *timer;
    QMap < double, QString> coef_par_freq;

private slots:

    void on_actionBase_de_donnees_triggered();

    void on_BtnStart_clicked();

    void on_BtnStop_clicked();

    void on_actionAfficherGraphique_triggered();

    void on_pushButton_clicked();

private:
    bool vers_la_droite = true,vers_la_gauche = false;
    Ui::MainWindow *ui;
    seriallink *arduino;
    IhmGraphique *graph;
    double checkPosition();
    double mesureTension(bool mesure_max);
    double movePosition(bool vers_la_droite, short limite_tension);
    double checkToMovePosition(bool vers_la_droite);
    void etatMachine();
};

#endif // MAINWINDOW_H

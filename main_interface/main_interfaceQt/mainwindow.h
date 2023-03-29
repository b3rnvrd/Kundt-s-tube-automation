#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <visa.h>
#include "seriallink.h"

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
    double freq,ampli,coef;
private slots:

    void on_actionBase_de_donnees_triggered();

    void on_BtnStart_clicked();

    void on_BtnStop_clicked();

private:
    bool vers_la_droite = true,vers_la_gauche;
    Ui::MainWindow *ui;
    seriallink *arduino;
    double checkPosition();
    double mesureTension(bool mesure_max);
    void movePosition(bool vers_la_droite, double tensionPos, short limite_tension);
    void checkToMovePosition(bool vers_la_droite);
};

#endif // MAINWINDOW_H

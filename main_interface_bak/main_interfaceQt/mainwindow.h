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
    Ui::MainWindow *ui;
    seriallink *arduino;
    double checkPosition(bool droite = true);
    double mesure(bool max = true);
    void movePosition(bool droite = true, double tensionPos);
};

#endif // MAINWINDOW_H

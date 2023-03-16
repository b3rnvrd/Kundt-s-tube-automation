#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <visa.h>
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
double freq,ampli;
private slots:
    void on_BtnApplyFreqAmpl_clicked();

    void on_BtnMeasure_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

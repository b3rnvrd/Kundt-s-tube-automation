#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // ouverture de la session ressource manager
    ViSession rscmng;
    ViStatus stat = viOpenDefaultRM(&rscmng);

    // Recherche de l'oscilloscope
    ViChar viFound[VI_FIND_BUFLEN];
    ViUInt32 nFound;
    ViFindList listOfFound;
    stat = viFindRsrc(rscmng, (ViString)"USB?*", &listOfFound, &nFound, viFound);

    stat = viOpen(rscmng, viFound, VI_NULL, VI_NULL, &osc);
    if (stat < VI_SUCCESS)
    {
        qDebug() << "Echec connexion oscilloscope";

    }
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    freq = ui->freqEdit->text().toDouble();
    ampli = ui->amplEdit->text().toDouble();
    viPrintf(osc,":APPLY:SIN ,%f,%f\n", freq, ampli); //on applique un signal sinusoidal de fréquence et amplitude choisies
}

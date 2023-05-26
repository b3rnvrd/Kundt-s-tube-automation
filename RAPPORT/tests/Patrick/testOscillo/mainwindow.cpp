#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BtnMesure_clicked()
{
    // ouverture de la session ressource manager
    ViSession rscmng;
    ViStatus stat = viOpenDefaultRM(&rscmng);

    // Recherche de l'oscilloscope
    ViChar viFound[VI_FIND_BUFLEN];
    ViUInt32 nFound;
    ViFindList listOfFound;
    stat = viFindRsrc(rscmng, (ViString)"USB?*", &listOfFound, &nFound, viFound);
    ViSession osc;
    stat = viOpen(rscmng, viFound, VI_NULL, VI_NULL, &osc);
    if (stat < VI_SUCCESS) qDebug() << "failed";
    char buf[256] = {0};
    viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN1\n"); //tension mesurée sur le channel 1
    viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
    qDebug()<<buf;
    QString essai =QString(buf);
    essai=essai+"V";
    qDebug()<<essai;
    ui->EdtOscillo->setText(essai);
    viPrintf(osc, (ViString)":APPLY:SIN 1500,5,0,0\n"); //on applique un signal sinusoidal de fréquence 1000 amplitude 5V offset 0 phase 0
    //viPrintf(osc, (ViString)":FREQuency 1000 \n"); //On applique une fréquence de 1000hz a la sortie 1 du gbf de l'oscillo
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <qstring.h>
#include <iostream>
#include <string>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ouverture de la session ressource manager
    ViSession rscmng;
    ViStatus stat = viOpenDefaultRM(&rscmng);

    // Recherche de l'oscilloscope
    ViChar viFound[VI_FIND_BUFLEN];
    ViUInt32 nFound;
    ViFindList listOfFound;
    stat = viFindRsrc(rscmng, (ViString)"USB?*", &listOfFound, &nFound, viFound);

    stat = viOpen(rscmng, viFound, VI_NULL, VI_NULL, &osc);
    if (stat < VI_SUCCESS) qDebug() << "failed";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnApplyFreqAmpl_clicked()
{
    freq=ui->comboBoxFreq->currentText().toDouble();
    ampli=ui->LineEditAmpl->text().toDouble();
    qDebug()<<freq;//verif valeur freq
    qDebug()<<ampli; //verif valeur ampli
    viPrintf(osc,":APPLY:SIN ,%f,%f\n",freq,ampli); //on applique un signal sinusoidal de fréquence et amplitude choisis
}

void MainWindow::on_BtnMeasure_clicked()
{
    char buf[256] = {0};
    viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN1\n"); //tension mesurée sur le channel 1
    viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
    qDebug()<<buf;
    double tension= QString(buf).toDouble();
    QString retour=QString::number(tension);
    retour=retour+"V";
    qDebug()<<retour;
    ui->LineEditVmax->setText(retour);
    qDebug()<<tension;
}

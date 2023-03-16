#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDebug>
#include <QMessageBox>

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
        QMessageBox::critical(this,"Attention","oscilloscope non connecté",QMessageBox::Ok);
        exit(0);
        qDebug() << "failed";

    }
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionBase_de_donnees_triggered()
{
    //    QProcess::setProgram("..\..\database\databaseQt\debug\MySql.exe");
    //    QProcess::startDetached();
}

void MainWindow::on_BtnStart_clicked()
{
    freq=ui->comboBoxFreq->currentText().toDouble();
    ampli=ui->EditAmpli->text().toDouble();
    if(ampli>5 ||ampli<0)
    {
        QMessageBox::critical(this,"Attention","amplitude superieure à 5V ou inférieure a 0V",QMessageBox::Ok);
        return;
    }
    qDebug()<<freq;//verif valeur freq
    qDebug()<<ampli; //verif valeur ampli
    viPrintf(osc,":APPLY:SIN ,%f,%f\n",freq,ampli); //on applique un signal sinusoidal de fréquence et amplitude choisis
    double pmax,pmin,n;
    /*
     *
     *
     *
     *
     * mesure pmax& pmin
     *
     *
     *
     *
     * */
    n=pmax/pmin;
    coef=1-pow((n-1)/(n+1),2);
    QString retour = QString(coef).number();
    ui->Editcoef->setText(retour);
}

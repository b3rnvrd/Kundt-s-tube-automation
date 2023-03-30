#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDebug>
#include <QMessageBox>
#include <unistd.h>

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
        QMessageBox::critical(this,"Attention","Echec connexion oscilloscope",QMessageBox::Ok);
        //  exit(0);//fermeture de la fenetre mainwindow
        qDebug() << "Echec connexion oscilloscope";

    }
    ui->setupUi(this);

    arduino = new seriallink;

    arduino->openConnection();

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
    freq = ui->comboBoxFreq->currentText().toDouble();
    ampli = ui->EditAmpli->text().toDouble();
    if(ampli > 5 || ampli < 0)
    {
        QMessageBox::critical(this,"Attention","amplitude supérieure à 5V ou inférieure a 0V",QMessageBox::Ok);
        return;
    }
    viPrintf(osc,":APPLY:SIN ,%f,%f\n", freq, ampli); //on applique un signal sinusoidal de fréquence et amplitude choisies
    //    viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
    //    viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
    double tensionPos = 0;
    tensionPos = checkPosition();
    double n, tension_max_mesuree , tension_min_mesuree;
    if(tensionPos > -5 || tensionPos < 5)  // -5 et 5 sont les tension max et min pour la position du micro
    {
        if(tensionPos < 0)
        {
            do
            {
                tension_max_mesuree = checkToMovePosition(vers_la_droite);
                tensionPos = checkPosition();
            }
            while(tensionPos < 4.5);
            do
            {
                tension_min_mesuree = checkToMovePosition(vers_la_gauche);
                tensionPos = checkPosition();
            }
            while(tensionPos > -4.5);

        }
        else
        {
            do
            {
                tension_max_mesuree = checkToMovePosition(vers_la_gauche);
                tensionPos = checkPosition();
            }
            while(tensionPos > -4.5);
            do
            {
                tension_min_mesuree = checkToMovePosition(vers_la_droite);
                tensionPos = checkPosition();
            }
            while(tensionPos < 4.5);

        }

        n = tension_max_mesuree/tension_min_mesuree;

        coef = 1 - pow((n-1)/(n+1),2);// formule calcul coef absobtion

        ui->Editcoef->setText(QString::number(coef));
    }
    else
        QMessageBox::critical(this,"Attention","Verifiez la position du micro",QMessageBox::Ok);



    //    for(int i = 0; i < 1; i++)
    //    {
    //        checkPosition();
    //        while(!(arduino->isWritable()));
    //            arduino->write("d");





    //        ui->Editcoef->setText(QString::number(mesureTension(vers_la_droite)));

    //    }
    //    viPrintf(osc, (ViString)":OUTP1 :0\n");
}

void MainWindow::on_BtnStop_clicked()//Arret d'urgence
{
    while(!(arduino->isWritable()));
    arduino->write("p");

    viPrintf(osc, (ViString)":OUTP1 :0\n");     //COUPER LE GBF DE L'OSCILLO

}

double MainWindow::checkPosition()//retourne la tension qui donne la position du micro
{
    viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
    viScanf(osc,(ViString)"%t",&buf);
    double tensionPos = QString(buf).toDouble();
    return tensionPos;
}

double MainWindow::mesureTension(bool mesure_max = true)// mesure de la tension
{
    double tension = 0, tension_mesuree = 0;
    viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN1\n"); //tension mesurée sur le channel 1
    viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
    tension_mesuree = QString(buf).toDouble();
    if(mesure_max)
    {
        if(tension < tension_mesuree)
            tension = tension_mesuree;
    }
    else
    {
        if(tension > tension_mesuree)
            tension = tension_mesuree;
    }
    viPrintf(osc, (ViString)":OUTP1 :0\n");

    return tension;
}

double MainWindow::movePosition(bool vers_la_droite, double tensionPos, short limite_tension)//mouvement du micro
{
    const char* caractere;
    double tension_mesuree;
    vers_la_droite ? caractere = "d" : caractere = "g";
    double pos = 0;
    for(pos = tensionPos; vers_la_droite ? pos < limite_tension : pos > limite_tension; pos = checkPosition())
    {
        while(!(arduino->isWritable()))
        {
            QMessageBox::critical(this,"Attention","L'écriture a échoué",QMessageBox::Ok);
            qDebug() << "Couldn't write to serial!";
            arduino->openConnection();
            sleep(10);
        }
        arduino->write(caractere); //mouvement micro vers le HP
        tension_mesuree = 0;

        if(tension_mesuree < mesureTension(vers_la_droite))
            tension_mesuree = mesureTension(vers_la_droite);
        else
            tension_mesuree = mesureTension(vers_la_droite);


        return tension_mesuree;

    }

}

double MainWindow::checkToMovePosition(bool vers_la_droite) //verif cote mouvement voulu
{
    double tensionPos = 0, tension_mesuree;
    tensionPos = checkPosition();

    short limite_tension = 0;

    tension_mesuree = 0;

    if(vers_la_droite)  //côté droit
    {
        limite_tension = 5;
        tension_mesuree = movePosition(vers_la_droite,tensionPos,limite_tension);

    }
    else    //côté gauche
    {
        limite_tension = -5;
        tension_mesuree = movePosition(vers_la_droite,tensionPos,limite_tension);
    }
    return tension_mesuree;
}

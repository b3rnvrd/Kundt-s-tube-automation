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
    freq=ui->comboBoxFreq->currentText().toDouble();
    ampli=ui->EditAmpli->text().toDouble();
    if(ampli > 5 || ampli < 0)
    {
        QMessageBox::critical(this,"Attention","amplitude supérieure à 5V ou inférieure a 0V",QMessageBox::Ok);
        return;
    }
    qDebug()<<freq;//verif valeur freq
    qDebug()<<ampli; //verif valeur ampli
    viPrintf(osc,":APPLY:SIN ,%f,%f\n",freq,ampli); //on applique un signal sinusoidal de fréquence et amplitude choisies
    viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
    viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
    double tensionPos = checkPosition();
    if(tensionPos > -5||tensionPos < 5)  // -5 et 5 sont les tension max et min pour la position du micro
    {
        if(tensionPos < 0){
            ui->Editcoef->setText("micro eloigné du HP");
            checkToMovePosition(vers_la_droite);
            checkToMovePosition(vers_la_gauche);
            //            for(double pos=tensionPos ;pos>-5;pos=tensionPos)
            //            {
            //                if(arduino->isWritable())
            //                    arduino->write("d"); //mouvement micro vers le HP
            //                ui->Editcoef->setText("vers la droite");
            //                else
            //                {
            //                    QMessageBox::critical(this,"Attention","L'écriture a échoué",QMessageBox::Ok);
            //                    qDebug() << "Couldn't write to serial!";
            //                    arduino->openConnection();
            //                }
            //                sleep(1);
            //                viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN1\n"); //tension mesurée sur le channel 1
            //                viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
            //                pmesure= QString(buf).toDouble();
            //                if(pmax<pmesure)
            //                    pmax=pmesure;
            //                viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
            //                viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
            //                tensionPos= QString(buf).toDouble();

            //            }
            //            for(double pos=tensionPos ;pos<5;pos=tensionPos)
            //            {

            //                if(arduino->isWritable())
            //                    arduino->write("g"); //mouvement micro vers le HP
            //                ui->Editcoef->setText("vers la gauche");
            //                else
            //                {
            //                    QMessageBox::critical(this,"Attention","L'écriture a échoué",QMessageBox::Ok);
            //                    qDebug() << "Couldn't write to serial!";
            //                    arduino->openConnection();
            //                }

            //                sleep(1);
            //                viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN1\n"); //tension mesurée sur le channel 1
            //                viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
            //                pmesure= QString(buf).toDouble();
            //                if(pmin>pmesure)
            //                    pmin=pmesure;
            //                viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
            //                viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
            //                tensionPos= QString(buf).toDouble();
            //            }
        }
        else
        {
            checkToMovePosition(vers_la_gauche);
            checkToMovePosition(vers_la_droite);
        }

        //        {
        //            for(double pos=tensionPos ;pos<5;pos=tensionPos)
        //            {

        //                if(arduino->isWritable())
        //                    arduino->write("g"); //mouvement micro vers le HP
        //                ui->Editcoef->setText("vers la gauche");
        //                else
        //                {
        //                    QMessageBox::critical(this,"Attention","L'écriture a échoué",QMessageBox::Ok);
        //                    qDebug() << "Couldn't write to serial!";
        //                    arduino->openConnection();
        //                }

        //                sleep(1);
        //                viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN1\n"); //tension mesurée sur le channel 1
        //                viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
        //                pmesure= QString(buf).toDouble();
        //                if(pmin>pmesure)
        //                    pmin=pmesure;
        //                viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
        //                viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
        //                tensionPos= QString(buf).toDouble();
        //            }
        //            for(double pos=tensionPos ;pos>-5;pos=tensionPos)
        //            {

        //                if(arduino->isWritable())
        //                    arduino->write("d"); //mouvement micro vers le HP
        //                ui->Editcoef->setText("vers la droite");
        //                else
        //                {
        //                    QMessageBox::critical(this,"Attention","L'écriture a échoué",QMessageBox::Ok);
        //                    qDebug() << "Couldn't write to serial!";
        //                    arduino->openConnection();
        //                }

        //                sleep(1);
        //                viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN1\n"); //tension mesurée sur le channel 1
        //                viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
        //                pmesure= QString(buf).toDouble();
        //                if(pmax<pmesure)
        //                    pmax=pmesure;
        //                viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
        //                viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
        //                tensionPos= QString(buf).toDouble();
        //            }

    }
    else
    QMessageBox::critical(this,"Attention","Verifiez la position du micro",QMessageBox::Ok);


    bool max = true, min = false;
    double n, tension_max_mesuree = mesureTension(max), tension_min_mesuree = mesureTension(min);

    n = tension_max_mesuree/tension_min_mesuree;
    coef = 1 - pow((n-1)/(n+1),2);// formule calcul coef absobtion
    QString retour = QString::number(coef);
    retour += "V";
    ui->Editcoef->setText(retour);

}

void MainWindow::on_BtnStop_clicked()
{
    if(arduino->isWritable())
        arduino->write("p");

    else
    {
        QMessageBox::critical(this,"Attention","L'écriture a échoué",QMessageBox::Ok);
        qDebug() << "Couldn't write to serial!";
        arduino->openConnection();
    }
}

double MainWindow::checkPosition()
{
    viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
    viScanf(osc,(ViString)"%t",&buf);
    double tensionPos = QString(buf).toDouble();
    return tensionPos;
}

double MainWindow::mesureTension(bool mesure_max = true)
{
    double tension, tension_mesuree;
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
    viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
    viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace

    return tension;
}

void MainWindow::movePosition(bool vers_la_droite, double tensionPos, short limite_tension)
{
    const char* caractere;

    vers_la_droite ? caractere = "d" : caractere = "g";
    for(double pos = tensionPos; vers_la_droite ? pos > limite_tension : pos < limite_tension; pos = tensionPos)
    {
        if(arduino->isWritable())
            arduino->write(caractere); //mouvement micro vers le HP
        //ui->Editcoef->setText("vers la droite");
        else
        {
            QMessageBox::critical(this,"Attention","L'écriture a échoué",QMessageBox::Ok);
            qDebug() << "Couldn't write to serial!";
            arduino->openConnection();
        }
        sleep(1);
    }
}

double MainWindow::checkToMovePosition(bool vers_la_droite)
{
    double tensionPos = checkPosition();
    short limite_tension;

    if(vers_la_droite)  //côté droit
    {
        limite_tension = -5;
        movePosition(vers_la_droite,tensionPos,limite_tension);
        return mesureTension(vers_la_droite);
    }
    else    //côté gauche
    {
        limite_tension = 5;
        movePosition(!vers_la_droite,tensionPos,limite_tension);
        return mesureTension(!vers_la_droite);
    }
}

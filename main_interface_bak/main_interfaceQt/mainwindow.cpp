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
    //connect(arduino, &seriallink::gotNewData, this, &MainWindow::updateGUI);
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_actionBase_de_donnees_triggered()
{
    QProcess *process = new QProcess(this);
    QString program = "MySqlQt.exe";
    QString folder = "C:\\Users\\etudiant\\Documents\\GitHub\\tube_de_kundt\\Apps\\BDD";
    process->start(program, QStringList() << folder);
    qDebug() << process->errorString();
}

void MainWindow::on_BtnStart_clicked()
{
    freq=ui->comboBoxFreq->currentText().toDouble();
    ampli=ui->EditAmpli->text().toDouble();
    if(ampli > 5 || ampli < 0)
    {
        QMessageBox::critical(this,"Attention","amplitude superieure à 5V ou inférieure a 0V",QMessageBox::Ok);
        return;
    }
    qDebug()<<freq;//verif valeur freq
    qDebug()<<ampli; //verif valeur ampli
    viPrintf(osc,":APPLY:SIN ,%f,%f\n",freq,ampli); //on applique un signal sinusoidal de fréquence et amplitude choisis
    double pmax,pmin,n,pmesure;
    viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
    viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
    double tensionPos= QString(buf).toDouble();
    if(arduino->isWritable())
        arduino->write("t");

    else
    {
        QMessageBox::critical(this,"Attention","L'écriture a échoué",QMessageBox::Ok);
        qDebug() << "Couldn't write to serial!";
        arduino->openConnection();
    }
    while(tensionPos>-5||tensionPos<5)  // -5 et 5 sont les tension max et min pour la position du micro
    {
        if(tensionPos<0){
            ui->Editcoef->setText("tension pos micro <0");
            for(double pos=tensionPos ;pos>-5;pos=tensionPos)
            {
                if(arduino->isWritable())
                    arduino->write("d"); //mouvement micro vers le HP
                ui->Editcoef->setText("vers la droite");
                else
                {
                    QMessageBox::critical(this,"Attention","L'écriture a échoué",QMessageBox::Ok);
                    qDebug() << "Couldn't write to serial!";
                    arduino->openConnection();
                }
                sleep(1);
                viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN1\n"); //tension mesurée sur le channel 1
                viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
                pmesure= QString(buf).toDouble();
                if(pmax<pmesure)
                    pmax=pmesure;
                viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
                viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
                tensionPos= QString(buf).toDouble();

            }
            for(double pos=tensionPos ;pos<5;pos=tensionPos)
            {

                if(arduino->isWritable())
                    arduino->write("g"); //mouvement micro vers le HP
                ui->Editcoef->setText("vers la gauche");
                else
                {
                    QMessageBox::critical(this,"Attention","L'écriture a échoué",QMessageBox::Ok);
                    qDebug() << "Couldn't write to serial!";
                    arduino->openConnection();
                }

                sleep(1);
                viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN1\n"); //tension mesurée sur le channel 1
                viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
                pmesure= QString(buf).toDouble();
                if(pmin>pmesure)
                    pmin=pmesure;
                viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
                viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
                tensionPos= QString(buf).toDouble();
            }
        }
        else
        {
            for(double pos=tensionPos ;pos<5;pos=tensionPos)
            {

                if(arduino->isWritable())
                    arduino->write("g"); //mouvement micro vers le HP
                ui->Editcoef->setText("vers la gauche");
                else
                {
                    QMessageBox::critical(this,"Attention","L'écriture a échoué",QMessageBox::Ok);
                    qDebug() << "Couldn't write to serial!";
                    arduino->openConnection();
                }

                sleep(1);
                viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN1\n"); //tension mesurée sur le channel 1
                viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
                pmesure= QString(buf).toDouble();
                if(pmin>pmesure)
                    pmin=pmesure;
                viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
                viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
                tensionPos= QString(buf).toDouble();
            }
            for(double pos=tensionPos ;pos>-5;pos=tensionPos)
            {

                if(arduino->isWritable())
                    arduino->write("d"); //mouvement micro vers le HP
                ui->Editcoef->setText("vers la droite");
                else
                {
                    QMessageBox::critical(this,"Attention","L'écriture a échoué",QMessageBox::Ok);
                    qDebug() << "Couldn't write to serial!";
                    arduino->openConnection();
                }

                sleep(1);
                viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN1\n"); //tension mesurée sur le channel 1
                viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
                pmesure= QString(buf).toDouble();
                if(pmax<pmesure)
                    pmax=pmesure;
                viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
                viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
                tensionPos= QString(buf).toDouble();
            }
        }
        break;
    }

    n = pmax/pmin;
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

double MainWindow::checkPosition(bool droite = true)
{
    double tensionPos = QString(buf).toDouble();
    double valeur = mesure(false);                  //cote gauche
    short limite = 5;                               //cote gauche
    if(droite)                  //cote droit
    {
        limite = -5;
        movePosition(tensionPos);
        valeur = mesure();
    }
    else
        movePosition(false,tensionPos);        //cote gauche
    tensionPos = QString(buf).toDouble();
    return tensionPos;
}

double MainWindow::mesure(bool max = true)
{
    double valeur, pmesure;
    viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN1\n"); //tension mesurée sur le channel 1
    viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
    pmesure = QString(buf).toDouble();
    if(max)
    {
        if(valeur < pmesure)
            valeur = pmesure;
    }
    else
        if(valeur > pmesure)
            valeur = pmesure;
    viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
    viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace

    return valeur;
}

void MainWindow::movePosition(bool droite = true, double tensionPos)
{
    char caractere = "d";
    if(!droite)
        caractere = "g";
    for(double pos=tensionPos; pos>limite; pos=tensionPos)
    {
        if(arduino->isWritable())
            arduino->write(caractere); //mouvement micro vers le HP
        ui->Editcoef->setText("vers la droite");
        else
        {
            QMessageBox::critical(this,"Attention","L'écriture a échoué",QMessageBox::Ok);
            qDebug() << "Couldn't write to serial!";
            arduino->openConnection();
        }
        sleep(1);
}


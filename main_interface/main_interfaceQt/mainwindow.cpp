#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDebug>
#include <QMessageBox>
#include <unistd.h>
#include <QThread>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    timer = new QTimer(this);
    timer->interval();
    QObject::connect(timer,&QTimer::timeout, [this](){ etatMachine(); });
    timer->start(1);
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
    QProcess *process = new QProcess(this);
    process->start("\"C:\\Users\\etudiant\\Documents\\GitHub\\tube_de_kundt\\Apps\\BDD\\MySqlQt.exe\"");
    qDebug() << process->errorString();
}

void MainWindow::on_BtnStart_clicked()
{
    viPrintf(osc, (ViString)"*RST\n");
    freq = ui->comboBoxFreq->currentText().toDouble();
    ampli = ui->EditAmpli->text().toDouble();
    if(ampli > 5 || ampli < 0)
    {
        QMessageBox::critical(this,"Attention","amplitude supérieure à 5V ou inférieure a 0V",QMessageBox::Ok);
        return;
    }
    viPrintf(osc,":APPLY:SIN ,%f,%f\n", freq, ampli); //on applique un signal sinusoidal de fréquence et amplitude choisies
    viPrintf(osc,":AUT\n");// autoset oscillo
    viPrintf(osc, (ViString)":CHAN3:SCAL 4\n");
    tensionPos = checkPosition();
//    double n, tension_max_mesuree = 1, tension_min_mesuree = 1;



    if(tensionPos > -5 && tensionPos < 5)  // -5 et 5 sont les tension max et min pour la position du micro
    {
        etat=1;

        QByteArray recu = arduino->read();
        qDebug() << recu << tensionPos;

        if (recu == "d_ACK")
            etat = 2;
        else
            if(recu == "g_ACK")
                etat = 4;
        
//        n = tension_max_mesuree/tension_min_mesuree;
        
        //coef = 1 - pow((n-1)/(n+1),2);  // formule calcul coef absorption
//        coef = 1;
//        ui->Editcoef->setText(QString::number(coef));

        coef_par_freq.insert(freq, QString::number(coef));
    }
    else
        QMessageBox::critical(this,"Attention","Verifiez la position du micro",QMessageBox::Ok);

}

void MainWindow::on_BtnStop_clicked()//Arret d'urgence
{
    while(!(arduino->isWritable()));
    arduino->write("s");
    
    viPrintf(osc, (ViString)":OUTP1 :0\n");     //COUPER LE GBF DE L'OSCILLO
    
}

double MainWindow::checkPosition()//retourne la tension qui donne la position du micro
{
    for(int i =0; i<256; i++)
        buf[i] = 0;
    viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
    viScanf(osc,(ViString)"%t",&buf);
    tensionPos = QString(buf).toDouble();
    return tensionPos;
}

double MainWindow::mesureTension()// mesure de la tension
{
    double tension = 0, tension_mesuree = 0;
    viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN1\n"); //tension mesurée sur le channel 1
    viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
    tension_mesuree = QString(buf).toDouble();
//    if(mesure_max)
//    {
//        if(tension < tension_mesuree)
//            tension = tension_mesuree;
//    }
//    else
//    {
//        if(tension > tension_mesuree)
//            tension = tension_mesuree;
//    }
//    //    viPrintf(osc, (ViString)":OUTP1 :0\n");
    
    return tension_mesuree;
}

double MainWindow::movePosition(bool vers_la_droite, short limite_tension) //mouvement du micro
{
    const char* caractere;
    double tension_mesuree, tension = 0;
    vers_la_droite ? caractere = "d" : caractere = "g";
    double pos = 0;
    for(pos = tensionPos; vers_la_droite ? pos < limite_tension : pos > limite_tension; pos += 1)
    {
        while(!(arduino->isWritable()))
        {
            QMessageBox::critical(this,"Attention","L'écriture a échoué, tentative de reconnexion avec la carte Arduino",QMessageBox::Ok);
            qDebug() << "Couldn't write to serial!";
            arduino->openConnection();
            sleep(10);
        }
        arduino->write(caractere); //mouvement micro vers le HP
        
        tension_mesuree = 0;
        //tension_mesuree = mesureTension(vers_la_droite);
        
        if(tension < tension_mesuree)
            tension = tension_mesuree;
        else
            tension = tension_mesuree;
    }
    return tension;
    
}

double MainWindow::checkToMovePosition(bool vers_la_droite) //verif cote mouvement voulu
{
    double tension_mesuree;
    tensionPos = checkPosition();
    
    short limite_tension = 0;
    
    tension_mesuree = 0;
    
    if(vers_la_droite)  //côté droit
    {
        limite_tension = 5;
        tension_mesuree = movePosition(vers_la_droite,limite_tension);
        
    }
    else    //côté gauche
    {
        limite_tension = -5;
        tension_mesuree = movePosition(vers_la_droite,limite_tension);
    }
    return tension_mesuree;
}

void MainWindow::etatMachine()
{
    tensionPos = checkPosition();
    switch (etat)
    {
    case 0:
        break;
    case 1:
        qDebug()<<"demande deplacement droite";
        if(tensionPos >= 4.5)
            etat = 2;
        arduino->write("d");
        pmesure=mesureTension();
        if((pmax<pmesure)&& pmesure<10)
            pmax=pmesure;
        qDebug()<<pmax;
//        viPrintf(osc,":AUT\n");// autoset oscillo
        sleep(1);
        break;

    case 2:
        qDebug()<<"demande deplacement gauche";
        if(tensionPos <= -4)
            etat = 4;
        pmesure=0;
        arduino->write("g");
        pmesure=mesureTension();
        if(pmesure<pmin)
            pmin=pmesure;
                qDebug()<<pmin;
//        viPrintf(osc,":AUT\n");// autoset oscillo
        sleep(1);
        break;
    case 4:
coef=1-pow(((pmax/pmin)-1)/((pmax/pmin)-1),2);
        viPrintf(osc, (ViString)":OUTP1 :0\n");
        arduino->write("s");
        timer->stop();
        break;
    }
}
void MainWindow::on_pushButtonGraphique_clicked()
{
    graph = new IhmGraphique(0,coef_par_freq);
    graph->show();
}

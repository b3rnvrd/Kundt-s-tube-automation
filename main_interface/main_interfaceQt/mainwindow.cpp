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
        qDebug() << "Echec connexion oscilloscope";
        
    }
    ui->setupUi(this);
    viPrintf(osc, (ViString)":CHAN3:SCAL 4\n");
    arduino = new seriallink;
    arduino->openConnection();
    arduino->write("o");

    for(int i = 0; i < 13; i++)
    {
        frequences[i] = i*500;
        coefficients[i] = {0.01};
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionBase_de_donnees_triggered()
{
    QProcess *process = new QProcess(this);
    process->start("\"C:\\Users\\etudiant\\Desktop\\tube_de_kundt\\Apps\\BDD\\MySqlQt.exe\"");            //chemin Eliott et Patrick
    qDebug() << process->errorString();
}

void MainWindow::on_BtnStart_clicked()
{
    freq = ui->comboBoxFreq->currentText().toDouble();
    ampli = ui->EditAmpli->text().toDouble();
    if(ampli > 5 || ampli < 1)
    {
        QMessageBox::critical(this,"Attention","amplitude supérieure à 5V ou inférieure a 1V",QMessageBox::Ok);
        return;
    }
    viPrintf(osc,":APPLY:SIN ,%f,%f\n", freq, ampli); //on applique un signal sinusoidal de fréquence et amplitude choisies
    viPrintf(osc,":AUT\n");// autoset oscillo
    viPrintf(osc, (ViString)":CHAN3:SCAL 10\n");
    viPrintf(osc, (ViString)":CHAN3:SCAL 10\n");
    tensionPos = checkPosition();
    //    double n, tension_max_mesuree = 1, tension_min_mesuree = 1;



    if(tensionPos > -5 && tensionPos < 5)  // -5 et 5 sont les tension max et min pour la position du micro

    {

        etat = 1;
        timer->start(1);


        QByteArray recu = arduino->read();
        qDebug() << recu << tensionPos;

        if (recu == "d_ACK")
            etat = 2;
        else
            if(recu == "g_ACK")
                etat = 4;
    }
    else
        QMessageBox::critical(this,"Attention","Verifiez la position du micro",QMessageBox::Ok);

}

void MainWindow::on_BtnStop_clicked()   //Arret d'urgence
{
    while(!(arduino->isWritable()));
    arduino->write("s");
    
    viPrintf(osc, (ViString)":OUTP1 :0\n");     //COUPER LE GBF DE L'OSCILLO
    etat = 0;
    
}

double MainWindow::checkPosition()//retourne la tension qui donne la position du micro
{
    for(int i = 0; i < 256; i++)
        buf[i] = 0;
    viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN3\n"); //tension mesurée sur le channel 3
    viScanf(osc,(ViString)"%t",&buf);
    tensionPos = QString(buf).toDouble();
    return tensionPos;
}

double MainWindow::mesureTension()// mesure de la tension
{
    double tension_mesuree = 0;
    viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN1\n"); //tension mesurée sur le channel 1
    viScanf(osc,(ViString)"%t",&buf);       //Lecture du resultat %t récupére toute la chaine de caractere si separé par un espace
    tension_mesuree = QString(buf).toDouble();
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
        qDebug() << "demande deplacement droite" << "tensionPos : " << tensionPos;
        if(tensionPos >= 3)
            etat = 2;
        arduino->write("d");
        pmesure = mesureTension();
        if((pmax<pmesure) && pmesure < 10)
            pmax = pmesure;
        qDebug() << pmax;
        sleep(1);
        break;

    case 2:
        qDebug()<<"demande deplacement gauche" << "tensionPos : " << tensionPos;
        if(tensionPos <= -3)
            etat = 3;
        pmesure = 0;
        arduino->write("g");
        pmesure=mesureTension();
        if(pmesure < pmin)
            pmin = pmesure;
        qDebug() << pmin;
        sleep(1);
        break;
    case 3:
        viPrintf(osc, (ViString)":OUTP1 :0\n");
        timer->stop();
        frequences[i] = freq;
        coefficients[i] = coef;
        i++;
        break;
    }
}

void MainWindow::on_pushButtonGraphique_clicked()
{
    graph = new IhmGraphique(0);
    graph->dessinerGraphique(frequences,coefficients);
    graph->show();
}

void MainWindow::on_pushButtonCoefficient_clicked()
{
    double n = pmax / pmin;
    coef = pow((n-1)/(n+1),2);
    coef = 1 - coef;

    qDebug() << coef;

    ui->Editcoef->setText(QString::number(coef,'f',3));
    if(arduino->isOpen())
    {
        arduino->write("f");
        arduino->closeConnection();
    }
    arduino->openConnection();
    arduino->write("o");
    arduino->clear();
    QByteArray donnees_a_afficher = ("$frequence : " + QByteArray::number(freq) + "      coef : " + QByteArray::number(coef));
    arduino->write(donnees_a_afficher);
}

void MainWindow::on_pushButtonPort_clicked()
{
    QString port = ui->spinBoxPort->text();
    arduino->setPort(port);
    arduino->openConnection();
    if(!arduino->isOpen())
        qDebug() << "Problème à l'ouverture du port sélectionné";
    else
        qDebug() << "connexion au nouveau port COM ok!";
    arduino->write("o");

    qDebug() <<"port demandé : " + port;
    tensionPos=checkPosition();
    while(tensionPos>0)
        arduino->write("g");
}

void MainWindow::on_spinBoxPort_valueChanged()
{
    arduino->write("f");
    arduino->closeConnection();
}

void MainWindow::on_comboBoxFreq_currentTextChanged(const QString &arg1)
{
    freq = arg1.toDouble();
    qDebug() << "changement de frequence : " << freq;
}

void MainWindow::on_actionRelancerConnexionOscillo_triggered()
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
        qDebug() << "Echec connexion oscilloscope";

    }
}

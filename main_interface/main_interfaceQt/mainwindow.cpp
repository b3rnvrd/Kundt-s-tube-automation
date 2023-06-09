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


    graph = new IhmGraphique(0);
    for(int i = 0; i < 13; i++)
    {

        coefficients[i] = {0};
    }
    frequences[0] = {200};
    frequences[1] = {250};
    frequences[2] = {315};
    frequences[3] = {400};
    frequences[4] = {500};
    frequences[5] = {630};
    frequences[6] = {800};
    frequences[7] = {1000};
    frequences[8] = {1250};
    frequences[9] = {1600};
    frequences[10] = {2000};
    frequences[11] = {2500};
    frequences[12] = {3150};
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionBase_de_donnees_triggered()
{
    QProcess *process = new QProcess(this);
    process->start("\"C:\\Users\\etudiant\\Desktop\\tube_de_kundt\\Apps\\BDD\\MySqlQt.exe\"");       //chemin Eliott et Patrick
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
    viPrintf(osc, (ViString)":CHAN1:SCAL 10\n"); // echelle verticale voie 1 a 10V
    viPrintf(osc, (ViString)":CHAN3:SCAL 10\n");//echelle verticale voie 3 a 10V
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
    arduino->clear();
    arduino->write("s"); //envoi d'un "s" sur la liaison serie pour arreter le moteur
    viPrintf(osc, (ViString)":OUTP1 :0\n");     //COUPER LE GBF DE L'OSCILLO
    etat = 0;
    
}

double MainWindow::checkPosition()//retourne la tension qui donne la position du micro
{
    for(int i = 0; i < 256; i++)
        buf[i] = 0; //on vide le buffer
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
        arduino->clear();
        qDebug() << "demande deplacement droite" << "tensionPos : " << tensionPos;
        if(tensionPos >= 4.5) //on garde de la marge car les instructions s'accumulent
            etat = 2;
        arduino->write("d"); //envoi d'un "d" sur la liaison serie pour indiquer au moteur qu'il doit aller a droite
        pmesure = mesureTension();
        if((pmax<pmesure) && pmesure < 10) //pmax prend la valeur de pmesure si elle est superieure a pmax et si pmesure est > 10 il y a probablement eu du bruit lors de la mesure
            pmax = pmesure;
        qDebug() << pmax;
        sleep(3);
        break;

    case 2:
        arduino->clear();
        qDebug()<<"demande deplacement gauche" << "tensionPos : " << tensionPos;
        if(tensionPos <= -2.9)//on garde de la marge car les instructions s'accumulent
            etat = 3;
        pmesure = 0;
        arduino->write("g");// envoi d'un "g" sur la liasion serie pour indiquer au moteur qu'il doit aller a gauche
        pmesure=mesureTension();
        if(pmesure < pmin)  // pmin prends la valeur de pmesure si elle est inferieure a pmin
            pmin = pmesure;
        qDebug() << pmin;
        sleep(3);
        break;
    case 3:
        arduino->clear();
        viPrintf(osc, (ViString)":OUTP1 :0\n");// arret du GBF de l'oscilloscope
        timer->stop();  //arret de qtimer
        frequences[incrementGraph] = freq;
        coefficients[incrementGraph] = coef;
        incrementGraph++;
        break;
    }
}

void MainWindow::on_pushButtonGraphique_clicked()
{
    //    coefficients[0] = 0.74851;
    //    coefficients[1] = 0.51234;
    //    coefficients[2] = 0.39541;
    //    coefficients[3] = 0.28743;



    graph->dessinerGraphique(frequences,coefficients);
    graph->show();
}

void MainWindow::on_pushButtonCoefficient_clicked()
{
    double n = pmax / pmin;     //taux d'ondes stationnaires
    coef = pow((n-1)/(n+1),2);
    coef = 1 - coef;

    qDebug() << coef;

    previousCoef = coef;

    ui->Editcoef->setText(QString::number(coef,'f',3));
    if(arduino->isOpen())
    {
        arduino->write("f"); //affichage sur l'ecran adafruit liaison fermee
        arduino->closeConnection();
    }
    arduino->openConnection();
    arduino->write("o");
    arduino->clear();
    QByteArray donnees_a_afficher = ("$frequence : " + QByteArray::number(freq) + "      coef : " + QByteArray::number(coef));
    arduino->write(donnees_a_afficher);

    frequences[0] = 2350;
    coefficients[0] = 0.74851;
    frequences[2] = 230;
    coefficients[2] = 0.39541;
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
    arduino->write("f");//affichage sur l'ecran adafruit liaison fermee
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
    else
        QMessageBox::critical(this,"Attention","Connexion oscilloscope déjà ouverte",QMessageBox::Ok);
}

void MainWindow::on_pushButtonResetGraphique_clicked()
{
    delete graph;
    graph = new IhmGraphique(0);
    for (int i = 0; i < 13; i++)
        coefficients[i] = 0;
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEditDernierCoef->setText(QString::number(previousCoef));
}

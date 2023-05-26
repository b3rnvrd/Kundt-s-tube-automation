#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    // open resource manager
//    ViSession rscmng;
//    ViStatus stat = viOpenDefaultRM(&rscmng);

//    // search for the oscilloscope
//    ViChar viFound[VI_FIND_BUFLEN];
//    ViUInt32 nFound;
//    ViFindList listOfFound;
//    stat = viFindRsrc(rscmng, (ViString)"USB?*", &listOfFound, &nFound, viFound);

//    // connect to the oscilloscope
//    ViSession osc;
//    stat = viOpen(rscmng, viFound, VI_NULL, VI_NULL, &osc);
//    if (stat < VI_SUCCESS) qDebug() << "failed";

//    // communicate
//    viPrintf(osc, (ViString)"*IDN?\n");     /* Send an *IDN? string to the device */
//    char buf[72] = {0};
//    viScanf(osc,(ViString)"%t",&buf);       /* Read results */ //%t récupère toute la chaine de caractère
//    qDebug()<<buf;
//    qDebug()<<stat;
//    viPrintf(osc, (ViString)":MEAS:ITEM? VMAX,CHAN1\n"); //tension mesurée sur le channel 1
//    viScanf(osc,(ViString)"%t",&buf);       /* Read results */
//    qDebug()<<buf;
//    // close VI sessions
//    viClose(rscmng);
//    viClose(osc);
//    //    viClose (vi);

    return a.exec();
}

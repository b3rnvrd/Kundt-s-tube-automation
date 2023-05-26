#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        QString s,strTemp;
        char* stringTemp;
        ViSession defaultRM, vi;//channels de communications
        ViChar buffer [VI_FIND_BUFLEN];
        ViRsrc matches=buffer;
        ViUInt32 nmatches;
        ViFindList list;
        viOpenDefaultRM (&defaultRM);
        viFindRsrc(defaultRM, "USB?*", &list,&nmatches, matches);
        viOpen (defaultRM,matches,VI_NULL,VI_NULL,&vi);
        strTemp = strTemp + "\n";
        stringTemp = (char*)(LPCTSTR)strTemp;
        viPrintf (vi,stringTemp);
        viScanf (vi, "%t\n", &buf);
        viClose (vi);
        viClose (defaultRM);
}

MainWindow::~MainWindow()
{
    delete ui;
}

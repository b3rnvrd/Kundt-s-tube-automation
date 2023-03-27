#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    arduino = new seriallink;

    arduino->openConnection();
    connect(arduino, &seriallink::gotNewData, this, &MainWindow::updateGUI);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateGUI(QByteArray data){
    ui->lcd_byte_received->display(ui->lcd_byte_received->value() + data.size());
}

void MainWindow::on_p_ledOn_clicked()
{
    if(arduino->isWritable())
        arduino->write("o");

    else
        qDebug() << "Couldn't write to serial!";
}

void MainWindow::on_p_ledOff_clicked()
{
    if(arduino->isWritable())
        arduino->write("n");

    else
        qDebug() << "Couldn't write to serial!";
}

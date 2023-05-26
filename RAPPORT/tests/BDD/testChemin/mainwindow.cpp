#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QProcess>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QProcess *process = new QProcess(this);
    process->start("\"C:\\Users\\etudiant\\Desktop\\tube_de_kundt\\Apps\\BDD\\MySqlQt.exe\"");
    //process->start("\"C:\\Users\\etudiant\\Documents\\GitHub\\tube_de_kundt\\Apps\\BDD\\MySqlQt.exe\"");
    qDebug() << process->errorString();
    qDebug() << process->error();
}

#include "dialoglogin.h"
#include "mainwindow.h"
#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollBar>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tableModel= 0;
    db= QSqlDatabase::addDatabase("QMYSQL","MaDB");
    db.setDatabaseName("MaBase");
    db.setHostName("172.22.16.13");
    db.setUserName("MaBase");
    db.setPassword("root");
    if(!db.open())
        QMessageBox::critical(this,"Attention","Pb d'accès",QMessageBox::Ok);
    else
        qDebug()<<"MaBase ouverte";

    queryModel = 0;
    ui->mainToolBar->insertWidget(0,&selNom);
}

MainWindow::~MainWindow()
{
    delete tableModel;
    if(db.isOpen())
        db.close();
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    int w= ui->tableView->width()-ui->tableView->verticalHeader()->width()
            -ui->tableView->verticalScrollBar()->width();
    ui->tableView->setColumnWidth(0,w/4);
    ui->tableView->setColumnWidth(1,w/4);
    ui->tableView->setColumnWidth(2,w/4);
    ui->tableView->setColumnWidth(3,w/4);
}

void MainWindow::on_actionRafraichir_triggered()
{
    if(selNom.text().isEmpty()){
        if(tableModel)
            delete tableModel;
        tableModel= new QSqlTableModel(this,db);
        tableModel->setTable("login");
        tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        if(tableModel->select())
            ui->tableView->setModel(tableModel);
    }
    else{
        if(queryModel)
            delete queryModel;
        queryModel= new QSqlQueryModel(this);
        queryModel->setQuery("SELECT user,passwd,id_login FROM login WHERE user LIKE '"+selNom.text()+"%'",db);
        ui->tableView->setModel(queryModel);
    }
}


void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QSqlRecord sqlRecord= tableModel->record(index.row());
    int id= sqlRecord.field("id_login").value().toInt();
    QString nom= sqlRecord.field("user").value().toString();
    QString passwd = sqlRecord.field("passwd").value().toString();
    QString str= "Ligne ="+QString::number(index.row())+" \n Id = "+ QString::number(id)+ " \n Login = " + nom + " \n Password = " + passwd;
    QMessageBox::information(this,"Sélection",str,QMessageBox::Ok);
}


void MainWindow::on_actionModifier_triggered()
{
    int ligne= ui->tableView->currentIndex().row();
    if(ligne<0) return;
    QSqlRecord sqlRecord= tableModel->record(ligne);
    int id= sqlRecord.field("id_login").value().toInt();
    QString nom= sqlRecord.field("user").value().toString();
    QString passwd = sqlRecord.field("passwd").value().toString();
    QSqlQuery query(db);
    if(!query.exec("UPDATE login SET user='"+nom+"',passwd='"+passwd+"' WHERE id_login="+QString::number(id)))
        QMessageBox::critical(this,"Attention","Pb Req",QMessageBox::Ok);
}

void MainWindow::on_actionSupprimer_triggered()
{
    int ligne= ui->tableView->currentIndex().row();
    if(ligne<0) return;
    QSqlRecord sqlRecord= tableModel->record(ligne);
    int id= sqlRecord.field("id_login").value().toInt();
    QSqlQuery query(db);
    QString titre,text;
    titre = "Suppression d'une ligne";
    text = "Voulez-vous supprimer cette ligne";
    if(QMessageBox::question(this,titre,text,QMessageBox::Yes | QMessageBox::No, QMessageBox::No)==QMessageBox::Yes){
        if(!query.exec("DELETE FROM login WHERE id_login="+QString::number(id)))
            QMessageBox::critical(this,"Attention","Pb Req",QMessageBox::Ok);
    }
}

void MainWindow::on_actionIns_rer_triggered()
{
    DialogLogin dlg; // Création de la boite de dialogue
    if(dlg.exec()) // affichage
    {
//        QString user = dlg.user;
//        QString password = dlg.passwd;
        QMessageBox::critical(0,"Erreur","Problème d'authentification");
        QSqlQuery query(db);
        if(!query.exec("INSERT table (id_login,user,passwd) VALUES ('valeur1',‘valeur2’,‘valeur3’)"))
            QMessageBox::critical(this,"Attention","Pb Req",QMessageBox::Ok);
    }

}

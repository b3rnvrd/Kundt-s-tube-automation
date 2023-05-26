#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include<QScrollBar>
#include <QSqlField>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    queryModel=0;
    tableModel= 0;
    //ui->mainToolBar->insertWidget(0,&selNom);
    db = QSqlDatabase::addDatabase("QMYSQL","MaDB");
    db.setDatabaseName("Kundt");
    db.setHostName("172.22.16.9");
    db.setUserName("Kundt");
    db.setPassword("Tube");
    if(!db.open())
        QMessageBox::critical(this,"Attention","Pb d'accès",QMessageBox::Ok);
    else
        qDebug()<<"MaBase ouverte";

}


MainWindow::~MainWindow()
{
    delete ui;
    delete tableModel;
    if(db.isOpen())
        db.close();

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    int w= ui->tableView->width()-ui->tableView->verticalHeader()->width()-ui->tableView->verticalScrollBar()->width();
    ui->tableView->setColumnWidth(0,w/4);
    ui->tableView->setColumnWidth(1,w/4);
    ui->tableView->setColumnWidth(2,w/4);
    ui->tableView->setColumnWidth(3,w/4);
}

void MainWindow::on_actionRafaichir_triggered()
{
    if(selNom.text().isEmpty()){
        if(tableModel)
            delete tableModel;
        tableModel= new QSqlTableModel(this,db);
        tableModel->setTable("materiau");
        tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        ui->tableView->hideColumn(0);
        //tableModel->setHeaderData(1, Qt::Horizontal, "Nom");
        if(tableModel->select())
            ui->tableView->setModel(tableModel);
    }
    else{
        if(queryModel)
            delete queryModel;
        queryModel= new QSqlQueryModel(this);
        queryModel->setQuery("SELECT * FROM materiau WHERE nom LIKE '"+selNom.text()+"%'",db);
        ui->tableView->setModel(queryModel);
    }
}


void MainWindow::on_actionModifier_triggered()
{
    int ligne = ui->tableView->currentIndex().row();
    if(ligne < 0) return;
    QSqlRecord sqlRecord = tableModel->record(ligne);
    int id = sqlRecord.field("idMateriau").value().toInt();
    QString nom = sqlRecord.field("nom").value().toString();
    double coef_abs = sqlRecord.field("coefficientAbsorption").value().toDouble();
    int frequence = sqlRecord.field("frequence").value().toInt();

    QSqlQuery query(db);
    query.prepare("UPDATE materiau SET nom=:nom,coefficientAbsorption=:coef_abs,frequence=:frequence WHERE idMateriau=:id");
    query.bindValue(":id", id_materiau);
    query.bindValue(":nom", nom);
    query.bindValue(":coef_abs", coef_abs);
    query.bindValue(":frequence", frequence);
    if(!query.exec())
        QMessageBox::critical(this,"Attention","Pb Req",QMessageBox::Ok);
    qDebug() << id;
    qDebug() << query.lastError();
}

void MainWindow::on_Ajouter_clicked()
{

    QString nom = ui->lineEditNom->text();
    double coef_abs = ui->lineEditCoef->text().toDouble();
    int frequence = ui->lineEditFrequence->text().toInt();

    QSqlQuery query(db);
    query.prepare("INSERT INTO materiau (idMateriau, nom, coefficientAbsorption, frequence) VALUES (:id, :nom, :coef_abs, :frequence)");
    query.bindValue(":id", id_materiau);
    query.bindValue(":nom", nom);
    query.bindValue(":coef_abs", coef_abs);
    query.bindValue(":frequence", frequence);
    if(!query.exec())
        QMessageBox::critical(this,"Attention","Pb Req",QMessageBox::Ok);

    id_materiau++;
    ui->lineEditNom->clear();
    ui->lineEditCoef->clear();
    ui->lineEditFrequence->clear();

    this->on_actionRafaichir_triggered();
}

void MainWindow::on_actionAfficher_l_ID_triggered()
{
    ui->tableView->showColumn(0);
}

void MainWindow::on_actionSupprimer_triggered()
{
    QSqlQuery query(db);

    int ligne = ui->tableView->currentIndex().row();
    if(ligne < 0) return;
    QSqlRecord sqlRecord= tableModel->record(ligne);
    int id = sqlRecord.field("idMateriau").value().toInt();

    query.prepare("DELETE FROM materiau WHERE idMateriau=:id");
    query.bindValue(":id", id);
    query.exec();

    this->on_actionRafaichir_triggered();
}

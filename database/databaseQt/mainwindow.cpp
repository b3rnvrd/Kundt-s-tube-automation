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
        QString nom = ui->lineEditNom->text();
        tableModel->setTable(nom);
        tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        ui->tableView->hideColumn(0);
        //tableModel->setHeaderData(1, Qt::Horizontal, "Nom");
        if(tableModel->select())
        {
            ui->tableView->setModel(tableModel);
        }
    }
    else{

        if(queryModel)
            delete queryModel;
        queryModel= new QSqlQueryModel(this);
        queryModel->setQuery("SELECT * FROM login WHERE user LIKE '"+selNom.text()+"%'",db);
        ui->tableView->setModel(queryModel);
    }
    ui->lineEditCoef->clear();
    ui->lineEditFrequence->clear();

}


void MainWindow::on_actionModifier_triggered()
{
    int ligne = ui->tableView->currentIndex().row();
    if(ligne < 0) return;
    QSqlRecord sqlRecord = tableModel->record(ligne);
    int id = sqlRecord.field("id_freq").value().toInt();
    double coef_abs = sqlRecord.field("coefficientAbsorption").value().toDouble();
    int frequence = sqlRecord.field("frequence").value().toInt();
    QString table = ui->lineEditNom->text();

    QSqlQuery query(db);
    query.prepare("UPDATE " + table + " SET frequence=" + QString::number(frequence) +" ,coefficientAbsorption=" + QString::number(coef_abs) +  " WHERE id_freq=" + QString::number(id));
    if(!query.exec())
        QMessageBox::critical(this,"Attention","Pb Req",QMessageBox::Ok);
    qDebug() << id;
    qDebug() << query.lastError();
}

void MainWindow::on_Ajouter_clicked()
{

    QString table = ui->lineEditNom->text();
    double coef_abs = ui->lineEditCoef->text().toDouble();
    int frequence = ui->lineEditFrequence->text().toInt();

    QSqlQuery query(db);
    query.prepare("INSERT INTO "+table+" (coefficientAbsorption, frequence) VALUES (:coef_abs, :frequence)");
    //query.prepare("CREATE TABLE `kundt`.`:table` ( `coef_abs` DOUBLE NOT NULL , `frequence` INT(50) NOT NULL ) ENGINE = MyISAM;");
    //query.bindValue(":table", table);
    query.bindValue(":coef_abs", coef_abs);
    query.bindValue(":frequence", frequence);
    if(!query.exec())
        QMessageBox::critical(this,"Attention","Pb Req",QMessageBox::Ok);
    qDebug() << query.lastError();
    id_freq++;

    this->on_actionRafaichir_triggered();
}

void MainWindow::on_actionAfficher_l_ID_triggered()
{
    ui->tableView->showColumn(0);
}

void MainWindow::on_actionSupprimer_triggered()
{
    QSqlQuery query(db);
    QString table = ui->lineEditNom->text();
    int ligne = ui->tableView->currentIndex().row();
    if(ligne < 0) return;
    QSqlRecord sqlRecord= tableModel->record(ligne);
    int id = sqlRecord.field("id_freq").value().toInt();

    query.prepare("DELETE FROM " + table + " WHERE " + table + ".id_freq = " + QString::number(id));
    query.exec();

    this->on_actionRafaichir_triggered();
}

void MainWindow::on_actionCreerTableMateriau_triggered()
{
    QString table = ui->lineEditNom->text();

    QSqlQuery query(db);
    query.prepare("CREATE TABLE `kundt`." + table + " ( `id_freq` INT(50) NOT NULL AUTO_INCREMENT , `frequence` INT(50) NOT NULL , `coefficientAbsorption` DOUBLE NOT NULL , PRIMARY KEY (`id_freq`), UNIQUE `UNIQUE` (`frequence`)) ENGINE = MyISAM;");
    if(!query.exec())
        QMessageBox::critical(this,"Attention","Pb Req",QMessageBox::Ok);

    this->on_actionRafaichir_triggered();
}

void MainWindow::on_actionSupprimerTable_triggered()
{
    QString table = ui->lineEditNom->text();

    QSqlQuery query(db);
    query.prepare("DROP TABLE " + table);
            if(!query.exec())
            QMessageBox::critical(this,"Attention","Pb Req",QMessageBox::Ok);

    this->on_actionRafaichir_triggered();
}

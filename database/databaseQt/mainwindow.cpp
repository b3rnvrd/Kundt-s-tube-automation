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
        QMessageBox::critical(this,"Attention","Pb d'accès 1",QMessageBox::Ok);
    else
        qDebug()<<"MaBase ouverte";

    this->on_actionRafaichir_triggered();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tableModel;
    if(db.isOpen())
        db.close();

}

void MainWindow::paintEvent()
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
        tableModel->setTable(table_selectionnee);
        tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        ui->tableView->hideColumn(0);
        if(tableModel->select())
        {
            ui->tableView->setModel(tableModel);
        }
    }
    else
    {
        if(queryModel)
            delete queryModel;
        queryModel= new QSqlQueryModel(this);
        queryModel->setQuery("SELECT * FROM login WHERE user LIKE '"+selNom.text()+"%'",db);
        ui->tableView->setModel(queryModel);
    }
    ui->lineEditCoef->clear();
}


void MainWindow::on_actionModifier_triggered()
{
    int ligne = ui->tableView->currentIndex().row();
    if(ligne < 0) return;
    QSqlRecord sqlRecord = tableModel->record(ligne);
    QString id = sqlRecord.field("id_enregistrement").value().toString();
    QString coef_abs = sqlRecord.field("absorption").value().toString();
    QString frequence = sqlRecord.field("frequence").value().toString();
    id_materiau = sqlRecord.field("id_materiau").value().toString();

    QSqlQuery query(db);
    query.prepare(
                "UPDATE enregistrement SET frequence = " + frequence + " , absorption = " + coef_abs
                + " , id_materiau = " + id_materiau +  " WHERE id_enregistrement = " + id
                );
    if(!query.exec())
        QMessageBox::critical(this,"Attention","Pb Req",QMessageBox::Ok);
    qDebug() << id;
    qDebug() << query.lastError();
}

void MainWindow::on_AjouterMateriau_clicked()
{
    QString materiau = ui->lineEditNom->text();

    QSqlQuery query(db);
    query.prepare("INSERT INTO materiau (nom) VALUES " + materiau);
    if(!query.exec())
    {
        QString error = query.lastError().text();
        QMessageBox::critical(this,"Attention","Impossible d'ajouter le matériau. ERREUR : " + error,QMessageBox::Ok);
    }
    qDebug() << query.lastError();
    ui->lineEditNom->clear();
    this->on_actionRafaichir_triggered();
}

//void MainWindow::on_actionCreerTableMateriau_triggered()
//{
//    QString table = ui->lineEditNom->text();

//    QSqlQuery query(db);
//    query.prepare("CREATE TABLE `kundt`." + table + " ( `id_freq` INT(50) NOT NULL AUTO_INCREMENT , `frequence` INT(50) NOT NULL , `coefficientAbsorption` DOUBLE NOT NULL , PRIMARY KEY (`id_freq`), UNIQUE `UNIQUE` (`frequence`)) ENGINE = MyISAM;");
//    if(!query.exec())
//        QMessageBox::critical(this,"Attention","Pb Req",QMessageBox::Ok);
//    this->on_actionRafaichir_triggered();
//}

//void MainWindow::on_actionSupprimerTable_triggered()
//{
//    QString table = ui->lineEditNom->text();

//    QSqlQuery query(db);
//    query.prepare("DROP TABLE " + table);
//            if(!query.exec())
//            QMessageBox::critical(this,"Attention","Pb Req",QMessageBox::Ok);

//    this->on_actionRafaichir_triggered();
//}

void MainWindow::on_spinBoxMateriau_valueChanged(const QString &arg1)
{
    id_materiau = arg1;
}

void MainWindow::on_actionafficherMateriaux_triggered()
{
    if(selNom.text().isEmpty()){
        if(tableModel)
            delete tableModel;
        tableModel= new QSqlTableModel(this,db);
        tableModel->setTable("materiau");
        tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        ui->tableView->hideColumn(0);
        if(tableModel->select())
        {
            ui->tableView->setModel(tableModel);
        }
    }
    else
    {
        if(queryModel)
            delete queryModel;
        queryModel= new QSqlQueryModel(this);
        queryModel->setQuery("SELECT * FROM login WHERE user LIKE '"+selNom.text()+"%'",db);
        ui->tableView->setModel(queryModel);
    }
    ui->lineEditCoef->clear();
}

void MainWindow::on_actionafficherMesures_triggered()
{
    if(selNom.text().isEmpty()){
        if(tableModel)
            delete tableModel;
        tableModel= new QSqlTableModel(this,db);
        tableModel->setTable("enregistrement");
        tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        ui->tableView->hideColumn(0);
        if(tableModel->select())
        {
            ui->tableView->setModel(tableModel);
        }
    }
    else
    {
        if(queryModel)
            delete queryModel;
        queryModel= new QSqlQueryModel(this);
        queryModel->setQuery("SELECT * FROM login WHERE user LIKE '"+selNom.text()+"%'",db);
        ui->tableView->setModel(queryModel);
    }
    ui->lineEditCoef->clear();

}

void MainWindow::on_comboBoxTableARafraichir_currentTextChanged(const QString &arg1)
{
    table_selectionnee = arg1.toLower();
    this->on_actionRafaichir_triggered();
}

void MainWindow::on_pushButtonSupprimerMateriau_clicked()
{
    QSqlQuery query(db);
    int ligne = ui->tableView->currentIndex().row();
    if(ligne < 0) return;
    QSqlRecord sqlRecord= tableModel->record(ligne);
    QString id = sqlRecord.field("id_materiau").value().toString();

    query.prepare("DELETE FROM materiau WHERE materiau.id_materiau = " + id);
    if(!query.exec())
    {
        QString error = query.lastError().text();
        QMessageBox::critical(this,"Attention","Impossible d'effacer le matériau. ERREUR : " + error,QMessageBox::Ok);
    }

    this->on_actionRafaichir_triggered();
}

void MainWindow::on_actionafficher_l_ID_triggered()
{
    ui->tableView->showColumn(0);
}

void MainWindow::on_pushButtonAjouterMesures_clicked()
{
    double coef_abs = ui->lineEditCoef->text().toDouble();
    if((0 >= coef_abs) || (1 <= coef_abs) )
        QMessageBox::critical(this,"Attention","Le coefficient doit être compris entre 0 et 1",QMessageBox::Ok);
    else
    {
        QSqlQuery query(db);
        query.prepare("INSERT INTO enregistrement (absorption, frequence, id_materiau) VALUES (" + QString::number(coef_abs) + ", " + frequence + ", " + id_materiau + ")");
        if(!query.exec())
            QMessageBox::critical(this,"Attention","ERREUR : " + query.lastError().text(),QMessageBox::Ok);
        qDebug() << query.lastError();

        this->on_actionRafaichir_triggered();
    }

}

void MainWindow::on_pushButtonSupprimerMesures_clicked()
{
    QSqlQuery query(db);
    int ligne = ui->tableView->currentIndex().row();
    if(ligne < 0) return;
    QSqlRecord sqlRecord= tableModel->record(ligne);
    QString id = sqlRecord.field("id_enregistrement").value().toString();

    query.prepare("DELETE FROM enregistrement WHERE enregistrement.id_enregistrement = " + id);
    query.exec();

    this->on_actionRafaichir_triggered();
}

void MainWindow::on_comboBoxFrequence_currentTextChanged(const QString &arg1)
{
    frequence = arg1;
}

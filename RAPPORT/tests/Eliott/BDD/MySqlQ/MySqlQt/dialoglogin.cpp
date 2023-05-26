#include "dialoglogin.h"
#include "ui_dialoglogin.h"
#include<QMessageBox>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

DialogLogin::DialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);
}

DialogLogin::~DialogLogin()
{
    delete ui;
}

void DialogLogin::on_buttonBox_accepted()
{
    int accepted = QDialog::Rejected;
    {   QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL","login");
        db.setDatabaseName("Kundt");
        //db.setPort(3306);
        db.setHostName("172.22.16.9");
        db.setUserName("Kundt");
        db.setPassword("Tube");
        if(db.open())
        { qDebug()<<"MaBase ouverte";
            QString user = ui->lineEditUser->text(); //lecture du lineEdit user
            QString password = ui->lineEditPassword->text(); //lecture du lineEdit password
            QSqlQuery query(db);
            if(!query.exec("SELECT password,id_login FROM login WHERE user='"+user+"'"))
                QMessageBox::critical(this,"Attention","Pb Req",QMessageBox::Ok);
            else
            { while(query.next())
                {
                    qDebug()<<query.value(0);
                    if(query.value(0).toString() == password)
                    {
                        accepted = QDialog::Accepted;
                        break;
                    }
                }
            }
            db.close();
        }
        else
            QMessageBox::critical(this,"Attention","Pb d'accès",QMessageBox::Ok);
    }
    QSqlDatabase::removeDatabase("Login");
    done(accepted);

}

#include "inserer.h"
#include "ui_inserer.h"

#include <QMessageBox>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

Inserer::Inserer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inserer)
{
    ui->setupUi(this);
}

Inserer::~Inserer()
{
    delete ui;
}

void Inserer::on_buttonBox_accepted()
{
            user= ui->lineEditUser->text(); //lecture du lineEdit user
            password = ui->lineEditPassword->text();
            id = ui->lineEditId->text();
}

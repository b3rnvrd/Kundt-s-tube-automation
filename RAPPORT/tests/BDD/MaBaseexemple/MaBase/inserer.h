#ifndef INSERER_H
#define INSERER_H

#include <QDialog>

namespace Ui {
class Inserer;
}

class Inserer : public QDialog
{
    Q_OBJECT
public:
    explicit Inserer(QWidget *parent = 0);
    ~Inserer();
    QString user;
    QString password;
    QString id;
private slots:
    void on_buttonBox_accepted();

private:
    Ui::Inserer *ui;
};

#endif // INSERER_H

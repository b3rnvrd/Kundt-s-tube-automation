#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QSqlDatabase db;
    QSqlTableModel *tableModel;
    QSqlQueryModel *queryModel;
    QLineEdit selNom;

    unsigned int id_freq = 1;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
void paintEvent(QPaintEvent *event);
private slots:
    void on_actionRafaichir_triggered();
    void on_actionModifier_triggered();
    void on_Ajouter_clicked();
    void on_actionAfficher_l_ID_triggered();
    void on_actionSupprimer_triggered();

    void on_actionCreerTableMateriau_triggered();

    void on_actionSupprimerTable_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QSqlQueryModel *queryModel;
    QLineEdit selNom;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSqlDatabase db;
    QSqlTableModel *tableModel;

    void paintEvent(QPaintEvent *);
private slots:
    void on_actionRafraichir_triggered();
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_actionModifier_triggered();

    void on_actionSupprimer_triggered();

    void on_actionIns_rer_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

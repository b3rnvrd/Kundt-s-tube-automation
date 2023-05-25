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
    QString id_materiau = "1", table_selectionnee = "materiau", frequence = "200";


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent();
private slots:
    void on_actionRafaichir_triggered();
    void on_actionModifier_triggered();
    void on_AjouterMateriau_clicked();
    void on_spinBoxMateriau_valueChanged(const QString &arg1);
    void on_actionafficherMateriaux_triggered();
    void on_actionafficherMesures_triggered();
    void on_pushButtonSupprimerMateriau_clicked();
    void on_comboBoxTableARafraichir_currentTextChanged(const QString &arg1);
    void on_actionafficher_l_ID_triggered();
    void on_pushButtonAjouterMesures_clicked();
    void on_pushButtonSupprimerMesures_clicked();

    void on_comboBoxFrequence_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

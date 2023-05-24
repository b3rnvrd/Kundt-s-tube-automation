#include "dialoglogin.h"
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogLogin dlg; // Création de la boite de dialogue
    if(dlg.exec()) // affichage
    {
        MainWindow w; // Création de la fenêtre principale
        w.show(); // Affichage
        return a.exec();// exécution de l'application
    }
    else
        QMessageBox::critical(0,"Erreur","Problème d'authentification");
    return 1;
}

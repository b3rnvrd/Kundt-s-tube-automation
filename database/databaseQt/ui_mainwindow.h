/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRafaichir;
    QAction *actionModifier;
    QAction *actionAfficher_l_ID;
    QAction *actionSupprimer;
    QAction *actionCreerTableMateriau;
    QAction *actionSupprimerTable;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *labelNom;
    QLineEdit *lineEditNom;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelCoef;
    QLineEdit *lineEditCoef;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelFrequence;
    QLineEdit *lineEditFrequence;
    QPushButton *Ajouter;
    QTableView *tableView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(788, 490);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/bdd.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionRafaichir = new QAction(MainWindow);
        actionRafaichir->setObjectName(QStringLiteral("actionRafaichir"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/rafraichir.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRafaichir->setIcon(icon1);
        actionModifier = new QAction(MainWindow);
        actionModifier->setObjectName(QStringLiteral("actionModifier"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/modifier.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionModifier->setIcon(icon2);
        actionAfficher_l_ID = new QAction(MainWindow);
        actionAfficher_l_ID->setObjectName(QStringLiteral("actionAfficher_l_ID"));
        actionSupprimer = new QAction(MainWindow);
        actionSupprimer->setObjectName(QStringLiteral("actionSupprimer"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/retirer_ligne.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSupprimer->setIcon(icon3);
        actionCreerTableMateriau = new QAction(MainWindow);
        actionCreerTableMateriau->setObjectName(QStringLiteral("actionCreerTableMateriau"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/ajouter_table.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreerTableMateriau->setIcon(icon4);
        actionSupprimerTable = new QAction(MainWindow);
        actionSupprimerTable->setObjectName(QStringLiteral("actionSupprimerTable"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/retirer_table.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSupprimerTable->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelNom = new QLabel(centralWidget);
        labelNom->setObjectName(QStringLiteral("labelNom"));

        horizontalLayout->addWidget(labelNom);

        lineEditNom = new QLineEdit(centralWidget);
        lineEditNom->setObjectName(QStringLiteral("lineEditNom"));

        horizontalLayout->addWidget(lineEditNom);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelCoef = new QLabel(centralWidget);
        labelCoef->setObjectName(QStringLiteral("labelCoef"));

        horizontalLayout_2->addWidget(labelCoef);

        lineEditCoef = new QLineEdit(centralWidget);
        lineEditCoef->setObjectName(QStringLiteral("lineEditCoef"));

        horizontalLayout_2->addWidget(lineEditCoef);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelFrequence = new QLabel(centralWidget);
        labelFrequence->setObjectName(QStringLiteral("labelFrequence"));

        horizontalLayout_3->addWidget(labelFrequence);

        lineEditFrequence = new QLineEdit(centralWidget);
        lineEditFrequence->setObjectName(QStringLiteral("lineEditFrequence"));

        horizontalLayout_3->addWidget(lineEditFrequence);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        Ajouter = new QPushButton(centralWidget);
        Ajouter->setObjectName(QStringLiteral("Ajouter"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/ajouter_ligne.png"), QSize(), QIcon::Normal, QIcon::Off);
        Ajouter->setIcon(icon6);

        verticalLayout->addWidget(Ajouter);


        verticalLayout_2->addLayout(verticalLayout);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_2->addWidget(tableView);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionCreerTableMateriau);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSupprimerTable);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRafaichir);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAfficher_l_ID);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionModifier);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSupprimer);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BaseDeDonnees", nullptr));
        actionRafaichir->setText(QApplication::translate("MainWindow", "Rafaichir", nullptr));
        actionModifier->setText(QApplication::translate("MainWindow", "Modifier la ligne", nullptr));
        actionAfficher_l_ID->setText(QApplication::translate("MainWindow", "Afficher l'ID", nullptr));
        actionSupprimer->setText(QApplication::translate("MainWindow", "Supprimer la ligne", nullptr));
        actionCreerTableMateriau->setText(QApplication::translate("MainWindow", "Cr\303\251er la table", nullptr));
        actionSupprimerTable->setText(QApplication::translate("MainWindow", "Supprimer la table", nullptr));
        labelNom->setText(QApplication::translate("MainWindow", "Nom du mat\303\251riau", nullptr));
        labelCoef->setText(QApplication::translate("MainWindow", "Coefficient d'absorption", nullptr));
        labelFrequence->setText(QApplication::translate("MainWindow", "Fr\303\251quence", nullptr));
        Ajouter->setText(QApplication::translate("MainWindow", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

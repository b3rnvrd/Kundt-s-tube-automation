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
        actionRafaichir = new QAction(MainWindow);
        actionRafaichir->setObjectName(QStringLiteral("actionRafaichir"));
        QIcon icon;
        icon.addFile(QStringLiteral("../images/rafraichir.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRafaichir->setIcon(icon);
        actionModifier = new QAction(MainWindow);
        actionModifier->setObjectName(QStringLiteral("actionModifier"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../images/modifier.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionModifier->setIcon(icon1);
        actionAfficher_l_ID = new QAction(MainWindow);
        actionAfficher_l_ID->setObjectName(QStringLiteral("actionAfficher_l_ID"));
        actionSupprimer = new QAction(MainWindow);
        actionSupprimer->setObjectName(QStringLiteral("actionSupprimer"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../images/corbeille.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSupprimer->setIcon(icon2);
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

        mainToolBar->addAction(actionAfficher_l_ID);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionModifier);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRafaichir);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSupprimer);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionRafaichir->setText(QApplication::translate("MainWindow", "Rafaichir", nullptr));
        actionModifier->setText(QApplication::translate("MainWindow", "Modifier", nullptr));
        actionAfficher_l_ID->setText(QApplication::translate("MainWindow", "Afficher l'ID", nullptr));
        actionSupprimer->setText(QApplication::translate("MainWindow", "Supprimer", nullptr));
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

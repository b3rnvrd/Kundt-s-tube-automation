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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRafraichir;
    QAction *actionModifier;
    QAction *actionSupprimer;
    QAction *actionIns_rer;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuOp_ration;
    QMenu *menuModifier;
    QMenu *menuSupprimer;
    QMenu *menuIns_rer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionRafraichir = new QAction(MainWindow);
        actionRafraichir->setObjectName(QStringLiteral("actionRafraichir"));
        actionModifier = new QAction(MainWindow);
        actionModifier->setObjectName(QStringLiteral("actionModifier"));
        actionSupprimer = new QAction(MainWindow);
        actionSupprimer->setObjectName(QStringLiteral("actionSupprimer"));
        actionIns_rer = new QAction(MainWindow);
        actionIns_rer->setObjectName(QStringLiteral("actionIns_rer"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tableView = new QTableView(widget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_2->addWidget(tableView, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuOp_ration = new QMenu(menuBar);
        menuOp_ration->setObjectName(QStringLiteral("menuOp_ration"));
        menuModifier = new QMenu(menuBar);
        menuModifier->setObjectName(QStringLiteral("menuModifier"));
        menuSupprimer = new QMenu(menuBar);
        menuSupprimer->setObjectName(QStringLiteral("menuSupprimer"));
        menuIns_rer = new QMenu(menuBar);
        menuIns_rer->setObjectName(QStringLiteral("menuIns_rer"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuOp_ration->menuAction());
        menuBar->addAction(menuModifier->menuAction());
        menuBar->addAction(menuIns_rer->menuAction());
        menuBar->addAction(menuSupprimer->menuAction());
        menuOp_ration->addAction(actionRafraichir);
        menuModifier->addAction(actionModifier);
        menuSupprimer->addAction(actionSupprimer);
        menuIns_rer->addAction(actionIns_rer);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionRafraichir->setText(QApplication::translate("MainWindow", "Rafraichir", nullptr));
        actionModifier->setText(QApplication::translate("MainWindow", "Modifier", nullptr));
        actionSupprimer->setText(QApplication::translate("MainWindow", "Supprimer", nullptr));
        actionIns_rer->setText(QApplication::translate("MainWindow", "Ins\303\251rer", nullptr));
        menuOp_ration->setTitle(QApplication::translate("MainWindow", "Op\303\251ration", nullptr));
        menuModifier->setTitle(QApplication::translate("MainWindow", "Modifier", nullptr));
        menuSupprimer->setTitle(QApplication::translate("MainWindow", "Supprimer", nullptr));
        menuIns_rer->setTitle(QApplication::translate("MainWindow", "Ins\303\251rer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

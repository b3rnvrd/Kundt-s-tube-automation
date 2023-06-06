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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QAction *actionafficherMateriaux;
    QAction *actionafficherMesures;
    QAction *actionafficher_l_ID;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *labelNom;
    QLineEdit *lineEditNom;
    QVBoxLayout *verticalLayout;
    QPushButton *AjouterMateriau;
    QPushButton *pushButtonSupprimerMateriau;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelCoef;
    QLineEdit *lineEditCoef;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelFrequence;
    QComboBox *comboBoxFrequence;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonAjouterMesures;
    QPushButton *pushButtonSupprimerMesures;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QSpinBox *spinBoxMateriau;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelTableARafraichir;
    QComboBox *comboBoxTableARafraichir;
    QTableView *tableView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1063, 592);
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
        actionafficherMateriaux = new QAction(MainWindow);
        actionafficherMateriaux->setObjectName(QStringLiteral("actionafficherMateriaux"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/bois.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionafficherMateriaux->setIcon(icon3);
        actionafficherMesures = new QAction(MainWindow);
        actionafficherMesures->setObjectName(QStringLiteral("actionafficherMesures"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/mesures.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionafficherMesures->setIcon(icon4);
        actionafficher_l_ID = new QAction(MainWindow);
        actionafficher_l_ID->setObjectName(QStringLiteral("actionafficher_l_ID"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelNom = new QLabel(centralWidget);
        labelNom->setObjectName(QStringLiteral("labelNom"));

        horizontalLayout->addWidget(labelNom);

        lineEditNom = new QLineEdit(centralWidget);
        lineEditNom->setObjectName(QStringLiteral("lineEditNom"));

        horizontalLayout->addWidget(lineEditNom);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        AjouterMateriau = new QPushButton(centralWidget);
        AjouterMateriau->setObjectName(QStringLiteral("AjouterMateriau"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/ajouter_ligne.png"), QSize(), QIcon::Normal, QIcon::Off);
        AjouterMateriau->setIcon(icon5);

        verticalLayout->addWidget(AjouterMateriau);

        pushButtonSupprimerMateriau = new QPushButton(centralWidget);
        pushButtonSupprimerMateriau->setObjectName(QStringLiteral("pushButtonSupprimerMateriau"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/retirer_ligne.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSupprimerMateriau->setIcon(icon6);

        verticalLayout->addWidget(pushButtonSupprimerMateriau);


        verticalLayout_4->addLayout(verticalLayout);


        horizontalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
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

        comboBoxFrequence = new QComboBox(centralWidget);
        comboBoxFrequence->addItem(QString());
        comboBoxFrequence->addItem(QString());
        comboBoxFrequence->addItem(QString());
        comboBoxFrequence->addItem(QString());
        comboBoxFrequence->addItem(QString());
        comboBoxFrequence->addItem(QString());
        comboBoxFrequence->addItem(QString());
        comboBoxFrequence->addItem(QString());
        comboBoxFrequence->addItem(QString());
        comboBoxFrequence->addItem(QString());
        comboBoxFrequence->addItem(QString());
        comboBoxFrequence->addItem(QString());
        comboBoxFrequence->addItem(QString());
        comboBoxFrequence->setObjectName(QStringLiteral("comboBoxFrequence"));

        horizontalLayout_3->addWidget(comboBoxFrequence);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButtonAjouterMesures = new QPushButton(centralWidget);
        pushButtonAjouterMesures->setObjectName(QStringLiteral("pushButtonAjouterMesures"));

        verticalLayout_2->addWidget(pushButtonAjouterMesures);

        pushButtonSupprimerMesures = new QPushButton(centralWidget);
        pushButtonSupprimerMesures->setObjectName(QStringLiteral("pushButtonSupprimerMesures"));

        verticalLayout_2->addWidget(pushButtonSupprimerMesures);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_6->addLayout(verticalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label);

        spinBoxMateriau = new QSpinBox(centralWidget);
        spinBoxMateriau->setObjectName(QStringLiteral("spinBoxMateriau"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBoxMateriau->sizePolicy().hasHeightForWidth());
        spinBoxMateriau->setSizePolicy(sizePolicy1);
        spinBoxMateriau->setMinimum(1);

        horizontalLayout_5->addWidget(spinBoxMateriau);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelTableARafraichir = new QLabel(centralWidget);
        labelTableARafraichir->setObjectName(QStringLiteral("labelTableARafraichir"));
        labelTableARafraichir->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(labelTableARafraichir);

        comboBoxTableARafraichir = new QComboBox(centralWidget);
        comboBoxTableARafraichir->addItem(QString());
        comboBoxTableARafraichir->addItem(QString());
        comboBoxTableARafraichir->setObjectName(QStringLiteral("comboBoxTableARafraichir"));

        horizontalLayout_7->addWidget(comboBoxTableARafraichir);


        verticalLayout_5->addLayout(horizontalLayout_7);


        verticalLayout_6->addLayout(verticalLayout_5);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_6->addWidget(tableView);


        gridLayout->addLayout(verticalLayout_6, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionRafaichir);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionModifier);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionafficherMateriaux);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionafficherMesures);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionafficher_l_ID);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Base de donnees", nullptr));
        actionRafaichir->setText(QApplication::translate("MainWindow", "Rafaichir la table", nullptr));
        actionModifier->setText(QApplication::translate("MainWindow", "Modifier les mesures", nullptr));
        actionafficherMateriaux->setText(QApplication::translate("MainWindow", "Afficher la table des mat\303\251riaux", nullptr));
        actionafficherMesures->setText(QApplication::translate("MainWindow", "Afficher la table des mesures", nullptr));
        actionafficher_l_ID->setText(QApplication::translate("MainWindow", "Afficher l'ID", nullptr));
#ifndef QT_NO_TOOLTIP
        actionafficher_l_ID->setToolTip(QApplication::translate("MainWindow", "afficher_l_ID", nullptr));
#endif // QT_NO_TOOLTIP
        labelNom->setText(QApplication::translate("MainWindow", "Nom du mat\303\251riau", nullptr));
        AjouterMateriau->setText(QApplication::translate("MainWindow", "Ajouter le mat\303\251riau", nullptr));
        pushButtonSupprimerMateriau->setText(QApplication::translate("MainWindow", "Supprimer le mat\303\251riau", nullptr));
        labelCoef->setText(QApplication::translate("MainWindow", "Coefficient d'absorption", nullptr));
        labelFrequence->setText(QApplication::translate("MainWindow", "Fr\303\251quence", nullptr));
        comboBoxFrequence->setItemText(0, QApplication::translate("MainWindow", "200", nullptr));
        comboBoxFrequence->setItemText(1, QApplication::translate("MainWindow", "250", nullptr));
        comboBoxFrequence->setItemText(2, QApplication::translate("MainWindow", "315", nullptr));
        comboBoxFrequence->setItemText(3, QApplication::translate("MainWindow", "400", nullptr));
        comboBoxFrequence->setItemText(4, QApplication::translate("MainWindow", "500", nullptr));
        comboBoxFrequence->setItemText(5, QApplication::translate("MainWindow", "630", nullptr));
        comboBoxFrequence->setItemText(6, QApplication::translate("MainWindow", "800", nullptr));
        comboBoxFrequence->setItemText(7, QApplication::translate("MainWindow", "1000", nullptr));
        comboBoxFrequence->setItemText(8, QApplication::translate("MainWindow", "1250", nullptr));
        comboBoxFrequence->setItemText(9, QApplication::translate("MainWindow", "1600", nullptr));
        comboBoxFrequence->setItemText(10, QApplication::translate("MainWindow", "2000", nullptr));
        comboBoxFrequence->setItemText(11, QApplication::translate("MainWindow", "2500", nullptr));
        comboBoxFrequence->setItemText(12, QApplication::translate("MainWindow", "3150", nullptr));

        pushButtonAjouterMesures->setText(QApplication::translate("MainWindow", "Ajouter les mesures", nullptr));
        pushButtonSupprimerMesures->setText(QApplication::translate("MainWindow", "Supprimer les mesures", nullptr));
        label->setText(QApplication::translate("MainWindow", "Id du mat\303\251riau", nullptr));
        labelTableARafraichir->setText(QApplication::translate("MainWindow", "Table s\303\251lectionn\303\251e :", nullptr));
        comboBoxTableARafraichir->setItemText(0, QApplication::translate("MainWindow", "Materiau", nullptr));
        comboBoxTableARafraichir->setItemText(1, QApplication::translate("MainWindow", "Enregistrement", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

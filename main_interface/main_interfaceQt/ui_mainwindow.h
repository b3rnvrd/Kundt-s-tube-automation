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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionBase_de_donnees;
    QAction *actionRelancerConnexionOscillo;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelPort;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *spinBoxPort;
    QPushButton *pushButtonPort;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxFreq;
    QHBoxLayout *horizontalLayout_2;
    QLabel *LblAmplitude;
    QLineEdit *EditAmpli;
    QPushButton *BtnStart;
    QPushButton *BtnStop;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLineEdit *Editcoef;
    QPushButton *pushButtonCoefficient;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonGraphique;
    QPushButton *pushButtonResetGraphique;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton;
    QLineEdit *lineEditDernierCoef;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1265, 582);
        actionBase_de_donnees = new QAction(MainWindow);
        actionBase_de_donnees->setObjectName(QStringLiteral("actionBase_de_donnees"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/bdd.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBase_de_donnees->setIcon(icon);
        actionRelancerConnexionOscillo = new QAction(MainWindow);
        actionRelancerConnexionOscillo->setObjectName(QStringLiteral("actionRelancerConnexionOscillo"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/oscillo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRelancerConnexionOscillo->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        labelPort = new QLabel(centralWidget);
        labelPort->setObjectName(QStringLiteral("labelPort"));

        verticalLayout_3->addWidget(labelPort);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        spinBoxPort = new QSpinBox(centralWidget);
        spinBoxPort->setObjectName(QStringLiteral("spinBoxPort"));

        verticalLayout_2->addWidget(spinBoxPort);

        pushButtonPort = new QPushButton(centralWidget);
        pushButtonPort->setObjectName(QStringLiteral("pushButtonPort"));

        verticalLayout_2->addWidget(pushButtonPort);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_4);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBoxFreq = new QComboBox(groupBox);
        comboBoxFreq->addItem(QString());
        comboBoxFreq->addItem(QString());
        comboBoxFreq->addItem(QString());
        comboBoxFreq->addItem(QString());
        comboBoxFreq->addItem(QString());
        comboBoxFreq->addItem(QString());
        comboBoxFreq->addItem(QString());
        comboBoxFreq->addItem(QString());
        comboBoxFreq->addItem(QString());
        comboBoxFreq->addItem(QString());
        comboBoxFreq->addItem(QString());
        comboBoxFreq->addItem(QString());
        comboBoxFreq->addItem(QString());
        comboBoxFreq->setObjectName(QStringLiteral("comboBoxFreq"));

        horizontalLayout->addWidget(comboBoxFreq);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        LblAmplitude = new QLabel(groupBox);
        LblAmplitude->setObjectName(QStringLiteral("LblAmplitude"));

        horizontalLayout_2->addWidget(LblAmplitude);

        EditAmpli = new QLineEdit(groupBox);
        EditAmpli->setObjectName(QStringLiteral("EditAmpli"));

        horizontalLayout_2->addWidget(EditAmpli);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        BtnStart = new QPushButton(groupBox);
        BtnStart->setObjectName(QStringLiteral("BtnStart"));

        gridLayout->addWidget(BtnStart, 1, 0, 1, 1);

        BtnStop = new QPushButton(groupBox);
        BtnStop->setObjectName(QStringLiteral("BtnStop"));

        gridLayout->addWidget(BtnStop, 2, 0, 1, 1);


        verticalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        Editcoef = new QLineEdit(groupBox_2);
        Editcoef->setObjectName(QStringLiteral("Editcoef"));
        Editcoef->setEnabled(false);

        gridLayout_3->addWidget(Editcoef, 0, 0, 1, 1);

        pushButtonCoefficient = new QPushButton(groupBox_2);
        pushButtonCoefficient->setObjectName(QStringLiteral("pushButtonCoefficient"));

        gridLayout_3->addWidget(pushButtonCoefficient, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButtonGraphique = new QPushButton(groupBox_2);
        pushButtonGraphique->setObjectName(QStringLiteral("pushButtonGraphique"));

        horizontalLayout_5->addWidget(pushButtonGraphique);

        pushButtonResetGraphique = new QPushButton(groupBox_2);
        pushButtonResetGraphique->setObjectName(QStringLiteral("pushButtonResetGraphique"));

        horizontalLayout_5->addWidget(pushButtonResetGraphique);


        gridLayout_3->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_6->addWidget(pushButton);

        lineEditDernierCoef = new QLineEdit(groupBox_2);
        lineEditDernierCoef->setObjectName(QStringLiteral("lineEditDernierCoef"));
        lineEditDernierCoef->setEnabled(false);

        horizontalLayout_6->addWidget(lineEditDernierCoef);


        gridLayout_3->addLayout(horizontalLayout_6, 3, 0, 1, 1);


        verticalLayout_5->addWidget(groupBox_2);


        gridLayout_2->addLayout(verticalLayout_5, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1265, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(actionBase_de_donnees);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRelancerConnexionOscillo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Tube de Kundt (mesures)", nullptr));
        actionBase_de_donnees->setText(QApplication::translate("MainWindow", "Base de donnees", nullptr));
        actionRelancerConnexionOscillo->setText(QApplication::translate("MainWindow", "Relancer la connexion avec l'oscilloscope", nullptr));
        labelPort->setText(QApplication::translate("MainWindow", "S\303\251lection du port COM : (5 par d\303\251faut)", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "( changer le port ferme la liaison pr\303\251c\303\251demment ouverte )", nullptr));
        pushButtonPort->setText(QApplication::translate("MainWindow", "S\303\251lectionner", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Contr\303\264le GBF", nullptr));
        label->setText(QApplication::translate("MainWindow", "Fr\303\251quence(Hz)", nullptr));
        comboBoxFreq->setItemText(0, QApplication::translate("MainWindow", "200", nullptr));
        comboBoxFreq->setItemText(1, QApplication::translate("MainWindow", "250", nullptr));
        comboBoxFreq->setItemText(2, QApplication::translate("MainWindow", "315", nullptr));
        comboBoxFreq->setItemText(3, QApplication::translate("MainWindow", "400", nullptr));
        comboBoxFreq->setItemText(4, QApplication::translate("MainWindow", "500", nullptr));
        comboBoxFreq->setItemText(5, QApplication::translate("MainWindow", "630", nullptr));
        comboBoxFreq->setItemText(6, QApplication::translate("MainWindow", "800", nullptr));
        comboBoxFreq->setItemText(7, QApplication::translate("MainWindow", "1000", nullptr));
        comboBoxFreq->setItemText(8, QApplication::translate("MainWindow", "1250", nullptr));
        comboBoxFreq->setItemText(9, QApplication::translate("MainWindow", "1600", nullptr));
        comboBoxFreq->setItemText(10, QApplication::translate("MainWindow", "2000", nullptr));
        comboBoxFreq->setItemText(11, QApplication::translate("MainWindow", "2500", nullptr));
        comboBoxFreq->setItemText(12, QApplication::translate("MainWindow", "3150", nullptr));

        LblAmplitude->setText(QApplication::translate("MainWindow", "Amplitude 1-5V", nullptr));
        BtnStart->setText(QApplication::translate("MainWindow", "Start", nullptr));
        BtnStop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Coeficient d'absorbtion", nullptr));
        pushButtonCoefficient->setText(QApplication::translate("MainWindow", "Afficher le coefficient d'absorption", nullptr));
        pushButtonGraphique->setText(QApplication::translate("MainWindow", "Afficher le graphique", nullptr));
        pushButtonResetGraphique->setText(QApplication::translate("MainWindow", "Reset le graphique", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Dernier coefficient en m\303\251moire :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

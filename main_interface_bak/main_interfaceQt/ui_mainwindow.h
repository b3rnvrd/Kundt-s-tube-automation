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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionBase_de_donnees;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
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
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *Editcoef;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(758, 544);
        actionBase_de_donnees = new QAction(MainWindow);
        actionBase_de_donnees->setObjectName(QStringLiteral("actionBase_de_donnees"));
        QIcon icon;
        icon.addFile(QStringLiteral("../images/bdd.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBase_de_donnees->setIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
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


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Editcoef = new QLineEdit(groupBox_2);
        Editcoef->setObjectName(QStringLiteral("Editcoef"));
        Editcoef->setEnabled(false);

        verticalLayout->addWidget(Editcoef);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 758, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(actionBase_de_donnees);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionBase_de_donnees->setText(QApplication::translate("MainWindow", "Base de donnees", nullptr));
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

        LblAmplitude->setText(QApplication::translate("MainWindow", "Amplitude 0-5V", nullptr));
        BtnStart->setText(QApplication::translate("MainWindow", "Start", nullptr));
        BtnStop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Coeficient d'absorbtion", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Afficher Graphique", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

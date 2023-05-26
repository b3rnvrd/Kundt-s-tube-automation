/********************************************************************************
** Form generated from reading UI file 'inserer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERER_H
#define UI_INSERER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Inserer
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditUser;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditPassword;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditId;

    void setupUi(QDialog *Inserer)
    {
        if (Inserer->objectName().isEmpty())
            Inserer->setObjectName(QStringLiteral("Inserer"));
        Inserer->resize(400, 300);
        buttonBox = new QDialogButtonBox(Inserer);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(Inserer);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 209, 84));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEditUser = new QLineEdit(widget);
        lineEditUser->setObjectName(QStringLiteral("lineEditUser"));

        horizontalLayout_2->addWidget(lineEditUser);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEditPassword = new QLineEdit(widget);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(lineEditPassword);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditId = new QLineEdit(widget);
        lineEditId->setObjectName(QStringLiteral("lineEditId"));
        lineEditId->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(lineEditId);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(Inserer);
        QObject::connect(buttonBox, SIGNAL(accepted()), Inserer, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Inserer, SLOT(reject()));

        QMetaObject::connectSlotsByName(Inserer);
    } // setupUi

    void retranslateUi(QDialog *Inserer)
    {
        Inserer->setWindowTitle(QApplication::translate("Inserer", "Dialog", nullptr));
        label_2->setText(QApplication::translate("Inserer", "Nom de Login", nullptr));
        label->setText(QApplication::translate("Inserer", "Mot de passe", nullptr));
        label_4->setText(QApplication::translate("Inserer", "id_personnel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Inserer: public Ui_Inserer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERER_H

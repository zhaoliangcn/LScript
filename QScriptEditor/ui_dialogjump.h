/********************************************************************************
** Form generated from reading UI file 'dialogjump.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGJUMP_H
#define UI_DIALOGJUMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogJump
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QDialog *DialogJump)
    {
        if (DialogJump->objectName().isEmpty())
            DialogJump->setObjectName(QString::fromUtf8("DialogJump"));
        DialogJump->resize(400, 171);
        pushButton = new QPushButton(DialogJump);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 110, 93, 28));
        lineEdit = new QLineEdit(DialogJump);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 70, 381, 21));
        label = new QLabel(DialogJump);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 72, 15));

        retranslateUi(DialogJump);

        QMetaObject::connectSlotsByName(DialogJump);
    } // setupUi

    void retranslateUi(QDialog *DialogJump)
    {
        DialogJump->setWindowTitle(QCoreApplication::translate("DialogJump", "DialogJump", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogJump", "Jump", nullptr));
        label->setText(QCoreApplication::translate("DialogJump", "LineNumber", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogJump: public Ui_DialogJump {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGJUMP_H

/********************************************************************************
** Form generated from reading UI file 'dialogfind.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFIND_H
#define UI_DIALOGFIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogFind
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;

    void setupUi(QDialog *DialogFind)
    {
        if (DialogFind->objectName().isEmpty())
            DialogFind->setObjectName(QString::fromUtf8("DialogFind"));
        DialogFind->resize(400, 300);
        DialogFind->setModal(true);
        buttonBox = new QDialogButtonBox(DialogFind);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textEdit = new QTextEdit(DialogFind);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 381, 241));

        retranslateUi(DialogFind);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogFind, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogFind, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogFind);
    } // setupUi

    void retranslateUi(QDialog *DialogFind)
    {
        DialogFind->setWindowTitle(QCoreApplication::translate("DialogFind", "DialogFind", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFind: public Ui_DialogFind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFIND_H

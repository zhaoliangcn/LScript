/********************************************************************************
** Form generated from reading UI file 'dialogreplace.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGREPLACE_H
#define UI_DIALOGREPLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogReplace
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QLabel *label;

    void setupUi(QDialog *DialogReplace)
    {
        if (DialogReplace->objectName().isEmpty())
            DialogReplace->setObjectName(QString::fromUtf8("DialogReplace"));
        DialogReplace->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogReplace);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::YesToAll);
        textEdit = new QTextEdit(DialogReplace);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 381, 91));
        textEdit_2 = new QTextEdit(DialogReplace);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(10, 140, 381, 91));
        label = new QLabel(DialogReplace);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 110, 181, 20));

        retranslateUi(DialogReplace);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogReplace, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogReplace, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogReplace);
    } // setupUi

    void retranslateUi(QDialog *DialogReplace)
    {
        DialogReplace->setWindowTitle(QCoreApplication::translate("DialogReplace", "DialogReplace", nullptr));
        label->setText(QCoreApplication::translate("DialogReplace", "ReplaceTo:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogReplace: public Ui_DialogReplace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGREPLACE_H

/********************************************************************************
** Form generated from reading UI file 'dialogfont.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFONT_H
#define UI_DIALOGFONT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogFont
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;

    void setupUi(QDialog *DialogFont)
    {
        if (DialogFont->objectName().isEmpty())
            DialogFont->setObjectName(QString::fromUtf8("DialogFont"));
        DialogFont->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogFont);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidget = new QListWidget(DialogFont);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 271, 271));

        retranslateUi(DialogFont);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogFont, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogFont, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogFont);
    } // setupUi

    void retranslateUi(QDialog *DialogFont)
    {
        DialogFont->setWindowTitle(QCoreApplication::translate("DialogFont", "DialogFont", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFont: public Ui_DialogFont {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFONT_H

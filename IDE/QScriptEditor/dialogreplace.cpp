#include "dialogreplace.h"
#include "ui_dialogreplace.h"
#include <QMessageBox>
#include <QPushButton>

DialogReplace::DialogReplace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogReplace)
{
    ui->setupUi(this);
}

DialogReplace::~DialogReplace()
{
    delete ui;
}

void DialogReplace::showEvent(QShowEvent *event)
{
    if(event)
    {
        if(text.isEmpty())
        {
            ui->textEdit->setFocus();
        }
        else {
            ui->textEdit_2->setFocus();
        }
    }

}

void DialogReplace::on_buttonBox_clicked(QAbstractButton *button)
{
    if( ui->buttonBox->button(QDialogButtonBox::Ok)  == button)
    {

        text=ui->textEdit->toPlainText().trimmed();
        reptext=ui->textEdit_2->toPlainText().trimmed();
        if(!text.isEmpty() && !reptext.isEmpty())
        {
            if(lasttext!=text)
            {
                if(editor->findFirst(text,false,false,false,true))
                {
                    lasttext=text;
                    editor->replace(reptext);
                }

            }
            else {
                if(editor->findNext())
                {
                    editor->replace(reptext);
                }
            }
        }

    }
    else if( ui->buttonBox->button(QDialogButtonBox::YesToAll)  == button)
    {
        text=ui->textEdit->toPlainText().trimmed();
        reptext=ui->textEdit_2->toPlainText().trimmed();
        if(!text.isEmpty() && !reptext.isEmpty())
        {
            if(lasttext!=text)
            {
                if(editor->findFirst(text,false,false,false,true))
                {
                    lasttext=text;
                    editor->replace(reptext);
                    while(editor->findNext())
                    {
                        editor->replace(reptext);
                    }
                }
            }
        }
    }
}

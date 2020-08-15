#include "dialogfind.h"
#include "ui_dialogfind.h"
#include <QMessageBox>
#include <QPushButton>

DialogFind::DialogFind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFind)
{
    ui->setupUi(this);
}

DialogFind::~DialogFind()
{
    delete ui;
}

void DialogFind::showEvent(QShowEvent *event)
{
    if(event)
    {
        ui->textEdit->setFocus();
        QDialog::showEvent(event);
    }

}

void DialogFind::on_buttonBox_clicked(QAbstractButton *button)
{
    if( ui->buttonBox->button(QDialogButtonBox::Ok)  == button)
    {
        //QMessageBox msg;
        //msg.information(this,"tofind",ui->textEdit->toPlainText());

        text=ui->textEdit->toPlainText().trimmed();
        if(!text.isEmpty())
        {
            if(lasttext!=text)
            {
                editor->findFirst(text,false,false,false,true);
                lasttext=text;
            }
            else {
                editor->findNext();
            }
        }
    }
}

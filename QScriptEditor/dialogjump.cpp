#include "dialogjump.h"
#include "ui_dialogjump.h"

DialogJump::DialogJump(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogJump)
{
    ui->setupUi(this);
}

DialogJump::~DialogJump()
{
    delete ui;
}

void DialogJump::showEvent(QShowEvent *event)
{
    if(event)
    {
        ui->lineEdit->setFocus();
        QDialog::showEvent(event);
    }
}

void DialogJump::on_pushButton_clicked()
{
    QString linenumber=ui->lineEdit->text();
    int line = linenumber.toInt();
    if(line>0)
    {
        editor->setCursorPosition(line-1,0);
    }
    this->close();
}

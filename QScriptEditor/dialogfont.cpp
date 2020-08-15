#include "dialogfont.h"
#include "ui_dialogfont.h"
#include <QPushButton>
#include <QFontDatabase>
#include <QMessageBox>
DialogFont::DialogFont(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFont)
{
    ui->setupUi(this);
}

DialogFont::~DialogFont()
{
    delete ui;
}

void DialogFont::showEvent(QShowEvent *event)
{
    if(event)
    {
        ui->listWidget->clear();
        QFontDatabase dbfont;
        foreach(const QString &family,dbfont.families(QFontDatabase::SimplifiedChinese))
        {
            ui->listWidget->insertItem(0,family);
        }
        ui->listWidget->setFocus();
        QDialog::showEvent(event);
    }
}

void DialogFont::on_buttonBox_clicked(QAbstractButton *button)
{
    if( ui->buttonBox->button(QDialogButtonBox::Ok)  == button)
    {
        QList<QListWidgetItem*>itmes= ui->listWidget->selectedItems();
        if(itmes.size()==1)
        {
            //QMessageBox msg;
            //msg.information(this,"tofind",itmes.at(0)->text());
            QString fontname=itmes.at(0)->text();
            QFont font(fontname,10,QFont::Normal);
            editor->setFont(font);
            editor->setMarginsFont(font);
            QFontMetrics fontmetrics=QFontMetrics(font);

        }

    }
}

#include "mainwindow.h"
#include <QApplication>
#include <qtextstream.h>
#include "dialogfind.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    if(argc==2)
    {
        w.scriptfilename=argv[1];
        QString content ;
        QFile file(w.scriptfilename);

        if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            //QMessageBox::critical(this,"critical",tr("OpenFile Fail"));
        }
        else
        {
            QTextStream stream(&file);
            while(!stream.atEnd())
            {
                content += stream.readLine();
                content+="\n";
            }
            file.close();
            w.editor->setText(content);
        }
    }
    w.show();

    return a.exec();
}

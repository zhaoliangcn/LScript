#ifndef DIALOGFIND_H
#define DIALOGFIND_H

#include <QDialog>
#include <QAbstractButton>
#include <Qsci/qsciscintilla.h>

namespace Ui {
class DialogFind;
}

class DialogFind : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFind(QWidget *parent = nullptr);
    ~DialogFind();

    QString text;
    QString lasttext;
    QsciScintilla *editor;
protected:
    virtual void	showEvent(QShowEvent * event);
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);
private:
    Ui::DialogFind *ui;
};

#endif // DIALOGFIND_H

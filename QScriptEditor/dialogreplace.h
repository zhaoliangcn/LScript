#ifndef DIALOGREPLACE_H
#define DIALOGREPLACE_H

#include <QDialog>
#include <QAbstractButton>
#include <Qsci/qsciscintilla.h>
namespace Ui {
class DialogReplace;
}

class DialogReplace : public QDialog
{
    Q_OBJECT

public:
    explicit DialogReplace(QWidget *parent = nullptr);
    ~DialogReplace();

    QString text;
    QString reptext;
    QString lasttext;
    QsciScintilla *editor;
protected:
    virtual void	showEvent(QShowEvent * event);
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::DialogReplace *ui;
};

#endif // DIALOGREPLACE_H

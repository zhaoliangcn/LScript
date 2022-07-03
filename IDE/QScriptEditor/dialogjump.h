#ifndef DIALOGJUMP_H
#define DIALOGJUMP_H

#include <QDialog>
#include <Qsci/qsciscintilla.h>
namespace Ui {
class DialogJump;
}

class DialogJump : public QDialog
{
    Q_OBJECT

public:
    explicit DialogJump(QWidget *parent = nullptr);
    ~DialogJump();
     QsciScintilla *editor;
protected:
    virtual void	showEvent(QShowEvent * event);
private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogJump *ui;
};

#endif // DIALOGJUMP_H

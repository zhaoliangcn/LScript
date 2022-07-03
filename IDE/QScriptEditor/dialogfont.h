#ifndef DIALOGFONT_H
#define DIALOGFONT_H

#include <QDialog>
#include <QAbstractButton>
#include <Qsci/qsciscintilla.h>
namespace Ui {
class DialogFont;
}

class DialogFont : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFont(QWidget *parent = nullptr);
    ~DialogFont();
     QsciScintilla *editor;
protected:
    virtual void	showEvent(QShowEvent * event);
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::DialogFont *ui;
};

#endif // DIALOGFONT_H

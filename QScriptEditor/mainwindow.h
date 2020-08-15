#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//QsciScintilla作为QWidget的控件，需要添加该控件的头文件
#include <Qsci/qsciscintilla.h>
//以python语法作为例子，该语法分析器的头文件
#include <Qsci/qscilexerpython.h>
#include <Qsci/qscilexercpp.h>
//设置代码提示功能，依靠QsciAPIs类实现
#include <Qsci/qsciapis.h>

#include <qfiledialog.h>
#include <QTextEdit>
#include <QDockWidget>
#include "ScriptEngineDll.h"
#include "dialogfind.h"
#include "dialogreplace.h"
#include "dialogfont.h"
#include "dialogjump.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetupEditor();
    void RunInEditor();
    QsciScintilla *editor;
    QString scriptfilename;
    QDockWidget* dock ;
    QTextEdit * edit_output ;
    void AppendMessage(QString message);
protected:
    void closeEvent ( QCloseEvent * e );
private slots:
    void on_actionSave_triggered();

    void on_actionSaveAs_triggered();

    void on_actionExit_triggered();

    void on_actionRun_triggered();

    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_actionAbout_triggered();

    void on_actionFind_triggered();

    void on_actionReplace_triggered();

    void on_actionComment_triggered();

    void on_actionUnComment_triggered();

    void on_actionNormalizeLineEnd_Unix_triggered();

    void on_actionNormalizeLineEnd_Win_triggered();

    void on_actionComment_2_triggered();

    void on_actionUnComment_2_triggered();

    void on_actionClose_triggered();

    void on_actionInsertFunction_triggered();

    void on_actionInsertClass_triggered();

    void on_actionDeleteEmptyLines_triggered();

    void on_actionFont_triggered();

    void on_actionJump_triggered();

    void on_textChanged();

private:
    Ui::MainWindow *ui;

    DialogFind f;
    DialogReplace dr;
    DialogFont dlgfont;
    DialogJump dlgjump;
    bool dirty_text;
};

void EditorUIMessage(void * uiclass, const wchar_t * message);

#endif // MAINWINDOW_H

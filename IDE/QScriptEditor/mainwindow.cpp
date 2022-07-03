#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>
#include <qtextstream.h>
#include <qprocess.h>
#include <QCoreApplication>
#include "scpkeywords.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetupEditor();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void  MainWindow::SetupEditor()
{
    this->setWindowTitle("ScriptEditor");
    editor=new QsciScintilla(this);
    setCentralWidget(editor);
    //设置语法
    QsciLexerCPP *textLexer = new ScpKeywords;//创建一个词法分析器
    editor->setLexer(textLexer);//给QsciScintilla设置词法分析器

    textLexer->setColor(QColor(Qt::darkBlue),ScpKeywords::Keyword);

    //行号提示
    editor->setMarginType(0,QsciScintilla::NumberMargin);//设置编号为0的页边显示行号。
    editor->setMarginLineNumbers(0,true);//对该页边启用行号
    editor->setMarginWidth(0,30);//设置页边宽度
    //代码提示
    QsciAPIs *apis = new QsciAPIs(textLexer);

    //获取程序当前运行目录
    QString fileName = QCoreApplication::applicationDirPath();
    fileName+="/keyword.txt";
    if(apis->load(fileName))
    {
         //QMessageBox::critical(this,"critical",tr("load keyword Fail"));
    }
    else
    {
        apis->add(QString("define"));
        apis->add(QString("show"));
        apis->add(QString("function"));
        apis->add(QString("int"));
        apis->add(QString("int64"));
        apis->add(QString("string"));
        apis->add(QString("double"));
        apis->add(QString("table"));
        apis->add(QString("file"));
        apis->add(QString("directory"));
        apis->add(QString("memory"));
    }

    apis->prepare();

    editor->setAutoCompletionSource(QsciScintilla::AcsAll);   //设置源，自动补全所有地方出现的
    editor->setAutoCompletionCaseSensitivity(true);   //设置自动补全大小写敏感
    editor->setAutoCompletionThreshold(1);    //设置每输入一个字符就会出现自动补全的提示
    editor->SendScintilla(QsciScintilla::SCI_SETCODEPAGE,QsciScintilla::SC_CP_UTF8);//设置编码为UTF-8
    //设置光标所在行背景色
    editor->setCaretLineBackgroundColor(Qt::lightGray);
        //pLayout = new QVBoxLayout(this);
        //pLayout->addWidget(editor);
       // pLayout->setContentsMargins(0,0,0,0);
    editor->setTabWidth(4);

    dock = new QDockWidget("output", this); //新建一个标题为dock的停靠窗口
    dock->setFeatures(QDockWidget::NoDockWidgetFeatures);//避免停靠窗口被关闭
    edit_output = new QTextEdit("", dock);
    dock->setWidget(edit_output); //将edit_output嵌套到停靠窗口中
    this->addDockWidget(Qt::BottomDockWidgetArea, dock); //主窗口添加dock停靠窗口到左边停靠区域

    // notify if cursor position changed
    connect(editor, SIGNAL(textChanged()), this, SLOT(on_textChanged()));
    dirty_text=false;
}
void MainWindow::on_actionSave_triggered()
{
    QString content =editor->text();
    if(!scriptfilename.isEmpty())
    {
        QFile file(scriptfilename);

        //增加QIODevice::Text 参数会自动去掉'\r'字符
        if (!file.open(QIODevice::WriteOnly))
        //if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            QMessageBox::critical(this,"critical",tr("SaveFile Fail"));
        }
        else
        {
            file.write(content.toUtf8());
            //QTextStream stream(&file);
            //stream <<content;
            //stream.flush();
            file.close();
            dirty_text=false;
        }
    }
    else {
        //QMessageBox msg;
        //msg.information(this,"test",content);
        if(!content.isEmpty())
        {
             on_actionSaveAs_triggered();
        }
    }
}

void MainWindow::on_actionSaveAs_triggered()
{
    QString filename;
    QFileDialog dlg;
    filename = dlg.getSaveFileName();
    if(!filename.isEmpty())
    {
        QString content =editor->text();
        QFile file(filename);

        if (!file.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            QMessageBox::critical(this,"critical",tr("SaveFile Fail"));
        }
        else
        {
            QTextStream stream(&file);
            stream <<content;
            stream.flush();
            file.close();
            dirty_text=false;
        }
    }
}

void MainWindow::on_actionExit_triggered()
{
    on_actionClose_triggered();
    exit(0);
}

void MainWindow::on_actionRun_triggered()
{
    RunInEditor();
    /*
    QString workpath = "E:\\opensource\\build\\build-QScriptEditor-Desktop_Qt_5_13_0_MSVC2017_64bit-Debug\\debug\\";
    QProcess proc;
    QString engine="C:/Program Files/SCRIPTENGINE/ScriptEngine.exe";
    workpath = "C:/Program Files/SCRIPTENGINE/";
    //engine="C:\\ScriptEngine\\ScritpEngine\\Release\\ScriptEngine.exe";
    QStringList arg;
    arg<<scriptfilename;
    proc.setWorkingDirectory(workpath);
    proc.start(engine,arg);
    proc.waitForFinished(30);
    //proc.execute(engine,arg);
    */
}

void MainWindow::on_actionOpen_triggered()
{
    QFileDialog dlg;
    QString filename = dlg.getOpenFileName();
    if(!filename.isEmpty())
    {
        scriptfilename=filename;
        QString content ;
        QFile file(scriptfilename);

        //QIODevice::Text 参数会自动去掉'\r'字符
        //if (!file.open(QIODevice::ReadOnly|QIODevice::Text))
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this,"critical",tr("OpenFile Fail"));
        }
        else
        {
            QByteArray all =file.readAll();
            content=QString(all);
//            while(!file.atEnd())
//            {
//                QByteArray line = file.readLine();
//                QString str(line);
//                content.append(str);
//            }

            //QTextStream stream(&file);
            //content =stream.readAll();
            //while(!stream.atEnd())
            //{
            //    content += stream.readLine();
                //content+="\n";
            //}
            file.close();
            editor->setText(content);
            dirty_text=false;
        }
    }
}

void MainWindow::on_actionNew_triggered()
{
    scriptfilename.clear();
    QString content ="#scp\n#scpeng\n";
    editor->setText(content);
    editor->setCursorPosition(2,0);
    dirty_text=false;
}
void MainWindow::RunInEditor()
{
    if(edit_output)
    {
        edit_output->setText("");
    }
    HANDLE hEngine = CreateScriptEngine();
    if (hEngine)
    {
        QString content =editor->text();
        int length = content.length()*6;
        if (length > 0)
        {
            wchar_t * Buffer = (wchar_t *)malloc(length + 10);
            if (Buffer)
            {
               memset(Buffer, 0, length + 10);
               ScriptRegisterUICallBack(hEngine, (void *)this, (UICallBack)EditorUIMessage);
               int reallength = content.toWCharArray(Buffer);
			   Buffer[reallength] = '\0';
               ScriptDebugMemoryScript(hEngine, Buffer);
               free(Buffer);
            }
        }
        CloseScriptEngine(hEngine);
    }
}

void MainWindow::AppendMessage(QString message)
{
    edit_output->append(message);
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    on_actionClose_triggered();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msg;
    msg.information(this,"About","Qt5 LScriptEditor");
}


void EditorUIMessage(void * uiclass, const wchar_t * message)
{
    MainWindow * mainwnd=(MainWindow*)uiclass;
    if(mainwnd)
    {
       QString result ;//= main->edit_output->toPlainText();
       result+=QString::fromWCharArray(message);
       //result+="\r\n";
       mainwnd->AppendMessage(result);
       //main->edit_output->setText(result);
    }
}

void MainWindow::on_actionFind_triggered()
{
    f.editor=this->editor;
    f.setModal(true); // 对话框特有
    f.setAttribute(Qt::WA_ShowModal, true); // 设置WA_ShowModal属性
    f.setWindowModality(Qt::ApplicationModal); // 设置阻塞方式
    f.show();



}

void MainWindow::on_actionReplace_triggered()
{
    dr.editor=this->editor;
    dr.setModal(true); // 对话框特有
    dr.setAttribute(Qt::WA_ShowModal, true); // 设置WA_ShowModal属性
    dr.setWindowModality(Qt::ApplicationModal); // 设置阻塞方式
    dr.show();

}

void MainWindow::on_actionComment_triggered()
{
    int linefrom;
    int lineto;
    int indexfrom;
    int indexto;
    editor->getSelection(&linefrom,&indexfrom,&lineto,&indexto);
    for( int i=linefrom;i<=lineto;i++)
        editor->insertAt("//",i,0);

}

void MainWindow::on_actionUnComment_triggered()
{

    int linefrom;
    int lineto;
    int indexfrom;
    int indexto;
    editor->getSelection(&linefrom,&indexfrom,&lineto,&indexto);
    for( int i=linefrom;i<=lineto;i++)
    {
        editor->setSelection(i,0,i,2);
        if(editor->selectedText()=="//")
        {
              editor->replaceSelectedText("");
        }

    }
}

void MainWindow::on_actionNormalizeLineEnd_Unix_triggered()
{
    //行尾标准化为linux 格式 \n
//    int linecount = editor->lines();
//    for(int i=0;i<linecount;i++)
//    {
//        int linelength=editor->lineLength(i);
//        if(linelength>2)
//        {
//            editor->setSelection(i,0,i,linelength);
//            QString lineText=editor->selectedText();
//            if(lineText.mid(lineText.length()-2)=="\r\n")
//            {
//                lineText=lineText.mid(0,lineText.length()-2)+"\n";
//                  editor->replaceSelectedText(lineText);
//            }
//        }
//    }
    QString text=editor->text();
    int pos = text.indexOf("\r\n");
    while(pos>=0)
    {
        text.replace(pos,2,"\n");
        pos = text.indexOf("\r\n",pos+1);
    }
    editor->setText(text);
}

void MainWindow::on_actionNormalizeLineEnd_Win_triggered()
{
    //行尾标准化为windows格式 \r\n
//    int linecount = editor->lines();
//    for(int i=0;i<linecount;i++)
//    {
//        int linelength=editor->lineLength(i);
//        if(linelength>1)
//        {
//            editor->setSelection(i,0,i,linelength);
//            QString lineText=editor->selectedText();
//            if(lineText.mid(lineText.length()-2,1)!="\r")
//            {
//                lineText=lineText.mid(0,lineText.length()-1)+"\r\n";
//                  editor->replaceSelectedText(lineText);
//            }
//        }
//    }
    QString text=editor->text();
    int pos = text.indexOf("\n");
    while(pos>0)
    {
        if(text.at(pos-1)!='\r')
        {
             text.replace(pos,1,"\r\n");
        }
        pos = text.indexOf("\n",pos+2);
    }
    editor->setText(text);
}

void MainWindow::on_actionComment_2_triggered()
{
    int linefrom;
    int lineto;
    int indexfrom;
    int indexto;
    editor->getSelection(&linefrom,&indexfrom,&lineto,&indexto);
    for( int i=linefrom;i<=lineto;i++)
    {
        editor->insertAt("#",i,0);
    }
}

void MainWindow::on_actionUnComment_2_triggered()
{
    int linefrom;
    int lineto;
    int indexfrom;
    int indexto;
    editor->getSelection(&linefrom,&indexfrom,&lineto,&indexto);
    for( int i=linefrom;i<=lineto;i++)
    {
        editor->setSelection(i,0,i,1);
        if(editor->selectedText()=="#")
        {
              editor->replaceSelectedText("");
        }
    }
}

void MainWindow::on_actionClose_triggered()
{
    if(!dirty_text)
    {
        scriptfilename="";
        editor->setText("");
        dirty_text=false;
    }
    else
    {
        QMessageBox msg;
        QMessageBox:: StandardButton result=msg.information(this,"Tip","FileChanged,Save To Disk?",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        switch (result)
        {
        case QMessageBox::Yes:
            //文件已经修改，先保存，再重新调用关闭
            if(scriptfilename.isEmpty())
            {
                on_actionSaveAs_triggered();
                on_actionClose_triggered();
            }
            else
            {
                on_actionSave_triggered();
                on_actionClose_triggered();
            }
            break;
        case QMessageBox::No:
            {
                scriptfilename="";
                editor->setText("");
                dirty_text=false;
            }
            break;
        default:
            break;
        }
    }

}

void MainWindow::on_actionInsertFunction_triggered()
{
    editor->insert("define:function,myfunc\n\nend\n");
    //查找myfunc使其处于选中状态，便于用户修改函数名
    int line ;
    int index;
    editor->getCursorPosition(&line,&index);
    editor->findFirst("myfunc",false,false,false,true,true,line,index);
}

void MainWindow::on_actionInsertClass_triggered()
{
    editor->insert("define:class,myclass\npublic:\n\nend\n");
    //查找myclass使其处于选中状态，便于用户修改类名
    int line ;
    int index;
    editor->getCursorPosition(&line,&index);
    editor->findFirst("myclass",false,false,false,true,true,line,index);
}

void MainWindow::on_actionDeleteEmptyLines_triggered()
{
    //查找并删除所有的空行
    //空行判断的条件是，行结束符"\r" "\n" "\r\n" 的前面是行结束符
    QString text=editor->text();
    int pos = text.indexOf("\n");
    while(pos>0 && pos<(text.length()-1))
    {
        if(text.at(pos+1)=='\n')
        {
             text.replace(pos+1,1,"");
             pos = text.indexOf("\n",pos);
        }
        else if(text.at(pos+1)=='\r')
        {
             text.replace(pos+1,1,"");
             pos = text.indexOf("\n",pos);
        }
        else
        {
             pos = text.indexOf("\n",pos+1);
        }
    }
    pos = text.indexOf("\r\n");
    while(pos>0  && pos<(text.length()-2))
    {
        if(text.mid(pos+2,2)=="\r\n")
        {
             text.replace(pos+2,2,"");
             pos = text.indexOf("\r\n",pos);
        }
        else
        {
            pos = text.indexOf("\r\n",pos+2);
        }

    }
    editor->setText(text);
}

void MainWindow::on_actionFont_triggered()
{
    dlgfont.editor=this->editor;
    dlgfont.show();
}

void MainWindow::on_actionJump_triggered()
{
    dlgjump.editor=this->editor;
    dlgjump.show();

}

void MainWindow::on_textChanged()
{
    //QMessageBox::critical(this,"critical",tr("on_textChanged"));
    dirty_text=true;
}

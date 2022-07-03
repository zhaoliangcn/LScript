/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionRun;
    QAction *actionDebug;
    QAction *actionSaveAs;
    QAction *actionAbout;
    QAction *actionNew;
    QAction *actionFind;
    QAction *actionReplace;
    QAction *actionComment;
    QAction *actionUnComment;
    QAction *actionNormalizeLineEnd_Unix;
    QAction *actionNormalizeLineEnd_Win;
    QAction *actionComment_2;
    QAction *actionUnComment_2;
    QAction *actionClose;
    QAction *actionInsertFunction;
    QAction *actionInsertClass;
    QAction *actionDeleteEmptyLines;
    QAction *actionFont;
    QAction *actionJump;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuScript;
    QMenu *menuHelp;
    QMenu *menuEdit;
    QMenu *menuoptions;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1101, 916);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        actionDebug = new QAction(MainWindow);
        actionDebug->setObjectName(QString::fromUtf8("actionDebug"));
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName(QString::fromUtf8("actionReplace"));
        actionComment = new QAction(MainWindow);
        actionComment->setObjectName(QString::fromUtf8("actionComment"));
        actionUnComment = new QAction(MainWindow);
        actionUnComment->setObjectName(QString::fromUtf8("actionUnComment"));
        actionNormalizeLineEnd_Unix = new QAction(MainWindow);
        actionNormalizeLineEnd_Unix->setObjectName(QString::fromUtf8("actionNormalizeLineEnd_Unix"));
        actionNormalizeLineEnd_Win = new QAction(MainWindow);
        actionNormalizeLineEnd_Win->setObjectName(QString::fromUtf8("actionNormalizeLineEnd_Win"));
        actionComment_2 = new QAction(MainWindow);
        actionComment_2->setObjectName(QString::fromUtf8("actionComment_2"));
        actionUnComment_2 = new QAction(MainWindow);
        actionUnComment_2->setObjectName(QString::fromUtf8("actionUnComment_2"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionInsertFunction = new QAction(MainWindow);
        actionInsertFunction->setObjectName(QString::fromUtf8("actionInsertFunction"));
        actionInsertClass = new QAction(MainWindow);
        actionInsertClass->setObjectName(QString::fromUtf8("actionInsertClass"));
        actionDeleteEmptyLines = new QAction(MainWindow);
        actionDeleteEmptyLines->setObjectName(QString::fromUtf8("actionDeleteEmptyLines"));
        actionFont = new QAction(MainWindow);
        actionFont->setObjectName(QString::fromUtf8("actionFont"));
        actionJump = new QAction(MainWindow);
        actionJump->setObjectName(QString::fromUtf8("actionJump"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1101, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuScript = new QMenu(menuBar);
        menuScript->setObjectName(QString::fromUtf8("menuScript"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuoptions = new QMenu(menuBar);
        menuoptions->setObjectName(QString::fromUtf8("menuoptions"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuScript->menuAction());
        menuBar->addAction(menuoptions->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addAction(actionClose);
        menuFile->addAction(actionExit);
        menuScript->addAction(actionRun);
        menuScript->addAction(actionDebug);
        menuHelp->addAction(actionAbout);
        menuEdit->addAction(actionFind);
        menuEdit->addAction(actionReplace);
        menuEdit->addAction(actionComment);
        menuEdit->addAction(actionUnComment);
        menuEdit->addAction(actionComment_2);
        menuEdit->addAction(actionUnComment_2);
        menuEdit->addAction(actionNormalizeLineEnd_Unix);
        menuEdit->addAction(actionNormalizeLineEnd_Win);
        menuEdit->addAction(actionInsertFunction);
        menuEdit->addAction(actionInsertClass);
        menuEdit->addAction(actionDeleteEmptyLines);
        menuEdit->addAction(actionJump);
        menuoptions->addAction(actionFont);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRun->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
#if QT_CONFIG(shortcut)
        actionRun->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDebug->setText(QCoreApplication::translate("MainWindow", "Debug", nullptr));
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "SaveAs", nullptr));
#if QT_CONFIG(shortcut)
        actionSaveAs->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFind->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
#if QT_CONFIG(shortcut)
        actionFind->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionReplace->setText(QCoreApplication::translate("MainWindow", "Replace", nullptr));
#if QT_CONFIG(shortcut)
        actionReplace->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionComment->setText(QCoreApplication::translate("MainWindow", "Comment(cpp)", nullptr));
#if QT_CONFIG(tooltip)
        actionComment->setToolTip(QCoreApplication::translate("MainWindow", "Comment(cpp style)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionComment->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+/", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUnComment->setText(QCoreApplication::translate("MainWindow", "UnComment(cpp)", nullptr));
#if QT_CONFIG(tooltip)
        actionUnComment->setToolTip(QCoreApplication::translate("MainWindow", "UnComment(cpp style)", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionUnComment->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+/", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNormalizeLineEnd_Unix->setText(QCoreApplication::translate("MainWindow", "NormalizeLineEnd(Unix)", nullptr));
#if QT_CONFIG(shortcut)
        actionNormalizeLineEnd_Unix->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N, Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNormalizeLineEnd_Win->setText(QCoreApplication::translate("MainWindow", "NormalizeLineEnd(Win)", nullptr));
#if QT_CONFIG(shortcut)
        actionNormalizeLineEnd_Win->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N, Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionComment_2->setText(QCoreApplication::translate("MainWindow", "Comment(#)", nullptr));
#if QT_CONFIG(shortcut)
        actionComment_2->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+3", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUnComment_2->setText(QCoreApplication::translate("MainWindow", "UnComment(#)", nullptr));
#if QT_CONFIG(shortcut)
        actionUnComment_2->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+3", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
#if QT_CONFIG(shortcut)
        actionClose->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionInsertFunction->setText(QCoreApplication::translate("MainWindow", "InsertFunction", nullptr));
#if QT_CONFIG(shortcut)
        actionInsertFunction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I, Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionInsertClass->setText(QCoreApplication::translate("MainWindow", "InsertClass", nullptr));
#if QT_CONFIG(shortcut)
        actionInsertClass->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I, Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDeleteEmptyLines->setText(QCoreApplication::translate("MainWindow", "DeleteEmptyLines", nullptr));
#if QT_CONFIG(shortcut)
        actionDeleteEmptyLines->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E, Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFont->setText(QCoreApplication::translate("MainWindow", "Font", nullptr));
        actionJump->setText(QCoreApplication::translate("MainWindow", "Jump", nullptr));
#if QT_CONFIG(shortcut)
        actionJump->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+J", nullptr));
#endif // QT_CONFIG(shortcut)
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuScript->setTitle(QCoreApplication::translate("MainWindow", "Script", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuoptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

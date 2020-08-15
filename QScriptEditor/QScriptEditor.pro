#-------------------------------------------------
#
# Project created by QtCreator 2019-09-26T15:16:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QScriptEditor
TEMPLATE = app
RC_ICONS = SCP.ico

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += .
INCLUDEPATH += E:\opensource\build\QScintilla_gpl-2.11.2\Qt4Qt5
#INCLUDEPATH += /home/coder/QScintilla-2.11.5/Qt4Qt5


QMAKE_LFLAGS = -Wl,--rpath=.


contains(QT_ARCH, i386) {
        message("32-bit")
LIBS += -L. -lqscintilla2_qt5
LIBS += -L. -lScriptEngineDll
    } else {
        message("64-bit")

CONFIG(debug, debug|release) {
message("debug")
LIBS += -L. -LE:\opensource\build\QScintilla_gpl-2.11.2\build-qscintilla-Desktop_Qt_5_13_0_MSVC2017_64bit-Debug\debug -lqscintilla2_qt5d
} else {
message("release")
LIBS += -L. -LE:\opensource\build\QScintilla_gpl-2.11.2\build-qscintilla-Desktop_Qt_5_13_0_MSVC2017_64bit-Release\release -lqscintilla2_qt5
}
#LIBS += -L. -L/home/coder/QScintilla-2.11.5/Qt4Qt5 -lqscintilla2_qt5
LIBS += -L. -lScriptEngineDll
    }
CONFIG += c++11

SOURCES += \
    dialogfont.cpp \
    dialogjump.cpp \
        main.cpp \
        mainwindow.cpp \
    scpkeywords.cpp \
    dialogfind.cpp \
    dialogreplace.cpp

HEADERS += \
    dialogfont.h \
    dialogjump.h \
        mainwindow.h \
    scpkeywords.h \
    dialogfind.h \
    dialogreplace.h

FORMS += \
    dialogfont.ui \
    dialogjump.ui \
        mainwindow.ui \
    dialogfind.ui \
    dialogreplace.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

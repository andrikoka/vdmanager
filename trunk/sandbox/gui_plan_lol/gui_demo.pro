#-------------------------------------------------
#
# Project created by QtCreator 2010-10-31T22:43:55
#
#-------------------------------------------------

QT       += core gui

TARGET = gui_demo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dirlist.cpp \
    vdfileitem.cpp \
    vdfilecontrol.cpp \
    vdlocalfile.cpp \
    vddispatcher.cpp \
    vdabstractfile.cpp

HEADERS  += mainwindow.h \
    dirlist.h \
    vdfileitem.h \
    vdfilecontrol.h \
    vdlocalfile.h \
    vddispatcher.h \
    vdabstractfile.h \
    dyn_ui_navigator.h

FORMS    += \
    gui_1.ui \
    navigator.ui

RESOURCES += \
    res.qrc

OTHER_FILES += \
    jegyzetek.txt

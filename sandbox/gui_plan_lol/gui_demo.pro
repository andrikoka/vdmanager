#-------------------------------------------------
#
# Project created by QtCreator 2010-10-31T22:43:55
#
#-------------------------------------------------

QT       += core gui

TARGET = VDManager
TEMPLATE = app


SOURCES += main.cpp\
    ProtocolManagers/vdlocalfile.cpp \
    ProtocolManagers/vdabstractfile.cpp \
    Control/vdfileitem.cpp \
    Control/vdfilecontrol.cpp \
    Control/vddispatcher.cpp \
    Gui/mainwindow.cpp

HEADERS  += ProtocolManagers/vdlocalfile.h \
    ProtocolManagers/vdabstractfile.h \
    Control/vdfileitem.h \
    Control/vdfilecontrol.h \
    Control/vddispatcher.h \
    Gui/mainwindow.h \
    Gui/dyn_ui_navigator.h

FORMS    += \
    Gui/Forms/navigator.ui \
    Gui/Forms/gui_1.ui

RESOURCES +=

OTHER_FILES += \
    jegyzetek.txt

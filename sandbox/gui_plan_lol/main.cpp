#include <QtGui/QApplication>
#include "mainwindow.h"
#include <vdfilecontrol.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    VDFileControl vdfc(&w);
    w.show();
    return a.exec();
}
#include <QtGui/QApplication>
#include "mainwindow.h"
#include "QStringList"
#include "dirlist.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    dirlist d;
    w.addFiles(d.listCurrent());
    w.show();
    return a.exec();
}

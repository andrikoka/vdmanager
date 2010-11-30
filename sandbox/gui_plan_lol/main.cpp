#include <QtGui/QApplication>
#include <Gui/mainwindow.h>
#include <Control/vdfilecontrol.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    VDFileControl vdfc(&w);
    w.show();
    return a.exec();
}

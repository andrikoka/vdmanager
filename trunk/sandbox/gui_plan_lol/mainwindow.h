#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_gui_1.h>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addFiles(QStringList,qint8 p=0);
    void setLeftLocation(QString);
    void setRightLocation(QString);

private:
    Ui::mW *ui;
    QString szLeftLocation,szRightLocation; // panel locations
    void panelLocationChanged(bool); //left: 0; right: 0;
    void addItems(QTableWidget*,QStringList);
};

#endif // MAINWINDOW_H

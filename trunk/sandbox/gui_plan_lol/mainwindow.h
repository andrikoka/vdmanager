#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <ui_gui_1.h>

#include <vdfileitem.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    //void panelContentChanged(QWidget *panel);
    void itemIsReadyToDisplay(VDFileItem * item);

private:
    Ui::mW *ui;
    void addItems(QListWidget *,QList<VDFileItem*>);
    QList<VDFileItem*> leftPanelList;
    QList<VDFileItem*> rightPanelList;
    QString leftCurrent,rightCurrent;
    QWidget * findItemInPanel(VDFileItem * item);
};

#endif // MAINWINDOW_H

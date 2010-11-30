#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QFileIconProvider>
#include <QTableWidgetItem>
#include <QDebug>

#include <Control/vdfileitem.h>
#include <ui_gui_1.h>
#include <Gui/dyn_ui_navigator.h>
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

public slots:
    //void panelContentChanged(QWidget *panel);
    void itemIsReadyToDisplay(VDFileItem * item);
    void clearPanel(int);
    void setDrive(QString drive,QIcon icon);
    void addItemToAddressbar(QString,int);

private:
    Ui::mW *ui;
    Ui_Navigator *nav_left,*nav_right;
protected slots:
    void driveButtonClicked();
private slots:
    void on_panel_left_itemActivated(QListWidgetItem* item);
    void on_panel_right_itemActivated(QListWidgetItem* item);
    void left_addressbarItemChanged(QString);
    void right_addressbarItemChanged(QString);
    void left_previousAddressRequested();
    void right_previousAddressRequested();
    void left_goButtonClicked();
    void right_goButtonClicked();

signals:
    // string: standardurl; int: panelnum
    void itemActivated(QString,int);
};

#endif // MAINWINDOW_H

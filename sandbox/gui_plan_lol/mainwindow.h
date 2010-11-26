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
    void clearPanel(int);

private:
    Ui::mW *ui;

private slots:
    void on_panel_left_itemDoubleClicked(QListWidgetItem* item);
    void on_panel_right_itemDoubleClicked(QListWidgetItem* item);
signals:
    // string: standardurl; int: panelnum
    void itemDoubleClicked(QString, int);
};

#endif // MAINWINDOW_H

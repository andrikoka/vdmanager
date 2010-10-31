#include "mainwindow.h"
#include "ui_gui_1.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::addFiles(QStringList a) {
    for(int i=0;i<a.count();i++){
            ui->listWidget->addItem(a[i]);
            ui->listWidget_2->addItem(a[i]);
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

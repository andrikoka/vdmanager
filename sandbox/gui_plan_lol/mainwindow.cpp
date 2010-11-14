#include "mainwindow.h"
#include "ui_gui_1.h"
#include <QFileIconProvider>
#include <QTableWidgetItem>
#include <QDebug>
#include <vdfileitem.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mW) // itt kapcsolodik a letrehozott form a koddal
{
    ui->setupUi(this);
}

void MainWindow::itemIsReadyToDisplay(VDFileItem *item){
    ui->panel_left->addItem(item->getFileName());
    qDebug() << item << "added";
}

MainWindow::~MainWindow()
{
    delete ui;
}

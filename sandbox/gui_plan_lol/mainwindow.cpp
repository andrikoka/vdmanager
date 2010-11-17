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
    QString StringItem;
    StringItem = QString("%1	%2 %3")
		 .arg(item->getFileName())
		 .arg(item->getSize())
		 .arg(item->getCreateDate().toString());
    //qDebug() << StringItem;
    QListWidgetItem * qlwi;
    qlwi = new QListWidgetItem(item->getIcon(),StringItem);
    switch (item->getPanelIndex()){
    case 0 :{
	ui->panel_left->addItem(qlwi);
    }
	break;
    case 1 : ui->panel_right->addItem(qlwi); break;
    }

    //qDebug() << item->getPanelIndex() << "panelnum";
}

MainWindow::~MainWindow()
{
    delete ui;
}

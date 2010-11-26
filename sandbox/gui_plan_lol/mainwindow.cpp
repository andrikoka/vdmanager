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
    QListWidgetItem * qlwi;
    StringItem = QString("%1	%2 %3")
		 .arg(item->getFileName())
		 .arg(item->getSize())
		 .arg(item->getCreateDate().toString());

    switch (item->getPanelIndex()){
    case 0 :{
	qlwi = new QListWidgetItem(item->getIcon(),StringItem,ui->panel_left);
	qlwi->setData(32,item->getStandardURL());
	//qDebug() << item->getPanelIndex() << "panelnum" << qlwi->data(32).toString();
    }
	break;
    case 1 : {
	    qlwi = new QListWidgetItem(item->getIcon(),StringItem,ui->panel_right);
	    qlwi->setData(32,item->getStandardURL());
	}
	;break;
    }

}

void MainWindow::clearPanel(int panel){
    switch(panel){
    case 0:{
	    if (ui->panel_left->count() > 0) ui->panel_left->clear();
	} break;
    case 1: {
	    if (ui->panel_right->count() > 0) ui->panel_right->clear();
	} break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_panel_left_itemDoubleClicked(QListWidgetItem* item)
{
    QVariant stuff;
    stuff = item->data(32);
    emit itemDoubleClicked(stuff.toString(),0);
}
void MainWindow::on_panel_right_itemDoubleClicked(QListWidgetItem* item)
{
    QVariant stuff;
    stuff = item->data(32);
    emit itemDoubleClicked(stuff.toString(),1);
}

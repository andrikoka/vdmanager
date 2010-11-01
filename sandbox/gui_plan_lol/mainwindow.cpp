#include "mainwindow.h"
#include "ui_gui_1.h"
#include <QFileIconProvider>
#include <QTableWidgetItem>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mW) // itt kapcsolodik a letrehozott form a koddal
{
    ui->setupUi(this);
}
void MainWindow::addFiles(QStringList a,qint8 p) {
    if (p == 0){
	addItems(ui->panel_left,a);
	addItems(ui->panel_right,a);
    } else if (p == 1) {
	addItems(ui->panel_left,a);
    } else {
	addItems(ui->panel_right,a);
    }
//p_an = ui->panel_left;

}
void MainWindow::addItems(QTableWidget * p_an,QStringList a) {
    QString headers;
    headers = "File;Size;Type";
    QFileIconProvider qfip;

    while(p_an->rowCount() != 0) { p_an->removeRow(0); } //cleanup
    while(p_an->columnCount() != 0) { p_an->removeColumn(0); } //cleanup
    p_an->setColumnCount(headers.split(";").count());
    p_an->setHorizontalHeaderLabels(headers.split(";"));

    for(int i=0;i<a.count();i++){
	    p_an->insertRow(i);
	    QFileInfo qfi;
	    QString p;
	    qfi = QFileInfo(a[i]);
	    QTableWidgetItem * fileItem = new QTableWidgetItem(qfip.icon(qfi),a[i]);
	    QTableWidgetItem * sizeItem = new QTableWidgetItem(QString("%1 byte").arg(qfi.size()));
	    qDebug() << qfi.size();
	    QTableWidgetItem * suffixItem = new QTableWidgetItem(qfi.suffix());
	    p_an->setItem(i,0,fileItem);
	    p_an->setItem(i,1,sizeItem);
	    p_an->setItem(i,2,suffixItem);
	}
}

void MainWindow::setLeftLocation(QString l) {
    this->szLeftLocation = l;
    this->panelLocationChanged(0);
}

void MainWindow::setRightLocation(QString r) {
    this->szRightLocation = r;
    this->panelLocationChanged(1);
}
void MainWindow::panelLocationChanged(bool p){
    if (p) {
	//this->addFiles()
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include <Gui/mainwindow.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mW) // itt kapcsolodik a letrehozott form a koddal
{
    ui->setupUi(this);
    this->nav_left = new Ui_Navigator(ui->centralwidget,this);
    ui->panelLeftLayout->insertLayout(0,nav_left->verticalLayout,0);
    ui->panelLeftLayout->setStretch(1,1);
    connect(nav_left->addressBar,SIGNAL(activated(QString)),this,SLOT(left_addressbarItemChanged(QString)));
    connect(nav_left->backButton,SIGNAL(clicked()),this,SLOT(left_previousAddressRequested()));
    connect(nav_left->goButton,SIGNAL(clicked()),this,SLOT(left_goButtonClicked()));


    this->nav_right = new Ui_Navigator(ui->centralwidget,this);
    ui->panelRightLayout->insertLayout(0,nav_right->verticalLayout,0);
    ui->panelRightLayout->setStretch(1,1);
    connect(nav_right->addressBar,SIGNAL(activated(QString)),this,SLOT(left_addressbarItemChanged(QString)));
    connect(nav_right->backButton,SIGNAL(clicked()),this,SLOT(right_previousAddressRequested()));
    connect(nav_right->goButton,SIGNAL(clicked()),this,SLOT(right_goButtonClicked()));
 }

void MainWindow::itemIsReadyToDisplay(VDFileItem *item){
    QString StringItem;
    QListWidgetItem * qlwi;
    QFileIconProvider qfip;
    QIcon icon = QIcon();
    StringItem = QString("%1	%2 %3")
		 .arg(item->getFileName())
		 .arg(item->getSize())
		 .arg(item->getCreateDate().toString());
    if (item->isDir()){
	icon = qfip.icon(QFileIconProvider::Folder);
    } else {
	icon = qfip.icon(QFileIconProvider::File);
	    };
    switch (item->getPanelIndex()){
    case 0 :{
	qlwi = new QListWidgetItem(icon,StringItem,ui->panel_left);
	qlwi->setData(32,item->getStandardURL());
	//qDebug() << item->getPanelIndex() << "panelnum" << qlwi->data(32).toString();
    }
	break;
    case 1 : {
	    qlwi = new QListWidgetItem(icon,StringItem,ui->panel_right);
	    qlwi->setData(32,item->getStandardURL());
	};
	break;
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

void MainWindow::on_panel_left_itemActivated(QListWidgetItem* item)
{
    QVariant stuff;
    stuff = item->data(32);
    emit itemActivated(stuff.toString(),0);
}
void MainWindow::on_panel_right_itemActivated(QListWidgetItem* item){
    QVariant stuff;
    stuff = item->data(32);
    emit itemActivated(stuff.toString(),1);
}
void MainWindow::setDrive(QString drive,QIcon icon){

    nav_left->add_drive_button("left://"+drive,icon);
    nav_right->add_drive_button("right://"+drive,icon);
}
void MainWindow::driveButtonClicked(){
    QString button_name = QObject::sender()->objectName();
    QStringList but = button_name.split("://");
    if (but[0] == "left") {
        emit itemActivated("file://"+but[1],0);
    } else {
        emit itemActivated("file://"+but[1],1);
    };
}
void MainWindow::addItemToAddressbar(QString url, int panel){
    if(panel == 0){
        this->nav_left->addAddressBarItem(url);
    } else {
        this->nav_right->addAddressBarItem(url);
    }
}
void MainWindow::left_addressbarItemChanged(QString url){ emit itemActivated(url,0); }
void MainWindow::right_addressbarItemChanged(QString url) { emit itemActivated(url,1); }
void MainWindow::left_previousAddressRequested(){ nav_left->setPreviousAddress(); }
void MainWindow::right_previousAddressRequested(){ nav_right->setPreviousAddress(); }
void MainWindow::left_goButtonClicked(){ emit itemActivated(nav_left->addressBar->currentText(),0); }
void MainWindow::right_goButtonClicked(){ emit itemActivated(nav_right->addressBar->currentText(),1); }

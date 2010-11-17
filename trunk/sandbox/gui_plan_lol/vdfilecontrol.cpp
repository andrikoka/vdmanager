#include "vdfilecontrol.h"
#include <QDir> // kezdeteknél kell
#include <vdlocalfile.h>
#include <qdebug.h>
VDFileControl::VDFileControl(MainWindow * GUI,QObject *parent) :
    QObject(parent)
{
    QDir dir;
    dispatcher = new VDDispatcher(this);
    this->mw = GUI;
    // elso elem letrehozasa, kesobb settings alapjan lehet a last used dir es egyeb
    // panel 0
    this->item = new VDFileItem(dir.homePath());
    this->list << this->item;
    this->lists << this->list;
    this->lists[0][0]->setItemIndex(0,0);
    // panel 1
    this->item = new VDFileItem(dir.homePath());
    this->list.clear();
    this->list << this->item;
    this->lists << this->list;
    this->lists[1][0]->setItemIndex(1,0);

    // panel 0
    this->localItem = new VDLocalFile(lists[0][0]->getFileName(),lists[0][0]);
    connect(this->lists[0][0],SIGNAL(readyToDisplay(VDFileItem*)),
    this,SLOT(VDRootItemIsReady(VDFileItem*)));

    connect(this->lists[1][0],SIGNAL(readyToDisplay(VDFileItem*)),
    this,SLOT(VDRootItemIsReady(VDFileItem*)));

    // kapcsolas utan toltjuk fel a dolgokat
    this->localItem->fillVDItem();
    //majd a masik panelt is beroffentjuk
    this->localItem = new VDLocalFile(lists[1][0]->getFileName(),lists[1][0]);
    this->localItem->fillVDItem();
    // panel 1

}

void VDFileControl::VDRootItemIsReady(VDFileItem * rootItem){
    QStringList entrylist;
    QString root;
    this->localItem = new VDLocalFile(rootItem->getFullPath() +"/"+ rootItem->getFileName(),rootItem);

    // fajlnevekkel ter vissza, rootitem/ nélkül, csak [filenev]!
    // ha csinalni akarunk ra egy vdfileitem-et, akkor tudnunk kell a root-nak
    // az eleresi utjat, amit megkaphatjuk tole

    entrylist = this->localItem->getContentList();
    root = this->localItem->getFullPath();

    // itt mar nem kapcsoljuk ossze a rootitemet es a kesz szignalt, kulonben kapunk egy
    // vegtelen ciklust. Amúgy is a controlnak a GUI fele kell az infókat szolgáltatni,
    // így oda kell továbbítani a kész elemeket.
    for (unsigned short int i=0;i< entrylist.count();i++){
	qint64 rootIndex = rootItem->getPanelIndex();
	// hozzaadjuk az uj elemet
	this->lists[rootIndex] << new VDFileItem(root +"/"+ entrylist[i]);
	this->lists[rootIndex][i+1]->setItemIndex(rootIndex,i+1);
	this->localItem = new VDLocalFile(lists[rootIndex][i+1]->getFileName(),this->lists[rootIndex][i+1]);

	connect(this->lists[rootIndex][i+1],SIGNAL(readyToDisplay(VDFileItem*)),this->mw,SLOT(itemIsReadyToDisplay(VDFileItem*)));

	this->localItem->fillVDItem();
    }
}

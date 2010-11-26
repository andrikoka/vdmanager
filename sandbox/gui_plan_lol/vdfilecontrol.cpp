#include "vdfilecontrol.h"
#include <QDir> // kezdeteknél kell
#include <QTime>
#include <vdlocalfile.h>
#include <qdebug.h>
VDFileControl::VDFileControl(MainWindow * GUI,QObject *parent) :
    QObject(parent)
{
    this->t.start();
    QDir dir;
    dispatcher = new VDDispatcher(this);
    this->mw = GUI;
    connect(dispatcher,SIGNAL(ExecutionRequest(QString,int)),this,SLOT(ExecutionRequest(QString,int)));
    connect(mw,SIGNAL(itemDoubleClicked(QString,int)),dispatcher,SLOT(PanelItemDoubleClicked(QString,int)));
    for (unsigned int i=0;i<2;i++){
	/* magyarazat:
	1: panelok feltoltese (i most konstans, de a megnyitott panelok szamanak megfelelo is lehet)
	2: elso elem letrehozasa, kesobb settings alapjan lehet a last used dir es egyeb
	3: vdfileitem pointereket beallitjuk majd megcsinaljuk a handler-t hozza
	4: bedrotozzuk a megfelelo helyre
	5: majd azt mondjuk neki, hogy toltikezhet
*/
	this->item = new VDFileItem(dir.homePath());
	this->panelRootList << this->item;
	this->panelRootList[i]->setItemIndex(i,0);
	this->localItem = new VDLocalFile(this->panelRootList[i]->getFileName(),
					  this->panelRootList[i]);
	this->handlerRootList << this->localItem;
	connect(this->panelRootList[i],SIGNAL(readyToDisplay(VDFileItem*)),
		this,SLOT(VDRootItemIsReady(VDFileItem*)));
	this->handlerRootList[i]->fillVDItem();
    }

    qDebug("Constructor end: Time elapsed: %d ms", t.elapsed());
}

void VDFileControl::VDRootItemIsReady(VDFileItem * rootItem){
    unsigned int panelindex = rootItem->getPanelIndex();
    this->mw->clearPanel(panelindex);
    qDebug("RootItemReady: Time elapsed: %d ms, generateList called", t.restart());
    this->handlerRootList[panelindex]->generateList(QString(),this->mw,panelindex);
    qDebug("RootItemReadyEnd: Time elapsed: %d ms, generateList finished", t.elapsed());
}
void VDFileControl::ExecutionRequest(QString url, int panel){
    qDebug("Exec: Start: %d ms", t.restart());
    // VDExecute kellene ide, ami ezt megcsinalja
    QStringList parts,pieces;
    qDebug() << "Control: ExecutionRequest" << url << panel;

    parts = url.split("://");
    pieces = parts[1].split("/");
    if (pieces.last() == ".."){
    qDebug() << "Command: .. (cdUp)";
    this->handlerRootList[panel]->cdUp();
    this->handlerRootList[panel]->fillVDItem();
    } else {
	this->item = new VDFileItem(parts[1]);
	this->localItem = new VDLocalFile(this->item->getFileName(),this->item);
	this->localItem->fillVDItem();
	if(this->item->isDir()) {
		this->handlerRootList[panel]->cd(pieces.last());
		this->handlerRootList[panel]->fillVDItem();
	    } else {
	qDebug() << "File execution request:" << this->item->getFullPath() << this->item->getFileName() << "isDir:" << this->item->isDir();
	}
    }


    qDebug("Exec: FillVDItem finished: %d ms", t.restart());
}

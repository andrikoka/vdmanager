#include "vdfilecontrol.h"
#include <QDir> // kezdeteknél kell
#include <vdlocalfile.h>
VDFileControl::VDFileControl(MainWindow * GUI,QObject *parent) :
    QObject(parent)
{
    QDir dir;
    dispatcher = new VDDispatcher(this);
    this->mw = GUI;

    // elso elem letrehozasa, kesobb settings alapjan lehet a last used dir es egyeb
    this->item = new VDFileItem(dir.homePath());
    this->list << this->item;
    this->lists << this->list;

    connect(this->lists[0][0],SIGNAL(readyToDisplay(VDFileItem*)),
    mw,
    SLOT(itemIsReadyToDisplay(VDFileItem*)));

    this->realHandlerList << new VDLocalFile(lists[0][0]->getFileName(),lists[0][0]);

}

void VDFileControl::VDFileItemIsReadyToDisplay(VDFileItem * item){

}

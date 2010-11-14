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
    this->VDFileItemList << new VDFileItem(dir.homePath());

    connect(this->VDFileItemList[0],SIGNAL(readyToDisplay(VDFileItem*)),
    mw,
    SLOT(itemIsReadyToDisplay(VDFileItem*)));

    this->realHandlerList << new VDLocalFile(VDFileItemList[0]->getFileName(),VDFileItemList[0]);

}

void VDFileControl::VDFileItemIsReadyToDisplay(VDFileItem * item){

}

#include "vddispatcher.h"
#include <qdebug.h>
VDDispatcher::VDDispatcher(QObject *parent) :
    QObject(parent)
{

}

void VDDispatcher::VDFileItemReadyToDisplay(VDFileItem *item){
    qDebug() << "ReadyToDisplay: " << item;

}

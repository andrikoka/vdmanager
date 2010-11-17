#include "vddispatcher.h"
#include <qdebug.h>
VDDispatcher::VDDispatcher(QObject *parent) :
    QObject(parent)
{
 /* ide jon majd a settings osztaly peldanya, amely alapjan a vdcontrol es a gui funkcioit
    osszekapcsoljuk. (billentyuparancs es egyeb marhasagok pld.
    Scriptelesnel ez az osztaly jo lehet event-kezelesre is.
    */
}

void VDDispatcher::VDFileItemReadyToDisplay(VDFileItem *item){
    qDebug() << "ReadyToDisplay: " << item;
}
void VDDispatcher::PanelItemDoubleClicked(QListWidgetItem *item){

}

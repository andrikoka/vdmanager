#include "vddispatcher.h"
#include <qdebug.h>
VDDispatcher::VDDispatcher(QObject *parent) : QObject(parent)
{
 /* ide jon majd a settings osztaly peldanya, amely alapjan a vdcontrol es a gui funkcioit
    osszekapcsoljuk. (billentyuparancs es egyeb marhasagok pld.
    Scriptelesnel ez az osztaly jo lehet event-kezelesre is.
    */
    //this->setParent(parent);
    //TODO: megtalálni miért nem a VDFileControl ennek a faterja.
}

void VDDispatcher::VDFileItemReadyToDisplay(VDFileItem *item){
    qDebug() << "ReadyToDisplay: " << item;
}
void VDDispatcher::PanelItemDoubleClicked(QString standardUrl,int panel){
    // ide kerülhet a duplaklikk kiertekelesere keszulo kod
    emit ExecutionRequest(standardUrl,panel);

}

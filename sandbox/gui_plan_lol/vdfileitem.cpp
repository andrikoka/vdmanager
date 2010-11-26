#include "vdfileitem.h"
#include <QString>
#include <QIcon>
#include <vddispatcher.h>
#include <QDebug>

VDFileItem::VDFileItem(QString filename,QObject *parent) :
    QObject(parent)
{
    this->fileName = filename;
}

// setter rész
void VDFileItem::setSize(qint64 Size){
    this->size = Size; emit sizeChanged(this->size);
    this->newPropertySet("size");
}
void VDFileItem::setFileName(QString filename){
    this->fileName = filename; emit fileNameChanged(this->fileName);
    this->newPropertySet("fileName");
}
void VDFileItem::setDirFlag(bool isDir){
    this->dir = isDir; emit dirFlagChanged(this->dir);
    this->newPropertySet("dir");
}
void VDFileItem::setIcon(QIcon icon) {
    this->icon = icon; emit iconChanged(this->icon);
    this->newPropertySet("icon");
}
void VDFileItem::setCreateDate(QDateTime cDate){
    this->createDate = cDate; emit createDateChanged(this->createDate);
    this->newPropertySet("createDate");
}
void VDFileItem::setModDate(QDateTime mDate) {
    this->modDate = mDate; emit modDateChanged(this->modDate);
    this->newPropertySet("modDate");
}
void VDFileItem::setStandardURL(QString newurl){
    this->standardURL = newurl; emit standardURLChanged(this->standardURL);
    this->newPropertySet("standardURL");
}

void VDFileItem::setFullPath(QString path){
    this->fullPath=path; emit fullPathChanged(this);
    this->newPropertySet("fullPath");
}

void VDFileItem::newPropertySet(QString property){
    this->properties.removeOne(property);
    //if (this->properties.count() == 0) { emit readyToDisplay(this); }
    //qDebug() << this->properties;
}
void VDFileItem::setNecessaryProperties(QStringList props){
    this->properties = props;
}
void VDFileItem::setItemIndex(qint64 panel, qint64 element){
    this->panel = panel; this->element = this->element;
}
void VDFileItem::setPropertyList(qint64 size, QDateTime createdate, QDateTime moddate, bool isdir, QString stdurl, QString path)
{
    this->size = size;
    this->createDate = createdate;
    this->modDate = moddate;
    this->dir = isdir;
    this->standardURL = stdurl;
    this->fullPath = path;
}


// getter rész
qint64 VDFileItem::getSize(){return this->size;};
QDateTime VDFileItem::getCreateDate(){ return this->createDate; };
QDateTime VDFileItem::getModDate(){ return this->modDate; };

QString VDFileItem::getFileName() { return this->fileName; };
QIcon VDFileItem::getIcon() { return this->icon; };
bool VDFileItem::isDir() { return this->dir; };
bool VDFileItem::isRoot() {return this->root; };
QString VDFileItem::getStandardURL() { return this->standardURL; }
qint64 VDFileItem::getPanelIndex(){ return this->panel; };

qint64 VDFileItem::getElementIndex() { return this->element; }
QString VDFileItem::getProtocol(){
    return this->standardURL.split("://")[0];
}
QString VDFileItem::getFullPath(){
    return this->fullPath;
}

void VDFileItem::finishedUpdate(){
    emit readyToDisplay(this);
}
void VDFileItem::setRootFlag(bool root){ this->root = root; emit rootFlagChanged(this->root); }

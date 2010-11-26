#include "vdlocalfile.h"
#include <QFileIconProvider>
#include <QDebug>
VDLocalFile::VDLocalFile(QString filename, VDFileItem * vdfitem)
{
    this->filename = filename;
    this->file = new QFile(filename);
    this->vditem = vdfitem;
    this->fileinfo = QFileInfo(filename);
    this->dir = new QDir(this->filename);
    //qDebug() << "Constr. file. ex.:" << this->dir->exists() << "filename:" << filename;
}
void VDLocalFile::fillVDItem(){
    QStringList props;
    QFileIconProvider qfip;

    this->vditem->setFileName(this->fileinfo.fileName());

    this->vditem->setPropertyList(this->fileinfo.size(),this->fileinfo.created(),this->fileinfo.lastModified(),this->fileinfo.isDir(),"local://"+this->fileinfo.path() +"/"+ this->fileinfo.fileName(),this->fileinfo.path());
    this->vditem->setIcon(qfip.icon(fileinfo)); // na erre kíváncsi leszek
    //qDebug() << this->filename << "finished update";
    this->vditem->finishedUpdate();
}

QStringList VDLocalFile::getContentList(){
    //qDebug() << "contentlist req for" << this->fileinfo.fileName();
    if (this->fileinfo.isDir()){
	//qDebug() << "EntryList:" << this->dir->entryList(QDir::NoFilter , QDir::DirsFirst);
	return this->dir->entryList(QDir::AllEntries | QDir::NoDot,QDir::DirsFirst);
    }
    else return QStringList();
}
QList<QFileInfo> VDLocalFile::getContentInfoList(){
	    return this->dir->entryInfoList(QDir::NoDot,QDir::DirsFirst);
	}


QString VDLocalFile::getFullPath(){
    return this->fileinfo.absolutePath(); // ezt lehetne szedni a standardurlbol is
}

void VDLocalFile::generateList(QString properties,MainWindow *mw,int panel){
    QFileInfoList qfilist = this->dir->entryInfoList(
		QDir::AllEntries |QDir::NoDot,QDir::DirsFirst
		);
    //QFileIconProvider qfip;
    unsigned int count = qfilist.count();
    for (unsigned int i=0;i<count;i++){
    VDFileItem item(qfilist[i].fileName());
    item.setPropertyList(qfilist[i].size(),
				qfilist[i].created(),
				qfilist[i].lastModified(),
				qfilist[i].isDir(),
				"local://"+qfilist[i].path() +"/"+ qfilist[i].fileName(),
				qfilist[i].path());
    //item.setIcon(qfip.icon(fileinfo));
    item.setItemIndex(panel,0);
    mw->itemIsReadyToDisplay(&item);
    }
}
void VDLocalFile::changePath(QString newPath){
    this->dir->setPath(newPath);
    this->filename = dir->path();
    this->file = new QFile(this->filename);
    this->fileinfo = QFileInfo(this->filename);
}
void VDLocalFile::cdUp(){
    this->dir->cdUp();
    this->changePath(this->dir->path());
}

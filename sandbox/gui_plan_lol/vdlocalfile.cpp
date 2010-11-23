#include "vdlocalfile.h"
#include <QFileIconProvider>
#include <QDebug>
VDLocalFile::VDLocalFile(QString filename, VDFileItem * vdfitem)
{
    this->filename = filename;
    this->file = new QFile(filename);
    this->file->open(QFile::ReadOnly | QIODevice::Text);
    this->vditem = vdfitem;
    this->fileinfo = QFileInfo(filename);
    //qDebug() << "Constr. file. ex.:" << this->file->exists() << "filename:" << filename;
    this->dir = new QDir(this->filename);
}
void VDLocalFile::fillVDItem(){
    QStringList props;
    // a VDFileItem ez alapján tudja mikor lesz "kész", adatai megjeleníthetõek
    props << "size"
	    << "dir"
	    //<< "icon"
	    << "createDate" << "modDate"
	    << "fullPath"
	    << "standardURL";
    this->vditem->setNecessaryProperties(props);
    this->vditem->setFileName(this->fileinfo.fileName());
    QFileIconProvider qfip;
    if (this->fileinfo.isDir()){
	this->vditem->setDirFlag(true);
    } else {
	this->vditem->setDirFlag(false);
    }

    this->vditem->setSize(this->fileinfo.size());
    this->vditem->setModDate(this->fileinfo.lastModified());
    this->vditem->setCreateDate(this->fileinfo.created());
    this->vditem->setFullPath(this->getFullPath());
    this->vditem->setIcon(qfip.icon(fileinfo)); // na erre kíváncsi leszek
    this->vditem->setStandardURL("local://"+this->fileinfo.path() +"/"+ this->fileinfo.fileName());
}

QStringList VDLocalFile::getContentList(){
    //qDebug() << "contentlist req for" << this->fileinfo.fileName();
    if (this->fileinfo.isDir()){
	//qDebug() << "entrylist prepare";
	return this->dir->entryList(QDir::AllEntries,QDir::DirsFirst);
    }
    else return QStringList();
}

QString VDLocalFile::getFullPath(){
    return this->fileinfo.absolutePath(); // ezt lehetne szedni a standardurlbol is
}

#include "vdlocalfile.h"
#include <QFileIconProvider>

VDLocalFile::VDLocalFile(QString filename, VDFileItem * vdfitem,QObject * parent) :
	QObject(parent)
{
    this->filename = filename;
    QStringList props;
    // a VDFileItem ez alapj�n tudja mikor lesz "k�sz", adatai megjelen�thet�ek
    props << "size"
	    << "dir"
	    //<< "icon"
	    << "createDate" << "modDate"
	    << "standardURL";
    vdfitem->setNecessaryProperties(props);
    QFileIconProvider qfip;
    this->fileinfo = new QFileInfo(filename);

    if (this->fileinfo->isDir()){
	vdfitem->setDirFlag(true);
	vdfitem->setSize(this->fileinfo->size());
    } else {
	vdfitem->setDirFlag(false);
	vdfitem->setSize(this->fileinfo->size());
    }
    vdfitem->setModDate(this->fileinfo->lastModified());
    vdfitem->setCreateDate(this->fileinfo->created());
    //vdfitem->setIcon(qfip.icon(fileinfo)); // na erre k�v�ncsi leszek
    vdfitem->setStandardURL("local://"+this->fileinfo->path() + this->fileinfo->fileName());
}

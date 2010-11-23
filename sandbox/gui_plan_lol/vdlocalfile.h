#ifndef VDLOCALFILE_H
#define VDLOCALFILE_H

#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <vdabstractfile.h>
#include <vdfileitem.h>
class VDLocalFile : public VDAbstractFile
{
    Q_OBJECT
    Q_INTERFACES(VDAbstractFile);
public:
    VDLocalFile(QString filename,VDFileItem * vdfitem);
    QStringList getContentList();
    void fillVDItem();
    QString getFullPath();
signals:

public slots:

private:
    QString filename;
    QFile * file;
    QFileInfo fileinfo;
    QDir * dir;
    VDFileItem * vditem;
};

#endif // VDLOCALFILE_H

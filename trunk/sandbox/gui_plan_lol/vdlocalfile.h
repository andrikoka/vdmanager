#ifndef VDLOCALFILE_H
#define VDLOCALFILE_H

#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <vdfileitem.h>
class VDLocalFile : public QObject
{
    Q_OBJECT
public:
    explicit VDLocalFile(QString filename,VDFileItem * vdfitem,QObject *parent = 0);
    QStringList getContentList();
    void fillVDItem();
    QString getFullPath();
signals:

public slots:

private:
    QString filename;
    QFile *file;
    QFileInfo *fileinfo;
    QDir * dir;
    VDFileItem * vditem;
};

#endif // VDLOCALFILE_H

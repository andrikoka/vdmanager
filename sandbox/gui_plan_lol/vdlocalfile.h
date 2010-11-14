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
signals:

public slots:

private:
    QFile *file;
    QFileInfo *fileinfo;
    QDir * dir;
};

#endif // VDLOCALFILE_H

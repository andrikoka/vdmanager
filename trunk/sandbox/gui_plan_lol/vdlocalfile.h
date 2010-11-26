#ifndef VDLOCALFILE_H
#define VDLOCALFILE_H

#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <vdabstractfile.h>
#include <vdfileitem.h>
#include <mainwindow.h>
class VDLocalFile : public VDAbstractFile
{
    Q_OBJECT
    Q_INTERFACES(VDAbstractFile);
public:
    VDLocalFile(QString filename,VDFileItem * vdfitem);
    QStringList getContentList();
    QList<QFileInfo> getContentInfoList();
    void fillVDItem();
    QString getFullPath();
    void generateList(QString properties,MainWindow *mw,int panel);
    void changePath(QString newPath);
    void cdUp();
    void cd(QString newDir);
signals:

public slots:

private:
    QString filename;
    QFile * file;
    QFileInfo fileinfo;
    QDir * dir;
    VDFileItem * vditem;
    QString getStandardUrl(QString="");
};

#endif // VDLOCALFILE_H

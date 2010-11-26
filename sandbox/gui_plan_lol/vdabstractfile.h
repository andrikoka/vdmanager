#ifndef VDABSTRACTFILE_H
#define VDABSTRACTFILE_H

#include <QObject>
#include <vdfileitem.h>
#include <mainwindow.h>

class VDAbstractFile : public QObject
{
    Q_OBJECT
public:
    VDAbstractFile();
    virtual QStringList getContentList() = 0;
    // returns with the list of the file, if that is a dir
    virtual void fillVDItem() = 0;
    // fills the vditem with proper data and triggers the ready signal
    virtual QString getFullPath() =0;
    // returnsh with the path
    virtual void generateList(QString,MainWindow*,int) =0;
    // fills the panel with vdfileitems according to the properties
    virtual void changePath(QString)=0;
    virtual void cdUp()=0;
    virtual void cd(QString)=0;
signals:

public slots:

};
Q_DECLARE_INTERFACE(VDAbstractFile,"VDManager.VDABstractFile/0.1")
#endif // VDABSTRACTFILE_H

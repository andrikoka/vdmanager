#ifndef VDFILECONTROL_H
#define VDFILECONTROL_H

#include <QObject>
#include <vdfileitem.h>
#include <vddispatcher.h>
#include <mainwindow.h>
#include <vdlocalfile.h>
class VDFileControl : public QObject
{
    Q_OBJECT
public:
    explicit VDFileControl(MainWindow * mw, QObject *parent = 0);
    void setMainWindow (MainWindow * mw) { this->mw = mw; }

private:
    QList<QList <VDFileItem* > > lists;
    VDFileItem *item;
    QList<VDFileItem*> list;
    // real handler peldanyok
    VDAbstractFile *localItem;

    VDDispatcher * dispatcher;
    MainWindow * mw;
public slots:
    void VDRootItemIsReady(VDFileItem * );
};

#endif // VDFILECONTROL_H

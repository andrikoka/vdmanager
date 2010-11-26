#ifndef VDFILECONTROL_H
#define VDFILECONTROL_H

#include <QObject>
#include <vdfileitem.h>
#include <vddispatcher.h>
#include <mainwindow.h>
#include <vdlocalfile.h>
#include <QTime>
class VDFileControl : public QObject
{
    Q_OBJECT
public:
    explicit VDFileControl(MainWindow * mw, QObject *parent = 0);
    void setMainWindow (MainWindow * mw) { this->mw = mw; }

private:
    VDFileItem *item;
    QList<VDFileItem*> panelRootList;
    // real handler peldanyok
    VDAbstractFile *localItem;
    QList<VDAbstractFile*> handlerRootList;

    VDDispatcher * dispatcher;
    MainWindow * mw;
    QTime t;
public slots:
    void VDRootItemIsReady(VDFileItem *);
    void ExecutionRequest(QString,int);
};

#endif // VDFILECONTROL_H

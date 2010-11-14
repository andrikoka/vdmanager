#ifndef VDFILECONTROL_H
#define VDFILECONTROL_H

#include <QObject>
#include <vdfileitem.h>
#include <vddispatcher.h>
#include <mainwindow.h>

class VDFileControl : public QObject
{
    Q_OBJECT
public:
    explicit VDFileControl(MainWindow * mw, QObject *parent = 0);
    void setMainWindow (MainWindow * mw) { this->mw = mw; }

private:
    QList<VDFileItem *> VDFileItemList;
    VDFileItem *item;
    QList<QObject *> itemOwner; // aki létrehozta az elemet
    QList<QObject *> realHandlerList; // QFTP, QFile, bármi
    VDDispatcher * dispatcher;
    MainWindow * mw;
public slots:
    void VDFileItemIsReadyToDisplay(VDFileItem * );
};

#endif // VDFILECONTROL_H

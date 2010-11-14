#ifndef VDFILEITEMLIST_H
#define VDFILEITEMLIST_H

#include <QObject>
#include <vdfileitem.h>
class VDFileItemList : public QObject
{
    Q_OBJECT
public:
    explicit VDFileItemList(QObject *parent = 0);
    QList<VDFileItem*> list;
signals:

public slots:

};

#endif // VDFILEITEMLIST_H

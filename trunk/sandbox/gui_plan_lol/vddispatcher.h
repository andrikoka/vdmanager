#ifndef VDDISPATCHER_H
#define VDDISPATCHER_H

#include <QObject>
#include <vdfileitem.h>
#include <qlistwidget.h>

class VDDispatcher : public QObject
{
    Q_OBJECT
public:
    explicit VDDispatcher(QObject *parent = 0);

signals:

public slots:
    void VDFileItemReadyToDisplay(VDFileItem * item);
    void PanelItemDoubleClicked(QListWidgetItem *item);
};

#endif // VDDISPATCHER_H

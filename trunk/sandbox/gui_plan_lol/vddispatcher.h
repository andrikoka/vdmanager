#ifndef VDDISPATCHER_H
#define VDDISPATCHER_H

#include <QObject>
#include <vdfileitem.h>


class VDDispatcher : public QObject
{
    Q_OBJECT
public:
    explicit VDDispatcher(QObject *parent);

signals:
    void ExecutionRequest(QString,int);
public slots:
    void VDFileItemReadyToDisplay(VDFileItem * item);
    void PanelItemDoubleClicked(QString,int);
};

#endif // VDDISPATCHER_H

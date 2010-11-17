#ifndef VDFILEITEM_H
#define VDFILEITEM_H

#include <QObject>
#include <QDateTime>
#include <QIcon>

class VDFileItem : public QObject
{
    Q_OBJECT
public:
    explicit VDFileItem(QString filename,QObject *parent=0);

    void setSize(qint64);
    void setCreateDate(QDateTime);
    void setModDate(QDateTime);
    void setFileName(QString);
    void setIcon(QIcon);
    void setDirFlag(bool);
    void setStandardURL(QString);
    void setNecessaryProperties(QStringList);
    void setItemIndex(qint64,qint64);
    void setFullPath(QString);

    qint64 getSize();
    QDateTime getCreateDate();
    QDateTime getModDate();
    QString getFileName();
    QIcon getIcon();
    bool isDir();
    QString getStandardURL();
    qint64 getPanelIndex();
    qint64 getElementIndex();
    QString getProtocol();
    QString getFullPath();


private:
    qint64 size;
    QDateTime createDate,modDate;
    QString fileName;
    QString standardURL;
    QIcon icon;
    bool dir;
    QStringList properties;
    qint64 panel,element;
    QString fullPath;
	void newPropertySet(QString);
signals:
    void sizeChanged(qint64);
    void createDateChanged(QDateTime);
    void modDateChanged(QDateTime);
    void fileNameChanged(QString);
    void dirFlagChanged(bool);
    void iconChanged(QIcon);
    void standardURLChanged(QString);
    void readyToDisplay(VDFileItem *);
    void fullPathChanged(VDFileItem *);
public slots:

};

#endif // VDFILEITEM_H

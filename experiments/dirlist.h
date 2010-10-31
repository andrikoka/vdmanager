#ifndef DIRLIST_H
#define DIRLIST_H
#include  <QStringList>
#include <QDir>
class dirlist
{
public:
    QDir dir;
    dirlist();
    QStringList listCurrent();
};

#endif // DIRLIST_H

#include "dirlist.h"
#include <QDir>



dirlist::dirlist()
{
    this->dir.setPath(QDir::currentPath());
}

QStringList dirlist::listCurrent() {
    return dir.entryList();
}

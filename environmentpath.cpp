#include "environmentpath.h"

EnvironmentPath::EnvironmentPath(QObject *parent) :
    QObject(parent)
{
    // nothing to do
}

void EnvironmentPath::updatePath(QString sPath)
{
    // TODO : update path
    path = sPath;
    qDebug() << path;
}

void EnvironmentPath::updatePathFile(QString sPathFile)
{
    pathFile = sPathFile;
    pathFile = pathFile.replace(path, "/vagrant");
    qDebug() << pathFile;
}

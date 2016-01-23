#include "environmentpath.h"

EnvironmentPath::EnvironmentPath(QObject *parent) :
    QObject(parent)
{
    // nothing to do
}

EnvironmentPath::~EnvironmentPath()
{

}

void EnvironmentPath::updatePath(QString sPath)
{
    path = sPath;
}

void EnvironmentPath::updatePathFile(QString sPathFile)
{
    pathFile = sPathFile;
    pathFile = pathFile.replace(path, "/vagrant");
}

#ifndef ENVIRONMENTPATH_H
#define ENVIRONMENTPATH_H

#include <QString>
#include <QFile>
#include <QProcess>
#include <QDebug>
#include <QString>
#include <QObject>
#include <QStringList>
#include <QElapsedTimer>
#include <QEventLoop>
#include <QThread>

class EnvironmentPath : public QObject
{
    public:
        EnvironmentPath(QObject *parent = 0);
        ~EnvironmentPath();
        void updatePath(QString);
        void updatePathFile(QString);

    protected:
        QString path;    // path of the environment
        QString pathFile; // option of the system call
        QElapsedTimer timer;
};

#endif // ENVIRONMENTPATH_H

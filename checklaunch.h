#ifndef CHECKLAUNCH_H
#define CHECKLAUNCH_H

#include <QObject>
#include <QFileInfo>
#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QStringList>

class CheckLaunch : public QObject
{
        Q_OBJECT
    public:
        CheckLaunch(QObject *parent = 0);
        ~CheckLaunch();
        bool isLaunch();

    private:
        QProcess *check;
        QString progName;
        bool result;
    private slots:
        void readStdOutput();
};

#endif // CHECKLAUNCH_H

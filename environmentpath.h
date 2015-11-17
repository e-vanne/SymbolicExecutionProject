#ifndef ENVIRONMENTPATH_H
#define ENVIRONMENTPATH_H

#include <QString>
#include <QFile>
#include <QProcess>

class EnvironmentPath
{
    public:
        EnvironmentPath();

    private:
        QFile *path;    // path of the environment
        QString option; // option of the system call
        QProcess *process;  // system call

    public slots:
        void updatePath(QString);
        void updateOption(QString);
        void execute();
};

#endif // ENVIRONMENTPATH_H

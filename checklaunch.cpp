#include "checklaunch.h"

CheckLaunch::CheckLaunch(QObject *parent) : QObject(parent)
{
    progName = QFileInfo( QCoreApplication::applicationFilePath() ).fileName();
    result = false;
}

CheckLaunch::~CheckLaunch()
{
    delete check;
}

bool CheckLaunch::isLaunch()
{
    check = new QProcess();
    check->setProcessChannelMode(QProcess::MergedChannels);
    connect(check, SIGNAL(readyReadStandardOutput()), this, SLOT(readStdOutput()));

    check->start("sh -c ps -e");
    check->waitForStarted();

    check->waitForFinished();

    return result;
}

void CheckLaunch::readStdOutput()
{
    QByteArray bytes = check->readAllStandardOutput();
    QStringList lines = QString(bytes).split("\n");

    qint32 numberOfInstance = 0;
    foreach (QString line, lines)
    {
        if (line.contains(progName))
        {
            numberOfInstance++;
            if (numberOfInstance >= 2)
            {
                result = true;
                break;
            }
        }
    }
    check->kill();
}

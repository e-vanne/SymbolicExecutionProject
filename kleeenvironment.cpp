#include "kleeenvironment.h"

KleeEnvironment::KleeEnvironment() : EnvironmentPath()
{
    flagRes = false;
    display = "";
    process = new QProcess();
    process->setProcessChannelMode(QProcess::MergedChannels);
}

KleeEnvironment::~KleeEnvironment()
{

}

void KleeEnvironment::execute()
{
    connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(readOutputProcess()));
    process->setWorkingDirectory(path);
    process->start("vagrant up");
    process->waitForFinished();
    process->start("vagrant ssh");
    process->waitForStarted();
    process->write(tr("cd %1\n").arg(pathFile).toUtf8());

    QEventLoop *qel = new QEventLoop();
    connect(this, SIGNAL(endMake()), qel, SLOT(quit()));
    timer.restart();
    process->write("make\n");
    qel->exec();
    qint64 timeElapse = timer.elapsed();
    emit updateExecTime(tr("%1").arg(timeElapse));
    process->write("./show_paths.sh\n");
    process->waitForBytesWritten();

    emit updateDisplay(display);
}

void KleeEnvironment::readOutputProcess()
{
    QByteArray bytes = process->readAllStandardOutput();
    QStringList lines = QString(bytes).split("\n");

    foreach (QString line, lines) {
        if (!flagRes && line.contains("# Link"))
            flagRes = true;
        qDebug() << line;
        if (line.contains("KLEE: done"))
        {
            if(line.contains("instructions")) {
                QStringList nbr = line.split("= ");
                emit updateNbrInstructions(nbr.at(nbr.length()-1));
            }
            else if (line.contains("completed"))
            {
                QStringList nbr = line.split("= ");
                emit updateNbrCompleted(nbr.at(nbr.length()-1));
            }
            else if (line.contains("generated"))
            {
                QStringList nbr = line.split("= ");
                emit updateNbrGenerated(nbr.at(nbr.length()-1));
                emit endMake();
                display += "\n# -------------------------------------- #\n";
            }
        }
    }

    if (flagRes)
        display += QString(bytes);
}

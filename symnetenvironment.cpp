#include "symnetenvironment.h"

SymnetEnvironment::SymnetEnvironment() : EnvironmentPath()
{
    nbrOkPath = 0;
    process = new QProcess();
    process->setProcessChannelMode(QProcess::MergedChannels);

    connect(this, SIGNAL(endProcess()), this, SLOT(stopProcess()));

    qel = new QEventLoop();
    connect(process, SIGNAL(finished(int)), qel, SLOT(quit()));
}

SymnetEnvironment::~SymnetEnvironment()
{
    delete process;
    delete qel;
    delete pd;
}

void SymnetEnvironment::execute()
{
    pd = new ProcessDialog(3, "Symnet operations");
    connect(this, SIGNAL(updateProgress(QString)), pd, SLOT(updateProgress(QString)));
    connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(readOutputProcess()));
    process->setWorkingDirectory(path);
    emit updateProgress("Starting the analysis ...");
    //timer.restart();
    process->start("sbt click");
    qel->exec();
    //qint64 timeElapse = timer.elapsed();
    //emit updateExecTime(tr("%1").arg(timeElapse));
    emit updateDisplay("\n# -------------------------------------- #\n\n");
    emit updateProgress("Processing result ...");
    process->start("cat template.output\n");
    qel->exec();
    emit processingEnd();
    emit endProcess();
}

void SymnetEnvironment::readOutputProcess()
{
    QByteArray bytes = process->readAllStandardOutput();
    QStringList lines = QString(bytes).split("\n");

    foreach (QString line, lines) {
        if (line.contains("Total time:"))
        {
            QStringList tmp = line.split(",");
            QStringList aux = tmp.at(0).split(": ");
            QStringList nbr = aux.at(aux.length()-1).split(" ");
            emit updateExecTime(QString::number(nbr.at(0).toInt()*1000));
        }
        if (line.contains("Ok states"))
        {
            QStringList tmp = line.split("(");
            QStringList nbr = tmp.at(tmp.length()-1).split(")");
            nbrOkPath += nbr.at(0).toInt();
        }
        else if (line.contains("Stuck states"))
        {
            QStringList tmp = line.split("(");
            QStringList nbr = tmp.at(tmp.length()-1).split(")");
            nbrOkPath += nbr.at(0).toInt();
        }
        else if (line.contains("Failed states"))
        {
            QStringList tmp = line.split("(");
            QStringList nbr = tmp.at(tmp.length()-1).split(")");
            emit updateNbrGenerated(QString::number(nbrOkPath + nbr.at(0).toInt()));
            emit updateNbrCompleted(QString::number(nbrOkPath));
        }
    }
    emit updateDisplay(QString(bytes));
}

void SymnetEnvironment::stopProcess()
{
    process->kill();
}

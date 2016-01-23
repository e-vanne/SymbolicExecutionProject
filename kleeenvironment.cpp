#include "kleeenvironment.h"

KleeEnvironment::KleeEnvironment() : EnvironmentPath()
{
    flagRes = false;
    flagShowPath = false;
    nbrPath = 0;
    nbrMaxPath = 0;
    display = "";
    process = new QProcess();
    process->setProcessChannelMode(QProcess::MergedChannels);

    connect(this, SIGNAL(endProcess()), this, SLOT(stopProcess()));

    qel = new QEventLoop();
    connect(this, SIGNAL(endMake()), qel, SLOT(quit()));
    connect(process, SIGNAL(finished(int)), qel, SLOT(quit()));
}

KleeEnvironment::~KleeEnvironment()
{
    delete process;
    delete pd;
    delete qel;
}

void KleeEnvironment::execute()
{
    pd = new ProcessDialog(7, "Klee operations");
    connect(this, SIGNAL(updateProgress(QString)), pd, SLOT(updateProgress(QString)));
    connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(readOutputProcess()));

    process->setWorkingDirectory(path);
    emit updateProgress("Vagrant is starting ...");
    process->start("vagrant up");
    qel->exec();
    emit updateProgress("Connecting to the vagrant box ...");
    process->start("vagrant ssh");
    process->waitForStarted();
    emit updateProgress("Setting the working directory ...");
    process->write(tr("cd %1\n").arg(pathFile).toUtf8());


    emit updateProgress("Starting the analysis ...");
    timer.restart();
    process->write("make\n");
    qel->exec();
    qint64 timeElapse = timer.elapsed();
    emit updateExecTime(tr("%1").arg(timeElapse));
    emit updateProgress("Processing result ...");
    process->write("./show_paths.sh\n");
    process->waitForBytesWritten();
    qel->exec();
    emit processingEnd();
}

void KleeEnvironment::readOutputProcess()
{
    bool flagSep = false;
    QByteArray bytes = process->readAllStandardOutput();
    QStringList lines = QString(bytes).split("\n");

    foreach (QString line, lines) {
        if (!flagRes && line.contains("# Link"))
            flagRes = true;
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

                flagShowPath = true;
                nbrMaxPath = nbr.at(nbr.length()-1).toInt();
                flagSep = true;
                emit endMake();

            }
        }
        if (flagShowPath)
        {
            if (line.contains("ktest"))
                nbrPath ++;
            if (nbrPath == nbrMaxPath && line.compare("0") == 0)
                emit endProcess();
        }
    }



    if (flagRes)
        emit updateDisplay(QString(bytes));
    if (flagSep)
        emit updateDisplay("\n# -------------------------------------- #\n\n");
}

void KleeEnvironment::stopProcess()
{
    emit updateProgress("Stopping connection with the vagrant box ...");
    process->write("exit\n");
    process->waitForBytesWritten();
    emit updateProgress("Stopping the vagrant box  ...");
    process->write("vagrant halt\n");
    process->waitForBytesWritten();
    process->kill();
    process->waitForFinished();
}

#ifndef SYMNETENVIRONMENT_H
#define SYMNETENVIRONMENT_H


#include "environmentpath.h"
#include "processdialog.h"

class SymnetEnvironment : public EnvironmentPath
{
        Q_OBJECT
    public:
        SymnetEnvironment();
        ~SymnetEnvironment();

    private:
        QProcess *process;
        QEventLoop *qel;
        ProcessDialog *pd;
        int nbrOkPath;

    private slots:
        void readOutputProcess();
        void stopProcess();

    public slots:
        void execute();

    signals:
        void updateNbrInstructions(QString);
        void updateNbrCompleted(QString);
        void updateNbrGenerated(QString);
        void updateExecTime(QString);
        void updateProgress(QString);

        void updateDisplay(QString);
        void processingEnd();

        void endProcess();
};

#endif // SYMNETENVIRONMENT_H

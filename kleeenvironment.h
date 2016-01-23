#ifndef KLEEENVIRONMENT_H
#define KLEEENVIRONMENT_H

#include "environmentpath.h"
#include "processdialog.h"

class KleeEnvironment : public EnvironmentPath
{
        Q_OBJECT
    public:
        KleeEnvironment();
        ~KleeEnvironment();

    private:
        QProcess *process;
        bool flagRes;
        bool flagShowPath;
        int nbrPath;
        int nbrMaxPath;
        QString display;
        ProcessDialog *pd;
        QEventLoop *qel;

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

        void endMake();

        void endProcess();
};

#endif // KLEEENVIRONMENT_H

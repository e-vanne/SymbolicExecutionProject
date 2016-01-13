#ifndef KLEEENVIRONMENT_H
#define KLEEENVIRONMENT_H

#include "environmentpath.h"

class KleeEnvironment : public EnvironmentPath
{
        Q_OBJECT
    public:
        KleeEnvironment();
        ~KleeEnvironment();

    private:
        QProcess *process;
        bool flagRes;
        QString display;

    private slots:
        void readOutputProcess();

    public slots:
        void execute();

    signals:
        void updateNbrInstructions(QString);
        void updateNbrCompleted(QString);
        void updateNbrGenerated(QString);
        void updateExecTime(QString);

        void updateDisplay(QString);

        void endMake();
};

#endif // KLEEENVIRONMENT_H

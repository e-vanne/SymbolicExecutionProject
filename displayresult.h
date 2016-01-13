#ifndef DISPLAYRESULT_H
#define DISPLAYRESULT_H

#include <QString>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>

class DisplayResult : public QWidget
{
        Q_OBJECT
    public:
        DisplayResult(QWidget *parent = 0);
        ~DisplayResult();

    private:
        QLabel *LexecTime;
        QLabel *LgeneratedPath;
        QLabel *LpathCompleted;
        QLabel *LnumberInstruction;

        QLineEdit *EexecTime;
        QLineEdit *EgeneratedPath;
        QLineEdit *EpathCompleted;
        QLineEdit *EnumberInstruction;

        void create();
        void createL();
        void createE();
        void createLayout();

    public slots:
        void updateExecTime(QString);
        void updateNbrCompleted(QString);
        void updateNbrGenerated(QString);
        void updateNbrInstructions(QString);
};

#endif // DISPLAYRESULT_H

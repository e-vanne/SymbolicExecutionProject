#ifndef PROCESSDIALOG_H
#define PROCESSDIALOG_H

#include <QProgressDialog>
#include <QWidget>
#include <QThread>

class ProcessDialog : public QProgressDialog
{
        Q_OBJECT
    public:
        ProcessDialog(int maxRange, QString title, QWidget *parent = 0);

    private:
        int counter;

    public slots:
        void updateProgress(QString);
};

#endif // PROCESSDIALOG_H

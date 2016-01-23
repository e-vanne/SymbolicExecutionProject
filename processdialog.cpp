#include "processdialog.h"

ProcessDialog::ProcessDialog(int maxRange, QString title, QWidget *parent) :
    QProgressDialog(parent)
{
    counter = 1;
    this->setWindowTitle(title);
    this->setLabelText(title);
    this->setRange(counter, maxRange);

    this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);

    this->show();
    this->raise();
}

void ProcessDialog::updateProgress(QString s)
{
    counter++;
    this->setLabelText(s);
    this->setValue(counter);
}

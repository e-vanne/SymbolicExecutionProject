#include "displayresult.h"

DisplayResult::DisplayResult(QWidget *parent) :
    QWidget(parent)
{
    create();
}

DisplayResult::~DisplayResult()
{

}

void DisplayResult::create()
{
    createL();
    createE();
    createLayout();
}

void DisplayResult::createL()
{
    LexecTime = new QLabel("<b>Time of execution (ms):</b>");
    LgeneratedPath = new QLabel("<b>Numbers of generated paths :</b>");
    LpathCompleted = new QLabel("<b>Numbers of completed paths :</b>");
    LnumberInstruction = new QLabel("<b>Numbers of instructions :</b>");
}

void DisplayResult::createE()
{
    EexecTime = new QLineEdit("0.0");
    EgeneratedPath = new QLineEdit("undefined");
    EpathCompleted = new QLineEdit("undefined");
    EnumberInstruction = new QLineEdit("0");

    EexecTime->setReadOnly(true);
    EgeneratedPath->setReadOnly(true);
    EpathCompleted->setReadOnly(true);
    EnumberInstruction->setReadOnly(true);
}

void DisplayResult::createLayout()
{
    QGridLayout *mainLayout = new QGridLayout();

    mainLayout->addWidget(LexecTime, 0, 0, 1, 2, Qt::AlignLeft);
    mainLayout->addWidget(LgeneratedPath, 1, 0, 1, 2, Qt::AlignLeft);
    mainLayout->addWidget(LpathCompleted, 2, 0, 1, 2, Qt::AlignLeft);
    mainLayout->addWidget(LnumberInstruction, 3, 0, 1, 2, Qt::AlignLeft);

    mainLayout->addWidget(EexecTime, 0, 2, 1, 2, Qt::AlignLeft);
    mainLayout->addWidget(EgeneratedPath, 1, 2, 1, 2, Qt::AlignLeft);
    mainLayout->addWidget(EpathCompleted, 2, 2, 1, 2, Qt::AlignLeft);
    mainLayout->addWidget(EnumberInstruction, 3, 2, 1, 2, Qt::AlignLeft);

    this->setLayout(mainLayout);
}

void DisplayResult::updateExecTime(QString t)
{
    EexecTime->setText(t);
}

void DisplayResult::updateNbrCompleted(QString c)
{
    EpathCompleted->setText(c);
}

void DisplayResult::updateNbrGenerated(QString g)
{
    EgeneratedPath->setText(g);
}

void DisplayResult::updateNbrInstructions(QString i)
{
    EnumberInstruction->setText(i);
}

#include "displayfile.h"

DisplayFile::DisplayFile(QWidget *parent) :
    QWidget(parent)
{
    create();
}

DisplayFile::~DisplayFile()
{
    delete qte;
    delete nameDir;
}

void DisplayFile::create()
{
    text = "";
    createQTE();
    createLabel();
    createLayout();
}

void DisplayFile::createQTE()
{
    qte = new QTextEdit();

    qte->setTextInteractionFlags(Qt::TextSelectableByMouse);
}

void DisplayFile::createLabel()
{
    nameDir = new QLabel(fileLoad + none);
}

void DisplayFile::createLayout()
{
    QGridLayout *mainLayout = new QGridLayout();

    mainLayout->addWidget(nameDir, 0, 0, 1, 4, Qt::AlignCenter);
    mainLayout->addWidget(qte, 1, 0, 10, 4);

    this->setLayout(mainLayout);
}

void DisplayFile::updateTextArea(QString display)
{
    text += display;
}

void DisplayFile::updateNameEnv(QString nameEnv)
{
    nameDir->setText(fileLoad + nameEnv);
}

void DisplayFile::displayText()
{
    qte->append(text);
}

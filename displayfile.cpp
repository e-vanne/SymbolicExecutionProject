#include "displayfile.h"

DisplayFile::DisplayFile(QWidget *parent) :
    QWidget(parent) {
    create();
}

DisplayFile::~DisplayFile() {
    delete qte;
    delete nameFile;
}

void DisplayFile::create() {
    createQTE();
    createLabel();
    createLayout();
}

void DisplayFile::createQTE() {
    qte = new QTextEdit();

    qte->setTextInteractionFlags(Qt::TextSelectableByMouse);
}

void DisplayFile::createLabel() {
    nameFile = new QLabel(fileLoad + none);
}

void DisplayFile::createLayout() {
    QGridLayout *mainLayout = new QGridLayout();

    mainLayout->addWidget(nameFile, 0, 0, 1, 4, Qt::AlignCenter);
    mainLayout->addWidget(qte, 1, 0, 10, 4);

    this->setLayout(mainLayout);
}

void DisplayFile::updateTextArea(QFile *f) {

}

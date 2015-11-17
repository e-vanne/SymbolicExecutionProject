#include "environmentbox.h"

EnvironmentBox::EnvironmentBox(QWidget *parent) :
    QDialog(parent)
{
    create();
}

EnvironmentBox::~EnvironmentBox()
{
    delete kleePath;
    delete symnetPath;

    delete klee;
    delete symnet;

    delete edit;
    delete close;
}

void EnvironmentBox::create()
{
    createEdit();
    createButton();
    createLayout();

    this->setWindowFlags(Qt::CustomizeWindowHint|Qt::WindowTitleHint);
    this->setFixedSize(500, 275);
    this->setModal(true);
    this->setWindowTitle("Setting environment");
    this->show();
    this->exec();
}

void EnvironmentBox::createEdit()
{
    kleePath = new QLineEdit();
    symnetPath = new QLineEdit();
}

void EnvironmentBox::createLayout()
{
    QGridLayout *mainLayout = new QGridLayout;
    QDialogButtonBox *buttonBox = new QDialogButtonBox;

    QGroupBox *kpgb = new QGroupBox("Klee path");
    QGridLayout *kpgl = new QGridLayout;

    QGroupBox *spgb = new QGroupBox("Symnet path");
    QGridLayout *spgl = new QGridLayout;

    buttonBox->addButton(edit, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(close, QDialogButtonBox::NoRole);

    kpgl->addWidget(kleePath, 0, 0, 1, 3);
    kpgl->addWidget(klee, 0, 3, 1, 1);

    kpgb->setLayout(kpgl);
    kpgb->setStyleSheet("QGroupBox {"\
                        "border-width: 1px;"\
                        "border-style: solid;"\
                        "border-color: grey;"\
                        "border-radius: 5px;"\
                        "padding: 7;}"\
                        "QGroupBox::title {"\
                        "border-top-left-radius: 0px;"\
                        "border-top-right-radius: 0px;}");

    mainLayout->addWidget(kpgb, 0, 0);

    spgl->addWidget(symnetPath, 1, 0, 1, 3);
    spgl->addWidget(symnet, 1, 3, 1, 1);

    spgb->setLayout(spgl);
    spgb->setStyleSheet("QGroupBox {"\
                        "border-width: 1px;"\
                        "border-style: solid;"\
                        "border-color: grey;"\
                        "border-radius: 5px;"\
                        "padding: 7;}"\
                        "QGroupBox::title {"\
                        "border-top-left-radius: 0px;"\
                        "border-top-right-radius: 0px;}");

    mainLayout->addWidget(spgb, 1, 0);
    mainLayout->addWidget(buttonBox, 2, 0);

    this->setLayout(mainLayout);
}

void EnvironmentBox::createButton()
{
    edit = new QPushButton("Edit");
    close = new QPushButton("Close");

    klee = new QPushButton("Browse...");
    symnet = new QPushButton("Browse...");

    connect(close, SIGNAL(clicked()), this, SLOT(exitProgram()));
    connect(edit, SIGNAL(clicked()), this, SLOT(close()));

    // TODO : connect to the QFileBox and retrieve path
}

void EnvironmentBox::exitProgram()
{
    exit(0);
}

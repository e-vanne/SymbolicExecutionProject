#include "environmentbox.h"

EnvironmentBox::EnvironmentBox(QWidget *parent) :
    QDialog(parent)
{
    create();
}

EnvironmentBox::~EnvironmentBox()
{
    delete kleePath;
    delete kleeFile;
    delete symnetPath;

    delete klee;
    delete kleeF;
    delete symnet;

    delete edit;
    delete close;

    delete browseK;
    delete browseKF;
    delete browseS;
}

QString EnvironmentBox::getKleePathFile()
{
    return kleeFile->text();
}

QString EnvironmentBox::getKleePath()
{
    return kleePath->text();
}

QString EnvironmentBox::getSymnetPath()
{
    return symnetPath->text();
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
}

void EnvironmentBox::createEdit()
{
    kleePath = new QLineEdit("Select the directory of klee");
    kleeFile = new QLineEdit("Select the directory of the file to analyze");
    symnetPath = new QLineEdit("Select the directory of symnet");

    kleePath->setReadOnly(true);
    kleeFile->setReadOnly(true);
    symnetPath->setReadOnly(true);

    connect(kleePath, SIGNAL(textChanged(QString)), this, SLOT(unlockEdit()));
    connect(kleeFile, SIGNAL(textChanged(QString)), this, SLOT(unlockEdit()));
    connect(symnetPath, SIGNAL(textChanged(QString)), this, SLOT(unlockEdit()));
}

void EnvironmentBox::createLayout()
{
    QGridLayout *mainLayout = new QGridLayout;
    QDialogButtonBox *buttonBox = new QDialogButtonBox;

    QGroupBox *kpgb = new QGroupBox("Klee env.");
    QGridLayout *kpgl = new QGridLayout;

    QGroupBox *spgb = new QGroupBox("Symnet env.");
    QGridLayout *spgl = new QGridLayout;

    buttonBox->addButton(edit, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(close, QDialogButtonBox::NoRole);

    kpgl->addWidget(kleePath, 0, 0, 1, 3);
    kpgl->addWidget(klee, 0, 3, 1, 1);
    kpgl->addWidget(kleeFile, 1, 0, 1, 3);
    kpgl->addWidget(kleeF, 1, 3, 1, 1);

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
    edit->setEnabled(false);

    close = new QPushButton("Close");

    klee = new QPushButton("Browse...");
    kleeF = new QPushButton("Browse...");
    symnet = new QPushButton("Browse...");

    createBrowse();

    connect(close, SIGNAL(clicked()), this, SLOT(exitProgram()));
    connect(edit, SIGNAL(clicked()), this, SLOT(close()));

    connect(klee, SIGNAL(clicked()), this, SLOT(browseKFile()));
    connect(kleeF, SIGNAL(clicked()), this, SLOT(browseKFFile()));
    connect(symnet, SIGNAL(clicked()), this, SLOT(browseSFile()));
}

void EnvironmentBox::createBrowse()
{
    browseK = new QFileDialog(0, "Locate Klee directory...");
    browseK->setDirectory(QDir::homePath());
    browseK->setViewMode(QFileDialog::Detail);
    browseK->setFileMode(QFileDialog::DirectoryOnly);

    browseKF = new QFileDialog(0, "Locate Klee file to analyze...");
    browseKF->setDirectory(QDir::homePath());
    browseKF->setViewMode(QFileDialog::Detail);
    browseKF->setFileMode(QFileDialog::DirectoryOnly);

    browseS = new QFileDialog(0, "Locate Symnet directory...");
    browseS->setDirectory(QDir::homePath());
    browseS->setViewMode(QFileDialog::Detail);
    browseS->setFileMode(QFileDialog::DirectoryOnly);
}

void EnvironmentBox::browseKFFile()
{
    browseKF->exec();
    QString dir = browseKF->selectedFiles().first();
    kleeFile->setText(dir);
}

void EnvironmentBox::browseKFile()
{
    browseK->exec();
    QString dir = browseK->selectedFiles().first();
    kleePath->setText(dir);
}

void EnvironmentBox::browseSFile()
{
    browseS->exec();
    QString dir = browseS->selectedFiles().first();
    symnetPath->setText(dir);
}

void EnvironmentBox::unlockEdit()
{
    if (!kleePath->text().contains("/"))
    {
        edit->setEnabled(false);
        return;
    }
    if (!kleeFile->text().contains("/"))
    {
        edit->setEnabled(false);
        return;
    }
    if (symnetPath->text().contains("/"))
        edit->setEnabled(true);
}

void EnvironmentBox::exitProgram()
{
    exit(0);
}

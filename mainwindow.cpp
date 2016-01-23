#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) {
    CheckLaunch *cl = new CheckLaunch();
    if (cl->isLaunch())
    {
        delete cl;
        exit(0);
    }
    QThread::usleep(10000);
    delete cl;

    initClass();

    eb->exec();

    initVar();

    create();
    ke->execute();
    se->execute();
    display();
}

MainWindow::~MainWindow() {
    delete click;
    delete clickR;
    delete cplusplus;
    delete cplusplusR;
    delete menuBar;

    delete splitter;
    delete eb;
    delete ke;
    delete se;
}

void MainWindow::initClass()
{
    click = new DisplayFile();
    cplusplus = new DisplayFile();
    clickR = new DisplayResult();
    cplusplusR = new DisplayResult();

    menuBar = new MenuBar();

    eb = new EnvironmentBox();

    ke = new KleeEnvironment();
    se = new SymnetEnvironment();

    connect(ke, SIGNAL(updateExecTime(QString)), cplusplusR, SLOT(updateExecTime(QString)));
    connect(ke, SIGNAL(updateNbrCompleted(QString)), cplusplusR, SLOT(updateNbrCompleted(QString)));
    connect(ke, SIGNAL(updateNbrGenerated(QString)), cplusplusR, SLOT(updateNbrGenerated(QString)));
    connect(ke, SIGNAL(updateNbrInstructions(QString)), cplusplusR, SLOT(updateNbrInstructions(QString)));
    connect(ke, SIGNAL(updateDisplay(QString)), cplusplus, SLOT(updateTextArea(QString)));
    connect(ke, SIGNAL(processingEnd()), cplusplus, SLOT(displayText()));

    connect(se, SIGNAL(updateExecTime(QString)), clickR, SLOT(updateExecTime(QString)));
    connect(se, SIGNAL(updateNbrCompleted(QString)), clickR, SLOT(updateNbrCompleted(QString)));
    connect(se, SIGNAL(updateNbrGenerated(QString)), clickR, SLOT(updateNbrGenerated(QString)));
    connect(se, SIGNAL(updateDisplay(QString)), click, SLOT(updateTextArea(QString)));
    connect(se, SIGNAL(processingEnd()), click, SLOT(displayText()));
}

void MainWindow::initVar()
{
    ke->updatePath(eb->getKleePath());
    ke->updatePathFile(eb->getKleePathFile());
    se->updatePath(eb->getSymnetPath());

    click->updateNameEnv(eb->getSymnetPath());
    cplusplus->updateNameEnv(eb->getKleePath());
}

void MainWindow::create() {
    createSplitter();
    createLayout();
}

void MainWindow::createSplitter() {
    splitter = new QSplitter(Qt::Horizontal);
    QWidget *left = new QWidget();
    QWidget *right = new QWidget();

    QGridLayout *rightL = new QGridLayout();
    QGridLayout *leftL = new QGridLayout();

    rightL->addWidget(click, 0, 0);
    rightL->addWidget(clickR, 1, 0);
    leftL->addWidget(cplusplus, 0, 0);
    leftL->addWidget(cplusplusR, 1, 0);

    right->setLayout(rightL);
    left->setLayout(leftL);

    splitter->addWidget(left);
    splitter->addWidget(right);

    splitter->setCollapsible(splitter->indexOf(left), false);
    splitter->setCollapsible(splitter->indexOf(right), false);
}

void MainWindow::createLayout() {
    QWidget *central = new QWidget;
    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->addWidget(splitter);

    central->setLayout(mainLayout);

    this->setCentralWidget(central);
}

void MainWindow::display() {
    this->setMenuBar(menuBar);
    menuBar->show();
    this->setFixedSize(QSize(1280,720));
    this->setEnabled(true);
    this->show();
}

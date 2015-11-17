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

    EnvironmentBox *eb = new EnvironmentBox();
    // TODO : get the result of eb and check if close or continue
    // remove exit from the class envvibox

    create();
    display();
}

MainWindow::~MainWindow() {
    delete click;
    delete cplusplus;
    delete menuBar;

    delete splitter;
}

void MainWindow::create() {
    createClass();
    createSplitter();
    createLayout();
}

void MainWindow::createClass() {
    click = new DisplayFile();
    cplusplus = new DisplayFile();
    menuBar = new MenuBar();
}

void MainWindow::createSplitter() {
    splitter = new QSplitter(Qt::Horizontal);

    splitter->addWidget(click);
    splitter->addWidget(cplusplus);

    splitter->setCollapsible(splitter->indexOf(click), false);
    splitter->setCollapsible(splitter->indexOf(cplusplus), false);
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
    this->setFixedSize(QSize(1024,708));
    this->setEnabled(true);
    this->show();
}

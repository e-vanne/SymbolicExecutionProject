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

    create();
    display();
}

MainWindow::~MainWindow() {
    delete click;
    delete cplusplus;
    delete menuBar;
}

void MainWindow::create() {
    createClass();

    createLayout();
}

void MainWindow::createClass() {
    click = new DisplayFile();
    cplusplus = new DisplayFile();
    menuBar = new MenuBar();
}

void MainWindow::createLayout() {
    QWidget *central = new QWidget();
    QGridLayout *mainLayout = new QGridLayout();

    mainLayout->addWidget(click, 0, 0);
    mainLayout->addWidget(cplusplus, 0, 1);

    central->setLayout(mainLayout);
    this->setCentralWidget(central);
}

void MainWindow::display() {
    this->setMenuBar(menuBar);
    this->setFixedSize(QSize(1024,708));
    this->setEnabled(true);
    this->show();
}

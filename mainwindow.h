#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QThread>
#include <QMainWindow>
#include <QSplitter>

#include "displayfile.h"
#include "checklaunch.h"
#include "menubar.h"
#include "environmentbox.h"
#include "kleeenvironment.h"
#include "symnetenvironment.h"
#include "displayresult.h"

class MainWindow : public QMainWindow
{
        Q_OBJECT
    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        DisplayFile *click; // Symnet
        DisplayFile *cplusplus; // Klee
        DisplayResult *clickR;
        DisplayResult *cplusplusR;

        MenuBar *menuBar;

        EnvironmentBox *eb;
        KleeEnvironment *ke;
        SymnetEnvironment *se;

        QSplitter *splitter;

        void create();
        void createSplitter();
        void createLayout();

        void display();

        void initClass();
        void initVar();
};

#endif // MAINWINDOW_H

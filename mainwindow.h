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

class MainWindow : public QMainWindow
{
        Q_OBJECT
    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        DisplayFile *click;
        DisplayFile *cplusplus;
        MenuBar *menuBar;

        QSplitter *splitter;

        void create();
        void createClass();
        void createSplitter();
        void createLayout();

        void display();
};

#endif // MAINWINDOW_H

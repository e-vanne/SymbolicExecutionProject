#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QThread>
#include <QMainWindow>

#include "displayfile.h"
#include "checklaunch.h"
#include "menubar.h"

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

        void create();
        void createClass();

        void createLayout();

        void display();
};

#endif // MAINWINDOW_H

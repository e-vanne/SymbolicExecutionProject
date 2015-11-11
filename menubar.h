#ifndef MENUBAR_H
#define MENUBAR_H

#include <QSignalMapper>
#include <QMessageBox>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QLabel>

#include "libstring.h"

class MenuBar : public QMenuBar
{
       Q_OBJECT
    public:
        MenuBar(QWidget * parent = 0);
        ~MenuBar();

    private:
        QMenu *aboutMenu;
        QLabel *version;
        QAction *aboutAction;
        QAction *contactAction;
        void create();

    public slots :
        void aboutBox();
        void contactBox();
};

#endif // MENUBAR_H

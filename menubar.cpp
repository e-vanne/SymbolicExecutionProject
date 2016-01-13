#include "menubar.h"

/*
 * Builder of MenuBar class.
 * Take in parameter a parent = 0.
 */
MenuBar::MenuBar(QWidget * parent) : QMenuBar(parent) {
    create();
}

/*
 * Desctructive of MenuBar class.
 */
MenuBar::~MenuBar() {
    delete aboutMenu;
    delete version;
    delete aboutAction;
    delete contactAction;
}

/*
 * Initialize the menu.
 * Help
 *  | - About
 *  | - Contact
 */
void MenuBar::create() {
    aboutMenu = new QMenu(tr("Help"));
    version = new QLabel(tr("Version : %1").arg(NUMBER_OF_VERSION));
    aboutAction = new QAction("About", aboutMenu);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(aboutBox()));

    contactAction = new QAction("Contact", aboutMenu);
    connect(contactAction, SIGNAL(triggered()), this, SLOT(contactBox()));

    aboutMenu->addAction(aboutAction);
    aboutMenu->addAction(contactAction);
    this->setCornerWidget(version, Qt::TopRightCorner);

    this->addMenu(aboutMenu);
}

/*
 * Initialize a message box.
 */
void MenuBar::aboutBox() {
    QMessageBox *msb = new QMessageBox();
    msb->setWindowTitle("About");
    msb->setText(tr("<b><span style=\"font-size:20px;\">SymbolicExecutionProject</span></b><br>"\
                    "%1<br>"\
                    "SymbolicExecutionProject is developped by two student<br>"\
                    "at Politehnica of Bucharest in ACS, for the Dependable System lesson.<br>"\
                    "Contributor Ivanne Sanchez and Thomas Guiot<br>"\
                    "<br>").arg(NUMBER_OF_VERSION));
    msb->exec();
    delete msb;
}


void MenuBar::contactBox() {
    QMessageBox *msb = new QMessageBox();
    msb->setWindowTitle("Contact");
    msb->setText("<b><span style=\"font-size:20px;\">SymbolicExecutionProject</span></b><br>"\
                 "Contact :<br>"\
                 "Ivanne Sanchez<br>"\
                 "Thomas GUIOT<br>");
    msb->exec();
    delete msb;
}

/*
 * Work in progress add the browser and set the line edit
 */
#ifndef ENVIRONMENTBOX_H
#define ENVIRONMENTBOX_H

#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QFileDialog>
#include <QGroupBox>
#include <QGridLayout>
#include <QDialogButtonBox>
#include <QLabel>
#include <QLineEdit>
#include <QStringList>
#include <QDebug>
#include <QDir>

class EnvironmentBox : public QDialog
{
        Q_OBJECT
    public:
        EnvironmentBox(QWidget *parent = 0);
        ~EnvironmentBox();

        QString getKleePath();
        QString getKleePathFile();
        QString getSymnetPath();

    private:
        QLineEdit *kleePath;
        QLineEdit *kleeFile;
        QLineEdit *symnetPath;

        QPushButton *klee;
        QPushButton *kleeF;
        QPushButton *symnet;

        QPushButton *edit;
        QPushButton *close;

        QFileDialog *browseK;
        QFileDialog *browseKF;
        QFileDialog *browseS;

        void create();
        void createEdit();
        void createButton();
        void createBrowse();
        void createLayout();

    private slots:
        void exitProgram();
        void browseKFFile();
        void browseKFile();
        void browseSFile();
        void unlockEdit();

    signals:
        void updateKleePath(QString);
        void updateSynmetPath(QString);
};

#endif // ENVIRONMENTBOX_H

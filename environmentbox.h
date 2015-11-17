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

class EnvironmentBox : public QDialog
{
        Q_OBJECT
    public:
        EnvironmentBox(QWidget *parent = 0);
        ~EnvironmentBox();

    private:
        QLineEdit *kleePath;
        QLineEdit *symnetPath;

        QPushButton *klee;
        QPushButton *symnet;

        QPushButton *edit;
        QPushButton *close;

        QFileDialog *browse;

        void create();
        void createEdit();
        void createButton();
        void createBrowse();
        void createLayout();

    private slots:
        void exitProgram();

    signals:
        void updateKleePath(QString);
        void updateSynmetPath(QString);
};

#endif // ENVIRONMENTBOX_H

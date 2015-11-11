#ifndef DISPLAYFILE_H
#define DISPLAYFILE_H

#include <QWidget>
#include <QFile>
#include <QTextEdit>
#include <QTextStream>
#include <QLabel>
#include <QGridLayout>

#include <libstring.h>

class DisplayFile : public QWidget
{
        Q_OBJECT
    public:
        DisplayFile(QWidget *parent = 0);
        ~DisplayFile();

    private:
        QLabel *nameFile;
        QTextStream qts;
        QTextEdit *qte;

        void create();
        void createQTE();
        void createLabel();
        void createLayout();

    public slots:
        void updateTextArea(QFile *f);
};

#endif // DISPLAYFILE_H

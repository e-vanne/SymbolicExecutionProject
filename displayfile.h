#ifndef DISPLAYFILE_H
#define DISPLAYFILE_H

#include <QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QGridLayout>

#include <libstring.h>

class DisplayFile : public QWidget
{
        Q_OBJECT
    public:
        DisplayFile(QWidget *parent = 0);
        ~DisplayFile();

        void updateNameEnv(QString);

    private:
        QLabel *nameDir;
        QTextEdit *qte;
        QString text;

        void create();
        void createQTE();
        void createLabel();
        void createLayout();

    public slots:
        void updateTextArea(QString);
        void displayText();
};

#endif // DISPLAYFILE_H

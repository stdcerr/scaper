#ifndef __SCAPER_H__
#define __SCAPER_H__

#define USEDEBUG
#include <iostream>
#include "ui_scaper.h"
#include "dialog.h"

#ifdef USEDEBUG
#define Debug(x) std::cout << (x)
#else

#define Debug(x)
#endif


#define OK      0
#define ERROR   -1

class scaper {
    private:
        int checkall(QObject*);
        int uncheckall(QObject*);
        int dialogShow(QWidget*);
        int check(QWidget*);
        int runsca(QTextEdit*);
        QString fname;
    public:
        void fname_set(QString str) { fname = str;}
        QString fname_get(void){return fname;}
        scaper(){}
        ~scaper(){}
        Ui::MainWindow ui;
    public slots:
        void ChckBtn(void);
        void UnchckBtn(void);
        void PthBtn(QLineEdit*);
        void DialogBtn(void);
        void ChckSCABtn(void);
};


#endif


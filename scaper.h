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
    public:
        scaper(){}
        ~scaper(){}
        Ui::MainWindow ui;
    public slots:
        void ChckBtn(void);
        void UnchckBtn(void);
        void PthBtn(void);
        void DialogBtn(void);
};


#endif


#ifndef __yasca_h__
#define __yaisca_h__

#include "ui_main.h"

#define OK      0
#define ERROR   -1

class yasca {
    private:
    int checkall(QObject*);
    int uncheckall(QObject*);
    public:
        yasca(){}
        ~yasca(){}
        Ui::MainWindow ui;
    public slots:
        void ChckBtn(void);
        void UnchckBtn(void);
        void PthBtn(void);
};


#endif


#ifndef __scaper_h__
#define __yaisca_h__

#include "ui_scaper.h"

#define OK      0
#define ERROR   -1

class scaper {
    private:
    int checkall(QObject*);
    int uncheckall(QObject*);
    public:
        scaper(){}
        ~scaper(){}
        Ui::MainWindow ui;
    public slots:
        void ChckBtn(void);
        void UnchckBtn(void);
        void PthBtn(void);
};


#endif


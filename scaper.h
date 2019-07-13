/* 
 * This file is part of the scaper distribution (https://github.com/reggler/ 
 * Copyright (c) 2019 Ron Eggler.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
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

#define DFLTPATH	"/usr/bin/splint"
#define LoadDefaults(x) (x)->fname_set(DFLTPATH);

class scaper {
    private:
        int checkall(QObject*);
        int uncheckall(QObject*);
        int dialogShow(QWidget*);
        int check(QWidget*);
		int choose (QWidget*);
		int asm_cmd(QString &cmd);
        int runsca(QTextEdit*);
		int CheckFilePath(QString path);
        QString fname;
        QStringList slst;
    public:
        void fname_set(const QString &s) { fname = s; }
        QString fname_get(void) const { return fname; }
        void srcs_set(const QStringList &l) { slst = l; }
        QStringList srcs_get(void) const { return slst; }
        ~scaper(){}
        Ui::MainWindow ui;
    public slots:
        void ChckBtn(void);
        void UnchckBtn(void);
        void PthBtn(QLineEdit*);
        void DialogBtn(void);
        void ChooseBtn(void);
        void ChckSCABtn(void);
};


#endif


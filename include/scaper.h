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

#define DEBUG

#ifdef DEBUG
#define dbg_prnt    std::cout
#else
#define dbg_prnt    std::cout.setstate(std::ios_base::badbit);\
                    std::cout
#endif

#define OK      0
#define ERROR   -1

#define DFLTPATH		"/usr/bin/splint"
#define CORP_NAME		"GNU"
#define PROGRAM_NAME	"SCAPER"
#define CFG_PRFX        QString("cfg_")
#define LoadDefaults(a) (a)->fname_set(DFLTPATH);
class ScaperDialog;		// foward declaration


class scaper :QMainWindow{
    private:
        int checkall(QObject*);
        int uncheckall(QObject*);
        int dialogShow(QWidget*);
        int check(QWidget*);
	QPushButton* DlgShwBtnCrt(QString nme);
	QCheckBox* DlgEnChckBxCrt(QString txt,Qt::CheckState chckd);
		int choose (QWidget*);
		int asm_cmd(QString &cmd);
        int runsca(QString&);
		int CheckFilePath(QString path);
		int ConfigGet(QStringList *con);
		QString pname;
        QString fname;
        QStringList slst;
		QStringList conf;
		QCheckBox *chkbox;
		QString grp;
		const QSettings *sttngs;
		void grp_set(const QString &str) {grp=str;}
		void sttngs_set(const QSettings* ptr) {sttngs = ptr;}
		QString grp_get(void) const {return grp;}
		const QSettings* sttngs_get(void) {return sttngs;}
        QString CmdStrBuild(QSettings *settings,const QString &grp);
        int ToolCmdExec();
    private slots:
    		void DlgEnChckSv(QString &group);
    public:
	scaper(QWidget *parent);
        ~scaper(){}
        void pname_set(const QString &s) { pname = s; }
        QString pname_get(void) const { return pname; }
        void fname_set(const QString &s) { fname = s; }
        QString fname_get(void) const { return fname; }
        void srcs_set(const QStringList &l) { slst = l; }
        QStringList srcs_get(void) const { return slst; }
		void conf_set(const QStringList &c) {conf = c; }
		QStringList conf_get(void) const { return conf; }
        Ui::MainWindow ui;
		QProcess *proc;
		struct sca_dat {
			QWidget *parent;
			ScaperDialog *dialog;
			QString name;
			QString fname;
			};
	 	int DialogShow(sca_dat&);
    public slots:
        void ChckBtn(void);
        void UnchckBtn(void);
        void PthBtn(QLineEdit*);
        void SplintDialogBtn(void);
        void ChooseBtn(void);
        void ChckSCABtn(void);
		void updateError(QProcess*);
        void updateText(QProcess*);
};


#endif


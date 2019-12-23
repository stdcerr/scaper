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
#include <string>
#include <QDir>
#include <QString>
#include <QtWidgets/QFileDialog>
#include <unistd.h>
#include "scaper.h"
#include "scacfg.h"


//-------------------------------------------------------------------------------------------------
scaper::scaper(QWidget *parent) {
	QGroupBox *grpbox = parent->findChild<QGroupBox *>("ConfigGroupBox");
	QVBoxLayout *vbox = new QVBoxLayout;
	/*QSettings **/sttngs = new QSettings(QSettings::NativeFormat,QSettings::UserScope,"GNU","scaper",nullptr);
	QCheckBox *tmpbox = nullptr;
	QString str = "";
	QStringList groups = sttngs->childGroups();
	foreach (const QString &grp, groups) {
		scacfg *config = new scacfg(grp, grpbox, sttngs);
		vbox->addWidget(config);
		dbg_prnt << "grp " <<grp.toStdString() << std::endl;
	}
	grpbox->setLayout(vbox);
}
//-------------------------------------------------------------------------------------------------
void scaper::DlgEnChckSv(QString &nme) {
	dbg_prnt << "inside " << __func__ << " for " << nme.toStdString() << std::endl;
    const QSettings *sttngs = sttngs_get();
}
//-------------------------------------------------------------------------------------------------
QPushButton* scaper::DlgShwBtnCrt(QString nme) {
	return new QPushButton(nme);
}
//-------------------------------------------------------------------------------------------------
QCheckBox* scaper::DlgEnChckBxCrt(QString txt,Qt::CheckState chckd) {
	QCheckBox *box = new QCheckBox(txt);
	box->setCheckState(chckd);
	return box;
}
//-------------------------------------------------------------------------------------------------

void scaper::SplintDialogBtn(void) {
    dbg_prnt << "inside " << __func__ <<std::endl;
	sca_dat splint;
	splint.parent = ui.centralwidget;
	splint.name = "Splint";
	splint.fname = fname_get();
	this->DialogShow(splint);
}
//-------------------------------------------------------------------------------------------------

void scaper::UnchckBtn(void) {
    dbg_prnt << "inside " << __func__ <<std::endl;
    if (!uncheckall(ui.SplintOptionsGroupBox))
        dbg_prnt << "all unchecked!" << std::endl;
}
//-------------------------------------------------------------------------------------------------

void scaper::ChckBtn(void) {
    dbg_prnt << "inside " << __func__ <<std::endl;
	if (!checkall(ui.SplintOptionsGroupBox))
        dbg_prnt << "all checked!" << std::endl;
	
}
//-------------------------------------------------------------------------------------------------

int scaper::CheckFilePath(QString path) {
return (access(path.toLocal8Bit().constData(), X_OK) == OK) ? OK : ERROR;
}

//-------------------------------------------------------------------------------------------------
void scaper::SrcFilesSet(QStringList FileList) {
    SrcLst = FileList;
}
//-------------------------------------------------------------------------------------------------

QStringList scaper::SrcFilesGet(void) {
    return SrcLst;
}
//-------------------------------------------------------------------------------------------------

void scaper::DisplayFiles(QStringList files) {

    QString fls;
	for ( const auto& i : files )
		fls.append(" \""+i+"\"");
    ui.FilesLineEdit->setText(fls);
}
//-------------------------------------------------------------------------------------------------

void scaper::ChooseBtn(void) {
    dbg_prnt << "inside " << __func__ <<std::endl;
	QFileDialog dialog(nullptr);
	QString dir = QDir::currentPath();
	dialog.setDirectory(dir);
	dialog.setFileMode(QFileDialog::ExistingFiles);
	dialog.setNameFilter("C Files(*.c *.cpp)");
	if (dialog.exec()){
		SrcFilesSet(dialog.selectedFiles());
        DisplayFiles(SrcFilesGet());
    }
}
//-------------------------------------------------------------------------------------------------

void scaper::ChckSCABtn(void) {
	QString cmd; 
    dbg_prnt << "inside " << __func__ <<std::endl;

	if (CheckFilePath(fname_get())) {
		std::cerr << "Error: check permissions of selected binary. Exit" << std::endl;
		exit(ERROR);
		}
	dbg_prnt << "OK"<< std::endl;
	AsmCmd(cmd);



    }
//-------------------------------------------------------------------------------------------------

void scaper::updateError(QProcess *proc) {
    dbg_prnt << "inside " << __func__ <<std::endl;
	QByteArray dat = proc->readAllStandardError();
	ui.outputTextEdit->append(QString(dat));
}
//-------------------------------------------------------------------------------------------------

void scaper::updateText(QProcess *proc) {
    dbg_prnt << "inside " << __func__ <<std::endl;
	QByteArray dat = proc->readAllStandardOutput();
	ui.outputTextEdit->append(QString(dat));
}
//-------------------------------------------------------------------------------------------------

void scaper::PthBtn(QLineEdit *edit) {
    dbg_prnt << "inside " << __func__ <<std::endl;
    fname_set(QFileDialog::getOpenFileName(nullptr,
        "Path to splint", "/usr/bin", "All Files (*.*)"));
    if(edit)
        edit->setText(fname_get());
}
//-------------------------------------------------------------------------------------------------

int scaper::checkall(QObject *parentWidget) {
    int rv = OK;
    QList<QCheckBox *>list = parentWidget->findChildren<QCheckBox *>();
    QList<QCheckBox *>::iterator i;
    for(i = list.begin();i != list.end(); i++) {
        dbg_prnt <<(*i)->text().toStdString() << std::endl;
        (*i)->setChecked(true);
    }
    return rv;
}
//-------------------------------------------------------------------------------------------------

int scaper::uncheckall(QObject *parentWidget) {
    int rv = OK;
    QList<QCheckBox *>list = parentWidget->findChildren<QCheckBox *>();
    QList<QCheckBox *>::iterator i;
    for(i = list.begin();i != list.end(); i++) {
        dbg_prnt << (*i)->text().toStdString() << std::endl;
        (*i)->setChecked(false);
    }
    return rv;
}
//-------------------------------------------------------------------------------------------------

int scaper::DialogShow(sca_dat &data) {
    return OK;
}
//-------------------------------------------------------------------------------------------------

int scaper::dialogShow(QWidget *parent) {
    return OK;
}
//-------------------------------------------------------------------------------------------------

void scaper::AsmCmd(QString &cmd) {
	int rv;
	//cmd = fname_get();
    QStringList tools = EnToolsGet(sttngs);
    foreach(const QString &tool, tools) {
        dbg_prnt << __func__ << ":: " << tool.toStdString() << std::endl;
        sttngs->beginGroup(tool);
        QString cmd = sttngs->value(CFG_PRFX+"path").toString();
        dbg_prnt << tool.toStdString() << " cmd: " << cmd.toStdString()<< std::endl;
        if (tool == "Splint") {
            //GetSplintOpts();
            dbg_prnt << "cmd: "<< cmd.toStdString() << " + appended options" << std::endl;
    
            foreach(QString key, sttngs->childKeys()) {
                /*if(!isValidKey(key)) {
                    continue;
    		}*/
            Qt::CheckState state = (Qt::CheckState) sttngs->value(key).toInt();
            if (state == Qt::Checked)
                cmd.append(" -" + key);
            }
            dbg_prnt << "assembled cmd: " << cmd.toStdString() <<std::endl;
        } //else {
        sttngs->endGroup();
            //dbg_prnt << "current tool is " << tool <<std::endl;
        	//QStringList sources = SrcFilesGet();
        	//for ( const auto& i : sources )
            //    cmd.prepend(" "+i);
            //dbg_prnt << __func__ << ": " << cmd.toStdString() << std::endl;
        //}
    }
	if (!RunSCA(cmd))
		dbg_prnt << "SCA invoked!" << std::endl;
}
//-------------------------------------------------------------------------------------------------

int scaper::RunSCA(QString &cmd) {
	int rv = OK;
    dbg_prnt << "inside " << __func__ <<std::endl;
	(void)proc->start(cmd);
	return rv;
}
//-------------------------------------------------------------------------------------------------

int scaper::ConfigGet(QStringList *con) {
	int rv = OK;
    dbg_prnt << "inside " << __func__ <<std::endl;
	return rv;
}
//-------------------------------------------------------------------------------------------------

QStringList scaper::EnToolsGet(QSettings *sttngs) {
    QStringList res; 
    QStringList groups = sttngs->childGroups();
    foreach(const QString &grp, groups) {
        sttngs->beginGroup(grp);
        Qt::CheckState state = (Qt::CheckState)sttngs->value(CFG_PRFX+"Enable").toInt();
        sttngs->endGroup();
        if (state == Qt::Checked) { 
            res.append(grp);
        } 
    }
    return res;

}
//-------------------------------------------------------------------------------------------------

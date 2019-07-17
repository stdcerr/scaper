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
#include "ui_scaper.h"
#include "scaper.h"

void scaper::DialogBtn(void) {
    dbg_prnt << "inside " << __func__ <<std::endl;
    if (!dialogShow(ui.centralwidget)) {
        dbg_prnt << "Testdialog showed!" << std::endl;
    }
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

void scaper::ChooseBtn(void) {
    dbg_prnt << "inside " << __func__ <<std::endl;
	QFileDialog dialog(nullptr);
	QString dir = QDir::currentPath();
	dialog.setDirectory(dir);
	dialog.setFileMode(QFileDialog::ExistingFiles);
	dialog.setNameFilter("C Files(*.c *.cpp)");
	if (dialog.exec())
		srcs_set(dialog.selectedFiles());
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
	asm_cmd(cmd);
	dbg_prnt << "cmd: " << cmd.toStdString() << std::endl;

	if (!runsca(cmd))
		dbg_prnt << "SCA invoked!" << std::endl;


    }
//-------------------------------------------------------------------------------------------------

void scaper:: updateError(QProcess *proc) {
    dbg_prnt << "inside " << __func__ <<std::endl;
	QByteArray dat = proc->readAllStandardError();
	ui.outputTextEdit->append(QString(dat));
}
//-------------------------------------------------------------------------------------------------

void scaper:: updateText(QProcess *proc) {
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

int scaper::dialogShow(QWidget *parent) {
    int rv = OK;
    dbg_prnt << "inside " << __func__ <<std::endl;
    ScaperDialog splintDia(parent);
	splintDia.fname_set(this->fname_get());
    splintDia.exec();
    return rv;
}
//-------------------------------------------------------------------------------------------------

int scaper::asm_cmd(QString &cmd) {
	int rv = OK;
	cmd = fname_get();
	// TODO: include all the options
	QStringList sources = srcs_get();
	for ( const auto& i : sources )
		cmd.append(" "+i);
	return rv;
}
//-------------------------------------------------------------------------------------------------

int scaper::runsca(QString &cmd) {
	int rv = OK;
    dbg_prnt << "inside " << __func__ <<std::endl;
	(void)proc->start(cmd);
	return rv;
}
//-------------------------------------------------------------------------------------------------

int scaper::CobfigGet(QStringList *con) {
	int rv = OK;
    dbg_prnt << "inside " << __func__ <<std::endl;
	return rv;
}

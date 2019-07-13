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
    std::cout << "inside " << __func__ <<std::endl;
    if (!dialogShow(ui.centralwidget)) {
        std::cout << "Testdialog showed!" << std::endl;
    }
}
//-------------------------------------------------------------------------------------------------

void scaper::UnchckBtn(void) {
    std::cout << "inside " << __func__ <<std::endl;
    if (!uncheckall(ui.SplintOptionsGroupBox))
        std::cout << "all unchecked!" << std::endl;
}
//-------------------------------------------------------------------------------------------------

void scaper::ChckBtn(void) {
    std::cout << "inside " << __func__ <<std::endl;
	if (!checkall(ui.SplintOptionsGroupBox))
        std::cout << "all checked!" << std::endl;
	
}
//-------------------------------------------------------------------------------------------------

int scaper::CheckFilePath(QString path) {
return (access(path.toLocal8Bit().constData(), X_OK) == OK) ? OK : ERROR;
}

//-------------------------------------------------------------------------------------------------

void scaper::ChooseBtn(void) {
    std::cout << "inside " << __func__ <<std::endl;
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
    std::cout << "inside " << __func__ <<std::endl;
	if (CheckFilePath(fname_get())) {
		std::cerr << "Error: check permissions of selected binary. Exit" << std::endl;
		exit(ERROR);
		}
	std::cout << "OK"<< std::endl;
	asm_cmd(cmd);
	if (!runsca(ui.OutputTextEdit))
		std::cout << "SCA invoked!" << std::endl;


    }
//-------------------------------------------------------------------------------------------------

void scaper::PthBtn(QLineEdit *edit) {
    std::cout << "inside " << __func__ <<std::endl;
    fname_set(QFileDialog::getOpenFileName(nullptr,
        "Path to splint", "/usr/bin", "All Files (*.*)"));
    if(edit)
        edit->setText(fname_get());
}
//-------------------------------------------------------------------------------------------------

int scaper::checkall(QObject *parentWidget) {
    int rv = OK;
    QList<QCheckBox *>list = parentWidget->findChildren<QCheckBox *>();
    QCheckBox chk;
    QList<QCheckBox *>::iterator i;
    for(i = list.begin();i != list.end(); i++) {
        std::cout <<(*i)->text().toStdString() << std::endl;
        (*i)->setChecked(true);
    }
    return rv;
}
//-------------------------------------------------------------------------------------------------

int scaper::uncheckall(QObject *parentWidget) {
    int rv = OK;
    QList<QCheckBox *>list = parentWidget->findChildren<QCheckBox *>();
    QCheckBox chk;
    QList<QCheckBox *>::iterator i;
    for(i = list.begin();i != list.end(); i++) {
        std::cout << (*i)->text().toStdString() << std::endl;
        (*i)->setChecked(false);
    }
    return rv;
}
//-------------------------------------------------------------------------------------------------

int scaper::dialogShow(QWidget *parent) {
    int rv = OK;
    std::cout << "inside " << __func__ <<std::endl;
    //ScaperDialog *dialog = ScaperDialog(parent);
    //dialog->show();
    ScaperDialog dialog(parent);
    dialog.exec();
    return rv;
}
//-------------------------------------------------------------------------------------------------

int scaper::asm_cmd(QString &cmd) {

}
//-------------------------------------------------------------------------------------------------

int scaper::runsca(QTextEdit *out) {

}

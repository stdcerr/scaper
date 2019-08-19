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
#include <iostream>
#include <fstream>
#include "dialog.h"
#include "scaper.h"


ScaperDialog::ScaperDialog(const QString &name, QWidget *parent) :QDialog(parent) {
	bool rv;
    int nWidth = 300;
    int nHeight = 300;    
	resize(nWidth, nHeight);
    nme_set(name);
    layout = new QVBoxLayout;
	mlab = new QLabel;
	blab = new QLabel;
	binpth  = new QLineEdit;
    QString optnsf = "splint_options";
    closeBtn = new QPushButton("Close");
    chooseBtn = new QPushButton("Choose");
    checkallBtn = new QPushButton("Check all");
    uncheckallBtn = new QPushButton("Uncheck all");
    hbox = new QHBoxLayout;
    chckbox = new QHBoxLayout;

	mlab->setText("Configuration:");
	blab->setText("Path:");

	// define slots
	rv = QObject::connect(this->chooseBtn, &QPushButton::clicked, [&] { this->ChooseBin();	 });
    if (!rv) {std::cerr << "connect() failed: rv:" << rv << std::endl;}
rv = QObject::connect(this->uncheckallBtn, &QPushButton::clicked, [&] { this->UncheckAll();	 });
    if (!rv) {std::cerr << "connect() failed: rv:" << rv << std::endl;}
	rv = QObject::connect(this->checkallBtn, &QPushButton::clicked, [&] { this->CheckAll();	 });
    if (!rv) {std::cerr << "connect() failed: rv:" << rv << std::endl;}
	rv = QObject::connect(this->closeBtn, &QPushButton::clicked, [&] { this->CloseDialog();	 });
    if (!rv) {std::cerr << "connect() failed: rv:" << rv << std::endl;}


	QSettings *sttngs = new QSettings(QSettings::NativeFormat,QSettings::UserScope,"GNU","scaper",nullptr);
	dbg_prnt << "nme_get(): " << nme_get().toStdString() << std::endl;
	sttngs->beginGroup(nme_get());
    dbg_prnt << "beginGroup [" << nme_get().toStdString() << "]"<<std::endl;
    QString test = sttngs->value("path").toString();
    dbg_prnt << "in " << __func__ << " path " << test.toStdString() << std::endl;
	fname_set(sttngs->value("path").toString());
		
	list = new QListWidget(this);
	foreach(const QString &key, sttngs->childKeys()) {
		item = new QListWidgetItem(list);
		item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
		if(!isValidKey(key)) {
			continue;
		}
		Qt::CheckState state = (Qt::CheckState) sttngs->value(key).toInt();
		item->setCheckState(state);
		item->setText(key);
		list->addItem(item);
	}
    sttngs->endGroup();
	layout->addWidget(mlab);
	hbox->addWidget(blab);
	hbox->addWidget(binpth);
	hbox->addWidget(chooseBtn);
	layout->addLayout(hbox);
    layout->addWidget(list);
	chckbox->addWidget(checkallBtn);
	chckbox->addWidget(uncheckallBtn);
	layout->addLayout(chckbox);
    layout->addWidget(closeBtn);

    this->setLayout(layout);
}
//-------------------------------------------------------------------------------------------------

void ScaperDialog::CheckAll(void) {
    dbg_prnt << "inside " << __func__ <<std::endl;
	QListWidget *list = parentWidget()->findChild<QListWidget *>();
	if (!list)
		std::cerr << "No QListWidget found" << std::endl;
	
	for (int i = 0;i != list->count(); i++) {
	QListWidgetItem *it = list->item(i);
		dbg_prnt << it->text().toStdString() << std::endl;
		it->setCheckState(Qt::Checked);
	}
}
//-------------------------------------------------------------------------------------------------

void ScaperDialog::UncheckAll(void) {
    dbg_prnt << "inside " << __func__ <<std::endl;
	QListWidget *list = parentWidget()->findChild<QListWidget *>();
	if (!list)
		std::cerr << "No QListWidget found" << std::endl;

}
//-------------------------------------------------------------------------------------------------

void ScaperDialog::CloseDialog(void) {
	QSettings *sttngs = new QSettings(QSettings::NativeFormat,QSettings::UserScope,"GNU",nme_get(),nullptr);
	sttngs->beginGroup(nme_get());
	sttngs->setValue("path",fname_get());
	sttngs->setValue("size", this->size());

	for (int i =0; i< list->count(); i++) {
		QListWidgetItem* row = list->item(i);
		sttngs->setValue(row->text(),row->checkState());
	}
    sttngs->endGroup();
	delete sttngs;

	close();
}
//-------------------------------------------------------------------------------------------------

void ScaperDialog::ChooseBin(void) {
    dbg_prnt << "inside " << __func__ <<std::endl;
    fname_set(QFileDialog::getOpenFileName(nullptr,
        "Path to splint", "/usr/bin", "All Files (*.*)"));
}
//-------------------------------------------------------------------------------------------------

void ScaperDialog::PathSet(QString txt) {
dbg_prnt << "in " << __func__ << " txt " << txt.toStdString() <<std::endl;
	binpth->setText(txt);
}
//-------------------------------------------------------------------------------------------------

void ScaperDialog::closeEvent(QCloseEvent *event) {
dbg_prnt << "in " << __func__ << std::endl;
this->CloseDialog();
}
//-------------------------------------------------------------------------------------------------

bool ScaperDialog::isValidKey (const QString &key) {

    if (key.startsWith("scapercfg_"))
        return false;
    	
	return true;
}

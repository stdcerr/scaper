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


ScaperDialog::ScaperDialog(QWidget *parent) :QDialog(parent) {
	bool rv;
    int nWidth = 300;
    int nHeight = 300;
	resize(nWidth, nHeight);
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

//--------------------------------------------------------------------------------------------------------

	QSettings *sttngs = new QSettings(QSettings::NativeFormat,QSettings::UserScope,"GNU","SCAPER",nullptr);
	nme_set(sttngs->value("name").toString());
	fname_set(sttngs->value("path").toString());
	sttngs->beginGroup("tooloptions");
		
	list = new QListWidget(this);
	foreach(const QString &key, sttngs->childKeys()) {
		item = new QListWidgetItem(list);
		item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
		Qt::CheckState state = (Qt::CheckState) sttngs->value(key).toInt();
		item->setCheckState(state);
		item->setText(key);
		list->addItem(item);
	}
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
}
//-------------------------------------------------------------------------------------------------

void ScaperDialog::UncheckAll(void) {
    dbg_prnt << "inside " << __func__ <<std::endl;
}
//-------------------------------------------------------------------------------------------------

void ScaperDialog::CloseDialog(void) {
	QSettings *sttngs = new QSettings(QSettings::NativeFormat,QSettings::UserScope,"GNU","SCAPER",nullptr);
	sttngs->beginGroup("global");
	sttngs->setValue("name",nme_get());
	sttngs->setValue("path",fname_get());
	dbg_prnt << "fname: " << fname_get().toStdString() <<std::endl;
	sttngs->setValue("size", this->size());
	sttngs->endGroup();
	sttngs->beginGroup("tooloptions");

	for (int i =0; i< list->count(); i++) {
		QListWidgetItem* row = list->item(i);
		sttngs->setValue(row->text(),row->checkState());
	}
	


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

void ScaperDialog::TextSet(QString txt) {
	binpth->setText(txt);
}
//-------------------------------------------------------------------------------------------------


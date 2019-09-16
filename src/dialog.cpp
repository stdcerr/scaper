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


ScaperDialog::ScaperDialog(QString name, QSettings *set, QWidget *parent) : QDialog(parent) {
	bool rv;
    int nWidth = 300;
    int nHeight = 300;    
    if (set)
        settings = set;
    nme_set(name);
    
    settings->beginGroup(nme_get());
	resize(settings->value(CFG_PRFX+"size").toSize());
    settings->endGroup();

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


	QSettings *settings = new QSettings(QSettings::NativeFormat,QSettings::UserScope,"GNU","scaper",nullptr);
	dbg_prnt << "nme_get(): " << nme_get().toStdString() << std::endl;
	settings->beginGroup(nme_get());
    dbg_prnt << "beginGroup [" << nme_get().toStdString() << "]"<<std::endl;
    QString test = settings->value(CFG_PRFX+"path").toString();
    dbg_prnt << "in " << __func__ << " path " << test.toStdString() << std::endl;
	name_set(settings->value(CFG_PRFX+"path").toString());
		
	list = new QListWidget(this);
	foreach(QString key, settings->childKeys()) {
		item = new QListWidgetItem(list);
		item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
		if(!isValidKey(key)) {
			continue;
		}
		Qt::CheckState state = (Qt::CheckState) settings->value(key).toInt();
		item->setCheckState(state);
		item->setText(key);
		list->addItem(item);
	}
    settings->endGroup();
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
    QSettings *sttngs = settings;
    QString name = nme_get();
	sttngs->beginGroup(name);
	sttngs->setValue(CFG_PRFX+"path",this->PathGet());
	sttngs->setValue(CFG_PRFX+"size", this->size());

	for (int i =0; i< list->count(); i++) {
		QListWidgetItem* row = list->item(i);
		sttngs->setValue(row->text(),row->checkState());
	}
    sttngs->endGroup();

	close();
}
//-------------------------------------------------------------------------------------------------

void ScaperDialog::ChooseBin(void) {
    dbg_prnt << "inside " << __func__ <<std::endl;
    //name_set(QFileDialog::getOpenFileName(nullptr,
    PathSet(QFileDialog::getOpenFileName(nullptr,
        "Path to splint", "/usr/bin", "All Files (*.*)"));
}
//-------------------------------------------------------------------------------------------------

void ScaperDialog::PathSet(QString txt) {
dbg_prnt << "in " << __func__ << " txt " << txt.toStdString() <<std::endl;
	binpth->setText(txt);
}
//-------------------------------------------------------------------------------------------------

QString ScaperDialog::PathGet() {
dbg_prnt << "in " << __func__ << " returning path " << binpth->text().toStdString() <<std::endl;
	return binpth->text();
}
//-------------------------------------------------------------------------------------------------

void ScaperDialog::closeEvent(QCloseEvent *event) {
dbg_prnt << "in " << __func__ << std::endl;
this->CloseDialog();
}
//-------------------------------------------------------------------------------------------------

bool ScaperDialog::isValidKey (QString &key) {

    if (key.startsWith("scapercfg_"))
        return false;
    	
	return true;
}

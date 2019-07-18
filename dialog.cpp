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

	std::ifstream ifs(optnsf.toUtf8());

	std::string line;
	if(!ifs.is_open()) {
	std::cerr << "Resource file \"" << std::string(optnsf.toUtf8()) << "\" not found, exit " << std::endl;
    exit(0);
	}

	list = new QListWidget(this);
	while (std::getline(ifs, line)) {// loop over in config file
		item = new QListWidgetItem();
		item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
		item->setCheckState(Qt::Unchecked);
    	item->setText(QString::fromStdString(line));
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


	rv = QObject::connect(this->closeBtn, &QPushButton::clicked, [&] {
			 this->CloseDialog();
	});
    if (!rv) {
        std::cerr << "connect() failed: rv:" << rv << std::endl;
    }



    this->setLayout(layout);
}

int ScaperDialog::CloseDialog(void) {
	QSettings *sttngs = new QSettings(QSettings::NativeFormat,QSettings::UserScope,"GNU","SCAPER",nullptr);

	sttngs->beginGroup(nme_get());
	sttngs->setValue("size", this->size());
	sttngs->endGroup();
	sttngs->beginGroup("tooloptions");

	for (int i =0; i< list->count(); i++) {
		QListWidgetItem* row = list->item(i);
		dbg_prnt << "item " << i << " " << row->text(); <<std::endl;

	}
	


	 delete sttngs;

	close();
}
void ScaperDialog::TextSet(QString txt) {
	binpth->setText(txt);
	}
void ScaperDialog::CheckAll(void){}
void ScaperDialog::UncheckAll(void){}


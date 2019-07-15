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
#include <dialog.h>
#include "scaper.h"


ScaperDialog::ScaperDialog(QWidget *parent) :QDialog(parent) {
	bool rv;
    int nWidth = 300;
    int nHeight = 300;
	resize(nWidth, nHeight);
    layout = new QVBoxLayout;
	label = new QLabel;
	
	label->setText("Test Configuration:");

	std::ifstream ifs("splint_options");

	std::string line;
	if(!ifs.is_open()) {
	std::cerr << "Resource file not found " << std::endl;
	}

	while (std::getline(ifs, line)) {
	dbg_prnt << line << std::endl;
	}
	list = new QListWidget(this);
	item = new QListWidgetItem();
	item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
	item->setCheckState(Qt::Unchecked);
	list->setItemWidget(item,new QCheckBox("checkBox"));
	list->addItem(item);
    closeBtn = new QPushButton("Close");
	layout->addWidget(label);
    layout->addWidget(list);
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
	dbg_prnt << "inside " << __func__ << std::endl;
	close();
}

void ScaperDialog::CheckAll(void){}
void ScaperDialog::UncheckAll(void){}

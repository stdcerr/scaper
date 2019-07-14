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
	list = new QListWidget(this);
	item1 = new QListWidgetItem();
	item2 = new QListWidgetItem();
	item3 = new QListWidgetItem();
	item4 = new QListWidgetItem();
	item1->setFlags(item1->flags() | Qt::ItemIsUserCheckable);
	item1->setCheckState(Qt::Unchecked);
	list->setItemWidget(item1,new QCheckBox("checkBox1"));
	list->setItemWidget(item2,new QCheckBox("checkBox2"));
	list->setItemWidget(item3,new QCheckBox("checkBox3"));
	list->setItemWidget(item4,new QCheckBox("checkBox4"));
	list->addItem(item1);
	list->addItem(item2);
	list->addItem(item3);
	list->addItem(item4);
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

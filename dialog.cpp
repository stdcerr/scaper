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


ScaperDialog::ScaperDialog(QWidget *parent, void *p, QString title) :QDialog(parent) {
	bool rv;
    int nWidth = 300;
    int nHeight = 300;
	resize(nWidth, nHeight);
    layout = new QVBoxLayout;
	mlab = new QLabel;
	blab = new QLabel;
	binpth  = new QLineEdit;
    QString optnsf = "splint_options";
	
	mlab->setText(title+" configuration:");
	mlab->setText("binary:");

	if(p)
	binpth->setText(scaper*)p->fname_get());

	std::ifstream ifs(optnsf.toUtf8());

	std::string line;
	if(!ifs.is_open()) {
	std::cerr << "Resource file \"" << std::string(optnsf.toUtf8()) << "\" not found, exit " << std::endl;
    exit(0);
	}

	list = new QListWidget(this);
	while (std::getline(ifs, line)) {
		//dbg_prnt << line << std::endl;
		
		item = new QListWidgetItem();
		item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
		item->setCheckState(Qt::Unchecked);
    	item->setText(QString::fromStdString(line));
		//list->setItemWidget(item,new QCheckBox("checkBox"));
		list->addItem(item);
    }
    closeBtn = new QPushButton("Close");
	layout->addWidget(mlab);
	layout->addWidget(blab);
	layout->addWidget(binpth);
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

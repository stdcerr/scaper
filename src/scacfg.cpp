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

#include "scacfg.h"
#include "scaper.h"

static void chckbxtggl();

scacfg::scacfg(const QString &caption, QWidget *parent,QSettings *config) : QWidget(parent),
           checkBox(new QCheckBox("Enabled")),
           button(new QPushButton(caption))
{
	if(config)
		this->sttngs = config;
	else
		return;
	this->name = caption;
	Qt::CheckState state = (Qt::CheckState) sttngs->value(caption+"/"+CFG_PRFX+"Enable").toInt();
	checkBox->setCheckState(state);
	checkBox->setTristate(false);
	button->setEnabled(state);
    connect(checkBox, &QCheckBox::toggled,
            [=](const int isChecked ) {sttngs->setValue(caption+"/"+CFG_PRFX+"Enable", (isChecked)?2:0);
									   button->setEnabled(isChecked);
									   });
    connect(button, &QPushButton::clicked,
			[=](){ dbg_prnt << "in " << __func__ << std::endl;openDialog(parent);});
            
    auto layout = new QHBoxLayout;
    layout->addWidget(checkBox);
    layout->addWidget(button);
    this->setLayout(layout);
}
//-------------------------------------------------------------------------------------------------

void scacfg::openDialog(QWidget *parent) {
    dbg_prnt << "inside " << __func__ <<std::endl;
	ScaperDialog *inst = new  ScaperDialog(this->name,this->sttngs,parent);
	//inst->fname_set(DFLTPATH);
	inst->nme_set(this->name);
	//data.dialog = inst;
	inst->exec();
}
//-------------------------------------------------------------------------------------------------

void scacfg::setCaption(const QString &caption) { 

	button->setText(caption); 
}
//-------------------------------------------------------------------------------------------------
    
bool scacfg::isChecked() const { 
	return checkBox->isChecked(); 
}
//-------------------------------------------------------------------------------------------------

void scacfg::setChecked(bool ch) { 
	checkBox->setChecked(ch); 
}
//-------------------------------------------------------------------------------------------------

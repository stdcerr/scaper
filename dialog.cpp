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
#include <QtGui>
#include <dialog.h>


ScaperDialog::ScaperDialog(QWidget *parent) :QDialog(parent) {

    int nWidth = 300;
    int nHeight = 300;
	int WidX = 100;
	int WidY = 100;
	resize(nWidth, nHeight);

	list = new QListWidget(this);
	list->setBaseSize(WidX,WidY);
	item = new QListWidgetItem();
	list->setItemWidget(item,new QCheckBox("checkBox"));
	list->addItem(item);
}

void ScaperDialog::CheckAll(void){}
void ScaperDialog::UncheckAll(void){}

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


scacfg::scacfg(const QString &caption = "Click Me", QWidget *parent = nullptr) : QWidget(parent),
           checkBox(new QCheckBox("Enabled")),
           button(new QPushButton(caption))
{
    connect(checkBox, &QCheckBox::toggled,
            button, &QPushButton::setEnabled);
    connect(checkBox, &QCheckBox::toggled,
            this, &scacfg::checkBoxToggled);
    connect(button, &QPushButton::clicked,
            this, &scacfg::buttonClicked);
            
    auto layout = new QHBoxLayout;
    layout->addWidget(checkBox);
    layout->addWidget(button);
    this->setLayout(layout);
}
//-------------------------------------------------------------------------------------------------
    
QString scacfg::caption() const { 

	return button->text(); 

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

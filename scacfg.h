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
#include <QPushButton>
#include <QCheckBox>
#include <QWidget>
#include <QBoxLayout>
#ifndef __SCACFG_H__
#define __SCACFG_H__

class scacfg : public QWidget
{
    Q_OBJECT

public:
    scacfg(const QString &caption, QWidget *parent);/* : QWidget(parent),
            checkBox(new QCheckBox("Enabled")),
            button(new QPushButton(caption)){};*/
    
    
    QString caption() const; 
    void setCaption(const QString &caption);
    
    bool isChecked() const;
    void setChecked(bool ch);
    
signals:
    void checkBoxToggled(bool) const;
    void buttonClicked() const;
    
private:
    QCheckBox *checkBox;
    QPushButton *button;    
};
#endif

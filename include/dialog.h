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
#ifndef __DIALOG_H__
#define __DIALOG_H__

#include <QtWidgets/QDialog>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtGui>
#include <QVBoxLayout>
#include <QtWidgets/QLabel>
#include "scaper.h"

class ScaperDialog: public QDialog
{
    Q_OBJECT
    public:
        ScaperDialog(QString name="", QSettings *set=nullptr, QWidget *parent=nullptr);
		void name_set(QString s) {name = s;}
		QString name_get(void) {return name;}
		void nme_set(QString s) {SCAnme = s;}
		QString nme_get(void) {return SCAnme;}
        ~ScaperDialog(){}

    private slots:
        void CheckAll(void);
        void UncheckAll(void);
		void CloseDialog(void);
		void ChooseBin(void);

    private:
	QString SCAnme;
	QString name;
	QVBoxLayout *layout;
	QLabel *mlab;
	QLabel *blab;
    QSettings *settings;

	QLineEdit *binpth;
    QListWidget *list;
    QListWidgetItem *item;
    //QCheckBox *chkall;
    //QCheckBox *unchkall;
    QPushButton *closeBtn;
    QPushButton *chooseBtn;
    QPushButton *checkallBtn;
    QPushButton *uncheckallBtn;
	QHBoxLayout *hbox;
	QHBoxLayout *chckbox;

    void PathSet(QString);
    QString PathGet();
    void closeEvent(QCloseEvent *event);
	bool isValidKey (QString &key);
        
};

#endif

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
/****************************************************************
**
** Scaper - static code analysis multi Eggler Ron
**
****************************************************************/
#include <QObject>
#include <qapplication.h>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>
#include "ui_scaper.h"
#include "scaper.h"
#include "dialog.h"

int main( int argc, char **argv )
{
    QApplication a( argc, argv );
	QProcess *proc = new QProcess;
    QMainWindow *widget = new QMainWindow;
    scaper *app = new scaper();
	LoadDefaults(app);	
    Ui::MainWindow ui;

    ui.setupUi(widget);
	app->proc = proc;
    app->ui = ui;
    bool rv = OK;
    QObject::connect(ui.checkallPushButton, &QPushButton::clicked, [&] {
                app->ChckBtn();
    });
    QObject::connect(ui.uncheckallPushButton, &QPushButton::clicked, [&] {
                app->UnchckBtn();
    });
    QObject::connect(ui.pathtosplintPushButton, &QPushButton::clicked, [&] {
                app->PthBtn(ui.pathtosplintLineEdit);
    });
    QObject::connect(ui.dialogPushButton, &QPushButton::clicked, [&] {
                app->DialogBtn();
    });
	QObject::connect(ui.checkPushButton, &QPushButton::clicked, [&] {
                app->ChckSCABtn();
    });
    QObject::connect(ui.choosePushButton, &QPushButton::clicked, [&] {
                app->ChooseBtn();
    });
	//QObject::connect(proc, SIGNAL(readyReadStdError()), this, SLOT(updateError()));
	QObject::connect(proc, &QProcess::readyReadStandardError, [&] {
				app->updateError();
	});
	rv = QObject::connect(proc, &QProcess::readyReadStandardOutput, [&] {
				app->updateText();
	});
    if (!rv) {
        std::cerr << "connect() failed: rv:" << rv << std::endl;
    }

    widget->show();
    return a.exec();

        
    return OK;
}
//-------------------------------------------------------------------------------------------------


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
#include "main.h"

int main( int argc, char **argv )
{
    QApplication a( argc, argv );
	QProcess *proc = new QProcess;
    QMainWindow *widget = new QMainWindow;
    scaper *app = new scaper;
    Ui::MainWindow ui;

	int_opt(argc, argv);

    ui.setupUi(widget);
	LoadDefaults(app,ui);
	app->proc = proc;
    app->ui = ui;
    bool rv = OK;
    QObject::connect(ui.SplintDialogPushButton, &QPushButton::clicked, [&] {
                app->SplintDialogBtn();
    });
	QObject::connect(ui.checkPushButton, &QPushButton::clicked, [&] {
                app->ChckSCABtn();
    });
	QObject::connect(proc, &QProcess::readyReadStandardError, [&] {
				app->updateError(proc);
	});
	rv = QObject::connect(proc, &QProcess::readyReadStandardOutput, [&] {
				app->updateText(proc);
	});
    if (!rv) {
        std::cerr << "connect() failed: rv:" << rv << std::endl;
    }

    widget->show();
    return a.exec();

        
    return OK;
}
//-------------------------------------------------------------------------------------------------

int int_opt(int argc, char *argv[]) {
/*
	while((opt = getopt(argc, argv, “:if:lrx”)) != -1)  
    {  
        switch(opt)  
        {  
            case ‘i’:  
            case ‘l’:  
            case ‘r’:  
                printf(“option: %c\n”, opt);  
                break;  
            case ‘f’:  
                printf(“filename: %s\n”, optarg);  
                break;  
            case ‘:’:  
                printf(“option needs a value\n”);  
                break;  
            case ‘?’:  
                printf(“unknown option: %c\n”, optopt); 
                break;  
        }  
    }  
      
    // optind is for the extra arguments 
    // which are not parsed 
    for(; optind < argc; optind++){      
        printf(“extra arguments: %s\n”, argv[optind]);  
    }*/
return OK;
}

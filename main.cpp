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
#include <stdio.h>     
#include <stdlib.h>    
#include <getopt.h>    
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
    Ui::MainWindow ui;
	int no_gui = 0;
	int_opt(argc, argv, &no_gui);

    if (!no_gui) {
	ui.setupUi(widget);
	scaper *app = new scaper(widget);
	app->pname_set(argv[0]);
	LoadDefaults(app);
	app->proc = proc;
    app->ui = ui;
    QObject::connect(ui.SplintDialogPushButton, &QPushButton::clicked, [&] {
                app->SplintDialogBtn();
    });
	QObject::connect(ui.checkPushButton, &QPushButton::clicked, [&] {
                app->ChckSCABtn();
    });
	QObject::connect(proc, &QProcess::readyReadStandardError, [&] {
				app->updateError(proc);
	});
	QObject::connect(proc, &QProcess::readyReadStandardOutput, [&] {
				app->updateText(proc);
	});

    widget->show();
    return a.exec();
	} else {
		std::cout << "--no-gui option supplied" <<std::endl;
	}

        
    return OK;
}
//-------------------------------------------------------------------------------------------------

int int_opt (int argc, char **argv, int *no_gui) {
    int c;
    int digit_optind = 0;
    int aopt = 0, bopt = 0;
    char *copt = 0, *dopt = 0;
    struct option long_options[] = {
        {"add", 1, 0, 0},
        {"append", 0, 0, 0},
        {"delete", 1, 0, 0},
        {"verbose", 0, 0, 0},
        {"create", 1, 0, 'c'},
        {"file", 1, 0, 0},
        {"debug",0, 0, 'd'},
        {"no-gui",0, no_gui, 1},
        {NULL, 0, NULL, 0}
    };
    int option_index = 0;
    while ((c = getopt_long(argc, argv, "abc:d:012",
                 long_options, &option_index)) != -1) {
        int this_option_optind = optind ? optind : 1;
        switch (c) {
        case 0:
            printf ("option %s", long_options[option_index].name);
            if (optarg)
                printf (" with arg %s", optarg);
            printf ("\n");
            break;
        case '0':
        case '1':
        case '2':
            if (digit_optind != 0 && digit_optind != this_option_optind)
              printf ("digits occur in two different argv-elements.\n");
            digit_optind = this_option_optind;
            printf ("option %c\n", c);
            break;
        case 'a':
            printf ("option a\n");
            aopt = 1;
            break;
        case 'b':
            printf ("option b\n");
            bopt = 1;
            break;
        case 'c':
            printf ("option c with value '%s'\n", optarg);
            copt = optarg;
            break;
        case 'd':
            printf ("option d with value '%s'\n", optarg);
            dopt = optarg;
            break;
        case '?':
            break;
        default:
            printf ("?? getopt returned character code 0%o ??\n", c);
        }
    }
    if (optind < argc) {
        printf ("non-option ARGV-elements: ");
        while (optind < argc)
            printf ("%s ", argv[optind++]);
        printf ("\n");
        
    }
    return OK;
}

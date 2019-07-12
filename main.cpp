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
    QMainWindow *widget = new QMainWindow;
    scaper *app = new scaper;
    Ui::MainWindow ui;

    ui.setupUi(widget);
    app->ui = ui;
    bool rv = OK;
    QObject::connect(ui.checkallPushButton, &QPushButton::clicked, [&] {
                app->ChckBtn();
    });
    QObject::connect(ui.uncheckallPushButton, &QPushButton::clicked, [&] {
                app->UnchckBtn();
    });
    rv = QObject::connect(ui.pathtosplintPushButton, &QPushButton::clicked, [&] {
                app->PthBtn();
    });
rv = QObject::connect(ui.dialogPushButton, &QPushButton::clicked, [&] {
                app->DialogBtn();
    });
    if (!rv) {
        std::cerr << "connect() failed: rv:" << rv << std::endl;
    }

    widget->show();
    return a.exec();

        
    return OK;
}
//-------------------------------------------------------------------------------------------------


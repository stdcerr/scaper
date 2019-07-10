/****************************************************************
**
** Scaper - static code analysis multi Eggler Ron
**
****************************************************************/

#include <iostream>
#include <QObject>
#include <qapplication.h>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include "ui_scaper.h"
#include "scaper.h"


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
    if (!rv) {
        std::cerr << "connect() failed: rv:" << rv << std::endl;
    }

    widget->show();
    return a.exec();

        
    return OK;
}

void scaper::UnchckBtn(void) {
    std::cout << "inside " << __func__ <<std::endl;
    if (!uncheckall(ui.SplintOptionsGroupBox))
        std::cout << "all unchecked!" << std::endl;
    QMessageBox msgBox;
    msgBox.setText("test!");
    msgBox.show();
}
void scaper::ChckBtn(void) {
    std::cout << "inside " << __func__ <<std::endl;
    if (!checkall(ui.SplintOptionsGroupBox))
        std::cout << "all checked!" << std::endl;
    QMessageBox msgBox;
    msgBox.setText("test!");
    msgBox.show();
}
void scaper::PthBtn(void) {
    std::cout << "inside " << __func__ <<std::endl;
    QString fname = QFileDialog::getOpenFileName(nullptr,
        "Path to splint", "/usr/bin", "All Files (*.*)");
}
int scaper::checkall(QObject *parentWidget) {
    int rv = OK;
    QList<QCheckBox *>list = parentWidget->findChildren<QCheckBox *>();
    QCheckBox chk;
    QList<QCheckBox *>::iterator i;
    for(i = list.begin();i != list.end(); i++) {
        std::cout << (*i)->text().toStdString() << std::endl;
        (*i)->setChecked(true);
    }
    return rv;
}

int scaper::uncheckall(QObject *parentWidget) {
    int rv = OK;
    QList<QCheckBox *>list = parentWidget->findChildren<QCheckBox *>();
    QCheckBox chk;
    QList<QCheckBox *>::iterator i;
    for(i = list.begin();i != list.end(); i++) {
        std::cout << (*i)->text().toStdString() << std::endl;
        (*i)->setChecked(false);
    }
    return rv;
}

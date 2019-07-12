#include <QtWidgets/QFileDialog>
#include "ui_scaper.h"
#include "scaper.h"

void scaper::DialogBtn(void) {
    std::cout << "inside " << __func__ <<std::endl;
    if (!dialogShow(ui.centralwidget)) {
        std::cout << "Testdialog showed!" << std::endl;
    }
}
//-------------------------------------------------------------------------------------------------

void scaper::UnchckBtn(void) {
    std::cout << "inside " << __func__ <<std::endl;
    if (!uncheckall(ui.SplintOptionsGroupBox))
        std::cout << "all unchecked!" << std::endl;
}
//-------------------------------------------------------------------------------------------------

void scaper::ChckBtn(void) {
    std::cout << "inside " << __func__ <<std::endl;
    if (!checkall(ui.SplintOptionsGroupBox))
        std::cout << "all checked!" << std::endl;
}
//-------------------------------------------------------------------------------------------------

void scaper::ChckSCABtn(void) {
    std::cout << "inside " << __func__ <<std::endl;
    if (!runsca(ui.OutputTextEdit))
        std::cout << "SCA invoked!" << std::endl;
}
//-------------------------------------------------------------------------------------------------

void scaper::PthBtn(QLineEdit *edit) {
    std::cout << "inside " << __func__ <<std::endl;
    fname_set(QFileDialog::getOpenFileName(nullptr,
        "Path to splint", "/usr/bin", "All Files (*.*)"));
    if(edit)
        edit->setText(fname_get());
}
//-------------------------------------------------------------------------------------------------

int scaper::checkall(QObject *parentWidget) {
    int rv = OK;
    QList<QCheckBox *>list = parentWidget->findChildren<QCheckBox *>();
    QCheckBox chk;
    QList<QCheckBox *>::iterator i;
    for(i = list.begin();i != list.end(); i++) {
        std::cout <<(*i)->text().toStdString() << std::endl;
        (*i)->setChecked(true);
    }
    return rv;
}
//-------------------------------------------------------------------------------------------------

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
//-------------------------------------------------------------------------------------------------

int scaper::dialogShow(QWidget *parent) {
    int rv = OK;
    std::cout << "inside " << __func__ <<std::endl;
    //ScaperDialog *dialog = ScaperDialog(parent);
    //dialog->show();
    ScaperDialog dialog(parent);
    dialog.show();
    return rv;
}
//-------------------------------------------------------------------------------------------------

int scaper::runsca(QTextEdit *out) {

}

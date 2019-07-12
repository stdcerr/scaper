#include <QtGui>
#include <dialog.h>


ScaperDialog::ScaperDialog(QWidget *parent) :QDialog(parent) {

list = new QListWidget(parent);
item = new QListWidgetItem();
list->setItemWidget(item,new QCheckBox("checkBox"));
list->addItem(item);
}

void ScaperDialog::CheckAll(void){}
void ScaperDialog::UncheckAll(void){}

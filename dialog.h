#ifndef __DIALOG_H__
#define __DIALOG_H__

#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>

class ScaperDialog: public QDialog
{
    Q_OBJECT
    public:
        ScaperDialog(QWidget *parent = 0);

        ~ScaperDialog(){}

    private slots:
        void CheckAll();
        void UncheckAll();

    private:
        QListWidget *list;
        QCheckBox *chkall;
        QCheckBox *unchkall;
        QPushButton *closeBtn;
        QListWidgetItem *item;
        
};

#endif

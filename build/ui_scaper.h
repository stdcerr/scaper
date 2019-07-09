/********************************************************************************
** Form generated from reading UI file 'scaper.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCAPER_H
#define UI_SCAPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *actionAboutQt;
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QTextEdit *OutputTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *FilesLineEdit;
    QPushButton *ChoosePushButton;
    QPushButton *CheckPushButton;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *weakModeRadioButton;
    QRadioButton *standardModeRadioButton;
    QRadioButton *checksModeRadioButton;
    QRadioButton *strictModeRadioButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *includedirsLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *definesLineEdit;
    QSpacerItem *verticalSpacer;
    QGroupBox *SplintOptionsGroupBox;
    QGridLayout *gridLayout_2;
    QPushButton *pathtosplintPushButton;
    QCheckBox *varuseCheckBox;
    QCheckBox *compdefCheckBox;
    QCheckBox *usedefCheckBox;
    QCheckBox *matchanyintegralCheckBox;
    QCheckBox *imptypeCheckBox;
    QCheckBox *ptrnegateCheckBox;
    QCheckBox *bufferoverflowhighCheckBox;
    QCheckBox *typeCheckBox;
    QCheckBox *mayaliasuniqueCheckBox;
    QCheckBox *trytorecoverCheckBox;
    QCheckBox *boolopsCheckBox;
    QCheckBox *nullpassCheckBox;
    QFrame *line;
    QCheckBox *nullderefCheckBox;
    QFrame *line_2;
    QLineEdit *pathtosplintLineEdit;
    QLabel *pathtosplintLabel;
    QCheckBox *globstateCheckBox;
    QCheckBox *formattypeCheckBox;
    QCheckBox *onlytransCheckBox;
    QCheckBox *globsCheckBox;
    QCheckBox *exportlocalCheckBox;
    QCheckBox *posixlibCheckBox;
    QCheckBox *unixlibCheckBox;
    QCheckBox *warnposixCheckBox;
    QCheckBox *posixstrictlibCheckBox;
    QCheckBox *preprocCheckBox;
    QCheckBox *mustfreefreshCheckBox;
    QCheckBox *unrecogCheckBox;
    QCheckBox *branchstateCheckBox;
    QCheckBox *nullretCheckBox;
    QCheckBox *retvalotherCheckBox;
    QCheckBox *retvalintCheckBox;
    QCheckBox *predboolothersCheckBox;
    QCheckBox *namechecksCheckBox;
    QCheckBox *isoreservedCheckBox;
    QCheckBox *isolibCheckBox;
    QCheckBox *exportfcnCheckBox;
    QCheckBox *gnuextensionsCheckBox;
    QCheckBox *paramuseCheckBox;
    QCheckBox *exportheaderCheckBox;
    QCheckBox *temptransCheckBox;
    QCheckBox *declundefCheckBox;
    QCheckBox *nullassignCheckBox;
    QCheckBox *formatconstCheckBox;
    QCheckBox *readonlytransCheckBox;
    QCheckBox *compdestroyCheckBox;
    QCheckBox *noeffectCheckBox;
    QPushButton *uncheckallPushButton;
    QPushButton *checkallPushButton;
    QSpacerItem *horizontalSpacer;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuSplint_GUI;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1095, 600);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAboutQt = new QAction(MainWindow);
        actionAboutQt->setObjectName(QStringLiteral("actionAboutQt"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        OutputTextEdit = new QTextEdit(tab);
        OutputTextEdit->setObjectName(QStringLiteral("OutputTextEdit"));
        OutputTextEdit->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        gridLayout->addWidget(OutputTextEdit, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        FilesLineEdit = new QLineEdit(tab);
        FilesLineEdit->setObjectName(QStringLiteral("FilesLineEdit"));

        horizontalLayout_3->addWidget(FilesLineEdit);

        ChoosePushButton = new QPushButton(tab);
        ChoosePushButton->setObjectName(QStringLiteral("ChoosePushButton"));

        horizontalLayout_3->addWidget(ChoosePushButton);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        CheckPushButton = new QPushButton(tab);
        CheckPushButton->setObjectName(QStringLiteral("CheckPushButton"));

        gridLayout->addWidget(CheckPushButton, 2, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        weakModeRadioButton = new QRadioButton(groupBox);
        weakModeRadioButton->setObjectName(QStringLiteral("weakModeRadioButton"));

        horizontalLayout->addWidget(weakModeRadioButton);

        standardModeRadioButton = new QRadioButton(groupBox);
        standardModeRadioButton->setObjectName(QStringLiteral("standardModeRadioButton"));
        standardModeRadioButton->setChecked(true);

        horizontalLayout->addWidget(standardModeRadioButton);

        checksModeRadioButton = new QRadioButton(groupBox);
        checksModeRadioButton->setObjectName(QStringLiteral("checksModeRadioButton"));

        horizontalLayout->addWidget(checksModeRadioButton);

        strictModeRadioButton = new QRadioButton(groupBox);
        strictModeRadioButton->setObjectName(QStringLiteral("strictModeRadioButton"));

        horizontalLayout->addWidget(strictModeRadioButton);


        gridLayout_5->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        includedirsLineEdit = new QLineEdit(groupBox_2);
        includedirsLineEdit->setObjectName(QStringLiteral("includedirsLineEdit"));

        horizontalLayout_2->addWidget(includedirsLineEdit);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        definesLineEdit = new QLineEdit(groupBox_2);
        definesLineEdit->setObjectName(QStringLiteral("definesLineEdit"));

        horizontalLayout_4->addWidget(definesLineEdit);


        gridLayout_3->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_2, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(858, 51, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 3, 0, 1, 1);

        SplintOptionsGroupBox = new QGroupBox(tab_2);
        SplintOptionsGroupBox->setObjectName(QStringLiteral("SplintOptionsGroupBox"));
        gridLayout_2 = new QGridLayout(SplintOptionsGroupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pathtosplintPushButton = new QPushButton(SplintOptionsGroupBox);
        pathtosplintPushButton->setObjectName(QStringLiteral("pathtosplintPushButton"));

        gridLayout_2->addWidget(pathtosplintPushButton, 0, 4, 1, 1);

        varuseCheckBox = new QCheckBox(SplintOptionsGroupBox);
        varuseCheckBox->setObjectName(QStringLiteral("varuseCheckBox"));

        gridLayout_2->addWidget(varuseCheckBox, 13, 3, 1, 1);

        compdefCheckBox = new QCheckBox(SplintOptionsGroupBox);
        compdefCheckBox->setObjectName(QStringLiteral("compdefCheckBox"));

        gridLayout_2->addWidget(compdefCheckBox, 5, 1, 1, 1);

        usedefCheckBox = new QCheckBox(SplintOptionsGroupBox);
        usedefCheckBox->setObjectName(QStringLiteral("usedefCheckBox"));

        gridLayout_2->addWidget(usedefCheckBox, 5, 3, 1, 1);

        matchanyintegralCheckBox = new QCheckBox(SplintOptionsGroupBox);
        matchanyintegralCheckBox->setObjectName(QStringLiteral("matchanyintegralCheckBox"));

        gridLayout_2->addWidget(matchanyintegralCheckBox, 7, 1, 1, 1);

        imptypeCheckBox = new QCheckBox(SplintOptionsGroupBox);
        imptypeCheckBox->setObjectName(QStringLiteral("imptypeCheckBox"));

        gridLayout_2->addWidget(imptypeCheckBox, 7, 3, 1, 1);

        ptrnegateCheckBox = new QCheckBox(SplintOptionsGroupBox);
        ptrnegateCheckBox->setObjectName(QStringLiteral("ptrnegateCheckBox"));

        gridLayout_2->addWidget(ptrnegateCheckBox, 11, 1, 1, 1);

        bufferoverflowhighCheckBox = new QCheckBox(SplintOptionsGroupBox);
        bufferoverflowhighCheckBox->setObjectName(QStringLiteral("bufferoverflowhighCheckBox"));

        gridLayout_2->addWidget(bufferoverflowhighCheckBox, 11, 3, 1, 1);

        typeCheckBox = new QCheckBox(SplintOptionsGroupBox);
        typeCheckBox->setObjectName(QStringLiteral("typeCheckBox"));

        gridLayout_2->addWidget(typeCheckBox, 12, 0, 1, 1);

        mayaliasuniqueCheckBox = new QCheckBox(SplintOptionsGroupBox);
        mayaliasuniqueCheckBox->setObjectName(QStringLiteral("mayaliasuniqueCheckBox"));

        gridLayout_2->addWidget(mayaliasuniqueCheckBox, 12, 1, 1, 1);

        trytorecoverCheckBox = new QCheckBox(SplintOptionsGroupBox);
        trytorecoverCheckBox->setObjectName(QStringLiteral("trytorecoverCheckBox"));

        gridLayout_2->addWidget(trytorecoverCheckBox, 10, 5, 1, 1);

        boolopsCheckBox = new QCheckBox(SplintOptionsGroupBox);
        boolopsCheckBox->setObjectName(QStringLiteral("boolopsCheckBox"));

        gridLayout_2->addWidget(boolopsCheckBox, 12, 3, 1, 1);

        nullpassCheckBox = new QCheckBox(SplintOptionsGroupBox);
        nullpassCheckBox->setObjectName(QStringLiteral("nullpassCheckBox"));

        gridLayout_2->addWidget(nullpassCheckBox, 13, 0, 1, 1);

        line = new QFrame(SplintOptionsGroupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 2, 0, 1, 8);

        nullderefCheckBox = new QCheckBox(SplintOptionsGroupBox);
        nullderefCheckBox->setObjectName(QStringLiteral("nullderefCheckBox"));

        gridLayout_2->addWidget(nullderefCheckBox, 13, 1, 1, 1);

        line_2 = new QFrame(SplintOptionsGroupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 0, 1, 1, 1);

        pathtosplintLineEdit = new QLineEdit(SplintOptionsGroupBox);
        pathtosplintLineEdit->setObjectName(QStringLiteral("pathtosplintLineEdit"));

        gridLayout_2->addWidget(pathtosplintLineEdit, 0, 3, 1, 1);

        pathtosplintLabel = new QLabel(SplintOptionsGroupBox);
        pathtosplintLabel->setObjectName(QStringLiteral("pathtosplintLabel"));

        gridLayout_2->addWidget(pathtosplintLabel, 0, 2, 1, 1);

        globstateCheckBox = new QCheckBox(SplintOptionsGroupBox);
        globstateCheckBox->setObjectName(QStringLiteral("globstateCheckBox"));

        gridLayout_2->addWidget(globstateCheckBox, 5, 4, 1, 1);

        formattypeCheckBox = new QCheckBox(SplintOptionsGroupBox);
        formattypeCheckBox->setObjectName(QStringLiteral("formattypeCheckBox"));

        gridLayout_2->addWidget(formattypeCheckBox, 5, 6, 1, 1);

        onlytransCheckBox = new QCheckBox(SplintOptionsGroupBox);
        onlytransCheckBox->setObjectName(QStringLiteral("onlytransCheckBox"));

        gridLayout_2->addWidget(onlytransCheckBox, 7, 6, 1, 1);

        globsCheckBox = new QCheckBox(SplintOptionsGroupBox);
        globsCheckBox->setObjectName(QStringLiteral("globsCheckBox"));

        gridLayout_2->addWidget(globsCheckBox, 11, 6, 1, 1);

        exportlocalCheckBox = new QCheckBox(SplintOptionsGroupBox);
        exportlocalCheckBox->setObjectName(QStringLiteral("exportlocalCheckBox"));

        gridLayout_2->addWidget(exportlocalCheckBox, 13, 6, 1, 1);

        posixlibCheckBox = new QCheckBox(SplintOptionsGroupBox);
        posixlibCheckBox->setObjectName(QStringLiteral("posixlibCheckBox"));

        gridLayout_2->addWidget(posixlibCheckBox, 7, 0, 1, 1);

        unixlibCheckBox = new QCheckBox(SplintOptionsGroupBox);
        unixlibCheckBox->setObjectName(QStringLiteral("unixlibCheckBox"));

        gridLayout_2->addWidget(unixlibCheckBox, 5, 0, 1, 1);

        warnposixCheckBox = new QCheckBox(SplintOptionsGroupBox);
        warnposixCheckBox->setObjectName(QStringLiteral("warnposixCheckBox"));

        gridLayout_2->addWidget(warnposixCheckBox, 11, 0, 1, 1);

        posixstrictlibCheckBox = new QCheckBox(SplintOptionsGroupBox);
        posixstrictlibCheckBox->setObjectName(QStringLiteral("posixstrictlibCheckBox"));

        gridLayout_2->addWidget(posixstrictlibCheckBox, 10, 0, 1, 1);

        preprocCheckBox = new QCheckBox(SplintOptionsGroupBox);
        preprocCheckBox->setObjectName(QStringLiteral("preprocCheckBox"));

        gridLayout_2->addWidget(preprocCheckBox, 10, 1, 1, 1);

        mustfreefreshCheckBox = new QCheckBox(SplintOptionsGroupBox);
        mustfreefreshCheckBox->setObjectName(QStringLiteral("mustfreefreshCheckBox"));

        gridLayout_2->addWidget(mustfreefreshCheckBox, 10, 6, 1, 1);

        unrecogCheckBox = new QCheckBox(SplintOptionsGroupBox);
        unrecogCheckBox->setObjectName(QStringLiteral("unrecogCheckBox"));

        gridLayout_2->addWidget(unrecogCheckBox, 10, 3, 1, 1);

        branchstateCheckBox = new QCheckBox(SplintOptionsGroupBox);
        branchstateCheckBox->setObjectName(QStringLiteral("branchstateCheckBox"));

        gridLayout_2->addWidget(branchstateCheckBox, 10, 7, 1, 1);

        nullretCheckBox = new QCheckBox(SplintOptionsGroupBox);
        nullretCheckBox->setObjectName(QStringLiteral("nullretCheckBox"));

        gridLayout_2->addWidget(nullretCheckBox, 11, 7, 1, 1);

        retvalotherCheckBox = new QCheckBox(SplintOptionsGroupBox);
        retvalotherCheckBox->setObjectName(QStringLiteral("retvalotherCheckBox"));

        gridLayout_2->addWidget(retvalotherCheckBox, 13, 7, 1, 1);

        retvalintCheckBox = new QCheckBox(SplintOptionsGroupBox);
        retvalintCheckBox->setObjectName(QStringLiteral("retvalintCheckBox"));

        gridLayout_2->addWidget(retvalintCheckBox, 12, 7, 1, 1);

        predboolothersCheckBox = new QCheckBox(SplintOptionsGroupBox);
        predboolothersCheckBox->setObjectName(QStringLiteral("predboolothersCheckBox"));

        gridLayout_2->addWidget(predboolothersCheckBox, 12, 6, 1, 1);

        namechecksCheckBox = new QCheckBox(SplintOptionsGroupBox);
        namechecksCheckBox->setObjectName(QStringLiteral("namechecksCheckBox"));

        gridLayout_2->addWidget(namechecksCheckBox, 5, 7, 1, 1);

        isoreservedCheckBox = new QCheckBox(SplintOptionsGroupBox);
        isoreservedCheckBox->setObjectName(QStringLiteral("isoreservedCheckBox"));

        gridLayout_2->addWidget(isoreservedCheckBox, 7, 7, 1, 1);

        isolibCheckBox = new QCheckBox(SplintOptionsGroupBox);
        isolibCheckBox->setObjectName(QStringLiteral("isolibCheckBox"));

        gridLayout_2->addWidget(isolibCheckBox, 14, 0, 1, 1);

        exportfcnCheckBox = new QCheckBox(SplintOptionsGroupBox);
        exportfcnCheckBox->setObjectName(QStringLiteral("exportfcnCheckBox"));

        gridLayout_2->addWidget(exportfcnCheckBox, 14, 1, 1, 1);

        gnuextensionsCheckBox = new QCheckBox(SplintOptionsGroupBox);
        gnuextensionsCheckBox->setObjectName(QStringLiteral("gnuextensionsCheckBox"));

        gridLayout_2->addWidget(gnuextensionsCheckBox, 14, 3, 1, 1);

        paramuseCheckBox = new QCheckBox(SplintOptionsGroupBox);
        paramuseCheckBox->setObjectName(QStringLiteral("paramuseCheckBox"));

        gridLayout_2->addWidget(paramuseCheckBox, 14, 6, 1, 1);

        exportheaderCheckBox = new QCheckBox(SplintOptionsGroupBox);
        exportheaderCheckBox->setObjectName(QStringLiteral("exportheaderCheckBox"));

        gridLayout_2->addWidget(exportheaderCheckBox, 14, 7, 1, 1);

        temptransCheckBox = new QCheckBox(SplintOptionsGroupBox);
        temptransCheckBox->setObjectName(QStringLiteral("temptransCheckBox"));

        gridLayout_2->addWidget(temptransCheckBox, 7, 5, 1, 1);

        declundefCheckBox = new QCheckBox(SplintOptionsGroupBox);
        declundefCheckBox->setObjectName(QStringLiteral("declundefCheckBox"));

        gridLayout_2->addWidget(declundefCheckBox, 5, 5, 1, 1);

        nullassignCheckBox = new QCheckBox(SplintOptionsGroupBox);
        nullassignCheckBox->setObjectName(QStringLiteral("nullassignCheckBox"));

        gridLayout_2->addWidget(nullassignCheckBox, 11, 5, 1, 1);

        formatconstCheckBox = new QCheckBox(SplintOptionsGroupBox);
        formatconstCheckBox->setObjectName(QStringLiteral("formatconstCheckBox"));

        gridLayout_2->addWidget(formatconstCheckBox, 12, 5, 1, 1);

        readonlytransCheckBox = new QCheckBox(SplintOptionsGroupBox);
        readonlytransCheckBox->setObjectName(QStringLiteral("readonlytransCheckBox"));

        gridLayout_2->addWidget(readonlytransCheckBox, 13, 5, 1, 1);

        compdestroyCheckBox = new QCheckBox(SplintOptionsGroupBox);
        compdestroyCheckBox->setObjectName(QStringLiteral("compdestroyCheckBox"));

        gridLayout_2->addWidget(compdestroyCheckBox, 7, 4, 1, 1);

        noeffectCheckBox = new QCheckBox(SplintOptionsGroupBox);
        noeffectCheckBox->setObjectName(QStringLiteral("noeffectCheckBox"));

        gridLayout_2->addWidget(noeffectCheckBox, 14, 5, 1, 1);

        uncheckallPushButton = new QPushButton(SplintOptionsGroupBox);
        uncheckallPushButton->setObjectName(QStringLiteral("uncheckallPushButton"));

        gridLayout_2->addWidget(uncheckallPushButton, 0, 7, 1, 1);

        checkallPushButton = new QPushButton(SplintOptionsGroupBox);
        checkallPushButton->setObjectName(QStringLiteral("checkallPushButton"));

        gridLayout_2->addWidget(checkallPushButton, 0, 6, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);


        gridLayout_5->addWidget(SplintOptionsGroupBox, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_4->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1095, 24));
        menuSplint_GUI = new QMenu(menubar);
        menuSplint_GUI->setObjectName(QStringLiteral("menuSplint_GUI"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuSplint_GUI->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuSplint_GUI->addAction(actionQuit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAboutQt);

        retranslateUi(MainWindow);
        QObject::connect(checkallPushButton, SIGNAL(clicked()), SplintOptionsGroupBox, SLOT(setFocus()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "&About SplintGUI", 0));
        actionAboutQt->setText(QApplication::translate("MainWindow", "A&boutQt", 0));
        label_2->setText(QApplication::translate("MainWindow", "Files:", 0));
        ChoosePushButton->setText(QApplication::translate("MainWindow", "Choose...", 0));
        CheckPushButton->setText(QApplication::translate("MainWindow", "Check!", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Check", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Check mode", 0));
        weakModeRadioButton->setText(QApplication::translate("MainWindow", "wea&k", 0));
        standardModeRadioButton->setText(QApplication::translate("MainWindow", "standard", 0));
        checksModeRadioButton->setText(QApplication::translate("MainWindow", "checks", 0));
        strictModeRadioButton->setText(QApplication::translate("MainWindow", "strict", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Compiler options", 0));
        label_3->setText(QApplication::translate("MainWindow", "Include dirs (e.g. -I<dir1> -I<dir2>:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Defines (e.g. -DDEBUG=1):", 0));
        SplintOptionsGroupBox->setTitle(QApplication::translate("MainWindow", "Splint options", 0));
        pathtosplintPushButton->setText(QApplication::translate("MainWindow", "Choose...", 0));
        varuseCheckBox->setText(QApplication::translate("MainWindow", "varuse", 0));
        compdefCheckBox->setText(QApplication::translate("MainWindow", "compdef", 0));
        usedefCheckBox->setText(QApplication::translate("MainWindow", "usedef", 0));
        matchanyintegralCheckBox->setText(QApplication::translate("MainWindow", "matchanyintegral", 0));
        imptypeCheckBox->setText(QApplication::translate("MainWindow", "imptype", 0));
        ptrnegateCheckBox->setText(QApplication::translate("MainWindow", "ptrnegate", 0));
        bufferoverflowhighCheckBox->setText(QApplication::translate("MainWindow", "bufferoverflowhigh", 0));
        typeCheckBox->setText(QApplication::translate("MainWindow", "type", 0));
        mayaliasuniqueCheckBox->setText(QApplication::translate("MainWindow", "mayaliasunique", 0));
        trytorecoverCheckBox->setText(QApplication::translate("MainWindow", "trytorecover", 0));
        boolopsCheckBox->setText(QApplication::translate("MainWindow", "boolops", 0));
        nullpassCheckBox->setText(QApplication::translate("MainWindow", "nullpass", 0));
        nullderefCheckBox->setText(QApplication::translate("MainWindow", "nullderef", 0));
        pathtosplintLabel->setText(QApplication::translate("MainWindow", "Path to splint:", 0));
        globstateCheckBox->setText(QApplication::translate("MainWindow", "globstate", 0));
        formattypeCheckBox->setText(QApplication::translate("MainWindow", "formattype", 0));
        onlytransCheckBox->setText(QApplication::translate("MainWindow", "onlytrans", 0));
        globsCheckBox->setText(QApplication::translate("MainWindow", "globs", 0));
        exportlocalCheckBox->setText(QApplication::translate("MainWindow", "exportlocal", 0));
        posixlibCheckBox->setText(QApplication::translate("MainWindow", "posixlib", 0));
        unixlibCheckBox->setText(QApplication::translate("MainWindow", "unixlib", 0));
        warnposixCheckBox->setText(QApplication::translate("MainWindow", "warnposix", 0));
        posixstrictlibCheckBox->setText(QApplication::translate("MainWindow", "posixstrictlib", 0));
        preprocCheckBox->setText(QApplication::translate("MainWindow", "preproc", 0));
        mustfreefreshCheckBox->setText(QApplication::translate("MainWindow", "mustfreefresh", 0));
        unrecogCheckBox->setText(QApplication::translate("MainWindow", "unrecog", 0));
        branchstateCheckBox->setText(QApplication::translate("MainWindow", "branchstate", 0));
        nullretCheckBox->setText(QApplication::translate("MainWindow", "nullret", 0));
        retvalotherCheckBox->setText(QApplication::translate("MainWindow", "retvalother", 0));
        retvalintCheckBox->setText(QApplication::translate("MainWindow", "retvalint", 0));
        predboolothersCheckBox->setText(QApplication::translate("MainWindow", "predboolothers", 0));
        namechecksCheckBox->setText(QApplication::translate("MainWindow", "namechecks", 0));
        isoreservedCheckBox->setText(QApplication::translate("MainWindow", "isoreserved", 0));
        isolibCheckBox->setText(QApplication::translate("MainWindow", "isolib", 0));
        exportfcnCheckBox->setText(QApplication::translate("MainWindow", "exportfcn", 0));
        gnuextensionsCheckBox->setText(QApplication::translate("MainWindow", "gnuextensions", 0));
        paramuseCheckBox->setText(QApplication::translate("MainWindow", "paramuse", 0));
        exportheaderCheckBox->setText(QApplication::translate("MainWindow", "exportheader", 0));
        temptransCheckBox->setText(QApplication::translate("MainWindow", "temptrans", 0));
        declundefCheckBox->setText(QApplication::translate("MainWindow", "declundef", 0));
        nullassignCheckBox->setText(QApplication::translate("MainWindow", "nullassign", 0));
        formatconstCheckBox->setText(QApplication::translate("MainWindow", "formatconst", 0));
        readonlytransCheckBox->setText(QApplication::translate("MainWindow", "readonlytrans", 0));
        compdestroyCheckBox->setText(QApplication::translate("MainWindow", "compdestroy", 0));
        noeffectCheckBox->setText(QApplication::translate("MainWindow", "noeffect", 0));
        uncheckallPushButton->setText(QApplication::translate("MainWindow", "Uncheck All", 0));
        checkallPushButton->setText(QApplication::translate("MainWindow", "Check All", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Options", 0));
        menuSplint_GUI->setTitle(QApplication::translate("MainWindow", "Fi&le", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCAPER_H

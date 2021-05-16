/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen;
    QAction *actionsave;
    QAction *actioncopy;
    QAction *actionpaste;
    QAction *actionaboutqt;
    QAction *actionnew;
    QAction *actioncut;
    QWidget *centralwidget;
    QPushButton *hintBtn;
    QToolButton *aboutQtBtn;
    QToolButton *newBtn;
    QPushButton *openBtn;
    QMenuBar *menubar;
    QMenu *menufile;
    QMenu *menuedit;
    QMenu *menuabout;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(672, 410);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionopen->setIcon(icon);
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsave->setIcon(icon1);
        actioncopy = new QAction(MainWindow);
        actioncopy->setObjectName(QString::fromUtf8("actioncopy"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioncopy->setIcon(icon2);
        actionpaste = new QAction(MainWindow);
        actionpaste->setObjectName(QString::fromUtf8("actionpaste"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionpaste->setIcon(icon3);
        actionaboutqt = new QAction(MainWindow);
        actionaboutqt->setObjectName(QString::fromUtf8("actionaboutqt"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/qt_32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionaboutqt->setIcon(icon4);
        actionnew = new QAction(MainWindow);
        actionnew->setObjectName(QString::fromUtf8("actionnew"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionnew->setIcon(icon5);
        actioncut = new QAction(MainWindow);
        actioncut->setObjectName(QString::fromUtf8("actioncut"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/image/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioncut->setIcon(icon6);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hintBtn = new QPushButton(centralwidget);
        hintBtn->setObjectName(QString::fromUtf8("hintBtn"));
        hintBtn->setGeometry(QRect(330, 160, 71, 31));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        hintBtn->setIcon(icon7);
        aboutQtBtn = new QToolButton(centralwidget);
        aboutQtBtn->setObjectName(QString::fromUtf8("aboutQtBtn"));
        aboutQtBtn->setGeometry(QRect(330, 100, 71, 31));
        aboutQtBtn->setIcon(icon4);
        aboutQtBtn->setToolButtonStyle(Qt::ToolButtonIconOnly);
        newBtn = new QToolButton(centralwidget);
        newBtn->setObjectName(QString::fromUtf8("newBtn"));
        newBtn->setGeometry(QRect(230, 100, 71, 31));
        newBtn->setIcon(icon5);
        newBtn->setToolButtonStyle(Qt::ToolButtonIconOnly);
        openBtn = new QPushButton(centralwidget);
        openBtn->setObjectName(QString::fromUtf8("openBtn"));
        openBtn->setGeometry(QRect(230, 160, 71, 31));
        openBtn->setIcon(icon);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 672, 26));
        menufile = new QMenu(menubar);
        menufile->setObjectName(QString::fromUtf8("menufile"));
        menuedit = new QMenu(menubar);
        menuedit->setObjectName(QString::fromUtf8("menuedit"));
        menuabout = new QMenu(menubar);
        menuabout->setObjectName(QString::fromUtf8("menuabout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menufile->menuAction());
        menubar->addAction(menuedit->menuAction());
        menubar->addAction(menuabout->menuAction());
        menufile->addAction(actionnew);
        menufile->addAction(actionopen);
        menufile->addAction(actionsave);
        menuedit->addAction(actioncopy);
        menuedit->addAction(actionpaste);
        menuabout->addAction(actionaboutqt);
        toolBar->addAction(actionsave);
        toolBar->addSeparator();
        toolBar->addAction(actioncut);
        toolBar->addAction(actioncopy);
        toolBar->addAction(actionpaste);
        toolBar->addSeparator();
        toolBar->addAction(actionaboutqt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionopen->setText(QApplication::translate("MainWindow", "open", nullptr));
        actionsave->setText(QApplication::translate("MainWindow", "save", nullptr));
        actioncopy->setText(QApplication::translate("MainWindow", "copy", nullptr));
        actionpaste->setText(QApplication::translate("MainWindow", "paste", nullptr));
        actionaboutqt->setText(QApplication::translate("MainWindow", "aboutQt", nullptr));
        actionnew->setText(QApplication::translate("MainWindow", "new", nullptr));
#ifndef QT_NO_TOOLTIP
        actionnew->setToolTip(QApplication::translate("MainWindow", "new", nullptr));
#endif // QT_NO_TOOLTIP
        actioncut->setText(QApplication::translate("MainWindow", "cut", nullptr));
#ifndef QT_NO_TOOLTIP
        actioncut->setToolTip(QApplication::translate("MainWindow", "cut", nullptr));
#endif // QT_NO_TOOLTIP
        hintBtn->setText(QApplication::translate("MainWindow", "hint", nullptr));
        aboutQtBtn->setText(QApplication::translate("MainWindow", "...", nullptr));
        newBtn->setText(QApplication::translate("MainWindow", "...", nullptr));
        openBtn->setText(QApplication::translate("MainWindow", "open", nullptr));
        menufile->setTitle(QApplication::translate("MainWindow", "file", nullptr));
        menuedit->setTitle(QApplication::translate("MainWindow", "edit", nullptr));
        menuabout->setTitle(QApplication::translate("MainWindow", "about", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

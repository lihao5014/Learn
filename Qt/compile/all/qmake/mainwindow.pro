QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = mainwindow
TEMPLATE = app

CONFIG += c++11
DESTDIR = $$PWD/bin

HEADERS += mainwindow.h

SOURCES += main.cpp  \
           mainwindow.cpp

#qmake中指定了ui界面文件，那么就会调用uic.exe界面编译器，将*.ui界面文件编译为ui_*.h头文件
FORMS +=mainwindow.ui

#qmake中指定了qrc资源文件，那么就会调用rcc.exe资源编译器，将*.qrc资源文件编译为qrc_*.cpp源文件
RESOURCES += $$PWD/resource.qrc
QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets   #Qt5中QWidget从Qt4中的gui模块移动到了widgets模块

TARGET = dialog
TEMPLATE = app

CONFIG += console c++11
DESTDIR = $$PWD/bin

SOURCES += main.cpp
QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = dockwidget
TEMPLATE = app

CONFIG += c++11
DESTDIR = $$PWD/bin

SOURCES += main.cpp
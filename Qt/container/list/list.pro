QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = list
TEMPLATE = app

CONFIG += console c++11
DESTDIR = $$PWD/bin

SOURCES += main.cpp


INCLUDEPATH += $$PWD/include
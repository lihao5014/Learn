QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = userinfo
TEMPLATE = app

CONFIG += console c++11
DESTDIR = $$PWD/bin

HEADERS += include/userinfodialog.h

SOURCES += source/main.cpp  \
           source/userinfodialog.cpp

INCLUDEPATH += $$PWD/include
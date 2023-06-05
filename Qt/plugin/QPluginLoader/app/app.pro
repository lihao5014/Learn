QT += core

TARGET = test
TEMPLATE = app

CONFIG += console
DESTDIR = $$PWD/bin

SOURCES += main.cpp

INCLUDEPATH += \
    $$PWD/../plugins/helloplugin/include  \
    $$PWD/../plugins/echoplugin/include

DEPENDPATH += \
    $$PWD/../plugins/helloplugin/include  \
    $$PWD/../plugins/echoplugin/include

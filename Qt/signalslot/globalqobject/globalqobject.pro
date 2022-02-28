QT += core

TARGET = globalqobject
TEMPLATE = app

CONFIG += console
DESTDIR = $$PWD/bin

HEADERS += include/globalqobject.h  \
           include/cat.h  \
		   include/mouse.h

SOURCES += source/main.cpp

INCLUDEPATH += $$PWD/include
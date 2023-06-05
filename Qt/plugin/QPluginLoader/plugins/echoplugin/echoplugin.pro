QT += core

TARGET = $$qtLibraryTarget(echoplugin)
TEMPLATE = lib

CONFIG += plugin

DESTDIR = $$PWD/lib
DLLDESTDIR = $$PWD/../../app/bin

HEADERS += \
	$$PWD/include/echointerface.h  \
	$$PWD/include/echoplugin.h

SOURCES += \
	$$PWD/source/echoplugin.cpp
	
INCLUDEPATH += $$PWD/include

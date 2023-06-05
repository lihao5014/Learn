QT += core

TARGET = $$qtLibraryTarget(helloplugin)
TEMPLATE = lib

CONFIG += plugin

DESTDIR = $$PWD/lib
DLLDESTDIR = $$PWD/../../app/bin

HEADERS += \
	$$PWD/include/helloservice.h  \
	$$PWD/include/helloplugin.h

SOURCES += \
	$$PWD/source/helloplugin.cpp
	
INCLUDEPATH += $$PWD/include

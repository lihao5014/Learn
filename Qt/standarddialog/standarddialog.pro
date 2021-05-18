QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = standarddialog
TEMPLATE = app

CONFIG += c++11
DESTDIR = $$PWD/bin

DEFINES += _TRANSLATE_

HEADERS += include/maindialog.h  \
	       include/common.h  \
           include/inputdialog.h  \
		   include/messageboxdialog.h  \
		   include/customdialog.h

SOURCES += source/main.cpp  \
           source/maindialog.cpp  \
		   source/inputdialog.cpp  \
		   source/messageboxdialog.cpp  \
		   source/customdialog.cpp

INCLUDEPATH += $$PWD/include
QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = personalcenter
TEMPLATE = app

CONFIG += c++11
DESTDIR = $$PWD/bin

#定义_TRANSLATE_编译宏，以控制程序里的中文是否需要转码。当源码为UTF-8编码时不要转码
#DEFINES += _TRANSLATE_

HEADERS += include/common.h  \
		   include/mainwindow.h  \
		   include/content.h  \
		   include/baseinfo.h  \
		   include/contact.h  \
		   include/detail.h

SOURCES += source/main.cpp  \
           source/mainwindow.cpp  \
		   source/content.cpp  \
		   source/baseinfo.cpp  \
		   source/contact.cpp  \
		   source/detail.cpp

INCLUDEPATH += $$PWD/include
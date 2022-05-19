QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = login
TEMPLATE = app

CONFING += c++11 precompile_header
DESTDIR =$$PWD/bin

#Qt中使用预编译头技术，只需要.pro文件中使用PRECOMPILED_HEADER变量指定就行。
PRECOMPILED_HEADER = include/pch.h

SOURCES += source/main.cpp  \
		   source/logindialog.cpp

HEADERS += include/logindialog.h

INCLUDEPATH += $$PWD/include
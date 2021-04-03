QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = login
TEMPLATE = app

CONFING += c++11
DESTDIR =$$PWD/bin

SOURCES += source/main.cpp  \
		   source/logindialog.cpp

HEADERS  += include/logindialog.h

INCLUDEPATH += $$PWD/include
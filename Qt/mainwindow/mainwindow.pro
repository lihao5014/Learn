QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mainwindow
TEMPLATE = app

DESTDIR = $$PWD/bin

SOURCES += source/main.cpp  \
		   source/mainwindow.cpp

HEADERS += include/mainwindow.h

FORMS += ui/mainwindow.ui

INCLUDEPATH += $$PWD/include

RESOURCES += $$PWD/icon/icon.qrc

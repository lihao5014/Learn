QT += core gui widgets

TARGET = circleArea
TEMPLATE = app
CONFIG += console
DESTDIR = $$PWD/../bin

HEADERS += widget.h

SOURCES += main.cpp   \
           widget.cpp
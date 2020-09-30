QT += core gui widgets

TARGET = circleArea
TEMPLATE = app
CONFIG += console
DESTDIR = $$PWD/../bin

HEADERS += view.h     \
           model.h    \
		   control.h

SOURCES += main.cpp      \
           view.cpp      \
		   model.cpp     \
		   control.cpp
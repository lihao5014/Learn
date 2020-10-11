QT += core gui widgets

TARGET = circleArea
TEMPLATE = app
CONFIG += console
DESTDIR = $$PWD/../bin

HEADERS += ui_calculator.h           \
           calculatorModel.h         \
		   calculator.h

SOURCES += main.cpp                  \
		   calculatorModel.cpp       \
		   calculator.cpp
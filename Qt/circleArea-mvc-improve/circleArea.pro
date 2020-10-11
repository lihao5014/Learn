QT += core gui widgets

TARGET = circleArea
TEMPLATE = app
CONFIG += console
DESTDIR = $$PWD/bin

HEADERS += view/calculatorUi.h         \
           model/calculatorModel.h      \
		   control/calculator.h

SOURCES += main.cpp                     \
           view/calculatorUi.cpp      \
		   model/calculatorModel.cpp    \
		   control/calculator.cpp
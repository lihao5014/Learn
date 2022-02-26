QT += core

TARGET = parameter
TEMPLATE = app

CONFIG += console
DESTDIR = $$PWD/bin

HEADERS += include/sender.h  \
           include/reciever.h  \
		   include/data.h

SOURCES += source/main.cpp  \
           source/sender.cpp  \
		   source/reciever.cpp
		   
INCLUDEPATH += $$PWD/include
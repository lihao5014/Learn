QT += core

TARGET = signalnotify
TEMPLATE = app

CONFIG += console
DESTDIR = $$PWD/bin

HEADERS += include/globalconnector.h  \
           include/signaladapter.h  \
		   include/counter.h  \
		   include/person.h

SOURCES += source/main.cpp  \
           source/globalconnector.cpp  \
		   source/signaladapter.cpp  \
		   source/counter.cpp  \
		   source/person.cpp

INCLUDEPATH += $$PWD/include
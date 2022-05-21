QT += core

TARGET = precompiled
TEMPLATE = app

CONFIG += console precompile_header c++11   #使编译器支持c++11标准
DESTDIR = $$PWD/bin

PRECOMPILED_HEADER = include/stable.h

HEADERS += include/ifactory.h  \
           include/dataacquirer.h  \
           include/dataacquirerabstract.h  \
           include/dataacquirerfactory.h

SOURCES += source/main.cpp  \
           source/dataacquirer.cpp  \
		   source/dataacquirerfactory.cpp

INCLUDEPATH += $$PWD/include
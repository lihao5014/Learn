QT += core

TARGET = search
TEMPLATE = lib

CONFIG += c++11       #使编译器支持c++11标准
DESTDIR = $$PWD/lib
DLLDESTDIR = $$PWD/../test/bin

DEFINES += SHARED_LIBRARY SEARCH_LIBRARY _DEBUG_

include($$PWD/../common/common.pri)

HEADERS += \
    $$PWD/include/libsearch_global.h  \
    $$PWD/include/search.h

SOURCES += \
    $$PWD/source/search.cpp

INCLUDEPATH += \
    $$PWD/include  \
	$$PWD/../common/include

DEPENDPATH += $$PWD/../common/include
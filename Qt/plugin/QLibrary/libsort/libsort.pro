QT += core

TARGET = sort
TEMPLATE = lib

CONFIG += c++11       #使编译器支持c++11标准
DESTDIR = $$PWD/lib
DLLDESTDIR = $$PWD/../test/bin

DEFINES += SHARED_LIBRARY SORT_LIBRARY _DEBUG_

include($$PWD/../common/common.pri)

HEADERS += \
    $$PWD/include/libsort_global.h  \
    $$PWD/include/sort.h

SOURCES += source/sort.c

INCLUDEPATH += \
    $$PWD/include  \
	$$PWD/../common/include

DEPENDPATH += $$PWD/../common/include
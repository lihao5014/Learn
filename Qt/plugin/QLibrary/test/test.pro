QT += core

TARGET = test
TEMPLATE = app

CONFIG += console c++11   #使编译器支持c++11标准
DESTDIR = $$PWD/bin

include($$PWD/../common/common.pri)

SOURCES += main.cpp

INCLUDEPATH += \
    $$PWD/../libsort/include  \
    $$PWD/../libsearch/include

LIBS += \
    -L$$PWD/../libsort/lib -lsort  \
    -L$$PWD/../libsearch/lib -lsearch

DEPENDPATH += \
    $$PWD/../libsort/include  \
    $$PWD/../libsearch/include
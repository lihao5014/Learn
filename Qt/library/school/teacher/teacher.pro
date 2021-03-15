QT += core

TARGET = teacher
TEMPLATE = lib

#CONFIG设置为static/staticlib时，编译成静态库。如果TEMPLATE设置为lib，
#而CONFIG没有显式指定为静态库，那么默认生成的库为动态库。
CONFIG += staticlib c++11
DESTDIR = $$PWD/../../bin/lib

HEADERS += iteacher.h  \
           teacher.h

SOURCES += teacher.cpp

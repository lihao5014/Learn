QT += core widgets

TARGET = login
TEMPLATE = app
CONFIG += console       #配置终端打印
DESTDIR = $$PWD/../bin

HEADERS += logindlg.h

SOURCES += main.cpp   \
           logindlg.cpp


DEFINES += _MSVC_COMPILE_      #暂时只能使用mingw64编译，qmake生成的Makefile中默认就是指定的g++编译器

if(contains(DEFINES,_MSVC_COMPILE_)){
QMAKE_CC = cl
QMAKE_CXX = cl
QMAKE_LINK = link
}else{
QMAKE_CC = g++
QMAKE_CXX = g++
QMAKE_LINK = g++
}

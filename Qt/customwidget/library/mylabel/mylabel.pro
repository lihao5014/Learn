QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#使用qtLibraryTarget()函数生成库名字时，可以确保windows下debug模式生成的动态库名自动加一个d。
#如果是debug模式下编译，将生成mylableplugind.dll库。如果是release模式下编译，将生成mylableplugin.dll库。
TARGET = $$qtLibraryTarget(mylabel)
TEMPLATE = lib

CONFIG += debug_and_release
DESTDIR = $$PWD/lib

DEFINES += MYLABEL_LIBRARY

HEADERS = include/mylabel.h  \
          include/mylabel_global.h

SOURCES = src/mylabel.cpp

FORMS += ui/mylabel.ui

INCLUDEPATH += $$PWD/include

#变量INSTALLS用于指定，当执行nmake install命令时，将编译生成的目标文件拷到给定目录中。
#而当运行nmake uninstall命令时，可以将拷贝到指定目录中的目标文件删除掉。

#当命令行中执行make install时，将编译生成的mylableplugin.dll或mylableplugind.dll拷贝到，
#测试工程test-mylabel的lib目录中。
static_library.files += $$PWD/lib/mylabel.lib
static_library.CONFIG += no_check_exist
static_library.path = $$PWD/../test-mylabel/lib

shared_library.files += $$PWD/lib/mylabel.dll
shared_library.CONFIG += no_check_exist
shared_library.path = $$PWD/../test-mylabel/bin

library_headers.files += $$PWD/include/mylabel.h \
                         $$PWD/include/mylabel_global.h
library_headers.path = $$PWD/../test-mylabel/include

INSTALLS += static_library shared_library library_headers

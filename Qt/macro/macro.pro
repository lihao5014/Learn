#pro工程管理文件，不仅可以用于管理Qt工程，普通的C/C++工程也可以使用pro文件来管理

QT += core

TARGET = macro
TEMPLATE = app

CONFIG += console c++11
DESTDIR = $$PWD/bin

DEFINES += _SUB_    #可以在pro文件中定义宏，然后在源文件中使用这个宏定义

HEADERS += include/mymath.h

SOURCES += source/main.c  \
	       source/mymath.c

INCLUDEPATH += $$PWD/include   #指定编译时头文件的路径，即指定头文件环境编译
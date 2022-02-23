QT += core sql

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = dbhelper
TEMPLATE = app

CONFIG += console
DESTDIR = $$PWD/bin

HEADERS += include/singleton.h   \
           include/dbhelper.h    \
		   include/dbconfig.h    \
		   include/student.h     \
		   include/studentdao.h

SOURCES += source/main.cpp        \
           source/dbhelper.cpp    \
		   source/studentdao.cpp

INCLUDEPATH += $$PWD/include

#因为MySQL的库文件是使用msvc编译器，而不是使用mingw编译器编译的，所以需要将编译环境切换到vc++编译环境
DEFINES += _MSVC_COMPILE_

if(contains(DEFINES,_MSVC_COMPILE_)){
QMAKE_CC = cl
QMAKE_CXX = cl
QMAKE_LINK = link
}else{
QMAKE_CC = g++
QMAKE_CXX = g++
QMAKE_LINK = g++
}
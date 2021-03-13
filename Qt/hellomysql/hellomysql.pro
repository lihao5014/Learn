QT += core sql   #QCoreApplication放置在core模块中，而QApplication在Qt5中放置在widgets模块中

TARGET = hellomysql
TEMPLATE = app

CONFIG += console c++11
DESTDIR = $$PWD/bin

SOURCES += main.cpp

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
QT += core

TARGET = student
TEMPLATE = lib

#CONFIG设置为shared/dll时，编译成动态库。如果TEMPALTE设置为lib，
#那么默认生成的库就是动态库。
CONFIG += dll console c++11
DESTDIR = $$PWD/../../bin/lib    #生成动态库时，同步创建的引入库/导入库是提供给其他程序编译期间使用的
DLLDESTDIR = $$PWD/../../bin     #动态库是程序运行时加载，所以需要放置到应用程序目录下

DEFINES += STUDENT_LIBRARY

HEADERS += istudent.h  \
           student_global.h  \
           student.h

SOURCES += student.cpp

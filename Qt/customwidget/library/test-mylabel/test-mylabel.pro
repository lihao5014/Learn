QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = testmylabel
TEMPLATE = app
DESTDIR = $$PWD/bin

include($$PWD/../mylabel/mylabel.pri)

HEADERS += include/widget.h  \
		   include/dialog.h

SOURCES += src/main.cpp  \
		   src/widget.cpp  \
		   src/dialog.cpp

FORMS += ui/widget.ui

#INCLUDEPATH变量用于编译时，指定头文件路径，不然就需要在源文件中添加头文件的完整路径。
INCLUDEPATH += $$PWD/include

#DEPENDPATH变量用于告诉编译器，如果DEPENDPATH指定的目录中头文件发生了变化，
#那么所有依赖这些头文件的源文件都需要被重新编译。
DEPENDPATH += $$PWD/include

LIBS += -L$$PWD/lib -lmylabel
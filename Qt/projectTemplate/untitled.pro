QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET =
TEMPLATE = app

CONFIG += console c++11   #使编译器支持c++11标准
DESTDIR = $$PWD/bin

DEFINES +=

HEADERS += include/

SOURCES += source/main.cpp  \
           source/

FORMS += ui/

INCLUDEPATH += $$PWD/include

CONFIG(debug,debug|release){
	LIBS += -L$$PWD/lib/     -ld       #当编译debug版本的应用程序时，调用debug版本的第三方库
} else {
	LIBS += -L$$PWD/lib/     -l        #当编译release版本的应用程序时，调用release版本的第三方库
}

DEPENDPATH += $$PWD/

RC_ICONS = $$PWD/resource/

RESOURCES += $$PWD/resource/
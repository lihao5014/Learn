QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET =
TEMPLATE = app

#CONFIG += console c++11   #使用编译器默认的c++14标准
DESTDIR = $$PWD/bin

#DEFINES +=

HEADERS += include/

SOURCES += source/main.cpp  \
           source/

FORMS += ui/

INCLUDEPATH += $$PWD/include

#DEPENDPATH += $$PWD/

#RC_ICONS = $$PWD/resource/

#RESOURCES += $$PWD/resource/
QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET =
TEMPLATE = app

CONFIG += console c++11
DESTDIR = $$PWD/bin

HEADERS += include/

SOURCES += source/main.cpp  \
           source/

FORMS += ui/

RC_ICONS = resource/

INCLUDEPATH += include
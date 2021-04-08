QT += core sql
QT -= gui

TEMPLATE = app
TARGET = hellosqlite

CONFIG += console
DESTDIR = $$PWD/bin

#DEFINES += _CHANGE_WAY_

SOURCES += main.cpp

QT += core gui webenginewidgets

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = webview
TEMPLATE = app
DESTDIR = $$PWD/bin

SOURCES += main.cpp
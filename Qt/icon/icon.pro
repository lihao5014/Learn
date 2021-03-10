QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET = icon
TEMPLATE = app

#对于gui应用程序一般不需要看qDebug()的终端打印信息，所以不用加CONFIG += console配置。
#如果gui应用程序加上了console配置，那么单独运行生成的exe时，即会打开gui窗体，也会再打开一个打印终端。
CONFIG += c++11
DESTDIR = $$PWD/bin

HEADERS += include/dialog.h

SOURCES += source/main.cpp  \
           source/dialog.cpp

#Qt中的UI文件可以直接在Qt Designer界面设计师中进行绘制，而不用打开Qt Creator进行设计。
FORMS += ui/dialog.ui

RC_ICONS = resource/google_chrome.ico

INCLUDEPATH += include
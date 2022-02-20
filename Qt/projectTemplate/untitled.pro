QT += core gui

greaterThan(QT_MAJOR_VERSION,4): QT += widgets

TARGET =
TEMPLATE = app

CONFIG += console c++11   #ʹ������֧��c++11��׼
DESTDIR = $$PWD/bin

DEFINES +=

HEADERS += include/

SOURCES += source/main.cpp  \
           source/

FORMS += ui/

INCLUDEPATH += $$PWD/include

CONFIG(debug,debug|release){
	LIBS += -L$$PWD/lib/     -ld       #������debug�汾��Ӧ�ó���ʱ������debug�汾�ĵ�������
} else {
	LIBS += -L$$PWD/lib/     -l        #������release�汾��Ӧ�ó���ʱ������release�汾�ĵ�������
}

DEPENDPATH += $$PWD/

RC_ICONS = $$PWD/resource/

RESOURCES += $$PWD/resource/
QT += core

TARGET = connect
TEMPLATE = app

#����release�汾��guiӦ�ó���һ�㲻��CONFIG += console���á���debug�汾�����Ҫ�鿴
#qDebug()������Ϣʱ������Ҫ��pro�ļ��м���console���á�������Դ�ӡ��Ϣ�޷����ն�����ʾ��
CONFIG += console c++11
DESTDIR = $$PWD/bin

HEADERS += include/counter.h

SOURCES += source/main.cpp  \
           source/counter.cpp

INCLUDEPATH += include
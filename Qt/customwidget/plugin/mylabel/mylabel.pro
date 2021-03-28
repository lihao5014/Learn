QT += core gui

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

#使用qtLibraryTarget()函数生成库名字时，可以确保windows下debug模式生成的动态库名自动加一个d。
#如果是debug模式下编译，将生成mylableplugind.dll库。
#如果是release模式下编译，将生成mylableplugin.dll库。
TARGET = $$qtLibraryTarget(mylabelplugin)
TEMPLATE = lib

CONFIG += plugin debug_and_release
DESTDIR = $$PWD/lib

HEADERS = include/mylabel.h  \
          include/mylabelplugin.h

SOURCES = src/mylabel.cpp  \
          src/mylabelplugin.cpp

FORMS += ui/mylabel.ui

INCLUDEPATH += $$PWD/include

#变量INSTALLS用于指定，当执行nmake install命令时，将编译生成的目标文件拷到给定目录中。
#而当运行nmake uninstall命令时，可以将拷贝到指定目录中的目标文件删除掉。

#当命令行中执行make install时，将编译生成的mylableplugin.dll或mylableplugind.dll拷贝到，
#Qt Creator安装路径下的plugins/designer目录中。即将自定义Qt Designer控件添加到Qt Creator
#界面设计师的标准控件箱中。
qtcreator_designer.files += $$PWD/lib/mylabelplugin.dll
qtcreator_designer.CONFIG += no_check_exist
qtcreator_designer.path = D:/Qt5.12/Tools/QtCreator/bin/plugins/designer

#当命令行中执行make install时，将编译生成的mylableplugin.dll或mylableplugind.dll拷贝到，
#Qt库安装路径下的plugins/designer目录中。即将自定义Qt Designer控件添加到MSVC 32位版本的
#Qt Designer界面设计师工具的标准控件箱中。
target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target qtcreator_designer
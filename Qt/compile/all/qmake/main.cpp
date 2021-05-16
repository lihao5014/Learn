/*Qt creator中执行qmake时只是生成Makefile文件，还不会调用uic.exe/rcc.exe/moc.exe工具编译
 *ui界面文件/qrc资源文件/h头文件，而真正到构建工程执行Makefile文件时，才会真正调用这三个
 *Qt预编译工具处理ui界面文件/qrc资源文件/h头文件。
 */

#include <QApplication>    //等效于QT += widgets
#include "mainwindow.h"

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	MainWindow mainWnd;
	mainWnd.show();

	return app.exec();
}
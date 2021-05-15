/*因为只添加了Qt库的include/lib目录到INCLUDE/LIB环境变量中，所以使用Qt库的头文件时
 *必须带上模块路径。这就等效于qmake文件中，使用QT += 模块名。
 */

/*如果*.ui界面文件中引用的图片来自于资源文件，那么使用uic.exe工具编译完*.ui界面文件后，
 *还需要使用rcc.exe工具编译*.qrc资源文件。如果*.ui文件中直接使用图片文件，而不是先将图片
 *添加到资源文件中，再使用资源文件，那么只需要使用界面编译工具uic.exe，编译*.ui文件即可。
 */

#include <QtWidgets/QApplication>    //等效于QT += widgets
#include "mainwindow.h"

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	MainWindow mainWnd;
	mainWnd.show();
	
	return app.exec();
}
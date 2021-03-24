/*使用windeployqt.exe工具打包发布Qt应用程序方法：
 *1.windeployqt + 二进制文件（库/exe文件）。
 *2.windeployqt + 二进制文件所在的目录。
 */

#include <QApplication>
#include <QFont>
#include "mainwindow.h"

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	QFont font("黑体",12);
	app.setFont(font);

	MainWindow mainWnd;
	mainWnd.show();

	return app.exec();
}
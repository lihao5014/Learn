//QWebEngineView只支持msvc编译器，不支持mingw编译器。

#include <QApplication>
#include <QWebEngineView>

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);

	QWebEngineView view;
	view.load(QUrl("https://www.baidu.com/"));
	view.show();

	return app.exec();
}
//QWebEngineViewֻ֧��msvc����������֧��mingw��������

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
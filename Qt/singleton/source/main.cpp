#include <QtGlobal>
#include <QDebug>
#include "singleton.h"

int main(int argc,char* argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);
	
	Singleton::getInstance().setText("hello world");
	QString text = Singleton::getInstance().getText();
	qDebug()<<"text ="<<text;
	
	Singleton::getInstance().display();

	return 0;
}
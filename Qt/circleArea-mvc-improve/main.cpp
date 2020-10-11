#include <QApplication>
#include "control/calculator.h"

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	Calculator calculator;
	calculator.show();

	return app.exec();
}
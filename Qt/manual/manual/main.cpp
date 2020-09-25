#include <QApplication>
#include <QDebug>
#include "logindlg.h"

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);

	LoginDlg dlg;
	dlg.show();
	
	if(dlg.exec() == QDialog::Accepted)
	{
		qDebug()<<"click ok button";
		return 0;
	}
	qDebug()<<"click cancel button";
	
	return app.exec();
}
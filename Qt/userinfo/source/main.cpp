#include <QApplication>
#include <QDebug>
#include "userinfodialog.h"

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	UserInfoDialog dlg;
	dlg.show();
	if(dlg.exec() != QDialog::Accepted)
	{
		qDebug()<<"---close dialog---";
		return 0;
	}
	qDebug()<<"---exit main---";
	
	return 0;
}
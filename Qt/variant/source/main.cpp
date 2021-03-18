#include <algorithm>
#include <QColor>
#include <QtGlobal>
#include <QDebug>
#include "foobar.h"

using namespace std;

int main(int argc,char* argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);

	QVariant i_var(10);     //QVariant保存基础数据类型
	qDebug()<<"i_var ="<<i_var.toInt();
	
	QVariant s_var("hello world");
	qDebug()<<"s_var ="<<s_var.toString();
	
	QStringList strList;     //QVariant保存容器类型
	strList<<"AAA"<<"BB"<<"CCC"<<"DDD";
	
	QVariant listVar(strList);
	if(listVar.type() == QVariant::StringList)
	{
		QStringList tempStrList = listVar.toStringList();
		QStringList::iterator iter = find_if(tempStrList.begin(),tempStrList.end(),
			[](const QString& str){
				return str == "CCC";
			}
		);
		
		if(iter != tempStrList.end())
		{
			qDebug()<<"find: "<<*iter<<" ,index ="<<iter - tempStrList.begin();
		}
		
		for_each(tempStrList.begin(),tempStrList.end(),
			[](const QString& str){
				qDebug()<<str<<" ";   //std::cout没有重载<<运算符用于打印QString类型，要打印QString必须使用QDebug。
			}
		);
	}
	qDebug()<<"";
	
	QMap<QString,QVariant> mapVar;   //QVariant类型存储到容器中
	mapVar["int"] = 11;
	mapVar["double"] = 3.14;
	mapVar["string"] = "how are you!";
	mapVar["QColor"] = QColor(255,0,0);
	
	qDebug()<<mapVar["int"]<<" "<<mapVar["int"].toInt();
	qDebug()<<mapVar["double"]<<" "<<mapVar["double"].value<double>();
	qDebug()<<mapVar["string"]<<" "<<mapVar["string"].toString();
	qDebug()<<mapVar["QColor"]<<" "<<mapVar["QColor"].value<QColor>();
	qDebug()<<"";

	Foobar foobar = {'a',20,2.71828,"welcome qt"};
	showStruct(foobar);
	
	QVariant baz = getMember(foobar,BAZ);
	qDebug()<<"baz ="<<baz.toDouble();
	
	convertStructToArray(foobar);
	printArray();
	
	QVariant qux = getMember(QUX);
	qDebug()<<"qux ="<<qux.toString();
	qDebug()<<"";
	
	Foobar foobar1;
	convertArrayToStruct(foobar1);
	showStruct(foobar1);
	
	return 0;
}
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <QtGlobal>
#include <QChar>
#include <QString>
#include <QStringList>
#include <QDebug>

//QString字符串的crud操作
static void create_string();
static void retrieve_string();
static void update_string();
static void delete_string();

int main(int argc,char* argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);

	create_string();
	retrieve_string();
	update_string();
	delete_string();

	return 0;
}

void create_string()
{
	QString str;       //调用QString默认构造函数
	str.append("append");    //通过构造一个空字符串，再以追加的方式往空字符串中添加内容
	str.prepend("a");
	str.insert(0,"this");
	str.insert(1,"is");
	str.insert(str.length(),"string");
	qDebug()<<"create string: append/prepend/insert ,str ="<<str;

	QString str1 = "hello world";  //隐式调用QString(const char* str)构造函数
	QString str2 = "hello c++";  //显式调用QString(const char* str)构造函数
	qDebug()<<"create string: constructor ,str1 ="<<str1<<" ,str2 ="<<str2;
	
	/*(1)编译器不优化的情况：先调用QString(const char* str)构造函数生成一个临时对象，再调用移动构造函数创建str3。
	 *(2)编译器优化的情况：直接优化为调用QString(const char* str)构造函数生成str3字符串。
	 */
	QString str3 = QString("hello qt");
	qDebug()<<"create string: move constructor , str3 ="<<str3;
	
	std::string cstr = "this is a std::string";
	QString str4 = QString::fromStdString(cstr);     //从其他类型字符串转换为QString字符串
	qDebug()<<"create string: fromStdString ,str4 ="<<str4;
	std::cout<<"create string: toStdString ,"<<str4.toStdString()<<std::endl;
	
	//格式化输入的方式生成字符串
	QString str5;
	str5.sprintf("%s value is %d","x",50);
	QString str6 = QString("%1 value is %2").arg("y").arg(3.14);
	qDebug()<<"create string: sprintf/arg ,str5 ="<<str5<<" ,str6 ="<<str6;
	
	std::cout<<std::endl;
}

void retrieve_string()
{
	QString str = "Hello world HELLO World qt";
	qDebug()<<"retrieve string: at/[]/front/back ,str.at(1) ="<<str.at(1)<<" ,str[4] ="<<str[4]
			<<" ,str.front() ="<<str.front()<<" ,str.back() ="<<str.back();
	
	qDebug()<<"retrieve string: isEmpty/isNull ,QString("").isEmpty() ="<<QString("").isEmpty()<<" ,QString("").isNull() ="<<QString("").isNull()
		    <<" ,QString().isEmpty() ="<<QString().isEmpty()<<" ,QString().isNull() ="<<QString().isNull();
	
	bool ret = str.contains("world",Qt::CaseInsensitive);     //不区分大小写
	qDebug()<<"retrieve string: constains ,ret ="<<ret;
	
	int num = str.count("hello",Qt::CaseInsensitive);   //统计"hello"字符串在str中出现的次数
	qDebug()<<"retrieve string: count ,num ="<<num;
	
	ret = str.startsWith("hello",Qt::CaseInsensitive);
	qDebug()<<"retrieve string: startsWith ,ret ="<<ret;
	
	ret = str.endsWith("world");
	qDebug()<<"retrieve string: endsWith ,ret ="<<ret;
	
	int pos = str.indexOf("world");     //搜索"world"在str字符串中第一次出现的位置
	qDebug()<<"retrieve string: indexOf from 0 ,pos ="<<pos;
	
	pos = str.indexOf("world",8,Qt::CaseInsensitive);
	qDebug()<<"retrieve string: indexOf from 8 ,pos ="<<pos;

	pos = str.lastIndexOf("world",-1,Qt::CaseInsensitive);
	qDebug()<<"retrieve string: lastIndexOf ,pos ="<<pos;
	
	QString str1("welcome");
	QString str2 = "world";
	ret = (str1 == str2) ? true : false;      //QString重载了==、!=、>、>=、<、<=运算符
	qDebug()<<"retrieve string: == ,ret ="<<ret;
	
	ret = (str1 > str2);
	qDebug()<<"retrieve string: > ,ret ="<<ret;	

	int result = str1.compare(str2,Qt::CaseInsensitive);
	if(result == 0)
	{
		qDebug()<<"retrieve string: compare ,"<<str1<<" is equal to "<<str2;	
	}else if(result > 0)
	{
		qDebug()<<"retrieve string: compare ,"<<str1<<" is greater than "<<str2;
	}else if(result < 0)
	{
		qDebug()<<"retrieve string: compare ,"<<str1<<" is less than "<<str2;
	}
	
	QString str3 = "forename,middlename,surname,phone";
	QStringList subStr = str3.split(",");     //以","分割字符串，返回分割后的字符串列表
	std::for_each(subStr.begin(),subStr.end(),
		[](const QString& str){
			std::cout<<str.toStdString()<<" ";
		}
	);
	std::cout<<std::endl;
	
	QString path = "/user/local/bin/myapp";
	qDebug()<<"retrieve string: path.section('/',3,3) ="<<path.section('/',3,3)      //以','分割符，将从左往右的第3段返回
	        <<" ,path.section('/',3,4) ="<<path.section("/",3,4)                     //以","分割符，将从左往右的第3段到第4段返回
	        <<" ,path.section('/',3,3,QString::SectionSkipEmpty) ="<<path.section("/",3,3,QString::SectionSkipEmpty)    //以","分割符，将从左往右的第3段返回(忽略前面的空字段)
            <<" ,path.section('/',-3,-2) ="<<path.section('/',-3,-2);                 //负号表示从右往左计算

	std::cout<<std::endl;
}

void update_string()
{
	QString str = "hello";
	str = "welcome";
	qDebug()<<"update string: = ,str ="<<str;
	
	str = str + " c++";
	qDebug()<<"update string: + ,str ="<<str;
	
	str +=" and qt";
	qDebug()<<"update string: += ,str ="<<str;
	
	str.push_front(QString("he "));
	str.push_front(QChar('T'));
	str.push_back(QString(" and c"));
	str.push_back(QString('#'));
	qDebug()<<"update string: push_front/push_back ,str ="<<str;
	
	str = "say yes";
	str.replace(4,3,"no");
	qDebug()<<"update string: replace ,str ="<<str;
	
	str = "The Qt PROject";
	qDebug()<<"update string: toLower/toUpper, "<<str.toLower()<<" ,"<<str.toUpper();
	
	QCharRef ch1 = str.front();
	QCharRef ch2 = str.back();
	ch1 = 't';
	ch2 = 'T';
	qDebug()<<"update string: front/back ,str ="<<str;
	
	bool ok = true;
	double dvar = QString("3.14").toDouble(&ok);
	if(ok)
	{
		qDebug()<<"update string: toDouble ,dvar ="<<dvar;
	}
	
	int ivar = QString("0x123").toInt(&ok,16);   //字符串"123" 按16进制转换为数字
	if(ok)
	{
		qDebug()<<"update string: toInt ,ivar ="<<ivar;
	}
	else
	{
		qDebug()<<"update string: QString convert to int failed";
	}
	
	//setNum()是QString类的普通成员函数，而number是QString类的静态成员函数
	str.setNum(123,16);     //数字123转换为16进制字符串
	qDebug()<<"update string: setNum , str ="<<str;
	
	str.setNum(2.71828,'g');     //'g'代表指定转换精度
	qDebug()<<"update string: setNum , str ="<<str;
	
	qDebug()<<"update string: number ,QString::number(200,10) ="<<QString::number(200,10)
	        <<" ,QString::number(0.618,'e') ="<<QString::number(0.618,'e');
			
	std::cout<<std::endl;
}

void delete_string()
{
	QString str = "welcome qt";
	str.clear();
	qDebug()<<"delete string: clear ,str ="<<str<<" ,length ="<<str.length();

	str = "welcome c++";
	str="";
	qDebug()<<"delete string: = ,str ="<<str<<" ,size ="<<str.size();
	
	str = "today is monday";
	str.chop(3);              //从字符串末尾删除若干字符
	qDebug()<<"delete string: chop ,str ="<<str;
	
	QString str1 = "  welcome \t to \n you!";
	str = str1.trimmed();     //移除字符串两端的空白字符，但中间的空白字符保持不变
	qDebug()<<"delete string: trimmed ,str ="<<str;
	
	str = str1.simplified();       //移除字符串两端的空白字符，并使用空格字符" "替换字符串中出现的空白字符
	qDebug()<<"delete string: simplified ,str ="<<str;

	str = "truncate test";
	str.truncate(strlen("trunc"));     //从指定位置截断字符串
	qDebug()<<"delete string: truncate ,str ="<<str;

	str = "a pineapple";
	qDebug()<<"delete string: mid/left/right ,str.mid(1,3) ="<<str.mid(2,4)      //从位置1开始，截取3个字符
	        <<" ,str.mid(6) ="<<str.mid(6)      //从第6个位置开始，一直截取到最后
            <<" ,str.left(4) ="<<str.left(5)
			<<" ,str.right(8) ="<<str.right(5);
	
	str.remove(2,4);
	qDebug()<<"delete string: remove ,str ="<<str;
	
	str.fill('*');
	qDebug()<<"delete string: fill ,str ="<<str;
	
	str.fill('A',4);
	qDebug()<<"delete string: fill ,str ="<<str;
}
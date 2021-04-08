/*使用了MySQL数据库的应用程序，运行时都需要将libmysql.dll动态库添加到生成的exe文件目录下。
 *否则会出现不能加载MySQL驱动的问题。
 */
 
/*因为本计算机中安装的MySQL数据库是mysql-8.0.16-winx64版本，它提供给用户开发的第三方库libmysql.dll
 *和mysqlclient.lib等是64位的，所以编译Qt操作MySQL数据库的应用程序时，需要使用MSVC 64位编译器。
 */

/*设置Qt MSVC64位编译环境步骤（设置Qt MSVC32位编译环境步骤类似）：
 *1.打开Qt5.12.0 64-bit for Desktop(MSVC 2017)终端或执行D:\Qt5.12\5.12.0\msvc2017_64\bin\qtenv2.bat批处理脚本，
 *  以设置Qt库运行环境与环境变量。
 *2.在打开的Qt5.12.0 64-bit for Desktop(MSVC 2017)命令行中执行D:\Visual Studio 2017\VC\Auxiliary\Build\vcvarsall.bat
 *  批处理脚本，以设置MSVC 64编译环境与环境变量。
 */

//打开Qt5.12.0 64-bit for Desktop(MSVC 2017)终端就等同于运行C:\Windows\System32\cmd.exe /A /Q /K D:\Qt5.12\5.12.0\msvc2017_64\bin\qtenv2.bat

//QCoreApplication放置在core模块中，而QApplication在Qt5中放置在widgets模块中
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>

#define _CREATE_TABLE_
#undef _CREATE_TABLE_

typedef enum __StudentProperty
{
	ID,
	NAME,
	SEX,
	AGE,
	StudentProperty_END     //用于记录学生属性个个数标准尾
}StudentProperty_t;

int main(int argc,char** argv)
{
	//需要操作MySQL数据库的Qt应用程序，创建一个QApplication应用程序对象，以加载MySQL数据库驱动。
	QCoreApplication app(argc,argv);
	
	//打开MySQL
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setDatabaseName("testdb");
	db.setUserName("root");
	db.setPassword("123456");
	if(!db.open())
	{
		qDebug()<<"failed to connect mysql with root user";
		return 0;
	}
	qDebug()<<"connect mysql success";
	
	QSqlQuery query(db);
#ifdef _CREATE_TABLE_
	//注意varchar类型一定要指定长度，且最大长度为20个字节
	if(!query.exec("create table students(id int primary key,name varchar(20),sex varchar(16),age int)"))
	{
		qDebug()<<"create table students failed: "<<query.lastError();
	}
	else
	{
		qDebug()<<"create table students successfuly";
	}
	
	query.exec("insert into students values(001,'amy','girl',24)");
	query.exec("insert into students values(002,'bob','boy',26)");
	query.exec("insert into students values(003,'lisa','girl',25)");
	query.exec("insert into students values(004,'mery','girl',24)");
	query.exec("insert into students values(005,'kevin','boy',23)");
#else
	//当执行完数据库查询语句后，我们便获取了相应的执行结果，因为获取的结果可能不止一条记录，
    //所以需要使用while(query.next())语句来遍历获取结果集中的内容。
	query.exec("select * from students");
	while(query.next())
	{
		int id = query.value(ID).toInt();    //QSqlQuery::value()函数的返回值时有个QVariant类型，所以使用时需要进行类型转换
		QString name = query.value(NAME).toString();
		QString sex = query.value(SEX).toString();
		QString age = query.value(AGE).toInt();
		
		qDebug()<<"id ="<<id<<" ,name ="<<name<<" ,sex ="<<sex<<" ,age ="<<age;
	}
	qDebug()<<"";
	
	query.exec("select min(id),max(id) from students");
	while(query.next())
	{
		for(int i=0;i<query.record().count();++i)
		{
			qDebug()<<query.value(i).toInt();
		}
	}
	qDebug()<<"";
#endif
	
	//查找满足id<4的第一条记录
	query.exec("select * from students where id < 4 order by id asc limit 0,1");
	query.next();
	for(int i=0;i<StudentProperty_END;++i)
	{
		qDebug()<<query.value(i).toString();   //数据库表格中id和age属性时int类型，所以打印最好用toInt()
	}
	
	return 0;   //只创建QCoreApplication对象以加载MySQL数据库驱动，但是不进入应用程序的事件循环。
}
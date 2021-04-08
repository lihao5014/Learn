/*SQLite数据库连接名为“:memory:”表示这是建立在内存中的数据库，也就是说该数据库只在程序运行期间有效。
 *如果需要保存该数据库文件，我们可以将它更改为实际的文件路径。程序中使用到的QSqlQuery类。
 */

#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

int main(int argc, char *argv[])
{
	//SQLite数据库与MySQL数据库不同，创建一个QApplication应用程序对象，以加载数据库驱动。
#ifndef _CHANGE_WAY_
    Q_UNUSED(argc);   //SQLite数一种文件型数据库，不需要加载数据库驱动，只需要包含SQLite数据库头文件就可以操作。
	Q_UNUSED(argv);
#else
	QCoreApplication a(argc, argv);
#endif

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");       //创建一个SQLite数据库连接
#ifndef _CHANGE_WAY_
	qDebug()<<"save database to file";
	db.setDatabaseName("../resource/students.db");                //建立文件数据库
#else
	qDebug()<<"create memory database";
	db.setDatabaseName(":memory:");                               //建立内存数据库
#endif
	if(!db.open())         //打开数据库
		return -1;       

    QSqlQuery query;
    query.exec("create table student(id int primary key,name varchar)");   //新建student表，id设置为主键，还有一个name项
    
    query.exec("insert into student values(1,'amy')");    //向表中插入3条记录
    query.exec("insert into student values(2,'lisa')");
    query.exec("insert into student values(3,'bob')");
    query.exec("select id,name from student where id >= 2");   //查找表中id >=2 的记录的id项和name项的值

    //query.next()指向查找到的第一条记录，然后每次后移一条记录
    while(query.next())
    {
        int value0 = query.value(0).toInt();           //query.value(0)是id的值，将其转换为int型
        QString value1 = query.value(1).toString();
        qDebug() << value0 << value1 ;
    }

#ifndef _CHANGE_WAY_
	return 0;
#else
	return a.exec;
#endif
}

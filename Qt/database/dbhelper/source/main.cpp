#include <QCoreApplication>
#include <QDebug>
#include "dbconfig.h"
#include "studentdao.h"
#include "dbhelper.h"

int main(int argc,char* argv[])
{
	QCoreApplication app(argc,argv);

	DBConfig config = {"127.0.0.1",3306,"root","123456","dbhelper"};
	DBHelper::getInstance()->openDB(config);
	
	Student student1 = {1,"amy",25,"Ů"};
	Student student2 = {2,"bob",28,"��"};
	Student student3 = {3,"kevin",30,"��"};
	Student student4 = {4,"lisa",26,"Ů"};
	StudentDao::getInstance()->insertStudent(student1);
	StudentDao::getInstance()->insertStudent(student2);
	StudentDao::getInstance()->insertStudent(student3);
	StudentDao::getInstance()->insertStudent(student4);
	
	QList<Student> studentList;
	StudentDao::getInstance()->selectAllStudent(studentList);
	foreach(const Student& student,studentList)
	{
		qDebug()<<"id ="<<student.id<<" ,name ="<<student.name
		        <<" ,age ="<<student.age<<" ,sex ="<<student.age;
	}

	return 0;
}
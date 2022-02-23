#include "studentdao.h"
#include "dbhelper.h"

bool StudentDao::insertStudent(const Student& student)
{
	DBRecord_t record;
	record["id"] = student.id;
	record["name"] = student.name;
	record.insert("age",student.age);
	record.insert("sex",student.sex);
	
	return DBHelper::getInstance()->insertToDB("student",record);
}

bool StudentDao::deleteStudentById(int id)
{
	return true;
}

bool StudentDao::updataStudentById(int id,const Student& student)
{
	return true;	
}

bool StudentDao::selectAllStudent(QList<Student>& studentList)
{
	DBResult_t result;
	bool ret = DBHelper::getInstance()->selectFromDB("student",result);
	
	for(const DBRecord_t& record : result)
	{
		Student student;
		student.id = record.value("id").toInt();
		student.name = record.value("name").toString();
		student.age = record.value("age").toInt();
		student.sex = record.value("sex").toString();
		
		studentList.append(student);
	}
	return ret;
}
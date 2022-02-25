#include "studentdao.h"
#include "dbhelper.h"

StudentDao::StudentDao()
	:m_tableName("student")
{
	
}

bool StudentDao::insertStudent(const Student& student)
{
	DBRecord_t record;
	record["id"] = student.id;
	record["name"] = student.name;
	record.insert("age",student.age);
	record.insert("sex",student.sex);
	
	return DBHelper::getInstance()->insertToDB(m_tableName,record);
}

bool StudentDao::deleteStudentById(int id)
{
	QString sqlWhere = QString("where id =%1").arg(id);
	return DBHelper::getInstance()->deleteFromDB(m_tableName,sqlWhere);
}

bool StudentDao::updateStudentById(int id,const Student& student)
{
	DBRecord_t record;
	record["id"] = student.id;
	record["name"] = student.name;
	record.insert("age",student.age);
	record.insert("sex",student.sex);
	
	QString sqlWhere = QString("where id =%1").arg(id);
	return DBHelper::getInstance()->updateToDB(m_tableName,record,sqlWhere);
}

bool StudentDao::selectAllStudent(QList<Student>& studentList)
{
	DBResult_t result;
	bool ret = DBHelper::getInstance()->selectFromDB(m_tableName,result);
	
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

bool StudentDao::clearStudent()
{
	return DBHelper::getInstance()->clearTable(m_tableName);
}
#include "coursedao.h"
#include "dbhelper.h"

CourseDao::CourseDao()
	:m_tableName("course")
{
	
}

bool CourseDao::insertCourse(const Course& course,QString* error)
{
	DBRecord_t record;
	record["id"] = course.id;
	record["name"] = course.name;
	record.insert("number",course.number);
	record.insert("teacher",course.teacher);
	
	return DBHelper::getInstance()->insertToDB(m_tableName,record,error);
}

bool CourseDao::deleteCourseById(int id,QString* error)
{
	QString sqlWhere = QString("where id =%1").arg(id);
	return DBHelper::getInstance()->deleteFromDB(m_tableName,sqlWhere,error);
}

bool CourseDao::updateCourseById(int id,const Course& course,QString* error)
{
	DBRecord_t record;
	record["id"] = course.id;
	record["name"] = course.name;
	record.insert("number",course.number);
	record.insert("teacher",course.teacher);
	
	QString sqlWhere = QString("where id =%1").arg(id);
	return DBHelper::getInstance()->updateToDB(m_tableName,record,sqlWhere,error);
}

bool CourseDao::selectAllCourse(QList<Course>& courseList,QString* error)
{
	DBResult_t result;
	bool ret = DBHelper::getInstance()->selectFromDB(m_tableName,result,"",error);
	
	for(const DBRecord_t& record : result)
	{
		Course course;
		course.id = record.value("id").toInt();
		course.name = record.value("name").toString();
		course.number = record.value("number").toInt();
		course.teacher = record.value("teacher").toString();
		
		courseList.append(course);
	}
	return ret;
}

bool CourseDao::clearCourse(QString* error)
{
	return DBHelper::getInstance()->clearTable(m_tableName,error);
}
#ifndef _COURSE_DAO_H
#define _COURSE_DAO_H

#include <QList>
#include "singleton.h"
#include "course.h"

class CourseDao:public Singleton<CourseDao>
{
	friend class Singleton<CourseDao>;
public:
	bool insertCourse(const Course& course,QString* error = nullptr);
	bool deleteCourseById(int id,QString* error = nullptr);
	bool updateCourseById(int id,const Course& course,QString* error = nullptr);
	bool selectAllCourse(QList<Course>& courseList,QString* error = nullptr);
	
	bool clearCourse(QString* error = nullptr);
private:
	CourseDao();
	
	QString m_tableName;
};

#endif  //_COURSE_DAO_H
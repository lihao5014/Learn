#ifndef _COURSE_DAO_H
#define _COURSE_DAO_H

#include <QList>
#include "singleton.h"
#include "course.h"

class CourseDao:public Singleton<CourseDao>
{
	friend class Singleton<CourseDao>;
public:
	bool insertCourse(const Course& course);
	bool deleteCourseById(int id);
	bool updateCourseById(int id,const Course& course);
	bool selectAllCourse(QList<Course>& courseList);
	
	bool clearCourse();
private:
	CourseDao();
	
	QString m_tableName;
};

#endif  //_COURSE_DAO_H
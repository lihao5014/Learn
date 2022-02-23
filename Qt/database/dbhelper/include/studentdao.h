#ifndef _STUDENT_DAO_H
#define _STUDENT_DAO_H

#include <QList>
#include "singleton.h"
#include "student.h"

class StudentDao:public Singleton<StudentDao>
{
	friend class Singleton<StudentDao>;
public:
	bool insertStudent(const Student& student);
	bool deleteStudentById(int id);
	bool updataStudentById(int id,const Student& student);
	bool selectAllStudent(QList<Student>& studentList);

private:
	StudentDao() = default;
};

#endif  //_STUDENT_DAO_H
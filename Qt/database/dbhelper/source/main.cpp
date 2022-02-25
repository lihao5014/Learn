#include <QCoreApplication>
#include <QDebug>
#include "dbconfig.h"
#include "studentdao.h"
#include "coursedao.h"
#include "dbhelper.h"

#pragma execution_character_set("utf-8")

#ifdef _TRANSLATE_
#define TR(str) QString::fromLocal8Bit(str)
#else
#define TR(str) str
#endif

static void clear_student();
static void insert_student();
static void delete_student();
static void update_student();
static void display_student();

static void clear_course();
static void insert_course();
static void delete_course();
static void update_course();
static void display_course();

int main(int argc,char* argv[])
{
	QCoreApplication app(argc,argv);

	DBConfig config = {"127.0.0.1",3306,"root","123456","dbhelper"};
	DBHelper::getInstance()->openDB(config);
	
	clear_student();
	insert_student();
	display_student();
	
	delete_student();
	update_student();
	display_student();
	
	clear_course();
	insert_course();
	display_course();
	
	delete_course();
	update_course();
	display_course();

	return 0;
}

void clear_student()
{
	StudentDao::getInstance()->clearStudent();
}

void insert_student()
{
	Student student1 = {1,"amy",25,TR("女")};
	Student student2 = {2,"bob",28,TR("男")};
	Student student3 = {3,"kevin",30,TR("男")};
	Student student4 = {4,"lisa",26,TR("女")};
	Student student5 = {5,"rambo",32,TR("男")};
	
	StudentDao::getInstance()->insertStudent(student1);
	StudentDao::getInstance()->insertStudent(student2);
	StudentDao::getInstance()->insertStudent(student3);
	StudentDao::getInstance()->insertStudent(student4);	
	StudentDao::getInstance()->insertStudent(student5);	
}

void delete_student()
{
	StudentDao::getInstance()->deleteStudentById(3);
}

void update_student()
{
	Student student = {1,"amy",24,TR("女")};
	StudentDao::getInstance()->updateStudentById(student.id,student);
}

void display_student()
{
	QList<Student> studentList;
	StudentDao::getInstance()->selectAllStudent(studentList);
	foreach(const Student& student,studentList)
	{
		qDebug()<<"id ="<<student.id<<" ,name ="<<student.name
		        <<" ,age ="<<student.age<<" ,sex ="<<student.sex;
	}
	qDebug()<<"";
}

void clear_course()
{
	CourseDao::getInstance()->clearCourse();
}

void insert_course()
{
	Course course1 = {1,TR("数学"),1001,TR("张三")};
	Course course2 = {2,TR("语文"),1002,TR("李四")};
	Course course3 = {3,TR("英语"),1003,TR("王五")};
	Course course4 = {4,TR("物理"),1004,TR("赵六")};
	Course course5 = {5,TR("化学"),1005,TR("钱七")};
	
	CourseDao::getInstance()->insertCourse(course1);
	CourseDao::getInstance()->insertCourse(course2);
	CourseDao::getInstance()->insertCourse(course3);
	CourseDao::getInstance()->insertCourse(course4);	
	CourseDao::getInstance()->insertCourse(course5);	
}

void delete_course()
{
	CourseDao::getInstance()->deleteCourseById(3);
}

void update_course()
{
	Course course = {1,TR("数学"),1010,TR("李梅")};
	CourseDao::getInstance()->updateCourseById(course.id,course);
}

void display_course()
{
	QList<Course> courseList;
	CourseDao::getInstance()->selectAllCourse(courseList);
	foreach(const Course& course,courseList)
	{
		qDebug()<<"id ="<<course.id<<" ,name ="<<course.name
		        <<" ,number ="<<course.number<<" ,teacher ="<<course.teacher;
	}
	qDebug()<<"";	
}
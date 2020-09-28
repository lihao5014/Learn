#include <iostream>
#include "clazz.h"
#include "grade.h"
#include "school.h"
#include "debug.h"

int main(int argc,char** argv)
{
	Student student1("amy",25);
	student1.info();
	cout<<endl;
	
	Teacher advisor1(GIRL,"high");
	advisor1.show();
	cout<<endl;	
	
	Clazz clazz1("english");
	clazz1.setAdvisor(new Teacher(BOY,"middle"));
	clazz1.addStudent(student1);
	clazz1.addStudent(Student("bob",24));
	clazz1.addStudent(Student("kevin",26));
	clazz1.display();
	cout<<endl;
	
	Clazz *pclazz2 = new Clazz("mathematics");
	pclazz2->setAdvisor(new Teacher(GIRL,"low"));
	pclazz2->addStudent(Student("lisa",24));
	pclazz2->addStudent(Student("marry",24));
	pclazz2->addStudent(Student("david",26));
	pclazz2->display();
	cout<<endl;
	
	Debug("break point1");
	Grade grade1(1001);
	grade1.addClazz(new Clazz(clazz1));
	grade1.addClazz(pclazz2);
	Debug("break point4");
	grade1.print();
	cout<<endl;
	
	Clazz *pclazz3 = new Clazz(clazz1);
	pclazz3->setMajor("mechanics");
	pclazz3->addStudent(Student("bill",22));
	
	Clazz *pclazz4 = new Clazz(*pclazz2);
	pclazz4->setMajor("physics");
	pclazz4->removeStudent(Student("marry",24));
	
	Grade *pgrade2 = new Grade(2002);
	pgrade2->addClazz(pclazz3);
	pgrade2->addClazz(pclazz4);    //因为grade1已经托管了pclazz2的内存，所以pgrade2不能再添加pclazz2指针
	pgrade2->print();
	cout<<endl;
	
	School school1("Beijing");
	school1.addGrade(new Grade(grade1));
	school1.addGrade(pgrade2);
	school1.detail();
	cout<<endl;
	
	return 0;
}
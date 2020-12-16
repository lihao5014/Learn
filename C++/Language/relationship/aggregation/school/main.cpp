#include <iostream>
#include "clazz.h"
#include "grade.h"
#include "school.h"
#include "debug.h"

#define _ERROR_
#undef _ERROR_

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
#ifdef _ERROR_
	//因为addGrade()方法是使用深拷贝实现的，所以School类析构时只释放addGrade()方法中new出来的Grade对象。
	//而不会管理调用addGrade()方法时，传入的实参Grade指针的内存释放。
	school1.addGrade(new Grade(grade1));     //会造成new出来的临时Grade对象的内存没有被释放。
	school1.addGrade(pgrade2);               //会造成pgrade2指针的内存没有被释放，从而引起内存泄漏问题。
#else
	Grade* ptempGrade = new Grade(grade1);
	school1.addGrade(ptempGrade);            //因为addGrade()方法使用深拷贝实现，所以调用addGrade()方法时避免传入临时指针。
	delete ptempGrade;
	
	school1.addGrade(pgrade2);    //调用addGrade()方法以后，最好及时释放Grade实参指针的内存，以免引起内存泄漏问题。
	if(pgrade2 != nullptr)
	{
		delete pgrade2;
		pgrade2 = nullptr;
	}
#endif
	school1.detail();
	cout<<endl;
	
	return 0;
}
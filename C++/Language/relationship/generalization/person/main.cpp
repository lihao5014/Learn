#include "child.h"

int main()
{
	Person person("Amy");
	person.show();
	cout<<endl;
	
	Parent parent("Tom",45);
	parent.show();
	cout<<endl;
	
	Child child("Kevin",25,BOY);
	child.show();
	cout<<endl;
	
	Person* ptr = &child;
	ptr->show();
	cout<<endl;
	
	ptr->setName("Lisa");
	ptr->show();
	cout<<endl;
	
	// ptr->setAge(28);      //Person类型没有setAge，所以不能实现多态
	// ptr->show();
	// cout<<endl;
	
	return 0;
}
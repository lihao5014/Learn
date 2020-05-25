#include <iostream>

using namespace std;

class Person
{
public:
	Person(){cout<<"person constructor"<<endl;}
	~Person(){cout<<"person destructor"<<endl;}
	
	void input()
	{
		cout<<"姓名："<<endl;cin>>name;
		cout<<"编号："<<endl;cin>>number;
		cout<<"年龄："<<endl;cin>>age;
	}
	
	void display()const
	{
		cout<<"姓名："<<name<<endl;
		cout<<"编号："<<number<<endl;
		cout<<"年龄："<<age<<endl;
	}
private:
	char name[32];
	char number[32];
	int age;
};

class Student:public Person
{
public:
	Student(){cout<<"Student constructor"<<endl;}
	~Student(){cout<<"Student destructor"<<endl;}
	
	void input()
	{
		Person::input();
		cout<<"班级："<<endl;cin>>department;
		cout<<"成绩："<<endl;cin>>degree;		
	}
	
	void display()const
	{
		Person::display();
		cout<<"班级："<<department<<endl;
		cout<<"成绩："<<degree<<endl;
	}
private:
	char department[32];
	int degree;
};

class Teacher:public Person
{
public:
	Teacher(){cout<<"Teacher constructor"<<endl;}
	~Teacher(){cout<<"Teacher destructor"<<endl;}
	
	void input()
	{
		Person::input();
		cout<<"主修："<<endl;cin>>major;
		cout<<"薪水："<<endl;cin>>salary;			
	}
	
	void display()const
	{
		Person::display();
		cout<<"主修："<<major<<endl;
		cout<<"薪水："<<salary<<endl;		
	}
private:
	char major[32];
	float salary;	
};

int main()
{
	Student student;
	Teacher teacher;
	
	cout<<"请输入学生信息："<<endl;
	student.input();
	student.display();
	
	cout<<endl;
	
	cout<<"请输入老师信息："<<endl;
	teacher.input();
	teacher.display();
	
	return 0;
}
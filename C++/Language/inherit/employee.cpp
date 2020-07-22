//如果用基类指针指向派生类对象实现多态，则虚函数的访问权限以基类中的访问权限为准。
//因此只要基类中的访问权限是public，就可以通过基类指针访问子类中的任意虚函数，private虚函数也可以访问。
//派生类对象的访问权限以派生类中的为准。

#include <iostream>
#include <cstring>

#define _ERROR_
#undef _ERROR_

using std::cout;
using std::endl;

using std::string;

class Employee
{
public:
	explicit Employee(const string& name,int number);
	Employee(const Employee& other);
	virtual ~Employee();
	
	void setName(const string& name);
	string getName()const;
	
	void setNumber(const int number);
	int getNumber()const;
	
	virtual double salary()const;
	virtual void showInfo()const;
private:
	string m_name;
	int m_number;
};

Employee::Employee(const string& name,int number)
	:m_name(name)
	,m_number(number)
{
	
}

Employee::Employee(const Employee& other)
	:m_name(other.m_name)
	,m_number(other.m_number)
{
	
}

Employee::~Employee()
{
	
}

void Employee::setName(const string& name)
{
	m_name = name;
}

string Employee::getName()const
{
	return m_name;
}

void Employee::setNumber(const int number)
{
	m_number = number;
}

int Employee::getNumber()const
{
	return m_number;
}

void Employee::showInfo()const
{
	cout<<"name ="<<m_name<<" ,number ="<<m_number<<endl;
}

double Employee::salary()const
{
	return 0;
}

class Manager:public Employee
{
public:
	explicit Manager(const string& name,int number,double salary);
	Manager(const Manager& other);
	virtual ~Manager();
	
	void setSalary(const double salary);
	double getSalary()const;
private:
	virtual void showInfo()const;            //基类中的虚函数可以在子类中改写其访问权限
	double salary()const override;           //只要基类中的虚函数是public，则其可以访问子类中的任意继承而来的虚函数
private:
	double m_salary;
};

Manager::Manager(const string& name,int number,double salary)
	:Employee(name,number)
	,m_salary(salary)
{
	
}

Manager::Manager(const Manager& other)
	:Employee(other)
	,m_salary(other.m_salary)
{
	
}

Manager::~Manager()
{
	
}

void Manager::setSalary(const double salary)
{
	m_salary = salary;
}

double Manager::getSalary()const
{
	return salary();
}

void Manager::showInfo()const
{
	Employee::showInfo();
	cout<<"salary ="<<m_salary<<endl;
}

double Manager::salary()const
{
	return m_salary;
}

int main(void)
{
	Employee *pemployee = new Manager("Tom",123456,50.00);
	
	//只要基类的虚函数权限是public，就可以使用基类指针访问到派生类私有的虚函数。
	pemployee->showInfo();
	cout<<pemployee->getName()<<" salary is "<<pemployee->salary()<<endl;
	
	pemployee->setName("lisa");
	cout<<pemployee->getName()<<" salary is "<<pemployee->salary()<<endl;
	if(pemployee != nullptr)
	{
		delete pemployee;
		pemployee = nullptr;
	}
	
	Manager manager("kevin",456789,150.00);
#ifdef _ERROR_
	manager.showInfo();            //private成员不能直接访问
	cout<<manager.getName()<<" salary is "<<manager.salary()<<endl;
#else
	cout<<manager.getName()<<" salary is "<<manager.getSalary()<<endl;
#endif

	return 0;
}

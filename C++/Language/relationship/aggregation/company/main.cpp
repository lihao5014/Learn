#include <cstring>
#include <iostream>
#include "date.h"
#include "employee.h"
#include "manager.h"
#include "department.h"
#include "company.h"

#define SAFE_DELETE(ptr)       \
	do{                        \
		if(ptr != nullptr)     \
		{                      \
			delete ptr;        \
			ptr = nullptr;     \
		}                      \
	}while(0)

static void test_Date();
static void test_Employee();
static void test_Manager();
static void test_Department();
static void test_Company();

int main(void)
{
	// test_Date();
	// test_Employee();
	// test_Manager();
	// test_Department();
	test_Company();
	
	return 0;
}

void test_Date()
{
	Date date(2020,11,9);
	date.print();
	
	date.setYear(2021);
	date.setMonth(1);
	date.setDay(12);
	std::cout<<date<<std::endl;
	printf("\n");
}

void test_Employee()
{
	Employee employee(001);
	employee.show();
	
	Date *pdate = new Date(2008,7,25);
	employee.setBirthday(pdate);
	employee.show();

	Employee employee1(employee);
	employee1.setNumber(002);
	employee1.show();

	Date *pbirthday = employee1.getBirthday();
	pbirthday->setYear(2010);
	pbirthday->setMonth(8);
	pbirthday->setDay(13);
	pbirthday->print();
	
	employee.show();
	employee1.show();
	
#ifdef _DEEPLY_COPY_
	delete pdate;
	pdate = nullptr;
#else
	employee1.release(SET_NULLPTR);
#endif
	fprintf(stdout,"\n");
}

void test_Manager()
{
	Manager manager(GIRL,5000);
	manager.display();
	
	manager.setSex(BOY);
	manager.setSalary(6000);
	std::cout<<"salary ="<<manager.getSalary()<<std::endl;
	manager.display();
	
	Manager manager1(manager);
	std::cout<<manager1<<std::endl;
	
	manager1.setSalary(8000);
	std::cout<<"sex ="<<manager1.getSex()<<std::endl;
	manager1.display();
	putc('\n',stdout);
}

void test_Department()
{
	Department department("accounting department");

	department.addManager("Director",Manager(BOY,25000));
	department.addManager("Supervisor",Manager(BOY,15000));
	department.addManager("CTO",Manager(GIRL,35000));   //CTO: chief technology officer
	department.addManager("CEO",Manager(GIRL,45000));   //CEO: chief executive office

	//如果Employee对象要通过addEmployee()放置到Department::employees容器中，那么Employee类必须实现深拷贝构造函数。
	//如果Employee类的拷贝构造函数是浅拷贝，那么调用addEmployee()传参时构造的临时Employee对象析构时，会将pbirthday成员指针的内存释放掉。
	//从而造成Department::employees容器中存储的Employee对象的pbirthday指针都是野指针。
	Date* pbirthday1 = new Date(1991,5,17);
	Date* pbirthday2 = new Date(1991,8,9);
	Date* pbirthday3 = new Date(1990,11,23);
	Date* pbirthday4 = new Date(1993,10,13);
	department.addEmployee(Employee(1001,pbirthday1));
	department.addEmployee(Employee(1002,pbirthday2));
	department.addEmployee(Employee(1003,pbirthday3));
	department.addEmployee(Employee(1004,pbirthday4));
	department.detail();
	puts("");
	
#ifdef _DEEPLY_COPY_
	SAFE_DELETE(pbirthday1);
	SAFE_DELETE(pbirthday2);
	SAFE_DELETE(pbirthday3);
	SAFE_DELETE(pbirthday4);
#endif
	
	Manager &manager = department.getManager("Supervisor");
	std::cout<<manager<<std::endl;
	
	manager.setSex(GIRL);
	manager.setSalary(18000);
	manager.display();
	fputs("\n",stdout);
	
	Employee employee = department.getEmployee(1);
	employee.show();
	
	Date date(1992,12,4);
	employee.setBirthday(&date);
	employee.setNumber(1102);
	employee.show();
	
	Employee &employee1 = department.getEmployee(2);
	employee1.show();
	
	Date date1(1993,6,9);
	employee1.setBirthday(&date1);
	employee1.setNumber(1103);
	employee1.show();
	putchar('\n');
	
	department.detail();
	putchar('\n');
	
	department.removeManager("Director");
	department.removeManager("CTO");
	
	Date birthday(1991,5,17);
	Employee employee2(1001,&birthday);
	department.removeEmployee(employee2);
	department.detail();
	std::cout<<std::endl;
	
	Department department1(department);
	department1.setName("design department");
	department1.detail();
	fputc('\n',stdout);
}

void test_Company()
{
	Company company("Beijing");
	
	Manager* manager1 = new Manager(BOY,11000);
	Manager* manager2 = new Manager(GIRL,12000);
	Manager* manager3 = new Manager(BOY,13000);
	company.registerManager(862147,manager1);
	company.registerManager(687126,manager2);
	company.registerManager(624209,manager3);
	company.info();
	fputs("\n",stdout);
	
	SAFE_DELETE(manager1);
	SAFE_DELETE(manager2);
	SAFE_DELETE(manager3);
	
	Department department("finance department");

	department.addManager("Director",Manager(BOY,25000));
	department.addManager("Supervisor",Manager(BOY,15000));
	department.addManager("CTO",Manager(GIRL,35000));   //CTO: chief technology officer
	department.addManager("CEO",Manager(GIRL,45000));   //CEO: chief executive office

	Date birthday1(1981,5,12);
	Date birthday2(1984,6,7);
	Date birthday3(1990,8,21);
	Date birthday4(1973,11,16);
	department.addEmployee(Employee(1011,&birthday1));
	department.addEmployee(Employee(1012,&birthday2));
	department.addEmployee(Employee(1013,&birthday3));
	department.addEmployee(Employee(1014,&birthday4));
	department.detail();
	puts("");

	company.registerDepartment(&department);
	company.info();
	fputc('\n',stdout);
	
	Department department1(department);
	department1.setName("manufacturing department");
	
	department1.removeManager("CEO");
	Manager &manager = department1.getManager("Supervisor");
	manager.setSalary(11500);
	
	department1.removeEmployee(Employee(1013,&birthday3));
	Employee &employee = department1.getEmployee(2);
	
	Date birthday5(1983,10,25);
	employee.setBirthday(&birthday5);
	employee.setNumber(1015);
	
	company.registerDepartment(&department1);
	company.info();
	putc('\n',stdout);
	
	company.unregisterManager(687126);
	Manager* pmanager = company.manager(624209);
	pmanager->setSex(GIRL);
	pmanager->setSalary(13500);
	
	Department department2("finance department");
	company.unregisterDepartment(&department2);
	
	Department *pdepartment = company.department(0);
	if(pdepartment != nullptr)
	{
		pdepartment->setName("purcharsing department");
	}
	
	pdepartment = company.department(1);
	if(pdepartment != nullptr)
	{
		pdepartment->setName("purcharsing department");
	}
	
	company.info();
	fwrite("\n",1,1,stdout);
}
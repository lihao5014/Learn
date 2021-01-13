#ifndef _DEPARTMENT_H
#define _DEPARTMENT_H

#include <map>
#include <vector>
#include <string>

#include "employee.h"
#include "manager.h"

using std::map;        //展开命名空间的语句最好放置到源文件中去。因为如果放置到头文件中，
using std::vector;     //会使头文件被包含时，展开命名空间的范围进一步被扩大，从而造成命名冲突问题。
using std::string;

class Department
{
public:
	Department(const char* name);       //使用const char*时只能使用深赋值实现构造函数。如果使用char*则可以使用深赋值，也可以使用浅赋值实现构造函数。
	Department(const Department& other);
	virtual ~Department();
	
	bool operator ==(const Department& other);
	
	void setName(const char* name);
	const char* getName()const;
	
	void addManager(const string& position,const Manager& manager);
	void removeManager(const string& position);
	Manager& getManager(const string& position);
	
	void addEmployee(const Employee& employee);
	void removeEmployee(const Employee& employee);
	Employee& getEmployee(const int index);
	
	void detail()const;
private:
	char* name;
	map<string,Manager> managers;     //key - 职位，value - 管理者
	vector<Employee> employees;
};

#endif //_DEPARTMENT_H
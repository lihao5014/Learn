#ifndef _COMPANY_H
#define _COMPANY_H

#include <map>
#include <array>
#include <string>

#define DEPARTMENT_COUNT 4

class Manager;      //使用类的前置声明，以减少头文件包含，从而避免头文件循环依赖问题。
class Department;

class Company
{
public:
	Company(const std::string& location);
	Company(const Company& other);
	virtual ~Company();
	
	Company& operator =(const Company& other) = delete;
	
	void setLocation(const std::string& location);
	const std::string& getLocation()const;
	
	void registerManager(int telephone,const Manager* pmanager);
	void unregisterManager(int telepthone);
	Manager* manager(int telephone);
	
	void registerDepartment(const Department* pdepartment);
	void unregisterDepartment(const Department* pdepartment);
	Department* department(const int index);
	
	void info()const;
private:
	std::string location;
	std::map<int,Manager*> leaders;   //key - 电话，value - 领导
	std::array<Department*,DEPARTMENT_COUNT> departments;
};

#endif //_COMPANY_H
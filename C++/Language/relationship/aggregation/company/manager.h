//C++类设计过程中，一般都需要提供数据输入，数据处理和数据输出三种接口，来共同实现类的功能。类中的成员函数设计时，
//最好也按照数据输入，数据处理和数据输出三种功能进行划分，以使类的功能更加层次分明，从而达到类设计的高内聚低耦合目的。

/*C++类中的所有成员函数都可以分为三大类：数据输入函数，数据处理函数和数据输出函数。其中数据输入和输出函数必须为public接口，
 *如果它们为private函数的话，那么就不能达到为类输入或输出数据的目的。而数据处理函数即可以为public接口，也可以为private函数，
 *但数据处理函数最好设置为private，以供数据输入或输出接口调用，从而达到类设计的高内聚低耦合目的。
 */

#ifndef _MANAGER_H
#define _MANAGER_H

#include <iostream>

typedef enum Sex_t
{
	GIRL,
	BOY
}Sex;

class Manager
{
public:
	Manager();         //存储在map中的值类型需要有默认拷贝构造函数，键类型需要重载大于>运算符。
	Manager(const Sex_t& sex,double salary);
	Manager(const Manager& other);      //判断一个类是否需要显示实现析构函数的方法是看这个类是否具有成员指针。
	                                    //如果具有成员指针那么就需要实现其析构函数，如果不具有成员指针那么就可以不需要实现其析构函数。
	void setSex(const Sex sex);
	Sex getSex()const;
	
	void setSalary(double salary);
	double getSalary()const;
	
	void display()const;
	
	friend std::ostream& operator <<(std::ostream& os,const Manager& other);
private:
	Sex_t sex;
	double salary;
};

#endif //_MANAGER_H
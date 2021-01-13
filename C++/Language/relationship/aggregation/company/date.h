//C++中检查单个源文件是否可以编译通过的命令：g++ -c 源文件名。例如：g++ -c date.cpp 或 g++ -c date.cpp -o date.o

#ifndef _DATE_H
#define _DATE_H

#include <iostream>

class Date
{
public:
	Date(int year,int month,int day);
	Date(const Date& other);
	
	Date& operator =(const Date& other);
	bool operator ==(const Date& other);
	
	void setYear(int year);
	int year()const;         //因为定义了year()成员函数，所以不能再定义year成员变量。只能将year成员变量重命名为m_year等。
	
	void setMonth(int month);
	int month()const;
	
	void setDay(int day);
	int day()const;
	
	void print()const;
	
	friend std::ostream& operator <<(std::ostream& os,const Date& other);
	
private:
	int m_year;      //C++中函数与变量不能同名，否则会标识符重命名冲突，代码编译不通过。
	int m_month;     //C++中函数与函数可以同名，函数的同名又称为函数的重载。
	int m_day;
};

#endif //_DATE_H
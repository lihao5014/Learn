#include <stdio.h>
#include <stdlib.h>    //atoi(),abort()
#include <assert.h>
#include <iostream>
#include <regex>       //regex_match

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using namespace std;

class Date
{
public:
	Date():m_year(0),m_mouth(0),m_day(0){};
	Date(int year,int mouth,int day):m_year(year),m_mouth(mouth),m_day(day){};
	Date(const Date& date):m_year(date.m_year),m_mouth(date.m_mouth),m_day(date.m_day){};
	
	void display()
	{
		cout<<m_year<<"-"<<m_mouth<<"-"<<m_day<<endl;
	}
	
	void show()
	{
		cout<<m_year<<"."<<m_mouth<<"."<<m_day<<endl;
	}
private:
	int m_year;
	int m_mouth;
	int m_day;
};

Date operator "" _D(const char* str,size_t len)
{
	assert(str != nullptr);
	
#ifndef _CHANGE_WAY_
	regex reg("\\d{4}/\\d{2}/\\d{2}");
#else
	regex reg(R"(\d{4}/\d{2}/\d{2})");
#endif
	if(!regex_match(str,reg))
	{
		printf("operator \"\" _D: str is illegal\n");
		exit(-1);
	}
	
	const char* pyear = str;
	const char* pmouth = nullptr;
	const char* pday = nullptr;
	
	const char* p = str;
	for(int i=0;i<len;++i)
	{
		if(*p++ == '/')
		{
			if(pmouth == nullptr)
			{
				pmouth = p;
			}
			else
			{
				pday = p;
				break;
			}
		}
	}

	return Date(atoi(pyear),atoi(pmouth),atoi(pday));
}

int main(int argc,char** argv)
{
	Date date("2021/11/08"_D);
	date.display();
	date.show();
	
	return 0;
}
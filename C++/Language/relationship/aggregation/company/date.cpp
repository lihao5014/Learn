#include "date.h"

using namespace std;

Date::Date(int year,int month,int day)
	:m_year(year)
	,m_month(month)
	,m_day(day)
{
	
}

Date::Date(const Date& other)
	:m_year(other.m_year)
	,m_month(other.m_month)
	,m_day(other.m_day)
{
	
}

Date& Date::operator =(const Date& other)
{
	m_year = other.m_year;
	m_month = other.m_month;
	m_day = other.m_day;
	
	return *this;
}

bool Date::operator ==(const Date& other)
{
	return (m_year == other.m_year) && (m_month == other.m_month) && (m_day == other.m_day);
}

void Date::setYear(int year)
{
	m_year = year;
}

int Date::year()const
{
	return m_year;
}

void Date::setMonth(int month)
{
	if(month < 0 || month > 12)
	{
		cout<<"setMonth error: month need to be between 0 and 12"<<endl;
	}
	
	this->m_month = month;
}

int Date::month()const
{
	return m_month;
}

void Date::setDay(int day)
{
	if(day < 0 || day > 31)
	{
		cout<<"setDay error: day need to be between 0 and 31"<<endl;
	}
	
	m_day = day;
}

int Date::day()const
{
	return m_day;
}

void Date::print()const
{
	cout<<m_year<<":"<<m_month<<":"<<m_day<<endl;
}

ostream& operator <<(ostream& os,const Date& other)
{
	os<<other.m_year<<":"<<other.m_month<<":"<<other.m_day;
	return os;
}
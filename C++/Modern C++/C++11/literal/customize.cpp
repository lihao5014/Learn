/*1.����������������:���û��Զ�������ֵ�ֳ�Ϊ�Զ����׺����Ҫ�����Ǽ򻯴���Ķ�д��
 *��1��������������������operator "" ��׺( )�������������Ϊ�����������������к�׺�����Զ��壬���������»��߿�ʼ��
 *     operator ""���û��Զ����׺ֱ�ӱ����пո�
 *��2����������������غ��������԰�����ֵ����ת������Ҫ�����Ͷ���������������������ǳ�Ա������
 */

/*2.���������ͣ�
 *��1��������Ϊ��������ô����������ֻ�ɽ���unsigned long long����const char*��Ϊ������
 *��2��������Ϊ������������������ֻ�ɽ���long double����const char*Ϊ������
 *��3��������Ϊ�ַ���������������ֻ�ɽ���const char*,size_tΪ������
 *��4��������Ϊ�ַ��������������ֻ����һ��charΪ������
 */

/*3.�������������Ĳ����������������ƣ�������C++11��׼ֻ������7�ֲ����б���ǺϷ��ģ�
 *��1��char const*
 *��2��unsigned long long
 *��3��long double
 *��4��char const*, size_t
 *��5��wchar_t const*, size_t
 *��6��char16_t const*, size_t
 *��7��char32_t const*, size_t
 *����ĸ������ַ����൱���ã���Ϊ�ڶ����������Զ��ƶ�Ϊ�ַ����ĳ��ȡ�
 */

/*4.��C++11��׼��������������ʹ�ù���
 *��1�����������Ϊ����������ô����������ֻ�ɽ���unsigned long long����const char*��Ϊ������
 *     ֻ���ڵ�unsigned long long�޷����ɸ���������ʱ�򣬱��������Զ�����������ת��Ϊ��'\0'��β���ַ�����
 *     ��������const char*Ϊ�����İ汾���д���
 *��2�����������Ϊ������������������ֻ�ɽ���long double����const char*Ϊ������const char*�汾���÷�ʽ������һ����
 *     ֻ���ڵ�long double�޷�����ʱ���á�
 *��3�����������Ϊ�ַ���������������ֻ�ɽ���const char*,size_tΪ������
 *��4�����������Ϊ�ַ��������������ֻ����һ��charΪ������
 *��5���������ķ���ֵ��û�б��ϸ��޶���
 *��6��ע��operater "" ���û��Զ���ĺ�׺֮������пո��û��Զ����׺�������»��߿�ʼ��
 */

#include <stdio.h>
#include <stdlib.h>    //atoi(),abort()
#include <string.h>    //strchr()
#include <iostream>
#include <string>

using namespace std;

long double operator"" _m(long double x)
{
	return x;
}

long double operator"" _mm(long double x)
{
	return x / 1000;
}

long double operator"" _km(long double x)
{
	return x * 1000;
}

//���ڲ���Ϊchar const*����������������Ӧ�ñ���Ϊԭʼ�������������
const char* operator "" _raw(const char* number)
{
	return number;
}

int operator "" _len(const char* str,size_t n)
{
	return n;
}

class Student
{
public:
	Student() = default;
	Student(string name,int age):m_name(name),m_age(age){};
	Student(const Student& student):m_name(student.m_name),m_age(student.m_age){};
	
	void display()
	{
		cout<<"name: "<<m_name<<" , age: "<<m_age<<endl;
	}
	
	friend bool compare(const Student& s1,const Student& s2);
private:
	string m_name;
	int m_age;
};

bool compare(const Student& s1,const Student& s2)
{
	if(s1.m_name == s2.m_name 
		&& s1.m_age == s2.m_age)
	{
		return true;
	}
	return false;
}

Student operator "" _ST(const char* str,size_t len)
{
	if(str == nullptr 
		|| strchr(str,' ') == nullptr
		|| *str == ' '
		|| str[len - 1] == ' ')
	{
			printf("operator "" _ST error: str is illegal\n");
			abort();
	}
	
	int nameLength = 0;
	const char* p = str;
	for(int i=0;i<len;++i)
	{
		if(*p++ == ' ')
		{
			break;
		}
		nameLength++;
	}
	
	string name(str,nameLength);
	int age = atoi(p);
	
	return Student(name,age);
}

int main(int argc,char* argv[])
{
	cout<<1.0_m<<endl;
	cout<<1.0_mm<<endl;
	cout<<1.0_km<<endl;
	
	const char* str = 50_raw;
	printf("int raw literal: %s\n",str);
	
	printf("double raw literal: %s\n",3.1415_raw);
	
	str = "hello world";
	cout<<"strlen(str) ="<<strlen(str)<<" , "<<"hello world"_len<<endl;
	
	//ʹ�����������������Լ򻯺������������룬������ֵ��������ʹ�ö�������������
	Student s("���� 25"_ST);
	s.display();
	
	if(compare("���� 23"_ST,"���� 24"_ST))
	{
		printf("equal\n");
	}
	else
	{
		printf("unequal\n");
	}
	
	return 0;
}
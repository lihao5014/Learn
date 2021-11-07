/*1.字面量操作符概念:（用户自定义字面值又称为自定义后缀，主要作用是简化代码的读写）
 *（1）字面量操作符：形如operator "" 后缀( )的运算符函数称为字面量操作符，其中后缀可以自定义，但建议以下划线开始。
 *     operator ""和用户自定义后缀直接必须有空格。
 *（2）字面量运算符重载函数：可以把字面值常量转换成需要的类型对象。字面量运算符不可以是成员函数。
 */

/*2.字面量类型：
 *（1）字面量为整数：那么操作符函数只可接受unsigned long long或者const char*作为参数。
 *（2）字面量为浮点数：操作符函数只可接受long double或者const char*为参数。
 *（3）字面量为字符串：操作符函数只可接受const char*,size_t为参数。
 *（4）字面量为字符：则操作符函数只接受一个char为参数。
 */

/*3.字面量操作符的参数数量与类型限制：（根据C++11标准只有下面7种参数列表才是合法的）
 *（1）char const*
 *（2）unsigned long long
 *（3）long double
 *（4）char const*, size_t
 *（5）wchar_t const*, size_t
 *（6）char16_t const*, size_t
 *（7）char32_t const*, size_t
 *最后四个对于字符串相当有用，因为第二个参数会自动推断为字符串的长度。
 */

/*4.在C++11标准中字面量操作符使用规则：
 *（1）如果字面量为整形数，那么操作符函数只可接受unsigned long long或者const char*作为参数。
 *     只有在当unsigned long long无法容纳该字面量的时候，编译器会自动将该字面量转化为以'\0'结尾的字符串，
 *     并调用以const char*为参数的版本进行处理。
 *（2）如果字面量为浮点数，操作符函数只可接受long double或者const char*为参数，const char*版本调用方式与整形一样，
 *     只有在当long double无法容纳时调用。
 *（3）如果字面量为字符串，操作符函数只可接受const char*,size_t为参数。
 *（4）如果字面量为字符，则操作符函数只接受一个char为参数。
 *（5）字面量的返回值并没有被严格限定。
 *（6）注意operater "" 与用户自定义的后缀之间必须有空格。用户自定义后缀建议以下划线开始。
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

//对于参数为char const*的字面量操作符，应该被称为原始字面量运算符。
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
	
	//使用字面量操作符可以简化函数参数的输入，用字面值常量代替使用多个参数构造对象
	Student s("张三 25"_ST);
	s.display();
	
	if(compare("李四 23"_ST,"王二 24"_ST))
	{
		printf("equal\n");
	}
	else
	{
		printf("unequal\n");
	}
	
	return 0;
}
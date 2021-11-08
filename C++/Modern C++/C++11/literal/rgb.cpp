#include <stdio.h>
#include <stdlib.h>    //atoi(),abort()
#include <iostream>
#include <regex>
#include <string>
#include <cassert>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using namespace std;

class RGB
{
public:
	RGB();
	RGB(unsigned int red,unsigned int green,unsigned int blue);
	RGB(const RGB& rgb);
	
	void print();
	
	friend RGB blend(RGB&& color1,RGB&& color2);
private:
	unsigned int m_red;
	unsigned int m_green;
	unsigned int m_blue;
};

RGB::RGB()
	:m_red(0)
	,m_green(0)
	,m_blue(0)
{
	
}

RGB::RGB(unsigned int red,unsigned int green,unsigned int blue)
	:m_red(red)
	,m_green(green)
	,m_blue(blue)
{
	
}

RGB::RGB(const RGB& rgb)
	:m_red(rgb.m_red)
	,m_green(rgb.m_green)
	,m_blue(rgb.m_blue)
{
	
}
	
void RGB::print()
{
	cout<<"r"<<m_red<<" g"<<m_green<<" b"<<m_blue<<endl;
}

/*当调用blend函数的时必须先定义两个RGB类的对象，并为RGB类的每个数据成员赋初值。当数据成员很多的时候，
 *这样做就很麻烦。自定义字面量操作符可以使一个以“_C”结尾的字符串表示一个RGB颜色。
 */
RGB blend(RGB&& color1,RGB&& color2)
{
	return RGB(color1.m_red + color2.m_red,color1.m_green + color2.m_green,color1.m_blue + color2.m_blue);
}

//解析以“_C”结尾的字符串，并返回一个RGB类型的临时变量。
RGB operator "" _C(const char* str,size_t len)
{
	assert(str != nullptr);

#ifndef _CHANGE_WAY_
	regex pattern("^r(\\d{1,3})[ ]g(\\d{1,3})[ ]b(\\d{1,3})");
#else
	regex pattern(R"(^r\d{1,3}[ ]g\d{1,3}[ ]b\d{1,3})");
#endif

	cmatch result;
	if(!regex_match(str,result,pattern))
	{
		printf("operator \"\" _D: str is illegal\n");
		abort();
	}
	
	string red = result[1].str();
	string green = result[2].str();
	string blue = result[3].str();
	return RGB(stoi(red),stoi(green),stoi(blue));
}

int main(int argc,char** argv)
{
	RGB color("r100 g50 b25"_C);
	color.print();
	
	//自定义了字面量运算符，调用blend函数时就可以用字符串的形式做参数了。
	color = blend("r10 g20 b30"_C,"r100 g110 b120"_C);
	color.print();
	
	return 0;
}
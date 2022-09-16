#include <iostream>
#include <regex>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using namespace std;

int main(void)
{
#ifndef _CHANGE_WAY_
	regex reg("\\d{4}/\\d{2}/\\d{2}");     //∆•≈‰»’∆⁄
#else
	regex reg(R"(\d{4}/\d{2}/\d{2})");
#endif

	bool ret = regex_match("2021/11/08",reg);
	cout<<"regex match: "<<ret<<endl;
	
	return 0;
}
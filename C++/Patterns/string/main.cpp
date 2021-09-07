#include "string.h"

using namespace std;

int main(int argc,char* argv[])
{
	String str("hello world");
	
	cout<<str<<" ,empty: "<<str.empty()<<" ,len ="<<str.length()<<endl;
	cout<<"str.at(3) ="<<str.at(3)<<" ,str[4] ="<<str[4]<<endl;
	
	String str1 = str;
	cout<<str1<<" ,str1 == str: "<<(str1 == str)<<endl;
	
	str1 += " test";
	cout<<str1<<" ,str1 == str: "<<(str1 == str)<<endl;
	
	str1[2] = 'f';
	str1[5] = 'g';
	cout<<str1<<" ,str1 > str: "<<(str1 > str)<<endl;
	
	cin>>str1;
	cout<<str1<<endl;
	
	return 0;
}
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc,char** argv)
{
	cout<<setw(10)<<1234567890<<endl;
	cout.width(10);
	cout<<1.2<<endl;
	
	cout<<oct<<17<<endl;
	cout<<hex<<17<<endl;
	
	cout<<12345.0<<endl;    //输出"12345" 
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<1.2345<<endl;    //输出"1.235" 
	cout<<setiosflags(ios::scientific)<<12345.0<<endl;    //输出"1.234500e+004 " 
	cout<<setprecision(3)<<12345.0<<endl;     //输出"1.235e+004 " 
	
	return 0;
}
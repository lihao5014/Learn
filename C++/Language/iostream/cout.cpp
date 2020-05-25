#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc,char** argv)
{
	cout.fill('*');
	cout.width(10);
	cout<<123.45<<endl;
	cout.width(8);
	cout<<123.45<<endl;
	cout.width(4);
	cout<<123.45<<endl;
	
	cout.width(10);
	cout<<setiosflags(ios::left)<<123.45<<endl;
	cout.width(8);
	cout<<123.45<<endl;
	cout.width(4);
	cout<<123.45<<endl;
	
	cout.width(10);
	cout<<resetiosflags(ios::right);
	cout<<dec<<160<<endl;
	cout.width(8);
	cout<<oct<<160<<endl;
	cout.width(4);
	cout<<hex<<160<<endl;
	
	return 0;
}
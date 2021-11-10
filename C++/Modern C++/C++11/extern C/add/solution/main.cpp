#include <iostream>
#include "add.h"

using namespace std;

int main(int argc,char* argv[])
{
	int ret = add(3,4);
	cout<<"3 + 4 ="<<ret<<endl;
	
	return 0;
}
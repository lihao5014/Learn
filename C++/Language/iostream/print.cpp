#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char buf[256] = {0};
#if 0	
	while(1){
		memset(buf,0,sizeof(buf));
		cin.read(buf,sizeof(buf));
		cout.write(buf,strlen(buf));
	}
#else
	while(1){
		memset(buf,0,sizeof(buf));
		cin>>buf;
		cout<<buf<<endl;
	}	
#endif
	return 0;
}
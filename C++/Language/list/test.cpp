#include <iostream>
#include <list>
#include <string.h>

using namespace std;

int main()
{
	
	list<int> ls;
	ls.push_back(0);
	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(3);
	ls.push_back(4);
	
	list<int>::iterator it = ls.begin();
	while(it != ls.end()){
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
	
	const char* str = "abcde";
	list<char> ls1(str,str+strlen(str));
	for(auto ch: ls1){
		cout<<ch<<" ";
	}
	cout<<endl;
	
	return 0;
}
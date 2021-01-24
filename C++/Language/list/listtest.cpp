#include <iostream>
#include <list>
#include <string.h>

#define _CHANFE_WAY_
// #undef _CHANFE_WAY_

#ifndef _CHANFE_WAY_
using namespace std;
#else
using std::list;
using std::cout;
using std::endl;
#endif

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

#ifndef _CHANFE_WAY_
	list<double> ls2 = {3.14,2.71,0.618};
#else
	list<double> ls2(3,0.618);
#endif
	for(list<double>::const_iterator iter = ls2.cbegin();iter != ls2.cend();++iter)
	{
		cout<<*iter<<" ";
	}
	cout<<endl;
	
	return 0;
}
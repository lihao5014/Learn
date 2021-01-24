#include <iostream>
#include <map>
#include <string>

using namespace std;

enum Color_t
{
	RED = 'a',
	YELLOW = 'b',
	GREEN = 'c',
	BLUE = 'd'
};

typedef void (*pFun)(int x);

static void foo(int x);
static void bar(int x);
static void baz(int x);
static void qux(int x);

int main(void)
{
	map<int,string> testMap;
	testMap.insert(pair<int,string>(0,"hello"));
	testMap.insert(pair<int,string>(1,"world"));
	testMap[2] = "C++";
	testMap[3] = "Java";
	
	map<int,string>::iterator iter = testMap.begin();
	while(iter != testMap.end())
	{
		cout<<"key ="<<iter->first<<" ,value ="<<iter->second<<endl;
		++iter;
	}
	
	map<Color_t,string> colorMap;
	colorMap.insert(pair<Color_t,string>(RED,"red"));
	colorMap.insert(pair<Color_t,string>(YELLOW,"yellow"));
	colorMap[GREEN] = "green";
	colorMap[BLUE] = "blue";
	
	for(auto iter = colorMap.begin();iter != colorMap.end();++iter)
	{
		cout<<"key ="<<iter->first<<" ,value ="<<iter->second<<endl;
	}
	
	map<Color_t,pFun> sigMap;
	sigMap.insert(pair<Color_t,pFun>(RED,foo));
	sigMap.insert(pair<Color_t,pFun>(YELLOW,bar));
	sigMap[GREEN] = baz;
	sigMap[BLUE] = qux;
	
	auto citer = sigMap.cbegin();
	for(;citer != sigMap.cend();++citer)
	{
		cout<<"key ="<<citer->first<<endl;
		citer->second(5);
	}
	
	return 0;
}

void foo(int x)
{
	cout<<"foo: x ="<<x<<endl;
}

void bar(int x)
{
	cout<<"bar: x ="<<x<<endl;
}

void baz(int x)
{
	cout<<"baz: x ="<<x<<endl;
}

void qux(int x)
{
	cout<<"qux: x ="<<x<<endl;
}
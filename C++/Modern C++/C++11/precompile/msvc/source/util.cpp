#include "stdafx.h"    //ʹ��Ԥ����ͷ��ÿһ��.cpp�ļ��Ŀ�ͷ��Ҫ����Ԥ����ͷ�ļ�#include "stdafx.h"
#include "util.h"

using namespace std;

vector<int> twice(const vector<int>& vec)
{
	vector<int> seq = vec;
	map<int>(seq,[](int n){return 2 * n;});
	return seq;
}

vector<int> square(const vector<int>& vec)
{
	vector<int> seq = vec;
	map<int>(seq,[](int n){return n * n;});
	return seq;
}

int summate(const vector<int>& vec)
{
	return reduce<int>(vec,0,[](int x,int y){return x + y;});
}

int product(const vector<int>& vec)
{
	return reduce<int>(vec,1,[](int x,int y){return x * y;});
}

string concat(const vector<string>& vec)
{
	return reduce<string>(vec,string(),[](string str1,string str2){return str1 + str2;});
}
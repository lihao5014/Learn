#include "stdafx.h"    //ʹ��Ԥ����ͷ��ÿһ��.cpp�ļ��Ŀ�ͷ��Ҫ����Ԥ����ͷ�ļ�#include "stdafx.h"
#include "util.h"

using namespace std;

int main(void)
{
	vector<int> vec = {1,2,3,4,5};
	for(int n : twice(vec))
	{
		cout<<n<<" ";
	}
	cout<<endl;
	
	for(int n : square(vec))
	{
		cout<<n<<" ";
	}
	cout<<endl;
	
	int ret = summate(vec);
	cout<<"summate: "<<ret<<endl;
	
	int result = product(vec);
	cout<<"product: "<<result<<endl;
	
	vector<string> seq = {"hello"," ","world"," ","C","/","C++"};
	string str = concat(seq);
	cout<<"concat: "<<str<<endl;
	
	return 0;
}
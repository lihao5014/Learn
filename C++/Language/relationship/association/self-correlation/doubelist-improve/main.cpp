#include <iostream>
#include "doublelist.h"

using namespace std;

int main(int argc,char* argv[])
{
	DoubleList dlist;
	dlist.init(5,1.11);
	dlist.show();
	dlist.rshow();

	dlist.append(2.12);
	dlist.append(2.12);
	dlist.prepend(3.13);
	dlist.prepend(3.13);
	dlist.insert(0,4.14);
	dlist.insert(2,4.14);
	dlist.show();
	if(dlist.empty())
	{
		cout<<"dlist is empty, length ="<<dlist.length()<<endl;
	}
	else
	{
		cout<<"dlist is not empty, length ="<<dlist.length()<<endl;
	}
	cout<<endl;
	
	dlist.clear();
	dlist.prepend(6.01);    //测试append、prepend、popBack、insert和remove特殊位置的节点，程序是否可以正常运行
	dlist.insert(1,6.02);
	dlist.insert(2,6.03);
	dlist.insert(3,6.04);
	dlist.insert(2,6.05);
	dlist.insert(5,6.06);
	dlist.insert(6,6.07);
	dlist.show();
	
	dlist.remove(dlist.length() - 1);
	dlist.remove(dlist.length() - 1);
	dlist.remove(6.04);
	dlist.remove(6.03);
	dlist.popBack();
	dlist.popBack();
	dlist.popFront();
	dlist.append(7.01);
	dlist.append(7.02);
	dlist.show();
	dlist.rshow();
	cout<<endl;
	
	dlist.clear();
	if(dlist.empty())
	{
		cout<<"dlist is empty, length ="<<dlist.length()<<endl;
	}
	else
	{
		cout<<"dlist is not empty, length ="<<dlist.length()<<endl;
	}
	
	dlist.append(7.21);
	dlist.prepend(6.21);
	dlist.insert(0,5.22);
	dlist.insert(1,5.23);
	dlist.insert(2,5.24);
	dlist.insert(4,5.25);
	dlist.insert(4,5.25);
	dlist.insert(6,5.25);
	dlist.insert(6,5.25);

	dlist.prepend(6.21);
	dlist.prepend(6.21);
	dlist.prepend(6.22);
	dlist.prepend(6.23);
	
	dlist.append(7.22);
	dlist.append(7.23);
	dlist.show();
	dlist.rshow();
	cout<<endl;
	
	data_t& firstData = dlist.front();
	firstData = 8.31;
	cout<<"front data: "<<dlist.front()<<endl;
	
	dlist.back() = 8.32;
	cout<<"last data: "<<dlist.back()<<endl;
	
	dlist.replace(2,9.41);
	dlist.replace(3,9.42);
	dlist.replace(6.21,6.31);
	dlist.replace(5.25,6.33);
	dlist.show();

	data_t &data = dlist[6];
	data = 10.51;
	
	dlist[7] = 10.52;
	cout<<"length ="<<dlist.length()<<" ,dlist.at(8) ="<<dlist.at(8)<<endl;
	dlist.show();
	cout<<endl;
		
	dlist.popFront();
	dlist.popBack();
	dlist.remove(2);
	dlist.remove(3);
	dlist.show();

	dlist.remove(6.22);
	dlist.remove(6.33);
	bool ret = dlist.remove(6.44);
	if(ret)
	{
		cout<<"remove(6.44) result: true"<<endl;
	}
	else
	{
		cout<<"remove(6.44) result: false"<<endl;
	}
	
	dlist.show();
	cout<<"length ="<<dlist.length()<<" , back date: "<<dlist.back()<<endl;
	cout<<endl;

	int index = dlist.find(10.52);
	cout<<"find(10.52) index: "<<index<<endl;
	
	index = dlist.find(11.00);
	cout<<"find(11.00) index: "<<index<<endl;
	
	dlist.reverse();
	dlist.show();
	cout<<endl;

	dlist.sort(INCREASE);
	dlist.show();
	dlist.rshow();

	dlist.sort(DECREASE);
	dlist.show();
	dlist.rshow();
	cout<<endl;
		
	DoubleList dlist1(dlist);
	dlist1.show();
	dlist1.rshow();
	
	dlist.init(8,12.12);
	dlist1 = dlist;
	dlist1.show();
	
	return 0;
}
#include <iostream>
#include "doublelist.h"

using namespace std;

int main(int argc,char* argv[])
{
	DoubleList dlist;
	dlist.init(5,1.11);
	dlist.display();
	dlist.rdisplay();

	dlist.append(2.12);
	dlist.append(2.12);
	dlist.prepend(3.13);
	dlist.prepend(3.13);
	dlist.insert(0,4.14);
	dlist.insert(2,4.14);
	dlist.display();
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
	if(dlist.empty())
	{
		cout<<"dlist is empty, length ="<<dlist.length()<<endl;
	}
	else
	{
		cout<<"dlist is not empty, length ="<<dlist.length()<<endl;
	}
	dlist.insert(0,5.22);
	dlist.insert(1,5.23);
	dlist.insert(2,5.24);
	dlist.insert(2,5.25);
	dlist.insert(2,5.25);
	dlist.insert(2,5.25);
	dlist.insert(2,5.25);
	dlist.prepend(6.21);
	dlist.prepend(6.21);
	dlist.prepend(6.21);
	dlist.prepend(6.22);
	dlist.prepend(6.23);
	dlist.append(7.21);
	dlist.append(7.22);
	dlist.append(7.23);
	dlist.display();
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
	dlist.display();

	data_t &data = dlist[6];
	data = 10.51;
	
	dlist[7] = 10.52;
	cout<<"length ="<<dlist.length()<<" ,dlist.at(8) ="<<dlist.at(8)<<endl;
	dlist.display();
	cout<<endl;
		
	dlist.popFront();
	dlist.popBack();
	dlist.remove(2);
	dlist.remove(3);
	dlist.display();

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
	
	dlist.display();
	cout<<"length ="<<dlist.length()<<" , back date: "<<dlist.back()<<endl;
	cout<<endl;

	int index = dlist.find(10.52);
	cout<<"find(10.52) index: "<<index<<endl;
	
	index = dlist.find(11.00);
	cout<<"find(11.00) index: "<<index<<endl;
	
	dlist.reverse();
	dlist.display();
	cout<<endl;

	dlist.sort(INCREASE);
	dlist.display();
	dlist.rdisplay();

	dlist.sort(DECREASE);
	dlist.display();
	dlist.rdisplay();
	cout<<endl;
		
	DoubleList dlist1(dlist);
	dlist1.display();
	dlist1.rdisplay();
	
	dlist.init(8,12.12);
	dlist1 = dlist;
	dlist1.display();

	return 0;
}
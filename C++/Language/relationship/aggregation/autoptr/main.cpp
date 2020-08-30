#include "autoptr.h"
#include "sample.h"

using namespace std;

int main(int argc,char** argv)
{
	Sample sample(10);
	sample.show();
	
	cout<<"please input value:"<<endl;
	cin >> sample;
	cout<<"print sample: "<<sample<<endl;

	{
		Sample *psample = new Sample(sample);
		psample->show();
		
		Auto_ptr<Sample> autoptr(psample);
		autoptr->setValue(20);
		cout<<"autoptr->getValue() = "<<autoptr->getValue()<<endl;
		autoptr->show();
		
		(*autoptr).setValue(30);
		cout<<"(*autoptr).getValue() = "<<(*autoptr).getValue()<<endl;
		(*autoptr).show();
	}
	
	cout<<"---end main---"<<endl;
	
	return 0;
}
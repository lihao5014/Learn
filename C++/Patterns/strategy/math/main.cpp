#include "context.h"
#include <iostream>

using namespace std;

int main()
{
	double num;
	Context context;
	Strategy *strategy;
	
	strategy = new OperationAdd();
	context.setStrategy(strategy);
	num = context.executeStrategy(4,5);
	cout<<"4+5="<<num<<endl;
	delete strategy;
	
	strategy = new OperationSub();
	context.setStrategy(strategy);
	num = context.executeStrategy(9,5);
	cout<<"9-5="<<num<<endl;
	delete strategy;
		
	strategy = new OperationMult();
	context.setStrategy(strategy);
	num = context.executeStrategy(4,5);
	cout<<"4*5="<<num<<endl;
	delete strategy;
	
	strategy = new OperationDivi();
	context.setStrategy(strategy);
	num = context.executeStrategy(20,5);
	cout<<"20/5="<<num<<endl;
	delete strategy;
	
	return 0;
}
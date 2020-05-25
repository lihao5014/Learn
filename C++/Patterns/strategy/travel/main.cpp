#include "context.h"

int main()
{
	IStrategy *strategy = new BikeStrategy();
	Context context(strategy);
	context.travel();
	delete strategy;
	
	strategy = new CarStrategy();
	context.setStrategy(strategy);
	context.travel();
	delete strategy;	
	
	strategy = new TrainStrategy();
	context.setStrategy(strategy);
	context.travel();
	delete strategy;
	
	return 0;
}
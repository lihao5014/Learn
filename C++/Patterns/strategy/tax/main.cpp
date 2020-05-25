#include "sales_order.h"

int main()
{
	TaxStrategy *strategy = new CNTax();
	SalesOrder order(strategy);
	order.calculateTax();
	delete strategy;
	
	strategy = new USTax();
	order.setStrategy(strategy);
	order.calculateTax();
	delete strategy;
	
	strategy = new DETax();
	order.setStrategy(strategy);
	order.calculateTax();
	delete strategy;
	
	return 0;
}
#include "factory.h"

int main()
{
	Factory* factory = new FactoryA();
	Product* product = factory->createProduct();
	Commodity* commodity = factory->createCommodity();
	product->show();
	commodity->display();
	delete commodity;
	delete product;
	delete factory;
	
	factory = new FactoryB();
	product = factory->createProduct();
	commodity = factory->createCommodity();
	product->show();
	commodity->display();
	delete commodity;
	delete product;
	delete factory;
	
	return 0;
}
#include "product.h"

int main(int argc,char* argv[])
{
	Product* product = new ConcreteProductA(10);
	product->show();
	Product* product1 = product->clone();
	product1->show();
	delete product;
	delete product1;
	
	product = new ConcreteProductB(20);
	product->show();
	product1 = product->clone();
	product1->show();
	delete product;
	delete product1;
	
	return 0;
}
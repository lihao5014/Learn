#include "director.h"

int main()
{
	AbstractBuilder* buider = new BuilderA();
	Director* director = new Director(buider);
	director->createProduct();
	Product* product = director->getProduct();
	product->show();
	delete product;
	delete buider;
	
	buider = new BuilderB();
	director->setBuilder(buider);
	director->createProduct();
	product = director->getProduct();
	product->show();
	delete product;
	delete buider;
	delete director;
	
	return 0;
}
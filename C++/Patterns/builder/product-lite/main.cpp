#include "builder.h"

int main()
{
	AbstractBuilder* buider = new BuilderA();
	buider->bulidProduct();
	Product* product = buider->getProduct();
	product->show();
	delete product;
	delete buider;
	
	buider = new BuilderB();
	buider->bulidProduct();
	product = buider->getProduct();
	product->show();
	delete product;
	delete buider;
	
	return 0;
}
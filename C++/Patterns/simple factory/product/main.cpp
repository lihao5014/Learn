#include "product.h"

int main()
{
	Factory factory;
	
	Product *productA = factory.createProduct(TypeA);
	productA->show();
	factory.destroyProduct(productA);
	
	Product *productB = factory.createProduct(TypeB);
	productB->show();
	factory.destroyProduct(productB);
	
	Product *productC = factory.createProduct(TypeC);
	productC->show();
	factory.destroyProduct(productC);
	
	return 0;
}
#include "product.h"
#include "factory.h"

using namespace std;

int main()
{
	Factory* factory = new ProductAFactory();
	Product *product = factory->createProduct();
	product->show();
	factory->destroyProduct(product);
	delete factory;
	
	factory = new ProductBFactory();
	product = factory->createProduct();
	product->show();
	factory->destroyProduct(product);
	delete factory;
	
	factory = new ProductCFactory();
	product = factory->createProduct();
	product->show();
	factory->destroyProduct(product);
	delete factory;	
		
	return 0;
}
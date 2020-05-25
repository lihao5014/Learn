#include "car.h"

int main(void)
{
	Car car1("Honda","blue",25.5);
	car1.detail();
	puts("");
	
	Car car2 = car1;        //µÈ¼ÛÓÚCar car2(car1)
	car2.detail();
	
	return 0;
}
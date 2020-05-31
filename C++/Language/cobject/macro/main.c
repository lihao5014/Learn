#include "light.h"
#include <stdio.h>

int main()
{
	Light *light = (Light*)Light_New();
	light->turnOn();
	light->turnOff();
	
	Light_Delete(&light);
	if(light == NULL)
	{
		puts("light = NULL");
	}
	
	return 0;
}
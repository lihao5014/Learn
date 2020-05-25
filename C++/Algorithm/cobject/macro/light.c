#include "light.h"
#include <stdio.h>

static void turn_on()
{
	printf("light turn on!\n");
}

static void turn_off()
{
	puts("light turn off!");
}

CTOR(Light)
FUNCTION_SETTING(turnOn,turn_on)
FUNCTION_SETTING(turnOff,turn_off)
END_CTOR(Light)
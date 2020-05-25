#include "iswitch.h"
#include "electrical.h"

int main(int argc,char* argv[])
{
	ButtonSwitch button;
	Light light("light",&button);
	light.powerOn();
	light.powerOff();
	light.display();
	
	RotarySwitch _switch;
	Fan fan("fan",&_switch);
	fan.powerOn();
	fan.powerOff();	
	
	fan.setSwitch(&button);
	fan.powerOn();
	fan.powerOff();	
	fan.display();
	
	return 0;
}
#include "wind_control.h"

int main()
{
	IWind *wind = new ColdWind();
	WindControl control(wind);
	control.blowWind();
	delete wind;
	
	wind = new WarmWind();
	control.setWind(wind);
	control.blowWind();
	delete wind;	

	wind = new NoWind();
	control.setWind(wind);
	control.blowWind();
	delete wind;
	
	return 0;
}
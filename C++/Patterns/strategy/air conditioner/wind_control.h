#ifndef _WIND_CONTROL_H
#define _WIND_CONTROL_H

#include "wind.h"

class WindControl
{
public:
	WindControl(IWind *wind):m_wind(wind){}
	void setWind(IWind *wind){m_wind = wind;}
	void blowWind()
	{
		m_wind->blowWind();
	}
private:
	IWind *m_wind;
};

#endif //_WIND_CONTROL_H
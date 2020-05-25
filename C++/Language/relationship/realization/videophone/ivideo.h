#ifndef _IVIDEO
#define _IVIDEO

struct IVideo
{
	virtual ~IVideo() = default;
	virtual void show() = 0;
};

#endif //_IVIDEO
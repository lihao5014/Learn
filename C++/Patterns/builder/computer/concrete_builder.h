#ifndef _CONCRETE_BUILDER_H
#define _CONCRETE_BUILDER_H

#include "ibuilder.h"
#include "computer.h"

class AppleBuilder:public IBuilder
{
public:
	AppleBuilder()
	{
		computer = new Computer();
	}
	
	void buildCpu()
	{
		if(computer != nullptr)
			computer->setCpu("Ryzen 3900x");
	}
	virtual void buildGpu()
	{
		if(computer != nullptr)
			computer->setGpu("AMD RX5700");		
	}
	
	void buildRam()override
	{
		if(computer != nullptr)
			computer->setRam("SAMSUNG 32G DDR");			
	}
	
	void buildBoard()final
	{
		if(computer != nullptr)
			computer->setBoard("ASUS X570");			
	}
};

class DellBuilder:public IBuilder
{
public:
	DellBuilder()
	{
		computer = new Computer();
	}
	
	void buildCpu()
	{
		if(computer != nullptr)
			computer->setCpu("Intel i7-9700K");
	}
	virtual void buildGpu()
	{
		if(computer != nullptr)
			computer->setGpu("Nvidia 1080Ti");		
	}
	
	void buildRam()override
	{
		if(computer != nullptr)
			computer->setRam("Kingston 32G DDR");			
	}
	
	void buildBoard()final
	{
		if(computer != nullptr)
			computer->setBoard("MSI X570");			
	}
};

#endif //_CONCRETE_BUILDER_H
#ifndef _FACTORY_H
#define _FACTORY_H

#include "assemble.h"

class Factory
{
public:
	Factory(Assemble* assemble):m_assemble(assemble)
	{
		
	}
	
	void assembleCar()
	{
		if(m_assemble != nullptr){
			m_assemble->assembleEngine();
			m_assemble->assembleWheel();
			m_assemble->assembleBody();		
		}
	}
	
	Car* getCar()
	{
		return m_assemble->getCar();
	}
private:
	Assemble* m_assemble;
};

#endif //_FACTORY_H
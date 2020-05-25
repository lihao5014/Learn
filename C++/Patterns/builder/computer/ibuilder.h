#ifndef _IBUILDER_H
#define _IBUILDER_H

class Computer;

class IBuilder
{
public:
	virtual ~IBuilder(){}
	Computer* getComputer(){return computer;}
	
	virtual void buildCpu() = 0;
	virtual void buildGpu() = 0;
	virtual void buildRam() = 0;
	virtual void buildBoard() = 0;
protected:
	Computer* computer;
};

#endif //_IBUILDER_H
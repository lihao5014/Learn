#ifndef _COMPUTER_H
#define _COMPUTER_H

#include <string>
#include <iostream>

class Computer
{
public:
	void setCpu(const std::string& cpu)
	{
		this->cpu = cpu;
	}
	
	void setGpu(const std::string& gpu)
	{
		this->gpu = gpu;
	}

	void setRam(const std::string& ram)
	{
		this->ram = ram;
	}
	
	void setBoard(const std::string& board)
	{
		this->board = board;
	}
	
	void show()const
	{
		std::cout<<cpu<<" , "<<gpu<<" , "<<board<<" , "<<ram<<std::endl;
	}
private:
	std::string cpu;
	std::string gpu;
	std::string ram;	
	std::string board;
};

#endif //_COMPUTER_H
#ifndef _COMPUTER_H
#define _COMPUTER_H

#include "board.h"
#include "gpu.h"
#include "cpu.h"
#include "ram.h"
#include "fan.h"

#include <array>
#include <list>
#include <vector>

#define CPU_COUNT 4
#define RAM_COUNT 4
#define FAN_COUNT 2

using namespace std;

template <typename T>
void safe_delete(T **pptr);

class Computer
{
public:
	Computer(const Board& board,
			 const Gpu& gpu,
			 const Cpu& cpu,
			 const Ram& ram,
			 const Fan& fan);
	Computer(const Computer& other);
	virtual ~Computer();
	
	void detail()const;
private:
	Board board;
	Gpu *gpu;
	array<Cpu*,CPU_COUNT> cpus;
	list<Ram*> rams;
	vector<Fan*> fans;
};

Computer::Computer(const Board& board,
		           const Gpu& gpu,
		           const Cpu& cpu,
		           const Ram& ram,
		           const Fan& fan)
	:board(board)
	,gpu(new Gpu(gpu))
	,cpus{new Cpu(cpu),new Cpu(cpu),new Cpu(cpu),new Cpu(cpu)}
	,rams{new Ram(ram),new Ram(ram),new Ram(ram),new Ram(ram)}
	,fans{new Fan(fan),new Fan(fan)}
{
			 
}

Computer::Computer(const Computer& other)
	:board(other.board)
	,gpu(new Gpu(*(other.gpu)))
	,cpus{new Cpu(*(other.cpus[0])),new Cpu(*(other.cpus[1])),new Cpu(*(other.cpus[2])),new Cpu(*(other.cpus[3]))}
	,fans{new Fan(*(other.fans[0])),new Fan(*(other.fans[1]))}
{
	//因为list不能通过[]或at()访问，所以要实现深拷贝不能在初始化列表中实现
	list<Ram*>::const_iterator citer = other.rams.cbegin();
	for(int i=0;i<RAM_COUNT;++i)
	{
		rams.push_back(new Ram(*(*citer)));
		++citer;
	}
}

Computer::~Computer()
{
	safe_delete(&gpu);
	
	for(int i=0;i<CPU_COUNT;++i)
	{
		safe_delete(&cpus[i]);
	}
	
	for(Ram* pram: rams)
	{
		safe_delete(&pram);
	}
	
	vector<Fan*>::iterator iter = fans.begin();
	while(iter != fans.end())
	{
		safe_delete(&(*iter));
		++iter;
	}
}

void Computer::detail()const
{
	board.display();
	
	if(gpu != nullptr)
	{
		gpu->display();
	}
	
	array<Cpu*,CPU_COUNT>::const_iterator citer = cpus.cbegin();
	while(citer != cpus.cend())
	{
		if(*citer != nullptr)
		{
			(*citer)->show();
		}
		++citer;
	}
	
	for(auto pram: rams)
	{
		if(pram != nullptr)
		{
			pram->print();
		}
	}
	
	for(int i=0;i<FAN_COUNT;++i)
	{
		if(fans[i] != nullptr)
		{
			fans[i]->show();
		}
	}
}

template <typename T>
void safe_delete(T **pptr)
{
	if(*pptr != nullptr)
	{
		delete *pptr;
		*pptr = nullptr;
	}
}

#endif //_COMPUTER_H
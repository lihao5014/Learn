#ifndef _STRATEGY_H
#define _STRATEGY_H

class Strategy
{
public:
	virtual ~Strategy(){}
	virtual double doOperation(int x,int y) = 0;
};

class OperationAdd:public Strategy
{
public:
	virtual double doOperation(int x,int y)
	{
		return x+y;
	}
};

class OperationSub:public Strategy
{
public:	
	virtual double doOperation(int x,int y)
	{
		return x-y;
	}	
};

class OperationMult:public Strategy
{
public:	
	virtual double doOperation(int x,int y)
	{
		return x*y;
	}	
};

class OperationDivi:public Strategy
{
public:
	virtual double doOperation(int x,int y)
	{
		return double(x)/y;
	}	
};

#endif //_STRATEGY_H
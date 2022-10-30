#include "mymath.h"
#include <stdlib.h>

#define _DEBUG_ON_
#include "debug.h"

using namespace std;

double power(double m,int n)
{	
	double ret = 1;
	while(n-->0)
	{
		ret *= m;
	}
	
	cout<<"["<<__TIME__<<" "<<__FILE__<<"] "<<__func__<<" (line:"<<__LINE__<<") -- "<<m<<"^"<<n<<" ="<<ret<<endl;
	return ret;
}

double add(double x,double y)
{
	TRACK(x + y);
	return x + y;
}

double sub(double x,double y)
{
	TRACK(x - y);
	return x - y;
}

double mult(double x,double y)
{
	TRACK(x * y);
	return x * y;
}

double divi(double x,double y)
{
	TRACK(x / y);
	if(y >= -EPS && y <= EPS)
	{
		puts("divi() error: divisor can't to be zero");
		abort();
	}
	
	return x / y;
}
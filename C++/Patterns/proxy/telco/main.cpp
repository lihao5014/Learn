#include "mobile.h"
#include "unicom.h"

int main()
{
	MobileProxy mobile;
	mobile.recharge(60);
	
	UnicomProxy unicom;
	unicom.recharge(120);
	
	return 0;
}
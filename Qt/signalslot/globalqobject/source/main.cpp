#include "cat.h"
#include "mouse.h"

int main()
{
	Cat tom;
	Mouse jerry;
	
	emit tom.miaow("hello jerry");
	emit tom.miaow("waiting for me!");

	return 0;
}
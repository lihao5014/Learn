#include "prime.h"
#include <stdio.h>

int main(void)
{
	if(isPrime(47))
	{
		printf("%d is prime\n",47);
	}
	else
	{
		printf("%d is not prime\n",47);
	}
	
	prime(100);
	
	return 0;
}
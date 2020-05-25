#include <stdio.h>

int sum(const int n);
int SUM(const int n);

int main()
{
	printf("sum =%d\n",sum(10));
	printf("SUM =%d\n",SUM(10));
	
	return 0;
}

int sum(const int n)
{
	int sum =0;
	
	if(n <=0) 
		return -1;
	
	for(int i=1;i<=n;++i)
		sum += i;
	return sum;
}

int SUM(const int n)
{
	int sum =0;
	
	if(n <=0) 
		return -1;

	if(1==n)
		return 1;
	return n+SUM(n-1);
}


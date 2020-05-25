#include <cstdio>

int mult(const int n);
int MULT(const int n);

int main()
{
	printf("mult(%d) =%d\n",5,mult(5));
	printf("MULT(%d) =%d\n",5,MULT(5));
	
	return 0;
}

int mult(const int n)
{
	int mult = 1;
	
	if(n <=0)
		return -1;
	for(int i=1;i<=n;++i)
		mult *= i;
	return mult;
}

int MULT(const int n)
{
	if(n <=0)
		return -1;
	
	if(n == 1)
		return 1;
	return n*MULT(n-1);
}
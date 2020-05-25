#include <stdio.h>
#include <stdlib.h>

static void arithmetic(int x,int y,char ch,double *z);

int main(int argc,char *argv[])
{
	if(argc != 4){
		printf("argc =%d\n",argc);
		return -1;
	}
	
	printf("argv[%d] =%s,argv[%d] =%s,argv[%d] =%s,argv[%d] =%s\n"
		,0,argv[0],1,argv[1],2,argv[2],3,argv[3]);
	
	double result = 0;
	printf("argv[%d] =%s,argv[%d] =%d,argv[%d] =%s,argv[%d] =%d\n"
		,0,argv[0],1,atoi(argv[1]),2,argv[2],3,atoi(argv[3]));
	arithmetic(atoi(argv[1]),atoi(argv[3]),*argv[2],&result);
	
	printf("%d %s %d =%f\n",atoi(argv[1]),argv[2],atoi(argv[3]),result);
	
	return 0;
}

void arithmetic(int x,int y,char ch,double *z)
{
	switch(ch){
	case '+':
		*z = x + y;
		break;
	case '-':
		*z = x - y;
		break;
	case 'x':
		*z = x * y;
		break;
	case '/':
		*z = (double)x/y;;
		break;			
	}
}
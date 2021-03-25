#include <stdio.h>

typedef enum {
	INPUT = 0,
	RUN,
	FINISH,
	EXIT
}Status_t;

int main(void)
{
	int num = 0,sum = 0;
	Status_t status = INPUT;
	while(status != EXIT)
	{
		switch(status){
		case INPUT:{
			printf("输入累加至的数值：");
			scanf("%d",&num);
			getchar();
			
			if(num <= 0)
			{
				puts("输入的数不能小于1");
				status = INPUT;
				break;
			}
			
			sum = 0;
			status = RUN;
			break;
		}
		case RUN:{
			for(int i=0;i<=num;++i)
			{
				sum += i;
			}
			
			status = FINISH;
			break;
		}
		case FINISH:{
			printf("sum =%d\n",sum);
			
			fputs("按任意键继续（q退出）：",stdout);
			if(getchar() == 'q')
			{
				status = EXIT;
			}
			else
			{
				status = INPUT;
			}
			
			getchar();
			break;
		}
		default:
			fprintf(stdout,"status error\n");
		}
	}
	
	puts("退出应用程序！");
	return 0;
}
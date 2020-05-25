#include <stdio.h>
#include <assert.h>

typedef int data_t;

static bool inputNumber(data_t *num);
static void display(const data_t a[],const int size);
int sequenceSearch(const data_t a[],const int size,const data_t num);

int main()
{
	data_t num = 0;
	int size,index = -1;
	data_t a[]={5,4,8,1,2,7,9,0,6,3};
	
	size = sizeof(a)/sizeof(a[0]);
	display(a,size);
	
	if(inputNumber(&num) != false){
		printf("你输入要查找的数是：%d\n",num);		
	}

	index = sequenceSearch(a,size,num);
	if(index == -1){
		printf("num =%d can't find\n",num);
	}else{
		printf("num =%d index =%d\n",num,index);
	}
	
	getchar();
	return 0;
}

bool inputNumber(data_t *num)
{
	printf("请输入0~9之间的数：\n");
	scanf("%d",num);
	if(*num >= 0 && *num <=9){
		return true;
	}else{
		while(getchar() != 'q'){
			printf("请重新输入0~9之间的数：\n");
			scanf("%d",num);
			if(*num >= 0 && *num <=9){
				return true;
			}else{
				printf("按任意字母继续输入，按q退出！\n");
				*num = 0;
				getchar();
			}
		}
	}
	
	return false;
}

void display(const data_t a[],const int size)
{
	assert(a != NULL);
	
	for(int i=0;i<size;++i){
		printf("%d ",a[i]);
	}
	printf("\n");
}

int sequenceSearch(const data_t a[],const int size,const data_t num)
{
	assert(a != NULL);
	
	for(int i=0;i<size;++i){
		if(num == a[i]){
			return i;
		}
	}
	return -1;
}
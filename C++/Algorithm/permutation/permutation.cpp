#include <stdio.h>
#include <string.h>

template <typename T>
static void swap(T &x,T &y);

void permutation(char *str,const int a,const int b);

int main()
{
	char a[] = "abcd";
	
	printf("需要排列的字母是：%s\n",a);
	permutation(a,0,strlen(a)-1);
	
	getchar();
	return 0;
}

template <typename T>
static void swap(T &x,T &y)
{
	T temp;
	temp = x;
	x = y;
	y = temp;
}

void permutation(char *str,const int a,const int b)
{
	if(str == NULL || a < 0 || b < 0){
		printf("permutation warn: str=NULL\n");
		return ;
	}
	
	if(a == b){
		for(int i=0;i<=b;++i){
			printf("%c",str[i]);
		}
		printf("\n");
		return ;
	}
	
	for(int i=a;i<=b;++i){
		swap(str[a],str[i]);
		permutation(str,a+1,b);
		swap(str[a],str[i]);
	}
}


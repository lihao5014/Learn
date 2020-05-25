/*************************************************************************
	> File Name: swap.c
	> Author: 
	> Mail: 
	> Created Time: Thu 15 Mar 2018 03:58:44 PM CST
 ************************************************************************/
#include <stdio.h>

// 传值,不带返回值
void swap1(int a,int b)
{
        int tmp;

        tmp = a;
        a = b;
        b = tmp;
}

// 传地址
void swap2(int *a,int *b)
{
        int tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}

// 值传递，内部输出值
void swap3(int a,int b)
{
        int tmp;

        tmp = a;
        a = b;
        b = tmp;
        printf("3---a=%d,b=%d\n",a,b);
} 

// 值传递，带返回值
void swap4(int a,int b,int *x,int *y)
{
        int tmp;

        tmp = a;
        a = b;
        b = tmp;
        *x=a;
        *y=b;
} 

int main(void)
{
        int a=33,b=88;
        printf("0---a=%d,b=%d\n",a,b);

        swap1(a,b);
        printf("1---a=%d,b=%d\n",a,b);
        
        a=33;b=88;
        swap2(&a,&b);
        printf("2---a=%d,b=%d\n",a,b);

        a=33;b=88;
        swap3(a,b);
//      printf("3---a=%d,b=%d\n",a,b);
       
        a=33;b=88;
        int x=0,y=0;
        swap4(a,b,&x,&y);
        printf("4---a=%d,b=%d\n",x,y);
        return 0;
}

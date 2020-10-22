#include "printui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _REPLACE_WAY_
// #undef _REPLACE_WAY_

#define DrawLine(w,ch)         \
	for(int i=0;i<w;++i)       \
	{                          \
		putchar(ch);           \
	}                          \
	putc('\n',stdout);

#define TOP_SIDE "**********************"
#define MID_SIDE "*                    *"

static int side_length = strlen(TOP_SIDE);

static void showArray(char* parray,int row,int column);

#ifndef _REPLACE_WAY_
//使用(20-len)/2和(20-len+1)/2的目的是防止如果20-len为奇数时，奇数除以2会造成四舍五入精度丢失问题
void welcomeUI(const char* text)
{
	if(NULL == text)
	{
		puts("welcomeUI error: text is null");
		return ;
	}
	
	system("cls");
	int len = strlen(text);
	printf("**********************\n");
	printf("*                    *\n");
	printf("*                    *\n");
	printf("*%*s%s%*s*\n",(20-len)/2," ",text,(20-len+1)/2," "); 
	printf("*                    *\n");
	printf("*                    *\n");
	printf("**********************\n");
	system("pause");
}
#else
void welcomeUI(const char* text)
{
	if(NULL == text)
	{
		fprintf(stdout,"welcomeUI error: text is null\n");
		return ;
	}
	
	system("cls");
	int len = strlen(text);
	
	printf("%s\n",TOP_SIDE);
	printf("%s\n",MID_SIDE);
	printf("%s\n",MID_SIDE);
	
	printf("*");
	for(int i=0;i<(side_length - len - 2)/2;++i)
	{
		printf(" ");
	}
	
	printf("%s",text);
	for(int i=0;i<(side_length - len - 1)/2;++i)
	{
		printf(" ");
	}
	printf("*\n");

	printf("%s\n",MID_SIDE);
	printf("%s\n",MID_SIDE);
	printf("%s\n",TOP_SIDE);
	system("pause");
}
#endif

#ifndef _REPLACE_WAY_
static char framebuffer[7][25] = {
	"************************",
	"*                      *",
	"*                      *",
	"*  text:___________    *",
	"*                      *",
	"*                      *",
	"************************"
};

void simpleUI(const char* text)
{
	if(NULL == text)
	{
		printf("simpleUI error: text is null\n");
		return ;
	}
	
	int len = strlen(text);
	int width = strlen(framebuffer[0]);
	if(len > width - 2)
	{
		puts("simpleUI error: text is too long");
		return ;
	}
	
	char *p = framebuffer[3];
	for(int i=0;i<width;++i)
	{
		if(*p == ':')
		{
			++p;
			memcpy(p,text,len);
			i += len;           //已经拷贝过了的内存，循环应该跳过。否则会造成text中有':'是会重复拷贝
		}
		
		if(*p == '_')
		{
			*p = ' ';
		}
		p++;
	}
	
	system("cls");
	showArray((char*)framebuffer,7,25);
	system("pause");
}
#else
	static char framebuffer[7][25] = {
	"************************",
	"*                      *",
	"*                      *",
	"*                      *",
	"*                      *",
	"*                      *",
	"************************"
};

void simpleUI(const char* text)
{
	if(NULL == text)
	{
		printf("simpleUI error: text is null\n");
		return ;
	}
	
	int len = strlen(text);
	int width = strlen(framebuffer[0]);
	if(len > width - 2)
	{
		puts("simpleUI error: text is too long");
		return ;
	}
	
	char *p = framebuffer[3] + (width - len + 1)/2;
	memcpy(p,text,len);
	
	system("cls");
	showArray((char*)framebuffer,sizeof(framebuffer)/(strlen(framebuffer[0]) + 1),width + 1);
	system("pause");
}
#endif

#ifndef _REPLACE_WAY_
void label(int width,const char *text)
{
	if(text == NULL)
	{
		printf("label error: text is null\n");
		return ;
	}
	
	int len = strlen(text);
	if(len > width - 2)
	{
		puts("label error: text is too long");
		return ;
	}
	
	system("cls");
	DrawLine(width,'*');
	printf("*%*s*\n",width-2," ");
	printf("*%*s*\n",width-2," ");
	printf("*%*s%s%*s*\n",(width-len-2)/2," ",text,(width-len-1)/2," ");
	printf("*%*s*\n",width-2," ");
	printf("*%*s*\n",width-2," ");
	DrawLine(width,'*');
	system("pause");
}
#else
static const int height = 7;

void label(int width,const char *text)     //width宽度是纯字符个数，没有包含字符结尾的'\0'
{
	if(text == NULL)
	{
		printf("label error: text is null\n");
		return ;
	}
	
	int len = strlen(text);
	if(len > width - 2)
	{
		puts("label error: text is too long");
		return ;
	}
	
	const char *p = text;
	char *buf = (char*)malloc(height * (width + 1));    //字符串结尾必须添加一个'\0'
	memset(buf,' ',height * (width + 1));
	
	for(int i=0;i<height;++i)
	{
		for(int j=0;j<width;++j)
		{
			if(i==0 || i==height - 1)
			{
				*(buf + i * (width + 1) + j) = '*';
			}
			
			if(j==0 || j==width - 1)
			{
				*(buf + i * (width + 1) + j) = '*';
			}
			
			if(i==3 && j>(width - len - 2)/2)
			{
				if(*p != '\0')
				{
					*(buf + i * (width + 1) + j) = *p++;
				}
			}
		}
		*(buf + i * (width + 1) + width) = '\0';
	}
	
	system("cls");
	showArray(buf,height,width + 1);
	system("pause");
	
	if(buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
}
#endif

void showArray(char* parray,int row,int column)
{
	if(parray == NULL || row < 0 || column < 0)
	{
		puts("showArray error: parray is null,or row/column is less than zero");
		return ;
	}
	
	for(int i=0;i<row;++i)
	{
		printf("%s\n",parray + i * column);
	}
	putchar('\n');
}
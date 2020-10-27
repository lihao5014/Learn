#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "calculatorUi.h"

//命令行圆面积计算器界面效果：
static const char uiBuffer[HEIGHT_SIZE][WIDTH_SIZE] =
{
	"+------------------------------+",
	"+                              +",
	"+------------------------------+",
	"+       radius:________        +",
	"+         area:________        +",
	"+                              +",
	"+          +---------+         +",
	"+          |calculate|         +",
	"+          +---------+         +",
	"+------------------------------+", 
	"+    0.clear        1.input    +",
	"+    2.calculate    3.quit     +", 
    "+------------------------------+"
};

static void showArray(char* parray,int row,int column);

CalculatorUi::CalculatorUi(const char* title)
{
	if(title == NULL || strlen(title) > MAX_SIZE - 1)
	{
		throw "calculatorUi constructor error: title is null ,or title is too long";
	}
	
	memcpy(this->title,title,strlen(title) + 1);
	memcpy(frameBuffer,uiBuffer,WIDTH_SIZE*HEIGHT_SIZE);
	
	initUi();
}

double CalculatorUi::getRadius()const
{
	return radius;
}

void CalculatorUi::setArea(double area)
{
	this->area = area;
}

void CalculatorUi::setTitle(const char* title)
{
	if(title == NULL || strlen(title) > MAX_SIZE - 1)
	{
		printf("setTitle error: title is null ,or title is too long");
		return ;
	}
	memcpy(this->title,title,strlen(title) + 1);
}

void CalculatorUi::initUi()
{
	radius = 0;
	area = EPS;       //EPS的值可以理解为double类型的0值
	memcpy(frameBuffer,uiBuffer,WIDTH_SIZE*HEIGHT_SIZE);
	
	int len = strlen(title);
	char *p = frameBuffer[1] + (WIDTH_SIZE - 1 - len)/2;       //设置窗口坐标
	memcpy(p,title,len);                                       //这里的len不能加1，因为会导致printf提前打印终结
	
	system("cls");
	showArray((char*)frameBuffer,HEIGHT_SIZE,WIDTH_SIZE);      //字符数组指针char (*frameBuffer)[WIDTH_SIZE]需要强转为char*字符指针
}

void CalculatorUi::update()
{
	if(radius >= -EPS && radius <= EPS)
	{
		memcpy(frameBuffer[3],uiBuffer[3],strlen(uiBuffer[3]) + 1);
	}
	else
	{
		char strRadius[MAX_SIZE] = {0};
		sprintf(strRadius,"%f",radius);
		char *p = frameBuffer[3];               //界面显示半径值
		for(int i=0;i<WIDTH_SIZE;++i)
		{
			if(*p == ':')
			{
				memcpy(++p,strRadius,strlen(strRadius));
				i += strlen(strRadius);
			}
			
			if(*p == '_')
			{
				*p = ' ';
			}
			p++;
		}
	}
	
	if(area >= -EPS && area <= EPS)
	{
		memcpy(frameBuffer[4],uiBuffer[4],strlen(uiBuffer[4]) + 1);
	}
	else
	{
		char strArea[MAX_SIZE] = {0};
		sprintf(strArea,"%f",area);
		char *q = frameBuffer[4] + strlen("+         area:");     //界面显示面积值
		memcpy(q,strArea,strlen(strArea));
		
		q += strlen(strArea);
		for(int i=0;i<WIDTH_SIZE - (q - frameBuffer[5]);++i)
		{
			if(*q == '_')
			{
				*q = ' ';
			}
			q++;
		}
	}
	
	system("cls");
	showArray((char*)frameBuffer,HEIGHT_SIZE,WIDTH_SIZE);       //字符数组指针char (*frameBuffer)[WIDTH_SIZE]需要强转为char*字符指针
}

void CalculatorUi::inputRadius()
{
	for(;;)
	{
		printf("Please input radius: ");
		scanf("%lf",&radius);
		if(radius >= EPS)
		{
			area = EPS;
			break;
		}
		
		puts("Radius can't less than zero,please input again");
	}
}

void showArray(char* parray,int row,int column)
{
	if(parray == NULL || row < 0 || column < 0)
	{
		puts("showArray error: parray is null or row/column is less than zero");
		return ;
	}
	
	for(int i=0;i<row;++i)
	{
		printf("%s\n",parray + i*column);
	}
	putchar('\n');
}
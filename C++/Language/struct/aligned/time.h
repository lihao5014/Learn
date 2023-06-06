#ifndef _TIME_H
#define _TIME_H

/*头文件中包含其他头文件不是必须的。如果当前头文件中不包含，则使用当前头文件的源文件必须包含，
 *且包含的顺序为在当前头文件以前。
 */
// #include <stdio.h> 
// #include <string.h>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define TIME_SIZE sizeof(Time)

typedef enum Time_t
{
	YEAR,
	MONTH,
	DAY,
	TIME_COUNT
}Time_t;

//因为Time类型中包含的变量都是int类型，所以Time结构体转化为数组时不用考虑字节对齐问题
typedef struct Time
{
	int year;
	int month;
	int day;
}Time;

const int time_size = sizeof(struct Time);
const int time_count = sizeof(Time)/sizeof(int);

#if 1
int timeArr[TIME_COUNT] = {0};                      //全局变量，用于模块之间传输数据
#else
int timeArr[time_size] = {0};                       //错误，不能使用变量指定数组大小。只能使用数字，枚举，宏，sizeof运算符
#endif

#ifndef _CHANGE_WAY_
void showTime(const Time time)
{
	printf("%d:%d:%d\n",time.year,time.month,time.day);
}

void showArray(const int* arr,int size)
{
	if(arr == NULL || size <0 || size > time_size)
	{
		fprintf(stdout,"showArray warn: input is illegal\n");
		return ;
	}
	
	for(int i=0;i<size;++i)
	{
		if(i == size -1)
		{
			printf("%d\n",*(arr+i));
			return ;
		}
		printf("%d:",arr[i]);
	}
}

void sendTime(const Time time)
{
	memset(timeArr,0,time_size);
	timeArr[YEAR] = time.year;
	timeArr[MONTH] = time.month;
	timeArr[DAY] = time.day;
}

void receiveTime(Time *time)
{
	if(time == NULL)
	{
		puts("receiveTime warn: time is null");
		return ;
	}
	
	time->year = timeArr[YEAR];
	time->month = timeArr[MONTH];
	time->day = timeArr[DAY];
	memset(timeArr,0,time_size);
}
#else
void showTime(const Time time)
{
	int arr[TIME_COUNT] = {0};
	Time* ptime = (Time*)arr;
	
	ptime->year = time.year;
	ptime->month = time.month;
	ptime->day = time.day;
	
	for(int i=0;i<time_count;++i)
	{
		if(i == time_count -1)
		{
			printf("%d\n",*(arr+i));
			return ;
		}
		printf("%d:",arr[i]);
	}
}

void showArray(const int* arr,int size)
{
	if(arr == NULL || size <0 || size > time_size)
	{
		fprintf(stdout,"showArray warn: input is illegal\n");
		return ;
	}
	
	const Time *ptime = (const Time*)arr;
	printf("%d:%d:%d\n",ptime->year,ptime->month,ptime->day);
}

void sendTime(const Time time)
{
	memset(timeArr,0,sizeof(timeArr));
	memcpy(timeArr,&time,sizeof(Time));
}

void receiveTime(Time *time)
{
	if(time == NULL)
	{
		fputs("receiveTime warn: time is null",stdout);
		return ;
	}
	
	memcpy(time,timeArr,sizeof(timeArr));
}
#endif   //_CHANGE_WAY_

#endif  //_TIME_H
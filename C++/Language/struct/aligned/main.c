#include <stdio.h>
#include <string.h>
#include "time.h"

int main()
{
	Time time1 = {2020,4,10};
	
	showTime(time1);
	sendTime(time1);
	showArray(timeArr,time_count);
	
	Time time2;
	receiveTime(&time2);
	showTime(time2);
	
	time2.year = 2019;
	time2.month = 4;
	time2.day = 23;
	showTime(time2);
	
	char buf[sizeof(Time)] = {0};
	memcpy(buf,&time2,time_size);
	showArray((int*)buf,sizeof(buf)/sizeof(int));
	
	Time* ptime1 = (Time*)buf;
	printf("%d:%d:%d\n",ptime1->year,ptime1->month,ptime1->day);
	
	char arr[TIME_SIZE] = {0};             //不能使用char arr[time_size]定义数组，因为time_size是变量，而不是常量
	Time* ptime2 = (Time*)arr;
	ptime2->year = 2018;
	ptime2->month = 8;
	ptime2->day = 15;
	showArray((int*)arr,sizeof(arr)/sizeof(int));
	
	return 0;
}
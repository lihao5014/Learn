#define _DEBUG_
#include "language.h"

typedef enum Attribute
{
	INIT_VALUE,
	PERCISION,
	TOP_LIMIT,
	BOTTOM_LIMIT,
	TOP_VIEW_,
	BOTTOM_VIEW,
	ATTRIBUTE_COUNT          //记录枚举值个数
}Attribute;

int main()
{
	showLanguage();
	
	DEBUG(language_data[CHINESE]);        //可以使用名称有意义的枚举值，作为数组下标以提高数组访问的阅读性
	TRACK(language_data[FRENCH]);
	
	double variable[ATTRIBUTE_COUNT];
	variable[INIT_VALUE] = 31.415000;
	variable[PERCISION] = 6;
	variable[TOP_LIMIT] = 100.000000;
	variable[BOTTOM_LIMIT] = 5.000000;
	variable[TOP_VIEW] = 50.000000;
	variable[BOTTOM_VIEW] = 20.000000;
	
	printf("varable init value is %f\n",variable[INIT_VALUE]);
	printf("varable top limit is %f\n",variable[TOP_LIMIT]);
	
	return 0;
}
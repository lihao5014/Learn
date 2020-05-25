#ifndef _LANGUAGE_H
#define _LANGUAGE_H

#include <stdio.h>

#if (defined _DEBUG_) | (defined _TRACK_)
#define DEBUG(expr)   \
	printf("%s = %s\n",#expr,(expr))
#define TRACK(expr)  \
	printf("[%s: %s %d] %s =%s\n",__FILE__,__func__,__LINE__,#expr,(expr))
#else
#define DEBUG(expr)
#define DEBUG(expr)	
#endif

typedef enum Language_t
{
	UNKNOWN,
	CHINESE,
	ENGLISH,
	FRENCH,
	GERMAN,
	SPANISH,
	JAPANESE,
	KOREAN
}Language;

//使用C99新特性
const char* language_data[] = {
	[UNKNOWN] = "未知",
	[CHINESE] = "中文",
	[ENGLISH] = "英文",
	[FRENCH] = "法语",
	[GERMAN] = "德语",
	[SPANISH] = "西班牙语",
	[JAPANESE] = "日语",
	[KOREAN] = "韩语"
};

const int language_data_size = sizeof(language_data)/sizeof(language_data[0]);

void showLanguage()
{
	for(int i=0;i<language_data_size;++i)
	{
		puts(language_data[i]);
	}
	putc('\n',stdout);
}

#endif //_LANGUAGE_H
#ifndef _MYSTRING_H
#define _MYSTRING_H

//求字符串的长度 
int myStrlen(const char* str);

//长度不受限制的字符串函数 
char* myStrcpy(char *dst,const char* src);
bool myStrcmp(const char *str1,const char *str2);
char* myStrcat(char* dst,const char* src);

//长度受限制的字符串函数 
char* myStrncpy(char *dst,const char *src,int n);
bool myStrncmp(const char *str1,const char *str2,int n);
char* myStrncat(char* dst,const char* src,int n);

//字符串查找 
char* myStrchr(const char* src,const char chr);
char* myStrstr(const char* src,const char* str);
char* myStrrchr(const char* src,const char chr);
char* myStrpbrk(const char* src,const char* key);

//显示字符串
void strShow(const char *str);

//截取子字符串
char* strLeft(const char* src,const int n);
char* strRight(const char* src,const int n);
char* strMid(const char* src,const int index,const int n);

//判断字符串的开头语结尾
bool startWith(const char* src,const char* str);
bool endWith(const char* src,const char* str);
bool contains(const char* src,const char* str);

#endif  //_MYSTRING_H
#ifndef _STUDENT_H
#define _STUDENT_H

#include <stddef.h>             //offsetof宏包含在stddef.h头文件中

#define NAME_SIZE 128
#define ADDRESS_SIZE 256
#define TELEPHONE_SIZE 32

#define GIRL 0
#define BOY 1
typedef char Sex;

#define STUDENT_SIZE sizeof(struct Student)

//因为student类型不是字节对齐的，所以只能转化为字符型数组
typedef struct Student
{
	int num;                        //学号
	char name[NAME_SIZE];           //名字
	Sex sex;                        //性别
	char age;                       //年龄
	double score;                   //分数
	char addr[ADDRESS_SIZE];        //地址
	char tel[TELEPHONE_SIZE];       //电话
}Student;

typedef enum Student_t
{
	NUM,
	NAME,
	SEX,
	AGE,
	SCORE,
	ADDRESS,
	TELEPHONE,
	PROPERTY_COUNT
}Student_t;

extern const int offsetArr[PROPERTY_COUNT];

void showStudent(const Student student);
void showArray(const char arr[],int size);

void studentToArray(const Student student,char* arr,int arrSize);
void arrayToStudent(const char* arr,int arrSize,Student* student);

//这两方法相同，都等于memcpy函数
void structToArray(void* arr,const void* pstruct,int size);
void arrayToStruct(void* pstruct,const void* arr,int size);

#endif //_STUDENT_H
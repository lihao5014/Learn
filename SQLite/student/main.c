/*Windows系统中配置第三方库的搜索路径是为了，方便cl编译器在预处理或衔接阶段能直接找到所需的
 *头文件或库文件，而不用指定第三方库的绝对路径。不过一般不推荐将第三方库配置到MSVC编译器的
 *搜索路径中，因为这可能造成项目源码在本机可以正常编译运行，而拷贝到其他计算机就无法编译通过
 *或正常运行。推荐的做法是将第三库头文件或库文件直接拷贝到项目源码路径下使用。
 */

/*Windows系统中配置第三方库的方法：
 *1.让cl编译器找到头文件：新建一个INCLUDE环境变量，并指定该环境变量的值包含第三方库头文件路径。
 *  即cl/MSVC/VS编译器的头文件搜索路径是由INCLUDE环境变量指定的。
 *2.让cl编译器找到库文件：新建一个LIB环境变量，并指定该环境变量的值包含第三方库文件路径。
 *  即cl/MSVC/VS编译器的库文件搜索路径是由LIB环境变量指定的。
 *3.PATH环境变量只能用于指定可执行程序exe，命令、工具的搜索路径，而不能用于配置Windows第三方库
 *  头文件和库文件路径。因为cl/MSVC/VS编译器在预处理或衔接阶段，不会到PATH环境变量指定的路径中
 *  去寻找库文件或头文件。WIndows系统中指定第三方库头文件需要使用INCLUDE环境变量，指定第三方库
 *  文件需要使用LIB环境变量。如果Windows系统中不存在INCLUDE/LIB环境变量，只需要自己新建就行。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

//将sqlite3库配置到MSVC编译器的查找路径中后，使用sqlite3.dll动态库时必须显示的加载sqlite3.lib导入库。
#pragma comment(lib,"sqlite3.lib")

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define NAME_LENGTH 64
#define MAX_SQL_SIZE 1024

typedef struct Student_t
{
	int id;
	char name[NAME_LENGTH];
	int age;
	double score;
}Student;

static Student student_table[] = {
	{1,"amy",25,80},
	{2,"lisa",26,75},
	{3,"bob",23,67},
	{4,"kevin",24,92},
	{5,"jorden",24,73},
	{6,"james",27,58},
	{7,"linda",23,76},
	{8,"david",26,69},
	{9,"susan",22,86}
};

static int callback(void *data,int column,char** rowData,char** columnName)
{
	if(data != NULL)
		printf("%s\n",(char*)data);
	
	for(int i=0;i<column;++i)
	{
		printf("%s =%s\n",columnName[i],rowData[i] ? rowData[i] : "null");
	}
	putchar('\n');
	
	return 0;
}

int main(void)
{
	FILE *db_fp = fopen("class.db","r");    //以只读方式打开文件，以判断文件是否存在
    
	sqlite3 *db;
	int ret = sqlite3_open("class.db",&db);     //打开或者创建student.db数据库
	if(ret != SQLITE_OK)
	{
		printf("class.db open failed: %s\n",sqlite3_errmsg(db));
		return -1;
	}
	
	char *errmsg = NULL;
	char sql[MAX_SQL_SIZE] = {0};
	if(db_fp == NULL)
    {
		//在class.db数据库中创建一张students表格
		sprintf(sql,"create table students(id integer primary key,name char(64),age int,score double)");
		ret = sqlite3_exec(db,sql,NULL,NULL,&errmsg);
		if(ret != SQLITE_OK)
		{
			printf("class.db create table students error: %s\n",errmsg);
			sqlite3_close(db);
			return -1;
		}
		puts("create table successfully!");
		
		//在students表格中插入几条记录
		for(int i=0;i<sizeof(student_table)/sizeof(student_table[0]);++i)
		{
			memset(sql,0,MAX_SQL_SIZE);
			sprintf(sql,"insert into students values(%d,'%s',%d,%f)",
				student_table[i].id,
				student_table[i].name,
				student_table[i].age,
				student_table[i].score);
				
			ret = sqlite3_exec(db,sql,NULL,NULL,&errmsg);
			if(ret != SQLITE_OK)
			{
				fprintf(stdout,"students insert record error: %s\n",errmsg);
				sqlite3_close(db);
				return -1;
			}
		}
		puts("students table insert data successfully!");
    }
	else
	{
		//显示students表格中的所以
		sprintf(sql,"select * from students");
#ifndef _CHANGE_WAY_
		const char* data = "Callback function called:";
		ret = sqlite3_exec(db,sql,callback,(void*)data,&errmsg);
		if(ret != SQLITE_OK)
		{
			fprintf(stdout,"select from students error: %s\n",errmsg);
			sqlite3_close(db);
			return -1;
		}
#else
		int row = 0;
		int column = 0;
		char **result = NULL;
		ret = sqlite3_get_table(db,sql,&result,&row,&column,&errmsg);
		if(ret != SQLITE_OK)
		{
			fprintf(stdout,"select from students error: %s\n",errmsg);
			sqlite3_close(db);
			return -1;
		}
		
		printf("result table: row =%d, column =%d\n",row,column);
		char** resultTable = result;
		for(int i=0;i<=row;++i)     //首行为表头，表格数据从index=1开始，所以使用i<=row
		{
			for(int j=0;j<column;++j)
			{
				printf("%s \t",*resultTable++);
			}
			puts("");
		}
		
		sqlite3_free_table(result);
#endif
	}
	
	sqlite3_close(db);
	return 0;
}
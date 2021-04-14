#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "include/sqlite3.h"

#pragma comment(lib,"lib/sqlite3.lib")

static bool isPrintHeader = false;

static void create_table(sqlite3 *db);
static void insert_table(sqlite3 *db);
static void select_all_table(sqlite3 *db);
static void select_part_table(sqlite3 *db);
static void update_table(sqlite3 *db);
static void delete_table(sqlite3 *db);

static int callback(void *data,int column,char** rowData,char** columnName)
{
	if(data != NULL)
		printf("%s\n",(char*)data);

	if(!isPrintHeader)      //保证表头只打印一次
	{
		for(int i=0;i<column;++i)
		{
			printf("%-12s\t",columnName[i]);
		}
		fputs("\n",stdout);
	}
	isPrintHeader = true;
		
	for(int i=0;i<column;++i)
	{	
		printf("%-12s\t",rowData[i] ? rowData[i] : NULL);
	}
	puts("");
}

int main(void)
{
	sqlite3 *db = NULL;
	int ret = sqlite3_open("bin/company.db",&db);
	if(ret != SQLITE_OK)
	{
		printf("class.db open failed: %s\n",sqlite3_errmsg(db));
		return -1;
	}
	fputs("opened database successfully\n",stdout);
	
	create_table(db);
	fputs("\n",stdout);
	
	insert_table(db);
	puts("");
	
	select_all_table(db);
	fputc('\n',stdout);
	
	select_part_table(db);
	putc('\n',stdout);
	
	update_table(db);
	putchar('\n');
	
	select_all_table(db);
	fprintf(stdout,"\n");
	
	delete_table(db);
	printf("\n");
	
	sqlite3_close(db);
	return 0;
}

void create_table(sqlite3 *db)
{
	if(db == NULL)
	{
		puts("create table error: db is null");
		return ;
	}
	
	//命令行中执行的SQL语句必须以';'分号结尾，而C/C++编程接口中执行的sql语句可以接';'分号结尾，也不可接';'分号结尾
	char *errmsg = NULL;
	char *sql = "create table employees(id int primary key,name text,age int,address char(64),salary real)";
	int ret = sqlite3_exec(db,sql,NULL,NULL,&errmsg);
	if(ret != SQLITE_OK)
	{
		printf("create table employees error: %s\n",errmsg);
		sqlite3_free(errmsg);
		sqlite3_close(db);
		exit(-1);
	}
	
	puts("table create successfully");
}

void insert_table(sqlite3 *db)
{
	if(db == NULL)
	{
		puts("create table error: db is null");
		return ;
	}
	
	char *errmsg = NULL;
	char *sql = "insert into employees values(1,'Paul',32,'California',20000.00);"  \
	            "insert into employees values(2,'Allen',25,'Texas',15000.00);"      \
	            "insert into employees values(3,'Teddy',23,'Norway',25000.00);"     \
	            "insert into employees values(4,'Mark',25,'Rich-Mond',60000.00);"   \
	            "insert into employees values(5,'James',28,'New-York',45000.00);";

	int ret = sqlite3_exec(db,sql,NULL,NULL,&errmsg);
	if(ret != SQLITE_OK)
	{
		printf("insert data to employees error: %s\n",errmsg);
		sqlite3_free(errmsg);
		sqlite3_close(db);
		exit(-1);
	}
	
	puts("insert data to table successfully");
}

void select_all_table(sqlite3 *db)
{
	if(db == NULL)
	{
		puts("select all table error: db is null");
		return ;
	}
	
	int row = 0;
	int column = 0;
	char *errmsg = NULL;
	char **resultTable = NULL;
	char *sql = "select * from employees";
	int ret = sqlite3_get_table(db,sql,&resultTable,&row,&column,&errmsg);
	if(ret != SQLITE_OK)
	{
		printf("select all data from table employees error: %s\n",errmsg);
		sqlite3_free(errmsg);
		sqlite3_close(db);
		exit(-1);
	}
	
	char **result = resultTable;
	for(int i=0;i<=row;++i)
	{
		for(int j=0;j<column;++j)
		{
			printf("%-12s\t",*result++);
		}
		puts("");
	}
	
	puts("select all data from table successfully");
	sqlite3_free_table(resultTable);
}

void select_part_table(sqlite3 *db)
{
	if(db == NULL)
	{
		puts("select part table error: db is null");
		return ;
	}
	
	char *errmsg = NULL;
	char *sql = "select name,age,address from employees where age > 26";
	int ret = sqlite3_exec(db,sql,callback,NULL,&errmsg);
	if(ret != SQLITE_OK)
	{
		printf("create table employees error: %s\n",errmsg);
		sqlite3_free(errmsg);
		sqlite3_close(db);
		exit(-1);
	}
	
	puts("select part data from table successfully");
}

void update_table(sqlite3 *db)
{
	if(db == NULL)
	{
		puts("update table error: db is null");
		return ;
	}
	
	char *errmsg = NULL;
	char *sql = "update employees set salary =30000 where id =1 or salary =25000";
	int ret = sqlite3_exec(db,sql,NULL,NULL,&errmsg);
	if(ret != SQLITE_OK)
	{
		printf("update table employees error: %s\n",errmsg);
		sqlite3_free(errmsg);
		sqlite3_close(db);
		exit(-1);
	}
	
	puts("table update successfully");
}

void delete_table(sqlite3 *db)
{
	if(db == NULL)
	{
		puts("delete table error: db is null");
		return ;
	}
	
	//命令行中执行的SQL语句必须以';'分号结尾，而C/C++编程接口中执行的sql语句可以接';'分号结尾，也不可接';'分号结尾
	char *errmsg = NULL;
	char *sql = "drop table employees;";
	int ret = sqlite3_exec(db,sql,NULL,NULL,&errmsg);
	if(ret != SQLITE_OK)
	{
		printf("delete table employees error: %s\n",errmsg);
		sqlite3_free(errmsg);
		sqlite3_close(db);
		exit(-1);
	}
	
	puts("table delete successfully");
}
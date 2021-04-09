#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>
#include <mysql.h>

#pragma comment(lib,"libmysql.lib")
#pragma comment(lib,"mysqlclient.lib")

#define UNUSED(x) (void)x

int main(int argc,char *argv)
{
	UNUSED(argc);
	UNUSED(argv);
	
	const char* server = "localhost";
	const char* user = "root";
	const char* password = "123456";
	const char* database = "testdb";

	MYSQL *conn = mysql_init(NULL);
	if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0))
	{
		printf("connect mysql failed: %s\n",mysql_error(conn));
		return -1;
	}
	
	puts("connect successed!");
	mysql_close(conn);
	
	return 0;
}
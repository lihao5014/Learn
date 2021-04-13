//因为安装的SQLite数据库是win64位，所以必须使用MSVC 64位编译器进行编译。

/*1.SQLite3函数接口：
 *（1）打开数据库:
 *	int sqlite3_open(const char* filename,sqlite3 **ppDb);
 *  功能：打开一个指向SQLite数据库文件的连接，返回一个用于其他SQLite程序的数据库连接对象。
 *  参数：filename——要操作的数据库文件的路径名，ppdb——代表数据库的操作句柄（SQLite db handle）。
 *  返回值：成功——SQLITE_OK，出错——错误码。
 *  注意：如果filename参数是NULL或':memory:'，那么sqlite3_open()将会在RAM中创建一个内存数据库，这只会在
 *        session的有效时间内持续。如果文件名filename不为NULL，那么sqlite3_open()将使用这个参数值尝试打开
 *        数据库文件。如果该名称的文件不存在，sqlite3_open()将创建一个新的命名为该名称的数据库文件并打开。
 *
 *（2）关闭数据库：
 *	int sqlite3_close(sqlite3* db);
 *  功能：关闭之前调用sqlite3_open()打开的数据库连接。
 *  参数：db——操作数据库的句柄。
 *  返回值：成功——SQLITE_OK，出错——错误码。
 *  注意：所有与连接相关的语句都应在连接关闭之前完成。如果还有查询没有完成，sqlite3_close()将返回SQLITE_BUSY
 *        禁止关闭的错误消息。
 *
 *（3）获取数据库操作的错误信息：
 * const char* sqlite3_errmsg(sqlite3* db);
 * 参数：db——SQLite database handle。
 * 返回值：错误信息的首地址。
 *
 *（4）执行sql语句：
 * int sqlite3_exec(sqlite3* db,const char* sql,sqlite3_callback callback,void* data,char **errmsg);
 * 功能：提供了一个执行SQL命令的快捷方式，SQL命令由sql参数提供，可以由多个SQL命令组成。
 * 参数：db——数据库操作句柄（An open database handle）。
 *       sql——一条sql语句（SQL to be evaluated）。
 *       callback——只有sql为查询语句时，才会执行此回调函数（Callback function）。
 *	     data——传递给回调函数callback的第一个参数（1st argument to callback）。
 *       errmsg——错误消息（Error msg written here）。
 * 返回值：成功——SQLITE_OK，出错——错误码。
 *
 *（5）获取查询结果：
 * typedef int (*sqlite3_callback)(void* data, int column, char** rowData, char** columnName);
 * 功能：这个回调提供了一个从SELECT语句获得结果的方式，函数的调用次数等于查询记录的条数。即如果sqlite3_callback回调在
         sqlite_exec()程序中作为第三个参数，那么SQLite将为SQL参数内执行的每个SELECT语句中处理的每条记录调用该回调函数。
 * 参数：data——sqlite3_exec()函数中传递给回调函数的参数（Data provided in the 4th argument of sqlite3_exec()）。
 *		 column——记录中包含的字段数目，即表格列数（The number of columns in row）。
 *       rowData——包含每个字段值的指针数组，即表格中每一行数据（An array of strings representing fields in the row）。
 *       columnName——包含每个字段名称的指针数组，即表格头（An array of strings representing column names）。
 * 返回值：成功返回0，失败返回-1。
 */

#include <stdio.h>
#include <sqlite3.h>

#ifdef _CHANGE_WAY_
#pragma message("---explicit load sqlite3.lib")
#pragma comment(lib,"sqlite3.lib")
#else
#pragma message("---implicit load sqlite3.lib")
#endif

int main(void)
{
	sqlite3 *db;
	
	int ret = sqlite3_open("bin/test.db",&db);
	if(ret != SQLITE_OK)
	{
		fprintf(stderr,"Can't open database: %s\n",sqlite3_errmsg(db));
		exit(-1);
	}
	else
	{
		puts("Opened database successfully\n");
	}

	sqlite3_close(db);

	return 0;
}
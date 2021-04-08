/*
  QtSql模块的类分层:
  +---------------------------------------------------------------------------------------------+
  | 用户接口层                                                                                  |
  |(QSqlQueryModel，QSqlTableModel和QSqlRelationalTableModel)                                   |
  +---------------------------------------------------------------------------------------------+
  | SQL接口层                                                                                   |
  |(QSqlDababase，QSqlQuery，QSqlError，QSqlField，QSqlIndex和QSqlRecord)                       |
  +---------------------------------------------------------------------------------------------+
  | 驱动层                                                                                      |
  |(QSqlDriver，QSqlDriverCreator<T>，QSqlDriverCreatorBase，QSqlDriverPlugin和QSqlResult)      |
  +---------------------------------------------------------------------------------------------+
  
  1.驱动层：为具体的数据库和SQL接口层之间提供了底层的桥梁。
  2.SQL接口层：提供了对数据库的访问，其中的QSqlDatabase类用来创建连接，QSqlQuery类可以使用SQL语句
    来实现与数据库交互，其他几个类对该层提供了支持；
  3.用户接口层：实现了将数据库中的数据链接到窗口部件上的功能。这些类是使用模型/视图框架实现的，
    它们是更高层次的抽象，即便不熟悉SQL也可以操作数据库。
  4.如果要使用QtQql模块中的这些类，需要在项目文件（.pro文件）中添加QT += sql这一行代码。
*/

/*QtSql模块使用数据库驱动来和不同的数据库接口进行通信。由于Qt的SQL模型的接口是独立于数据库的，
 *所以所有数据库特定的代码都包含在了这些驱动中。
 */

/*Qt5支持的数据库驱动：（但由于GPL许可证的兼容性问题，并不是这里列出的所有驱动插件都提供给了Qt的开源版本）
  驱动类型         描述
    QDB2	       IBM DB2
    QIBASE         Borland InterBase Driver
    QMYSQL         MySql Driver
    QOCI	       Oracle Call Interface Driver
    QODBC	       ODBC Driver（includes Microsoft SQL Server）
    QPSQL	       PostgreSQL Driver
    QSQLITE	       SQLite version 3 or above
    QSQLITE2	   SQLite version 2
    QTDS	       Sybase Adaptive Server
*/

//通过程序来查看一下现在版本的Qt中可用的数据库插件
#include <QSqlDatabase>
#include <QStringList>
#include <QtGlobal>
#include <QDebug>

int main(int argc, char *argv[])
{
	Q_UNUSED(argc);
	Q_UNUSED(argv);
	
    qDebug() << "available drivers:";
    QStringList drivers = QSqlDatabase::drivers();   //获取支持的数据库驱动
    foreach(QString driver, drivers)
        qDebug() << driver;

    return 0;
}

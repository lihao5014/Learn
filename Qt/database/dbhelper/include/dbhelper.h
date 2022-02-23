#ifndef _DB_HELPER_H
#define _DB_HELPER_H

#include <QString>
#include <QVariant>
#include <QList>
#include <QHash>
#include <QSqlDatabase>
#include "singleton.h"
#include "dbconfig.h"

typedef QHash<QString,QVariant> DBRecord_t;
typedef QList<DBRecord_t> DBResult_t;

class DBHelper:public Singleton<DBHelper>
{
	friend class Singleton<DBHelper>;
public:
	bool openDB(const DBConfig& config);
	bool reconnectDB();
	
	bool insertToDB(const QString& tableName,const DBRecord_t& record);
	bool deleteFromDB(const QString& tableName,const QString& sqlWhere);
	bool updateToDB(const QString& tableName,const DBRecord_t& record,const QString& sqlWhere = "");
	bool selectFromDB(const QString& tableName,DBResult_t& result,const QString& sqlWhere = "");
	bool clearTable(const QString& tableName);
	
	bool execSql(const QString& strSql);
	bool execSql(const QString& strSql,DBResult_t& result);
	
	bool transaction();
	bool commit();
	bool rollback();
	
private:
	DBHelper();
	
	DBConfig m_config;
	QSqlDatabase m_database;
};

#endif  //_DB_HELPER_H
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
	bool openDB(const DBConfig& config,QString* error = nullptr);
	bool reconnectDB(QString* error = nullptr);
	
	bool insertToDB(const QString& tableName,const DBRecord_t& record,QString* error = nullptr);
	bool deleteFromDB(const QString& tableName,const QString& sqlWhere,QString* error = nullptr);
	bool updateToDB(const QString& tableName,const DBRecord_t& record,const QString& sqlWhere = "",QString* error = nullptr);
	bool selectFromDB(const QString& tableName,DBResult_t& result,const QString& sqlWhere = "",QString* error = nullptr);
	bool clearTable(const QString& tableName,QString* error = nullptr);
	
	bool execSql(const QString& strSql,QString* error = nullptr);
	bool execSql(const QString& strSql,DBResult_t& result,QString* error = nullptr);
	
	bool transaction(QString* error = nullptr);
	bool commit(QString* error = nullptr);
	bool rollback(QString* error = nullptr);
	
private:
	DBHelper();
	
	QSqlDatabase m_database;
};

#endif  //_DB_HELPER_H
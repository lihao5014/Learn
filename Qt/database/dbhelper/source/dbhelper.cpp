#include "dbhelper.h"
#include <QTextCodec>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>

DBHelper::DBHelper()
{
	// QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
}

bool DBHelper::openDB(const DBConfig& config,QString* error)
{
	m_database = QSqlDatabase::addDatabase("QMYSQL");
	m_database.setHostName(config.m_ip);
	m_database.setPort(config.m_port);
	m_database.setUserName(config.m_username);
	m_database.setPassword(config.m_password);
	m_database.setDatabaseName(config.m_databaseName);
	
	if(!m_database.open())
	{
		QString strError = m_database.lastError().text();
		qDebug()<<strError;
		
		if(error != nullptr)
		{
			*error = strError;
		}
		return false;
	}
	return true;
}

bool DBHelper::reconnectDB(QString* error)
{
	if(m_database.isOpen())
	{
		return true;
	}
	
	if(!m_database.open())
	{
		QString strError = m_database.lastError().text();
		qDebug()<<strError;
		
		if(error != nullptr)
		{
			*error = strError;
		}
		return false;
	}
	return true;
}

bool DBHelper::insertToDB(const QString& tableName,const DBRecord_t& record,QString* error)
{
	if(tableName.isEmpty() || record.isEmpty() || !reconnectDB(error))
	{
		return false;
	}
	
	QString strFields,strValues;
	for(auto citer = record.constBegin();citer != record.constEnd();++citer)
	{
		strFields += citer.key() + ",";
		strValues += ":" + citer.key() + ",";
	}
	strFields.chop(1);
	strValues.chop(1);
	QString strSql = QString("insert into %1(%2) values(%3)").arg(tableName).arg(strFields).arg(strValues);
	
	QSqlQuery query(m_database);
	query.prepare(strSql);
	for(auto citer = record.constBegin();citer != record.constEnd();++citer)
	{
		QString placeholder = ":" + citer.key();
		query.bindValue(placeholder,citer.value());
	}
	
	if(!query.exec())
	{
		QString strError = query.lastError().text();
		qDebug()<<strError;
		
		if(error != nullptr)
		{
			*error = strError;
		}
		return false;
	}
	return true;
}

bool DBHelper::deleteFromDB(const QString& tableName,const QString& sqlWhere,QString* error)
{
	if(tableName.isEmpty() || sqlWhere.isEmpty())
	{
		return false;
	}
	
	QString strSql = QString("delete from %1 %2").arg(tableName).arg(sqlWhere);
	return execSql(strSql,error);
}

bool DBHelper::updateToDB(const QString& tableName,const DBRecord_t& record,const QString& sqlWhere,QString* error)
{
	if(tableName.isEmpty() || record.isEmpty() || !reconnectDB(error))
	{
		return false;
	}
	
	QString strSet;
	for(auto citer = record.constBegin();citer != record.constEnd();++citer)
	{
		strSet += citer.key() + " = :" + citer.key() + ",";
	}
	strSet.chop(1);
	QString strSql = QString("update %1 set %2 %3").arg(tableName).arg(strSet).arg(sqlWhere);
	
	QSqlQuery query(m_database);
	query.prepare(strSql);
	for(auto citer = record.constBegin();citer != record.constEnd();++citer)
	{
		QString placeholder = ":" + citer.key();
		query.bindValue(placeholder,citer.value());
	}
	
	if(!query.exec())
	{
		QString strError = query.lastError().text();
		qDebug()<<strError;
		
		if(error != nullptr)
		{
			*error = strError;
		}
		return false;
	}
	return true;
}

bool DBHelper::selectFromDB(const QString& tableName,DBResult_t& result,const QString& sqlWhere,QString* error)
{
	if(tableName.isEmpty())
	{
		return false;
	}
	
	QString strSql = QString("select * from %1 %2").arg(tableName).arg(sqlWhere);
	return execSql(strSql,result,error);
}

bool DBHelper::clearTable(const QString& tableName,QString* error)
{
	if(tableName.isEmpty())
	{
		return false;
	}

	QString strSql = QString("delete from %1").arg(tableName);
	return execSql(strSql,error);
}

bool DBHelper::execSql(const QString& strSql,QString* error)
{
	if(strSql.isEmpty() || !reconnectDB(error))
	{
		return false;
	}
	
	QSqlQuery query(m_database);
	if(!query.exec(strSql))
	{
		QString strError = query.lastError().text();
		qDebug()<<strError;
		
		if(error != nullptr)
		{
			*error = strError;
		}
		return false;
	}
	return true;
}

bool DBHelper::execSql(const QString& strSql,DBResult_t& result,QString* error)
{
	if(strSql.isEmpty() || !reconnectDB(error))
	{
		return false;
	}
	
	QSqlQuery query(m_database);
	if(!query.exec(strSql))
	{
		QString strError = query.lastError().text();
		qDebug()<<strError;
		
		if(error != nullptr)
		{
			*error = strError;
		}
		return false;
	}
	
	QSqlRecord record = query.record();
	while(query.next())
	{
		DBRecord_t dbrecord;
		for(int i=0;i<record.count();++i)
		{
			dbrecord.insert(record.fieldName(i),query.value(i));
		}
		result.append(dbrecord);
	}
	
	return true;
}

bool DBHelper::transaction(QString* error)
{
	if(!reconnectDB(error))
	{
		return false;
	}
	
	if(!m_database.transaction())
	{
		QString strError = m_database.lastError().text();
		qDebug()<<strError;
		
		if(error != nullptr)
		{
			*error = strError;
		}
		return false;
	}
	return true;
}

bool DBHelper::commit(QString* error)
{
	if(!reconnectDB(error))
	{
		return false;
	}
	
	if(!m_database.commit())
	{
		QString strError = m_database.lastError().text();
		qDebug()<<strError;
		
		if(error != nullptr)
		{
			*error = strError;
		}
		return false;
	}
	return true;
}

bool DBHelper::rollback(QString* error)
{
	if(!reconnectDB(error))
	{
		return false;
	}
	
	if(!m_database.rollback())
	{
		QString strError = m_database.lastError().text();
		qDebug()<<strError;
		
		if(error != nullptr)
		{
			*error = strError;
		}
		return false;
	}
	return true;
}
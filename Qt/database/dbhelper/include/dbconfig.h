#ifndef _DB_CONFIG_H
#define _DB_CONFIG_H

#include <QString>

struct DBConfig
{
	QString m_ip;             //数据库主机IP
	int m_port;               //数据库服务程序端口号
	
	QString m_username;       //数据库登录用户名
	QString m_password;      //数据库登录密码
	
	QString m_databaseName;   //数据库名
};

#endif  //_DB_CONFIG_H
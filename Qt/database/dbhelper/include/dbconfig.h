#ifndef _DB_CONFIG_H
#define _DB_CONFIG_H

#include <QString>

struct DBConfig
{
	QString m_ip;             //���ݿ�����IP
	int m_port;               //���ݿ�������˿ں�
	
	QString m_username;       //���ݿ��¼�û���
	QString m_password;      //���ݿ��¼����
	
	QString m_databaseName;   //���ݿ���
};

#endif  //_DB_CONFIG_H
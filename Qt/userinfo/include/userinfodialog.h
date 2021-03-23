#ifndef _USER_INFO_DIALOG_H
#define _USER_INFO_DIALOG_H

#include <QDialog>

class UserInfoData;

class UserInfoDialog:public QDialog
{
	Q_OBJECT
public:
	UserInfoDialog(QWidget *parent = nullptr);
	virtual ~UserInfoDialog();
	
private:
	UserInfoData* pdata;
};

#endif //_USER_INFO_DIALOG_H
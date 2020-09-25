#ifndef _LOGINDLG_H
#define _LOGINDLG_H

#include <QDialog>
#include <QString>

class QLineEdit;
class QPushButton;

class LoginDlg:public QDialog
{
	Q_OBJECT
public:
	LoginDlg(QWidget *parent = nullptr);
	virtual ~LoginDlg();
	
	QString getUsername()const;
	QString getPassword()const;

public slots:
	void on_okBtn_clickd();
	void on_cancelBtn_clicked();

private:
	QLineEdit* usernameLineEdit;
	QLineEdit* passwordLineEdit;
	QPushButton* okBtn;
	QPushButton* cancelBtn;
};

#endif //_LOGINDLG_H
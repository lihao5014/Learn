#ifndef _CUSTOM_DIALOG_H
#define _CUSTOM_DIALOG_H

#include <QMessageBox>

class QPushButton;

class CustomDialog:public QMessageBox
{
	Q_OBJECT
public:
	typedef enum{
		NoneButton,
		YesButton,
		NoButton,
		CancelButton
	}ButtonType;
	
	CustomDialog(QWidget *parent = nullptr);
	virtual ~CustomDialog();
	
	ButtonType clickedButtonType();
private:
	QPushButton *yesBtn;
	QPushButton *noBtn;
	QPushButton *cancelBtn;
};

#endif //_CUSTOM_DIALOG_H
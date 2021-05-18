#ifndef _MESSAGE_BOX_DIALOG_H
#define _MESSAGE_BOX_DIALOG_H

#include <QDialog>

class QLabel;
class QPushButton;

class MessageBoxDialog:public QDialog
{
	Q_OBJECT
public:
	MessageBoxDialog(QWidget *parent = nullptr);
	virtual ~MessageBoxDialog();

private slots:
	void showQuestionMsgBox();
	void showInformationMsgBox();
	void showWarningMsgBox();
	void showCriticalMsgBox();
	void showAboutMsgBox();
	void showAboutQtMsgBox();
	
private:
	QLabel* textLabel;
	QPushButton* questionMsgBtn;
	QPushButton* informationMsgBtn;
	QPushButton* warningMsgBtn;
	QPushButton* criticalMsgBtn;
	QPushButton* aboutMsgBtn;
	QPushButton* aboutQtMsgBtn;
};

#endif //_MESSAGE_BOX_DIALOG_H
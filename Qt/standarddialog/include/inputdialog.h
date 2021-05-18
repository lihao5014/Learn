#ifndef _INPUT_DIALOG_H
#define _INPUT_DIALOG_H

#include <QDialog>

class QLabel;
class QPushButton;
class QLineEdit;
class QInputDialog;

class InputDialog:public QDialog
{
	Q_OBJECT
public:
	InputDialog(QWidget *parent = nullptr);
	virtual ~InputDialog();

private slots:
	void onChangeName();
	void onChangeSex();
	void onModifyAge();
	void onModifyScore();

private:
	QLabel *nameLabel;
	QLineEdit *nameLineEdt;
	QPushButton *nameBtn;
	
	QLabel *sexLabel;
	QLineEdit *sexLineEdt;
	QPushButton *sexBtn;
	
	QLabel *ageLabel;
	QLineEdit *ageLineEdt;
	QPushButton *ageBtn;
	
	QLabel *scoreLabel;
	QLineEdit *scoreLineEdt;
	QPushButton *scoreBtn;

	QInputDialog *m_pinputDlg;
};

#endif //_INPUT_DIALOG_H
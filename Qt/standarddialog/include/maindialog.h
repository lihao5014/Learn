#ifndef _MAIN_DIALOG_H
#define _MAIN_DIALOG_H

#include <QDialog>

class QPushButton;
class QLineEdit;
class QFrame;
class QLabel;

class MainDialog:public QDialog
{
	Q_OBJECT
public:
	MainDialog(QWidget *parent = nullptr);
	virtual ~MainDialog();

private slots:
	void onShowFileDlg();
	void onShowColorDlg();
	void onShowFontDlg();
	void onShowInputDlg();
	void onShowMessageBoxDlg();	
	void onShowCustomDlg();
	
private:
	QPushButton *fileBtn;
	QLineEdit *fileLineEdt;
	
	QPushButton *colorBtn;
	QFrame *colorFrame;
	
	QPushButton *fontBtn;
	QLineEdit *fontLineEdt;
	
	QPushButton *inputBtn;
	QPushButton *msgBtn;
	
	QPushButton *customBtn;
	QLabel *customLabel;
};

#endif //_MAIN_DIALOG_H
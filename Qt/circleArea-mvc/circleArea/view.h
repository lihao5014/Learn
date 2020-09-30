#ifndef _VIEW_H
#define _VIEW_H

#include <QWidget>
#include <QString>

class QLabel;
class QPushButton;
class QLineEdit;

class View:public QWidget     //视图是使用Qt实现的GUI界面
{
	Q_OBJECT
public:
	View(const QString& title,QWidget *parent = nullptr);
	virtual ~View();
	
	QString getRadius()const;
	void setArea(const QString& area);

signals:
	void calculated();

public slots:
	void on_calculateBtn_clicked();
	void on_radiusLineEdit_returnPressed();

private:
	View(const View& other);
	View& operator =(const View& other);
	void init();
	
	QLabel* resultLabel;
	QPushButton* calculateBtn;
	QLineEdit* radiusLineEdit;
};

#endif //_VIEW_H
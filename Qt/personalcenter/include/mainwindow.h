#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <QSplitter>
#include <QListWidget>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

class Content;

class MainWindow:public QSplitter
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = nullptr);
	virtual ~MainWindow();
	
private:
	/*如果listWgt没有在其他成员函数中被使用，那么可以不必将其定义为成员变量，直接在构造函数
	 *中new出来，一次性使用就可以了。这样可以减少成员变量的个数，从而降低类之间的耦合性。
	 */
#ifdef _CHANGE_WAY_
	QListWidget *listWgt;   //该程序中，就可以不必把listWgt定义为成员变量
#endif
	Content *m_content;
};

#endif //_MAINWINDOW_H
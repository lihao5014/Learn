/*QDockWidget主要用于实现主窗口QMainWindow中的停靠窗口布局，将需要实现停靠效果的窗体直接设置到停靠布局窗口中。
 *在将停靠窗口添加到主窗口上，并设置停靠布局窗口的停靠属性和允许停靠的区域就行。
 */
 
/*Qt中的窗体布局方式：
 *（1）基础布局：水平布局、垂直布局、网格布局。
 *（2）高级布局：分割窗口布局、浮动窗口布局，堆栈窗口布局。
 */

/*在学习Qt中的某一个新类时，最快捷的方法是采用基于对象的编程方式书写Demo，而不是面向对象的编程方式。
 *因为面向对象的编程方式使用了封装、继承和多态特性，反而使想要学习的类API调用起来不够直接，增加了编
 *写学习Demo的代码量。
 */

//只要控件类显示到了主窗口上，那么控件对象的内存就已经被主窗口所托管了，不需要用户再手动释放了。

#include <QApplication>
#include <QMainWindow>
#include <QDockWidget>
#include <QTextEdit>

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	QMainWindow mainWnd;
	mainWnd.resize(500,400);
	mainWnd.setWindowTitle("dock widget test");
	
	/*因为后面调用的QMainWindow::setCentralWidget()方法会自动为mainTextEdt添加父对象，
	 *所以构造mainTextEdt对象时，可以指定父对象，也可以不指定父对象。
	 */
	QTextEdit* mainTextEdt = new QTextEdit();
	mainTextEdt->setText("main window");
	mainTextEdt->setAlignment(Qt::AlignHCenter);
	mainWnd.setCentralWidget(mainTextEdt);      //将mainTextEdt编辑框设置为主窗口的中央窗体
	
	/*因为后面调用的QMainWindow::addDockWidget()方法会自动为topDock添加父对象，
	 *所以构造topDock对象时，可以指定父对象，也可以不指定父对象。
	 */
	QDockWidget* topDock = new QDockWidget("top dock widget");
	topDock->setFeatures(QDockWidget::DockWidgetMovable);     //设置topDock停靠属性为可移动
	topDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);   //设置停靠窗口的可停靠区域
	
	QTextEdit* topEdt = new QTextEdit("the dock widget can be moved between docks by user");
	topDock->setWidget(topEdt);
	mainWnd.addDockWidget(Qt::RightDockWidgetArea,topDock);   //将停靠窗口添加到主窗口上，并指定其初始停靠位置
	
	//由于midDock没有设置QDockWidget::DockWidgetMoveable属性，所以它不能被拖动
	QDockWidget* midDock = new QDockWidget("mid dock widget");
	midDock->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable);
	
	QTextEdit* midEdt = new QTextEdit();
	midEdt->setText("the dock widget can be detached from the main window,and floated as an independent window");
	midDock->setWidget(midEdt);
	mainWnd.addDockWidget(Qt::RightDockWidgetArea,midDock);
	
	//由于bottomDock没有设置允许停靠的区域，所以默认主窗口中所有区域都可以停靠
	QDockWidget* bottomDock = new QDockWidget("bottom dock widget");
	bottomDock->setFeatures(QDockWidget::AllDockWidgetFeatures);   //全部停靠属性，即可移动、可关闭、可浮动
	
	QTextEdit* bottomEdit = new QTextEdit("bottom dock widget");
	bottomEdit->setText("the dock widget can be closed,moved and floated");
	bottomDock->setWidget(bottomEdit);       //一个QDockWidget中只能设置一个QWidget，一个QSplitter窗口中可以添加多个QWidget。
	mainWnd.addDockWidget(Qt::RightDockWidgetArea,bottomDock);

	mainWnd.show();
	return app.exec();
}
#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

#include <QMainWindow>

namespace Ui{
class MainWindow;
}

class QToolButton;
class QPushButton;

/*由于MainWindow类中开启了信号槽机制，所以需要使用moc.exe工具对mainwindow.h头文件进行元编译，
 *生成moc_mainwindow.cpp源文件。Qt中的信号槽机制是在标准C++基础上扩充编译器功能实现的，它在
 *进行代码编译以前多进行了一次moc源对象编译，将Qt中扩展的非标准C++语法，编译为标准C++源文件。
 */

/*类声明中使用了Q_OBJECT宏开启信号槽机制，就会自动调用moc.exe元编译工具，对开启了信号槽机制的
 *类进行处理，生成moc_*.cpp源文件。uic.exe界面编译器和rcc.exe资源编译器的自动调用都是在pro工程
 *管理文件中指定的，唯独moc.exe元对象编译器的调用与否是在头文件或源文件中指定的。
 */
class MainWindow:public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = nullptr);
	virtual ~MainWindow();

private slots:
	void showNewQuestionMsgBox();
	void showAboutQtMsgBox();
	void showOpenFileDlg();
	void showHintAboutMsgBox();

private:
	Ui::MainWindow *ui;
	
	QToolButton *menuNewBtn;
	QPushButton *menuOpenBtn;
};

#endif //_MAIN_WINDOW_H
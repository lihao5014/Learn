#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

/*因为只添加了Qt库的include/lib目录到INCLUDE/LIB环境变量中，所以使用Qt库的头文件时
 *必须带上模块路径。这就等效于qmake文件中，使用QT += 模块名。
 */
#include <QtWidgets/QMainWindow>    //等效于QT += widgets

/*因为mainwindow.ui界面文件中使用了QIcon图标，而QIcon类的实现在Qt5Gui.lib/Qt5Guid.lib
 *所以编译mainwindow.cpp源文件时，需要衔接Qt5Gui.lib/Qt5Guid.lib库。
 */
namespace Ui{
class MainWindow;
}

class QToolButton;
class QPushButton;

/*由于MainWindow类中开启了信号槽机制，所以需要使用moc.exe工具对mainwindow.h头文件进行元编译，
 *生成moc_mainwindow.cpp源文件。Qt中的信号槽机制是在标准C++基础上扩充编译器功能实现的，它在
 *进行代码编译以前多进行了一次moc源对象编译，将Qt中扩展的非标准C++语法，编译为标准C++源文件。
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
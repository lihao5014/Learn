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

/*仅观察uic.exe工具进行*.ui界面编译，将*.ui文件编译为ui_*.h头文件，所以暂时不开启MainWindow类
 *的信号槽操作。否则还需要使用moc.exe工具对本头文件进行元编译，生成moc_mainwindow.cpp源文件。
 */
class MainWindow:public QMainWindow
{
	// Q_OBJECT
public:
	MainWindow(QWidget *parent = nullptr);
	virtual ~MainWindow();
	
private:
	Ui::MainWindow *ui;
};

#endif //_MAIN_WINDOW_H
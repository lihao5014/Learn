#include "pch.h"
#include "logindialog.h"

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifndef _CHANGE_WAY_
	//在用户登录前就已经将主窗口构造出来了，只是还没有show()。这样可以提升
	//用户登录速度，但缺点是用户在还没登录前需要占用多余的内存空间。
    QWidget w;
	w.setWindowTitle("welcome");
	w.setWindowIcon(QIcon("../resource/myico.ico"));

    LoginDialog dlg;
    if(dlg.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
#else
    LoginDialog dlg;
    if(dlg.exec() == QDialog::Accepted)
    {
		//用户登录后才将主窗口构造出来。这样可以避免内存空间浪费的现象。
		//但缺点用户登录以后，加载主窗口的速度较慢。
		QWidget w;
		w.setWindowTitle("welcome");
		w.setWindowIcon(QIcon("../resource/myico.ico"));
        w.show();
		
        return a.exec();
    }
#endif

	return 0;
}



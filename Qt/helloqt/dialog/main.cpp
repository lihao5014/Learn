#include <cstdio>
#include <QApplication>
#include <QObject>
#include <QDialog>
#include <QPushButton>
#include <QLabel>

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

#define BUTTON_WIDTH 60
#define BUTTON_HEIGHT 30

static const int label_width = 100;
static const int label_height = 30;
static const int yoffset = 20;

static QLabel* g_plabel = nullptr;

static void registerLabel(QLabel* plabel);
static void onChangeText();

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	QDialog dlg;
	dlg.setWindowTitle("simplest gui");
	dlg.resize(300,200);
	
#ifdef _ERROR_
	dlg.show();   //父窗口的显示必须放置到所有子空间的布局语句之后。否则父窗口显示时，其上面不会显示show()方法以后所添加的控件。
#endif

	QLabel label("hello world",&dlg);
	label.setAlignment(Qt::AlignHCenter);   //设置QLabel显示文件为水平居中对齐
	label.setGeometry((dlg.width() - label_width)/2,dlg.height()/2 - yoffset,label_width,label_height);
	
	QPushButton button("click",&dlg);
	button.resize(BUTTON_WIDTH,BUTTON_HEIGHT);
	button.move((dlg.width() - BUTTON_WIDTH)/2,dlg.height()/2 + yoffset);     //使用setGeometry()和move()方法进行绝对布局
	
#ifndef _CHANGE_WAY_
	registerLabel(&label);
	QObject::connect(&button,&QPushButton::clicked,onChangeText);    //信号绑定普通函数
#else
	QObject::connect(&button,&QPushButton::clicked,                  //信号绑定lambda表达式
		[&label](){
			if(label.text() == "hello world")
			{
				label.setText("welcome qt");
			}
			else
			{
				label.setText("hello world");
			}
		}
	)
#endif

#ifndef _ERROR_
	dlg.show();
#endif

#ifdef _CHANGE_WAY_
	if(dlg.exec() != QDialog::Accepted)    //进入对话框的事件循环，所以dlg将设置为模态窗口
	{
		fprintf(stdout,"exit dialog event loop\n");
		return -1;
	}
#endif

	return app.exec();
}

void registerLabel(QLabel* plabel)
{
	g_plabel = plabel;
}

void onChangeText()
{
	if(g_plabel == nullptr)
	{
		puts("onChangeText warn: g_plabel is null");
		return ;
	}
	
	if(g_plabel->text() == "hello world")
	{
		g_plabel->setText("welcome qt");
		return ;
	}

	g_plabel->setText("hello world");
}
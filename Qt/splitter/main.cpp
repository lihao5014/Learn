//QSplitter主要用于实现分割窗口布局，将需要实现分割效果的多个窗体直接添加到QSplitter分割布局窗口中就行。

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
#include <QSplitter>
#include <QTextEdit>
#include <QFont>

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	QFont font("黑体",12);
	app.setFont(font);
	
	QSplitter mainSplitter;     //主分割窗口
	mainSplitter.setWindowTitle("splitter test");
	mainSplitter.resize(500,400);
	
	//leftTextEdt被new出来时，指定了父对象，那么它就被添加到了主分割窗口中。
	QTextEdit *leftTextEdt = new QTextEdit("left text edit",&mainSplitter);
	leftTextEdt->setAlignment(Qt::AlignHCenter);
	mainSplitter.setOpaqueResize(true);
	
	QSplitter *rightSpliter = new QSplitter(Qt::Vertical,&mainSplitter);    //右分割窗口
	rightSpliter->setOpaqueResize(false);     //设置右分割窗口在拖动分割条时，不实时更新窗口显示大小
	
	QTextEdit *upTextEdt = new QTextEdit("top text edit",rightSpliter);   //右分割器中添加上文本编译框
	upTextEdt->setAlignment(Qt::AlignHCenter);
	
	//midTextEdt被new出来时，没有指定父对象，那么它就还没有被添加到了任何窗口中。
	QTextEdit *midTextEdt = new QTextEdit("middle text edit");
	midTextEdt->setAlignment(Qt::AlignHCenter);
	//添加midTextEdt到右分割器中。QSpliter::addWidget()会自动为添加到分割器中的窗口添加父对象。
	//以实现子对象的自动内存回收。
	rightSpliter->addWidget(midTextEdt);
	
	QTextEdit *bottonTextEdt = new QTextEdit("bottom text edit");
	bottonTextEdt->setAlignment(Qt::AlignHCenter);
	rightSpliter->addWidget(bottonTextEdt);   //右分割器中添加下文本编辑框
	
	//设定可伸缩控件，第一个参数用于指定设置的控件（序号从0起编号），第2个参数的值大于0则表示此控件为可伸缩控件。
	mainSplitter.setStretchFactor(0,0);   //设置左文本编辑器为不可伸缩控件。但实际测试中发现这个API无效，属于Qt的一个Bug。
	mainSplitter.show();    //Qt中所有控件都继承至QWidget窗口部件，都是可以作为一个独立窗口来显示的。
	
	return app.exec();
}
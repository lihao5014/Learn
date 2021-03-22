/*如果一个对象继承自QObject类，并且指定了parent对象，那么他的内存释放就可以交由它的父对象来进行管理。
 *Qt中推荐的内存管理方式是，在main函数中将主窗口创建为程序中唯一的栈对象。而其他类型的Qt对象都定义为
 *堆对象，并通过直接或间接指定主窗口为父窗口，来实现对内存的半自动回收。
 */

/*Qt中半自动内存回收的触发条件：
 *1.类继承自QObject。
 *2.对象指定了parent父对象。
 *3.parent父对象析构的时候，会连同它包含的子对象也一并析构掉。
 */

/*Qt中指定父对象的几种常用方式：
 *1.通过对象构造时，传入parent父对象。
 *2.通过主动调用setParent()方法指定父对象。
 *3.QLayout的addWidget()方法，会为添加到布局管理器中的窗口，自动添加上父对象。
 *4.QWidget的setLayout()方法，会为放置到窗体上的布局管理器，自动添加上父对象。
 *5.QMainWindow的setCentralWidget()方法，会为设置到主窗口的中心窗口，自动添加上父对象。
 *6.QMainWindow的setDockWidget()方法，会为添加到主窗口中的浮动窗口，自动添加上父对象。
 *7.QDockWidget的setWidget()方法，会为设置到停靠布局窗体中的窗口，自动添加上父对象。
 *8.QSplitter/QStackedWidget的addWidget()方法，会为添加到分割布局或堆栈布局窗口中的窗体，自动添加上父对象。
 */

/*为QWidget及其子类对象指定parent的作用：
 *1.通过指定的parent托管对象自身的内存释放工作。
 *2.设置窗口部件定位显示的坐标系为父QWidget的坐标系，即将其添加到父窗体中。
 */

/*Qt半自动内存管理机制的缺陷：在于parent不区分它的child是分配到栈上还是堆上，结果可能会出现parent析构栈上
 *创建的子对象情况。因此Qt对象析构的核心原则是保证子对象先析构，这样子对象会把它自己从父对象列表中删除掉，
 *二者取消关联，那么父对象析构时就不会再次析构子对象了。
 */

//QStackedWidget主要用于实现堆栈窗口布局，将需要实现层叠效果的多个窗体直接添加到QStackedWidget堆栈布局窗口中就行。

#include <QApplication>
#include <QDialog>
#include <QStackedWidget>
#include <QListWidget>
#include <QLabel>
#include <QHBoxLayout>

#define _ERROR_
#undef _ERROR_

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);

	//main函数中主窗口一般定义为栈对象，并将它作为parent父对象，管理着它上面放置的子控件的内存释放。
	QDialog dlg;
	dlg.setWindowTitle("stacked widget test");
	dlg.resize(400,300);

	//除了主窗口以外，其他类型的控件建议都定义为堆对象，并为其指定父对象用于自动管理自身的内存释放。
	QListWidget *listWgt = new QListWidget(&dlg);
	listWgt->addItem("window1");
	listWgt->insertItem(1,"window2");
	listWgt->addItem("window3");
	
	QStackedWidget *stackedWgt = new QStackedWidget();
	stackedWgt->setParent(&dlg);     //通过调用setParent()方法为stackedWgt指定父对象
	
#ifdef _ERROR_
	/*如果构造topLabel时只是指定stackedWgt作为父对象，但不调用addWidget()方法将其添加到堆栈窗口中，
	 *那么topLabel只会将stackedWgt作为一个普通的QWidget窗体放置到它上面，而达不到堆栈布局的效果。
	 */
	QLabel *topLabel = new QLabel("top window test",stackedWgt);
	topLabel->setAlignment(Qt::AlignHCenter);
#else
	QLabel *topLabel = new QLabel("top window test");
	topLabel->setAlignment(Qt::AlignHCenter);
	stackedWgt->addWidget(topLabel);
#endif

	//midLabel构造时没有指定父对象，使用addWidget()将其放置到堆栈窗口中时，会自动为其指定父对象。
	QLabel *midLabel = new QLabel("middle window test");
	midLabel->setAlignment(Qt::AlignVCenter);
	stackedWgt->addWidget(midLabel);
	
	//bottomLabel构造时已经指定了父对象，所以调用addWidget()将其放置到堆栈窗口中时，不会再为其添加父对象。
	QLabel *bottomLabel = new QLabel("bottom window test",stackedWgt);
	bottomLabel->setAlignment(Qt::AlignVCenter);
	stackedWgt->addWidget(bottomLabel);
	
	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->setMargin(10);    //设置布局管理器与主窗口边距为10
	mainLayout->setSpacing(5);   //设置布局管理器中各控件之间的间隔为5
	mainLayout->addWidget(listWgt);
	mainLayout->addWidget(stackedWgt);
	
	/*setStretchFactor()用于设置可伸缩控件，第1个参数用于指定设置的控件（序号从0开始），
	 *第2个参数的值大于0则表示此控件为可伸缩控件。
	 */
	mainLayout->setStretchFactor(listWgt,1);
	mainLayout->setStretchFactor(stackedWgt,3);    //在布局管理器中stackedWgt大小是listWgt的3:1倍
	
	//mainLayout构造时没有指定parent父对象，使用setLayout()将其添加到对话框中时，会自动为其指定父对象。
	dlg.setLayout(mainLayout);
	QObject::connect(listWgt,SIGNAL(currentRowChanged(int)),stackedWgt,SLOT(setCurrentIndex(int)));
	
	dlg.show();
	return app.exec();
}
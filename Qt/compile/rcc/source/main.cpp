/*Qt资源文件*.qrc由两种使用方式：（Qt中资源文件可以包含图片、图标、翻译文件、ini文件、json文件、xml文件等）
 *（1）先将*.qrc资源文件编译为*.rcc二进制资源文件，然后再使用QResource::registerResource()函数动态注册二进制资源文件。
 *而在加载的资源使用完成或不再使用时，通过QResource::unregisterResource()函数注销*.rcc文件，以释放资源占用的内存空间。
 *使用动态加载资源文件的方式，比直接将资源文件编译进应用程序中更加灵活，类似于动态库和静态库的关系。如果程序中资源发
 *生了变化，只需要替换掉二进制资源文件，而不需要再重新编译应用程序。rcc -binary icon.qrc -o icon.rcc。
 *（2）先将*.qrc资源文件编译为qrc_*.cpp源文件，然后再将资源文件生成的qrc_*.cpp源文件与应用程序的源文件一起编译。从而
 *将资源文件直接编译到应用程序中去。资源文件的这种使用方式与静态库类似，如果其中一个资源发生了变化，那么还需要重新编
 *编译exe文件。rcc icon.qrc -o qrc_icon.cpp。
 */

#include <QtCore/QDebug>
#include <QtGui/QPixmap>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);
	
	QWidget wgt;
	wgt.setWindowTitle("resource compile test");
	wgt.setWindowIcon(QIcon(":/image/qt_32x32.png"));
	
	QLabel *label = new QLabel;
	label->setPixmap(QPixmap(":/image/qt.png"));
	
	QToolButton *copyBtn = new QToolButton;
	copyBtn->setIcon(QIcon(":/image/copy.png"));
	copyBtn->setText("copy");
	copyBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	
	QToolButton *pasteBtn = new QToolButton;
	pasteBtn->setIcon(QIcon(":/image/paste.png"));
	pasteBtn->setText("paste");
	pasteBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	
	QToolButton *cutBtn = new QToolButton();
	cutBtn->setIcon(QIcon(":/image/cut.png"));
	cutBtn->setText("cut");
	cutBtn->setToolButtonStyle(Qt::ToolButtonIconOnly);    //QToolButton默认就是只显示图标
	
	QPushButton *openBtn = new QPushButton("open");
	openBtn->setIcon(QIcon(":/image/open.png"));
	
	QGridLayout *layout = new QGridLayout(&wgt);
	layout->addWidget(label,0,1,1,1);
	layout->addWidget(copyBtn,1,0);
	layout->addWidget(pasteBtn,1,1);
	layout->addWidget(cutBtn,1,2);
	layout->addWidget(openBtn,2,1,1,1);
	layout->setColumnStretch(0,1);
	layout->setColumnStretch(1,2);
	layout->setColumnStretch(2,1);
	
	wgt.show();
	
	return app.exec();
}
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVBoxLayout>

#define _ERROR_
// #undef _ERROR_

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

static void initWidget(QWidget *wgt);

int main(int argc,char* argv[])
{
	QApplication app(argc,argv);

	QWidget wgt;
	initWidget(&wgt);
	wgt.show();
	
	return app.exec();
}

void initWidget(QWidget *wgt)
{
	QVBoxLayout *mainLayout = new QVBoxLayout(wgt);
	mainLayout->setMargin(5);
	mainLayout->setSpacing(5);
	
	/* static */ QListWidget *listWgt = new QListWidget();
	listWgt->addItem(new QListWidgetItem("name: bob"));
	listWgt->insertItem(1,new QListWidgetItem("age: 25"));

#ifndef _CHANGE_WAY_
	QComboBox *sexComboBox = new QComboBox();
	QLineEdit *scoreLineEdt = new QLineEdit("score: 80");
	QLabel *contentLabel = new QLabel("selected content");
#else
	static QComboBox *sexComboBox = new QComboBox();
	static QLineEdit *scoreLineEdt = new QLineEdit("score: 80");
	static QLabel *contentLabel = new QLabel("selected content");
#endif
	sexComboBox->addItem("sex: boy");
	sexComboBox->insertItem(0,"sex: girl");
	contentLabel->setAlignment(Qt::AlignHCenter);

	QListWidgetItem *sexItem = new QListWidgetItem("sex: ");
	listWgt->addItem(sexItem);
	listWgt->setItemWidget(sexItem,sexComboBox);
	
	QListWidgetItem *scoreItem = new QListWidgetItem;
	scoreItem->setText("score: 60");
	listWgt->insertItem(listWgt->count(),scoreItem);
	listWgt->setItemWidget(scoreItem,scoreLineEdt);

	mainLayout->addWidget(listWgt);
	mainLayout->addWidget(contentLabel);
	
	/*由于connect是绑定listWgt指针指向的堆对象，所以即使listwgt指针本身被销毁了，
	 *currentTextChanged信号也能发送出去，而不会导致野指针访问bug。
	 */
	QObject::connect(listWgt,&QListWidget::currentTextChanged,contentLabel,&QLabel::setText);
	
#ifndef _ERROR_
#ifndef _CHANGE_WAY_
	QObject::connect(sexComboBox,&QComboBox::currentTextChanged,contentLabel,&QLabel::setText);
	QObject::connect(scoreLineEdt,&QLineEdit::textEdited,contentLabel,&QLabel::setText);
#else
	/*由于除了initWidget()函数作用域所以的局部变量指针都会被销毁，以后再触发currentTextChanged信号来，
	 *就会造成contentLabel野指针访问，导致软件崩溃。为防止sexComboBox、scoreLineEdt和contentLabel指针
	 *出了作用域被销毁，所以将它们定义为static变量。
	 */
	 
	 //lambda表达式按[=]值/[&]引用捕获父作用域中的所有变量时，不会自动捕获static静态变量，所以这里编译可以通过。
	QObject::connect(sexComboBox,&QComboBox::currentTextChanged,
		[&](const QString &text){
			contentLabel->setText(text);
		}
	);
	
	/*外部static静态变量可以在lambda表达式中被直接使用，而不需要再被捕获。外部静态变量出现在lambda
	 *表达式的捕获列表中，反而会导致编译警告。
	 */
	QObject::connect(scoreLineEdt,&QLineEdit::editingFinished,
		[](){
			contentLabel->setText(scoreLineEdt->text());
		}
	);
#endif   //_CHANGE_WAY_
#else
	QObject::connect(sexComboBox,&QComboBox::currentTextChanged,
		[&contentLabel](const QString &text){
			contentLabel->setText(text);
		}
	);
	
	QObject::connect(scoreLineEdt,&QLineEdit::editingFinished,
		[&contentLabel,&scoreLineEdt](){
			contentLabel->setText(scoreLineEdt->text());
		}
	);
#endif   //_ERROR_
}
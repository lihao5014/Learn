#include "foobar.h"
#include <string.h>
#include <QDebug>

const int foobar_size = sizeof(Foobar);

QVariant foobarArr[FOOBAR_COUNT] = {0};

#if 0
/*对两个QVariant类型的变量进行memcpy内存拷贝，并使用MingW编译器进行编译，
 *程序运行结束以后，会造成软件崩溃。但使用MSVC编译器编译程序可以正常运行。
 */
void convertStructToArray(const Foobar& foobar)
{
	memset(foobarArr,0,foobar_size);
	memcpy(foobarArr,&foobar,foobar_size);
}

/*C++中往struct或class里赋值，最好使用初始化列表、拷贝构造函数或赋值运算符。
 *而不要使用传统C语言中的memset或memcpy函数，因为它们对于类中的成员指针的拷贝
 *是浅拷贝。类的浅拷贝有可能会造成成员指针析构时，多次被释放问题。
 */
void convertArrayToStruct(Foobar& foobar)
{
	memset(&foobar,0,sizeof(Foobar));
	memcpy(&foobar,foobarArr,sizeof(Foobar));
}
#elif 0
void convertStructToArray(const Foobar& foobar)
{
	Foobar *pfoobar = (Foobar*)foobarArr;
	pfoobar->foo = foobar.foo;
	pfoobar->bar = foobar.bar;
	pfoobar->baz = foobar.baz;
	pfoobar->qux = foobar.qux;
}

void convertArrayToStruct(Foobar& foobar)
{
	const Foobar* pfoobar = (Foobar*)foobarArr;
	foobar.foo = pfoobar->foo;
	foobar.bar = pfoobar->bar;
	foobar.baz = pfoobar->baz;
	foobar.qux = pfoobar->qux;
}
#elif 0
void convertStructToArray(const Foobar& foobar)
{
	foobarArr[FOO] = foobar.foo;
	foobarArr[BAR] = foobar.bar;
	foobarArr[BAZ] = foobar.baz;
	foobarArr[QUX] = foobar.qux;
}

void convertArrayToStruct(Foobar& foobar)
{
	foobar.foo = foobarArr[FOO];
	foobar.bar = foobarArr[BAR];
	foobar.baz = foobarArr[BAZ];
	foobar.qux = foobarArr[QUX];
}
#elif 1
//如果Foobar结构体中成员数据都是相同类型，那么就可以像数组一样循环来遍历操作。
void convertStructToArray(const Foobar& foobar)
{
	const QVariant *pvar = (QVariant*)&foobar;
	for(int i=0;i<FOOBAR_COUNT;++i)
	{
		foobarArr[i] = *pvar;
		pvar++;
	}
}

void convertArrayToStruct(Foobar& foobar)
{
	QVariant *pvar = (QVariant*)&foobar;
	for(int i=0;i<FOOBAR_COUNT;++i)
	{
		*pvar = foobarArr[i];
		++pvar;
	}
}
#endif

QVariant getMember(const Foobar& foobar,const Member_t member)
{
	switch(member){
	case FOO:
		return foobar.foo;
	case BAR:
		return foobar.bar;
	case BAZ:
		return foobar.baz;
	case QUX:
		return foobar.qux;
	default:
		qDebug()<<"getMember: argument is illegal";
		return QVariant();
	}
}

QVariant getMember(const Member_t member)
{
	if(member < FOO || member >QUX)
	{
		qDebug()<<"getMember: member is illegal";
		return QVariant();
	}
	
	return foobarArr[member];
}

void showStruct(const Foobar& foobar)
{
	qDebug()<<foobar.foo.toChar()<<" "
	        <<foobar.bar.toInt()<<" "
			<<foobar.baz.toDouble()<<" "
			<<foobar.qux.toString();
}

void printArray()
{
	qDebug()<<foobarArr[FOO].toChar()<<" "
	        <<foobarArr[BAR].toInt()<<" "
			<<foobarArr[BAZ].toDouble()<<" "
			<<foobarArr[QUX].toString();
}
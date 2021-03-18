#ifndef _FOOBAR_H
#define _FOOBAR_H

#include <QVariant>

#define FOOBAR_COUNT sizeof(Foobar)/sizeof(QVariant)

enum Member_t
{
	FOO = 0,
	BAR,
	BAZ,
	QUX
};

//如果结构体中的成员数据类型都相同，那么就可以使用指针加循环语句的方式来进行遍历。
struct Foobar
{
	QVariant foo;     //char
	QVariant bar;     //int
	QVariant baz;     //double
	QVariant qux;     //QString
};

extern const int foobar_size;

extern QVariant foobarArr[];

extern void convertStructToArray(const Foobar& foobar);
extern void convertArrayToStruct(Foobar& foobar);

QVariant getMember(const Foobar& foobar,const Member_t member);
QVariant getMember(const Member_t member);

void showStruct(const Foobar& foobar);
void printArray();

#endif //_FOOBAR_H
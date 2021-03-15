#ifndef _STUDNET_H
#define _STUDENT_H

/*Windows操作系统中使用MSVC编译器生成dll动态库时，会同时生成一个以lib结尾的导入库/引入库。
 *虽然导入库/引入库和静态库都是以lib后缀结尾的，但是它们不是同一个东西，且具有本质的区别。
 *引入库中只有变量、函数或类的符号声明与这些符号在dll动态库中的地址，而变量、函数或类的真
 *正定义实现是在dll动态库中。静态库中既有变量、函数或类的符号声明，也具有它们的定义或实现。
 */

/*Linux操作系统中生成动态库时，只有一个.so动态库文件，而没有像Windows系统那样继续生成一个，
 *专门用于说明动态库中导出符号和地址的导入库/引入库文件。
 */

#include "istudent.h"
#include "student_global.h"

class STUDENT_SHARED_EXPORT Student:public IStudent
{
public:
	Student(const QString& name,const QString& note);
	Student(const Student& other);
	
	virtual void setName(const QString& name);
	virtual QString getName()const;
	
	void setNote(const QString& note) override;
	QString getNote()const override;
	
	void show()const final;
private:
	QString name;
	QString note;
};

#endif //_STUDENT_H
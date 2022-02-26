#include <QDebug>
#include "counter.h"

#define _APP_
#undef _APP_

#ifdef _APP_
#include <QCoreApplication>
#endif

#define UNUSED(x) (void)x

static void updataValue(int value);

int main(int argc,char* argv[])
{
#ifdef _APP_
	QCoreApplication app(argc,argv);     //���߳��źŲۿ��Բ������¼�ѭ���Ϳ�����������
#endif

	Counter counterA(10),counterB(20);
	QObject::connect(&counterA,SIGNAL(valueChange(int)),&counterB,SLOT(onChangeValue(int)));
	counterA.setValue(11);
	counterB.display();
	qDebug()<<"";
	
	QObject::connect(&counterA,&Counter::valueChange,updataValue);    //�ź�������ͨ����
	counterA.setValue(12);
	qDebug()<<"";
	
	counterB.display();
	QObject::connect(&counterA,&Counter::valueChange,               //�ź�����lambda���ʽ
		[&counterB](int value){
			qDebug()<<"lambda: value ="<<value;
			counterB.setValue(value);
		}
	);
	counterA.setValue(13);
	counterB.display();

#ifdef _APP_
	return app.exec();   //���Qt������û��GUI���֣����źŲ�Ϊ���߳��źŲۣ���ô�Ϳ��Բ��ÿ���Qt���¼�ѭ��
#else
	return 0;
#endif
}

void updataValue(int value)
{
	qDebug()<<"updataValue: value ="<<value;
}
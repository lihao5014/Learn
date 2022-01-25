/*1.C++98/03��׼�м���������������
 *��1��assert�������ڶ����������������ڼ�Ĵ��󣬵���������ǰ�������ڷ��ִ���Ҳ������ǿ���ԣ�
 *     Ҳ̸���ϸ��Ʊ�����Ϣ�Ŀɶ��ԡ���Ȼ�������ڼ�飬�����ܿ϶�����Ӱ��ģ������ڷ��а汾��
 *     һ��assert���ᱻ�ص���
 *��2��#error������Ԥ����ʱ��ʾһ��������Ϣ�������޷���ñ�����Ϣ��#error�������#ifdef/ifndef
 *     ����Ԥ�����������飬ʵ��������Ԥ�����ڶ��ԵĹ��ܡ�
 */

/*2.static_assert��̬���ԣ���static_assertʱC++11��׼������Ĺؼ��֣������������ڼ�Ķ��ԣ�    
 *��1���﷨��static_assert(�������ʽ����ʾ�ַ���)��
 *��2�����������������һ�������������ʽ��ֵΪfalse�������һ���������
 *     ����λ�þ��Ǹ�static_assert��������У��ڶ����������Ǵ�����ʾ�ַ�����
 *��3��ʹ�÷�Χ��static_assert�Ķ��Ա��ʽ�Ľ���������ڱ���ʱ�ڿ��Լ���ı��ʽ���������ǳ������ʽ��
 *     static_assert��������ȫ�������������ռ䡢��������ͺ����������У��������Բ������Ƶ�ʹ�á�
 *��4�����ã�ʹ��static_assert�����ڱ����ڼ䷢�ָ���Ĵ����ñ�������ǿ�Ʊ�֤һЩ��Լ��
 *     ���������Ǹ��Ʊ�����Ϣ�Ŀɶ��ԣ�����������ģ���ʱ�򡣱�����������һ��static_assert���ʱ��
 *     ͨ�����̽����һ��������Ϊ�������ʽ�������㣬������ó������ʽ������ĳЩģ�������
 *     ���ӳٵ�ģ��ʵ����ʱ�ٽ������㣬����ü��ģ�������Ϊ�˿��ܡ�
 *��5�����ܣ�������static_assert�����ڼ���ԣ�������Ŀ����룬���static_assert��������κ�������������ʧ��
 */

/*3.C/C++�к����βε�2�����ͣ�
 *��1���������������ں��������޸����βε�ֵ�����ں������ʵ�β��ᱻ�޸ģ���ô���βξ���һ�����������
 *     in��������ʹ��ֵ���ݡ�const����ָ�봫�ݺ�const�������ô��ݡ�
 *��2���������������ں��������޸����βε�ֵ���Ҵ��뺯����ʵ��Ҳ�ᱻ�޸ģ���ô���βξ���һ�����������
 *     out��������ʹ��ָ�봫�ݺ����ô��ݡ�
 *��3���ں��������б��У����ĳ������ʹ��ֵ���ݡ�constָ�봫�ݺ�const���ô��ݣ��ͱ����ò�����һ�����������
 *     �������в����޸ĸñ�����ֵ������������ܴӺ������л�ȡ���κ�����/��Ϣ��
 *��4���ں��������б��У����ĳ������ʹ�õ�ַ���ݺ����ô��ݣ��ͱ����ò�����һ������������������л��޸ĸ�
 *     ������ֵ������������ԴӺ������д������õ�����/��Ϣ��
 *��5����Ȼ�������������Ҳ�����������ڴ������ݣ������Խ���������������������������ʹ�á�
 *     ��Ϊ��ʹ�����ĸ�����ְ�������ͨ���������������ֻ��Ϊ�������ṩ�������������ʹ�ã�
 *     �������������ֻ��Ϊ�Ӻ������л�ȡ�����������ʹ�á�ֻ�в��޸�ĳ������ֵ�������У�
 *     ���������ͬʱ�����������ʹ�á�
 */

#include <assert.h>
#include <iostream>

#define _CHANGE_WAY 0

using namespace std;

struct Point
{
	int x;
	int y;
};

#if _CHANGE_WAY
Point* addPoint(const Point* p1,const Point* p2)   //p1��p2ʹ��constָ�봫�ݣ����Զ������������
{
	assert(p1 != NULL && p2 != NULL);    //��Ϊp1��p2��ָ�����������(p1 != NULL && p2 != NULL)���ǳ������ʽ������ʹ��static_assert��̬���ԡ�
	return new Point{p1->x + p2->x,p1->y + p2->y};   //ʹ����C++11�е�ͳһ��ʼ�����﷨��addPoint()��������������ڴ棬��Ҫ�����������Լ��ͷš�
}

Point subPoint(const Point& p1,const Point& p2)   //p1��p2ʹ��const���ô��ݣ����Զ������������
{
	return {p1.x - p2.x,p1.y - p2.y};   //�б��ʼ��������һ����ʱ��Point���󣬲�����Point��Ĭ�Ͽ������캯����ֵ���ء�
}

void modifyPoint(Point* p)   //pʹ�õ�ַ���ݣ����޸ı���ֵ�����У��������������Ҳ�����������
{
	if(p == nullptr)
	{
		cout<<"modifyPoint error: p is null"<<endl;
		return;
	}
	
	++(p->x);
	++(p->y);
}
#else
void addPoint(Point p1,const Point* p2,Point* p3)   //p1ֵ���� - ���������p2����ָ�봫�� - in������p3ָ�봫�� - out����
{
	if(p2 == nullptr || p3 == nullptr)
	{
		cout<<"addPoint error: p2 or p3 is null"<<endl;
		return;
	}
	
	p3->x = p1.x + p2->x;
	p3->y = p1.y + p2->y;
}

void subPoint(Point p1,const Point& p2,Point& p3)   //p1ֵ���� - ���������p2�������ô��� - in������p3ָ�봫�� - out����
{
	p3.x = p1.x - p2.x;
	p3.y = p1.y - p2.y;
}

void modifyPoint(Point& p)   //pʹ�����ô��ݣ����޸ı���ֵ�����У�����in������Ҳ��out������
{
	p.x += 2;
	p.y += 2;
}
#endif

int main(void)
{
	static_assert(sizeof(void*) == 4,"This is not a 32-bit system");
	// static_assert(sizeof(void*) == 8,"This is not a 64-bit system");
	
	
	Point p1{13,14};
	Point p2 = {3,4};
#ifndef _CHANGE_WAY
	Point *pointPtr = addPoint(&p1,&p2);
	cout<<"addPoint(const Point*,const Point*): ("<<pointPtr->x<<","<<pointPtr->y<<")"<<endl;
	delete pointPtr;
	pointPtr = nullptr;
	
	Point p3 = subPoint(p1,p2);
	cout<<"subPoint(const Point&,const Point&): ("<<p3.x<<","<<p3.y<<")"<<endl;
	
	modifyPoint(&p2);
	cout<<"modifyPoint(Point*): ("<<p2.x<<","<<p2.y<<")"<<endl;
#else
	Point p3 = {0};
	addPoint(p1,&p2,&p3);
	cout<<"addPoint(Point,const Point*,Point*): ("<<p3.x<<","<<p3.y<<")"<<endl;
	
	subPoint(p1,p2,p3);
	cout<<"subPoint(Point,const Point&,Point&): ("<<p3.x<<","<<p3.y<<")"<<endl;
	
	modifyPoint(p2);
	cout<<"modifyPoint(Point&): ("<<p2.x<<","<<p2.y<<")"<<endl;
#endif
	
	return 0;
}
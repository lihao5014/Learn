/*1.����ʽ��̵ĸ��
 *��1������ʽ������롰������󡱺͡����̻�����̲��е�һ�ֱ�̷�ʽ��Ҳ������α�д����ķ����ۡ�
 *     �����ڽṹ����̵�һ�֣���Ҫ˼���ǰ�������̾���д��һϵ��Ƕ�׵ĺ������á�
 *��2������ʽ�������Ҫ�������ǣ�������Ϊ��һ�ȹ���������������㿴������ѧ�к����ļ��㣬
 *     ǿ����������̷ֽ�ɿɸ��õĺ������ұ�����״̬�Լ������ĸ��ֻ�д���ġ�û�и�����
 *     �ĺ��������Ǻϸ�ĺ�����
 */

/*2.����ʽ��̵��ص㣺
 *��1�������ǵ�һ�ȹ�����ν����һ�ȹ���ָ���Ǻ�����������������һ��������ƽ�ȵ�λ��
 *     ���Ը�ֵ������������Ҳ������Ϊ������������һ��������������Ϊ��ĺ����ķ���ֵ��
 *��2��ֻ�ñ��ʽ��������䡣 �����ʽ����һ��������������̣������з���ֵ������䡱��ִ��ĳ�ֲ�����
 *     û�з���ֵ������ʽ���Ҫ��ֻʹ�ñ��ʽ������ʹ����䡣Ҳ����˵ÿһ�����ǵ��������㣬
 *     ���Ҷ��з���ֵ��ԭ���Ǻ���ʽ��̵Ŀ���������һ��ʼ����Ϊ�˴������㣬������ϵͳ��I/O��д��
 *     ������ڶ�ϵͳ�Ķ�д���������Ծͱ��ų����⡣��Ȼʵ��Ӧ���в���I/O��д�����ǲ����ܵġ�
 *     ��˺���ʽ��̹�����ֻҪ���I/O���Ƶ���С����Ҫ�в���Ҫ�Ķ�д��Ϊ�����ּ�����̵ĵ����ԡ�
 *��3��û�и����á���ν�������á�ָ���Ǻ����ڲ����ⲿ��������������������������������͵����
 *     �����޸�ȫ�ֱ�����ֵ������ʽ���ǿ��û�и����ã���ζ�ź���Ҫ���ֶ��������й��ܾ��Ƿ���
 *     һ���µ�ֵ��û��������Ϊ�������ǲ����޸��ⲿ������ֵ��
 *��4�����޸�״̬������ʽ���ֻ�Ƿ����µ�ֵ�����޸�ϵͳ��������˲��޸ı���Ҳ������һ����Ҫ�ص㡣
 *     ��������̷�ʽ�������У����������������桰״̬�������޸ı�������ζ��״̬���ܱ����ڱ����С�
 *     ����ʽ���ʹ�ò�������״̬����õ����Ӿ��ǵݹ顣����ʹ���˵ݹ飬����ʽ���Ե������ٶȱȽ�����
 *     ���������ڲ�����ҵ���ƹ����Ҫԭ��
 *��5������͸����������͸����ָ���Ǻ��������в��������ⲿ������״̬��ֻ����������Ĳ�����
 *     �κ�ʱ��ֻҪ������ͬ�����ú������õ��ķ���ֵ������ͬ�ġ����������͵ı�������У�
 *     �����ķ���ֵ������ϵͳ״̬�йأ���ͬ��״̬֮�£�����ֵ�ǲ�һ���ġ���ͽС����ò�͸������
 *     �ܲ����ڹ۲�����������Ϊ��
 */

/*3.����ʽ��̵��ŵ㣺
 *��1�������࣬�������١�����ʽ��̴���ʹ�ú����������˴�����ظ�����˳���Ƚ϶̣�
 *     �����ٶȽϿ졣
 *��2���ӽ���Ȼ���ԣ�������⡣����ʽ��̵����ɶȺܸߣ�����д���ܽӽ���Ȼ���ԵĴ��롣
 *��3��������Ĵ����������ʽ��̲�������Ҳ����ı�����״̬��ֻҪ�������������
 *     ���صĽ���ض���ͬ�����ÿһ�����������Ա�����������Ԫ���������ڽ��е�Ԫ���Ժͳ���
 *     �Լ�ģ�黯��ϡ�
 *��4�����ڲ�����̡�����ʽ��̲���Ҫ������������Ϊ�����޸ı��������Ը������������̵߳����⡣
 *     ���ص���һ���̵߳����ݱ���һ���߳��޸ģ����Կ��Ժܷ��ĵذѹ�����̯������̣߳����𲢷���̡�
 *     ���ں���֮�以�����ţ������޸ı�����˭��ִ��������ν�ģ����Կ��Է��ĵ������̣߳������Ƿ���
 *     ������߳�����ɡ��������͵����Ծ���������һ�㣬��Ϊһ�������п��ܻ��޸�ϵͳ״̬���������
 *     �����п��ܻ��õ���Щ״̬�����Գ�����Ҫ��֤���������ִ��˳����ȻҲ�Ͳ��ܲ��𵽶���߳��ϡ�
 *     ���CPU�ǽ����ĳ��������Ժ���ʽ��̵�������Էǳ���Ҫ��
 *��5�������������������ʽ���û�и����ã�ֻҪ��֤�ӿڲ��䣬�ڲ�ʵ�����ⲿ�޹صġ����Կ���������
 *     ״̬��ֱ���������룬����Ҫ������Ҳ����Ҫͣ����
 */

#include <stdio.h>
#include <iostream>
#include <string>

#define _CHANGE_WAY_
#undef _CHANGE_WAY_

using namespace std;

static int g_count = 5;

//��Ϊincrement()�����������ⲿ�����ݣ������޸����ⲿ���ݵ�ֵ�����Բ����ں���ʽ��̷�ʽ��
void increment()
{
    g_count++;
}

//����ʽ��̵�׼�򣺲��������ⲿ�����ݣ�����Ҳ���ı��ⲿ���ݵ�ֵ�����Ƿ���һ���µ�ֵ����
int increment(int num)
{
    return num+1;
}

class Number
{
public:
	Number(int n):m_value(n){}
	Number(const Number& other):m_value(other.m_value){}
	
	void setValue(int num){m_value = num;}
	int getValue()const{return m_value;}
	
	Number add(Number m){return Number(m_value + m.m_value);}
	Number subtract(Number m){return Number(m_value - m.m_value);}
	Number multiply(Number m){return Number(m_value * m.m_value);}
	
	friend Number add(Number x,Number y);
	friend Number subtract(Number x,Number y);
	friend Number multiply(Number x,Number y);
	
	friend ostream& operator <<(ostream &os,const Number& num)
	{
		os << num.m_value;
		return os;
	}
private:
	int m_value;
};

int add(int x,int y)
{
	return x + y;
}

int subtract(int x,int y)
{
	return x - y;
}

int multiply(int x,int y)
{
	return x * y;
}

Number add(Number x,Number y)
{
	return Number(x.m_value + y.m_value);
}

Number subtract(Number x,Number y)
{
	return Number(x.m_value - y.m_value);
}

Number multiply(Number x,Number y)
{
	return Number(x.m_value * y.m_value);
}

typedef int data_t;
typedef void (*pFun)(data_t);

void print(data_t n)
{
	cout<<n<<" ";
}

//��Ϊforeach()��������������Ϊ��������������һ���߽׺�����
#ifndef _CHANGE_WAY_
void foreach(data_t* beginPtr,data_t* endPtr,pFun fun)  //ѭ�������ʹ���˾ֲ����������Բ����ں���ʽ��̡�
{
	for(data_t* p = beginPtr;p != endPtr;++p)
	{
		fun(*p);
	}
}
#else
void foreach(data_t* beginPtr,data_t* endPtr,pFun fun)  //ʹ�õݹ����ѭ����䣬���Ǻ���ʽ��̵ķ�ʽ��
{
	if(beginPtr == endPtr)
	{
		return;
	}
	else
	{
		fun(*beginPtr);
		return foreach(beginPtr + 1,endPtr,fun);
	}
}	
#endif

//���ַ����������еĺ���������ʾ�˲�ͬ�Ĳ�����ξ���������������"״̬".
string stringReverse(string str)
{
	if(str.length() <= 1)
	{
		return str;
	}
	else
	{
		return stringReverse(str.substr(1,str.length())) + str.at(0);
	}
}

int main(void)
{
	increment();    //��״̬�����ǲ�������ģ��Ǻ���ʽ��̷�ʽ���Ƽ�ʹ�õĺ������͡�
	cout<<"g_count ="<<g_count<<endl;
	
	int count = 5;
	int ret = increment(count);    //��״̬�������ǿ�����ģ����ڲ���������ƣ��Ǻ���ʽ��̷�ʽ���Ƽ�ʹ�õĺ������͡�
	cout<<"ret ="<<ret<<endl<<endl;
	
	//��ͳ�Ĺ���ʽ����У�ʹ�ú���ʽ���˼�����(1 + 2) * 3 - 4���ʽ��
	int a = 1 + 2;
	int b = a * 3;
	int c = b - 4;
	printf("(1 + 2) * 3 - 4 =%d\n",c);
	
	//����ʽ���Ҫ��ʹ�ú��������ǿ��԰�������̶���Ϊ��ͬ�ĺ���������������ı��ʽ��������װ�ɺ�����
	ret = subtract(multiply(add(1,2),3),4);       //C���Ժ���ʽ����е�pipeline������ʽ��
	printf("(1 + 2) * 3 - 4 =%d\n",ret);
	
	//��Ϊʹ��add(1,2)�����add(int,int)���غ�����Ϊ����ʾ����add(Number,Number)ֻ��ʹ��add(Number(1),2)��
	Number num = add(Number(1),2).multiply(3).subtract(4);     //����ʽ����е�pipeline������ʽ��
	cout<<"(1 + 2) * 3 - 4 ="<<num<<endl<<endl;
	
	data_t arr[] = {2,4,6,7,0,8,1,5,9,3};
	foreach(arr,arr + sizeof(arr)/sizeof(arr[0]),print);
	cout<<endl<<endl;
	
	string str = "hello world";
	cout<<"str ="<<str<<" , reverse: "<<stringReverse(str)<<endl;
	
	return 0;
}
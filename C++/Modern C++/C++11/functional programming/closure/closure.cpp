/*2.����ʽ����еıհ�:���հ� = ״̬ + ���� = �ࣩ
 *��1�������Ͷ�����Χ״̬������������һ�𹹳ɱհ���Ҳ����˵���հ�����������ڲ����������ⲿ����������
 *��2���հ��ֳƴʷ��հ������հ��������������ɱ����ĺ�������������õ����ɱ��������������һͬ���ڣ�
 *     ��ʹ�Ѿ��뿪�˴������Ļ���Ҳ�����⡣��������һ��˵����Ϊ���հ����ɺ�����������ص����û������
 *     ���ɵ�ʵ�塣�հ�������ʱ�����ж��ʵ������ͬ�����û�������ͬ�ĺ�����Ͽ��Բ�����ͬ��ʵ����
 *��3���հ������ܹ���ȡ���������ڲ������ĺ������������������ɱ����ĺ������������������ĵĺ�������
 *     ����״̬�ĺ����������⺯����
 *��4���հ��ǿ��԰������ɱ����Ĵ���飬��Щ�������������������ڻ����κ�ȫ���������ж���ģ�
 *     �����ڶ�������Ļ����ж��壨�ֲ����������հ���Ҫִ�еĴ�����Ϊ���ɱ����ṩ�󶨵�
 *     ���㻷�������������ߵĽ�ϡ�
 *��5���հ��Ǵ��������ĵĺ�������״̬�ĺ���������˵�հ���������������е����ں���ʽ�����
 *     ���˸����ֶ��ѡ�����������״̬�ͱ���˱հ�������״̬����˼������հ��������Լ��ı�����
 *     ��Щ��������ֵ�Ǵ����հ���ʱ�����õģ����ڵ��ñհ���ʱ�򣬿��Է�����Щ������
 *��6�������Ǵ��룬״̬��һ��������������һ�����������γ��˱հ������ڲ�����static��̬����
 *     �ĺ������Ǳհ�����Ϊstatic��̬���������������ǲ�������ͬ��static��̬��������Ϊ���
 *     �ڱ����ʱ���Ѿ�ȷ���ˡ��հ���״̬���󣬱��뷢��������ʱ��
 */

/*2.C++�бհ��ģ���ʵ�ַ�����
 *��1������operator()�ĺ���������Ϊ�հ���һ����������״̬����״̬����ͨ��������thisָ�봫�룬
 *     ���Ահ���Ȼ��һ������������Ϊ��Ա�������Ǽ��õ����ڱ���״̬�Ĺ��ߡ����ʵ��operator()
 *     ��������أ�����Ķ��������Ϊ�հ�ʹ�á�Ĭ�ϴ����thisָ���ṩ�˷��ʳ�Ա������;����
 *     ��ʵ��lambda���ʽ��std::bind()��ԭ����ͨ���º���ʵ�ֵġ�
 *��2��lambda���ʽ��c++11���ṩ��lambda����ʵ�ֱհ��ܺõ��﷨�ǡ��䱾�ʺ���д�ĺ�������û������
 *     ʵ���ϱ������ǽ�lambda���ʽ�����δ�������δ�������������˺����������������lambda�в���
 *     ����ʱ����δ�����������Լ��ĳ�Ա���ݣ����γ��˱հ�������lambda���ʽ���Ǻ�������ļ�д����
 *��3��std::bind()��c++11��׼�����ṩ��bind()�Ǹ���ǿ����﷨�ǣ����Խ���Ҫ��д�ܶ����ıհ���
 *     Ũ����һ��bind()�Ϳ��Ը㶨�ˡ�
 */

/*3.C++��ʹ�ñհ���ע�����
 *��1���հ���״̬��ָ�����е������ġ��հ�������������ʱ��Ҫ�������ģ��Ӷ���֤��closure����ʱ��������
 *     ������closure����ʱ��Ȼ��Ч���հ����������ĵ���һ�ص�ͨ����������capture�����������"bind"����
 *     capture��������Լ�д���캯�����Σ�Ҳ������std::bind()����Ȼ���Ļ����ñ����������Զ���ɡ�
 *     ���������Զ�ʶ��closure�õ��ı�����Ȼ�󴴽�һ���������࣬������������浽������ĳ�Ա�����С�
 *��2��C++��lambda���ʽ��2��capture��ʽ��by value��by reference��д����[=]��[&]����Ҫע�ⰴ���ò���
 *     �ǲ����޸ı�capture�������������ڵģ�Ҫ��Ϊ��֤��capture�ı�����closure����ʱ����Ч�ġ�
 *��3����lambda���ʽ�����ıհ����������صģ�ÿ�δ���һ��closure�����������ᴴ��һ���µ����͡�
 *     ����뱣��һ���հ�ʱ�Ͳ�����ôֱ�ӣ���Ϊ��֪���������͡��򵥵ķ�ʽ��ֱ����auto�ؼ��ֻ�
 *     std::function�����档
 *��3��C++�հ��б������������ȫ���������õı����Ŀ��������á�����Ƕ���绷���еĶ�������ã�
 *     �ұհ�ִ��ʱ����绷���ı����Ѿ������ڣ���ô�ɵ���δ������Ϊ����ΪC++������չ��Щ������
 *     ����绷���ı����������ڡ���C++�бհ�ֻʹ����Щ������������Щ�������������ڡ�
 */

#include <iostream>
#include <functional>       //function,bind(),placeholders::_1,placeholders::_2
#include <string>
#include <memory>           //unique_ptr,shared_ptr
#include <unordered_map>    //unordered_map

#define _ERROR_
#undef _ERROR_

using namespace std;

/*ͨ��������"()"���������������ʹ����ĳ�Ա����ʵ�ֱհ���һ����C++��Ҳ�Ʊհ�ΪЯ����״̬�ĺ�������
 *�ⲿ������Ϊ���������״̬����������"()"�������ķ�ʽʹ�ñհ��ȽϷ���������ÿһ�αհ����붼Ҫ����
 *дһ�����������࣬����C++11�������˸�Ϊ����ķ�ʽ����lambda���ʽ��std::bind()��
 */
class Accumulator
{
public:
	Accumulator(int init):m_result(init){}
	
	int operator ()(int n)
	{
		m_result += n;
		return m_result;
	}
	
private:
	int m_result;   //һ�������������һ���հ������к�������ĳ�Ա�������൱�ڱհ���״̬��
};

/*�հ������ܹ���ȡ���������ڲ������ĺ�����ֻ�к����ڲ����Ӻ������ܶ�ȡ�ֲ�������
 *���Ահ��������ɡ�������һ�������ڲ��ĺ��������ڱ����ϱհ��ǽ������ڲ��ͺ���
 *�ⲿ����������������
 */
#ifndef _ERROR_
function<int(int)> accumulator()
{
	int sum = 0;                 //��Ϊ�����ڲ������˾ֲ����������Ըñհ�������״̬���б����ıհ���
	return [=](int n)mutable{
				sum += n;
				return sum;
			};
}
#else
function<int(int)> accumulator()
{
	int sum = 0;              //���˺���������ֲ������ͱ������ˣ�����ʵ����״̬�ıհ�ʱ��������ʹ�����ò���
	return [&sum](int n){
				sum += n;
				return sum;
			};
}
#endif

/*��Ϊlambda���ʽ����ͨ�������б����ʵ�lambda�ⲿ�������еı�����
 *����lamdba���ʽ������֧�ֺ���ʽ��̵ıհ����Եġ�
 */
function<int(int)> adder(int x)    //��״̬���ޱ����ıհ�
{
	return [x](int y){return x + y;};
}

/*std::bind()ͨ�����ⲿ�����ͺ�������һ��ʵ�ֱհ���bind()����ֵΪһ����������
 *��ʹ����ģ��std::function���ա�
 */
int power(int m,int n)
{
	int ret = 1;
	while(n --> 0)
	{
		ret *= m;
	}
	return ret;
}

/*�ڲ�����static��̬�����ĺ������Ǳհ�����Ϊstatic��̬������once()�������رհ��Ĺ���״̬��
 *������ĳ���հ���˽��״̬��
 */
function<void(void)> once()
{
	static bool flag = true;
	return []{                  //��̬����������lambda��ֱ�ӷ��ʣ�������Ҫ����
				if(flag)
				{
					cout<<"function call once!"<<endl;
				}
				flag = false;
			};
}

#ifndef _ERROR_
function<int(void)> fibonacci()    //ʹ�ñհ�ʵ��쳲���������
{
	int a = 1,b = 1;
	return [=]()mutable{
				int temp = a;
				a = b;
				b = temp + b;
				return a;
			};
}
#else
function<int(void)> fibonacci()
{
	int a = 0,b = 1;           //���˺���������ֲ������ͱ������ˣ�����ʵ����״̬�ıհ�ʱ��������ʹ�����ò���
	return [&](){
				int temp = a;
				a = b;
				b = temp + b;
				return a;
			};
}	
#endif

//C++Ϊ��̬���ԣ�ʹ���κ��ֶ�ģ�⶯̬���ܣ�����ζ��������ʧ��һζ��׷���﷨���㣬�������ϵ�������ì�ܵġ�
unordered_map<string,function<int(void)>> counter(int init)
{
	shared_ptr<int> pnumber(new int{init});
	unordered_map<string,function<int(void)>> funcHash;
	
	funcHash["reset"] = [=]()->int{
		*pnumber = init;
		return *pnumber;
	};
	
	funcHash["next"] = [=]{
		return ++(*pnumber);
	};
	
	return funcHash;
}

int main(void)
{
	int ret = 0;
	int initNumber = 0;
	Accumulator add(initNumber);     //��������Ĺ��캯�����Σ����൱��lambda���ʽ�Ĳ��������
	for(int i=11;i<20;++i)
	{
		ret = add(i);
	}
	cout<<"11 + 12 + ... + 19 ="<<ret<<endl;
	
	function<int(int)> sum = accumulator();    //��ͨ�հ�����
	sum(1);
	sum(2);
	ret = sum(3);
	cout<<"1 + 2 + 3 ="<<ret<<endl;
	
	auto plus = adder(0);            //��״̬���ޱ����ıհ�����
	for(int i=1;i<10;++i)
	{
		ret = plus(i);
		plus = adder(ret);
	}
	cout<<"1 + 2 + ... + 9 ="<<ret<<endl;
	
	/*�ɵ��ö���square��Ϊһ���հ����հ�square�а����ֲ�����exponent�뺯��power()��
	 *�ڽ�������square��ʹ�ã�ֱ�ӵ���power()�����ͱ���exponent��
	 */
	int exponent = 2;
	auto square = std::bind(power,placeholders::_1,exponent);
	cout<<"5 * 5 ="<<square(5)<<endl;
	cout<<"6^2 ="<<square(6)<<endl;
	
	exponent = 3;
	function<int(int)> cube = std::bind(power,placeholders::_1,exponent);
	cout<<"5 * 5 *5 ="<<cube(5)<<endl;
	cout<<"6^3 ="<<cube(6)<<endl;
	
	auto foo = once();
	foo();
	
	function<void(void)> bar = once();
	foo();
	
	auto fun = fibonacci();
	for(int i=0;i<10;++i)
	{
		cout<<fun()<<" ";
	}
	cout<<endl;
	
	auto counterA = counter(10);
	cout<<"counterA next: "<<counterA["next"]()<<endl;
	cout<<"counterA next: "<<counterA["next"]()<<endl;
	
	cout<<"counterA reset: "<<counterA["reset"]()<<endl;
	cout<<"counterA next: "<<counterA["next"]()<<endl;
	
	return 0;
}
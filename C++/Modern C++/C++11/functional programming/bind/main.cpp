/*1.C++�пɵ��ö����5������:
 *��1����ͨ����ָ�롣
 *��2������operator()��Ա������������
 *��3���ɱ�ת���ɺ���ָ��������
 *��4����ĳ�Ա����ָ�롣
 *��5��lambda���ʽ��
 */
 
/*C++�пɵ��ö������Ȼ����һ���Ƚ�ͳһ�Ĳ�����ʽ�����Ƕ��巽���廨���ţ���͵���ʹ��ͳһ�ķ�ʽ����
 *�ɵ��ö�����ߴ��ݿɵ��ö���ʱ����ʮ�ַ�����C++11���ṩ��function��bindͳһ�˿ɵ��ö���ĸ��ֲ�����
 */

/*2.std::function�ɵ��ö����װ��:
 *��1��std::function��һ���ɵ��ö����װ������һ����ģ�壬�������ɳ������Ա����ָ��֮�������
 *     �ɵ��ö�����������ͳһ�ķ�ʽ���������������󡢺���ָ�룬����������ӳ����ǵ�ִ�С�
 *��2��std::function����ȡ������ָ������ã���Ϊ�������ӳٺ�����ִ�У��ر��ʺ���Ϊ�ص�����ʹ�á�
 *     ������ͨ����ָ����ӵİ�ȫ�����ͱ�����
 */

/*3.std::bind������������
 *��1���ɽ�std::bind��������һ��ͨ�õĺ�����������������һ���ɵ��ö�������һ���µĿɵ��ö���
 *     ������Ӧ��ԭ����Ĳ����б�
 *��2��std::bind���ɵ��ö����������һ����а󶨣��󶨺�Ľ������ʹ��std::function���档
 */

/*4.std::bind��������Ҫ���ã�
 *��1�����ɵ��ö����������󶨳�һ���º�����
 *��2��ֻ�󶨲��ֲ��������ٿɵ��ö�����Ĳ�����
 */

/*5.std::bind����ͨ������
 *��1��std::bind�ĵ�һ�������Ǻ���������ͨ������ʵ��ʱ������ʽת���ɺ���ָ�롣
 *��2��_1��ʾռλ��λ��<functional>�У�std::placeholders::_1��
 *��3��_2��ʾռλ��λ��<functional>�У�std::placeholders::_2��
 */

/*6.std::bind��һ����Ա����:
 *��1��bind�����Ա����ʱ����һ��������ʾ����ĳ�Ա������ָ�룬�ڶ���������ʾ����ĵ�ַ��
 *��2������ʹ��&ȡ��ַ����ʾ��ָ����Ա������ַ����Ϊ���������Ὣ����ĳ�Ա������ʽת���ɺ���ָ�룬
 *     ���Ա����ڳ�Ա����ǰ���&��
 *��3��ʹ�ö����Ա������ָ��ʱ������Ҫ֪����ָ�������ĸ��������std::bind�ĵڶ�������Ϊ����ĵ�ַ��
 */

#include <iostream>
#include <functional>
#include "calculator.h"

using namespace std;

int add(int x,int y)    //�ɵ��ö�����ͨ����
{
	return x + y;
}

struct subtract         //�ɵ��ö��󣺺���������/�º���
{
	int operator ()(int x,int y)
	{
		return x - y;
	}
};

auto mod = [](int x,int y){return x % y;};   //�ɵ��ö���lambda���ʽ

class Compare
{
public:
	bool less(double x,double y)
	{
		return x < y; 
	}
	
	bool greater(double x,double y)
	{
		return x > y ? true : false;
	}
};

int main(int argc,char** argv)
{
	/*add��subtract��mod���ֿɵ��ö�����Ȼ���Ͳ�ͬ�����ǹ�����ͬһ�ֵ�����ʽint(int,int)��
	 *����ͬ���͵Ŀɵ��ö��󣬿��ܾ�����ͬ�ĵ�����ʽ��ʹ��std::function<int(int,int)>�Ϳ���
	 *�������ֿɵ��ö������ͱ���������
	 */
	using pf = int(int,int);
	function<pf> func_add = add;
	function<pf> func_sub = subtract();
	function<pf> func_mod = mod;
	
	cout<<"func_add(1,2) ="<<func_add(1,2)<<endl;
	cout<<"func_sub(3,1) ="<<func_sub(3,1)<<endl;
	cout<<"func_mod(5,2) ="<<func_mod(5,2)<<endl<<endl;
	
	/*��ΪC++��׼�����Ѿ�����std::multiplies������������Ϊ�˱����ʶ��������
	 *ʹ���Զ����multiplies()����ʱ��������ϡ�::��ȫ��������
	 */
	auto twice = std::bind(::multiplies,placeholders::_1,2);
	
	using placeholders::_1;
	function<data_t(data_t)> half = bind(::divides,_1,2);
	
	cout<<"twice(4) ="<<twice(4)<<endl;
	cout<<"half(6) ="<<half(6)<<endl<<endl;

	Compare compare;
	auto isNegative = std::bind(&Compare::less,&compare,_1,0);
	function<bool(double)> greaterThan_5 = bind(&Compare::greater,&compare,_1,5);
	
	cout<<"isNegative(-3.14) ="<<isNegative(-3.14)<<endl;
	cout<<"greaterThan_5(9.8) ="<<greaterThan_5(9.8)<<endl<<endl;
	
	int ret = calculate(4,5,ADD);
	cout<<"4 + 5 ="<<ret<<endl;
	
	ret = calculate(9,3,SUB);
	cout<<"9 - 3 ="<<ret<<endl;
	
	ret = calculate(7,6,MULT);
	cout<<"7 * 6 ="<<ret<<endl;
	
	ret = calculate(8,2,DIVI);
	cout<<"8 / 2 ="<<ret<<endl;
	
	return 0;
}
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

/*7.std::bind��һ�����ò���:
 *��1��Ĭ�������std::bind()����Щ����ռλ���Ĳ������Ǳ�ֱ�ӿ�����bind()���صĿɵ��ö����С�
 *     ������lambda���ƣ���ʱϣ���󶨵Ĳ��������õķ�ʽ���ݣ�����Ҫ�󶨲����������޷�������
 *     ���Ǿͱ���ʹ�ñ�׼���ṩ��std::ref()������
 *��2��std::ref()ֻ�ǳ���ģ�����ô��ݣ�����������������ã��ڷ�ģ��״����ref()�����޷�ʵ�����ô��ݣ�
 *     ֻ��ģ���Զ��Ƶ�����ʱ��std::ref()���ð�װ����reference_wrapper�����汾���ᱻʶ���ֵ���ͣ�
 *     ��reference_wrapper����ʽת��Ϊ�����õ�ֵ���������͡�
 *��3��C++��������������&��������C++11��������std::ref��std::cref����Ҫ�ǿ���std::bind()��ʹ��ʱ��
 *     �ǶԲ���ֱ�ӿ��������������á�
 *��4��C++��&������˵������std::ref()��һ������������std::reference_wrapper��
 */

#include <iostream>
#include <sstream>   //ostringstream
#include <string>
#include <vector>
#include <functional>    //function,bind(),ref(),std::plus,std::minus,std::multiplies,std::divides
#include <algorithm>
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

//����std::ref��Ҫ�ǿ��Ǻ���ʽ��̣���std::bind����ʹ��ʱ���ǶԲ���ֱ�ӿ��������������á�
void foo(int& x,int& y,const int& z)
{
	cout<<"in foo(): "<<x<<" "<<y<<" "<<z<<endl;
	++x;
	++y;
}

ostream& print(ostream& os,const string& str,char ch)
{
	os<<str<<ch;
	return os;
}

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

	/*��1�������Ա����ָ��ʱ������ָ����������򡣼�����˵����Ա����ָ��ָ���Ǹ����е��Ǹ���Ա������
	 *��2����Ϊ���еķǾ�̬��Ա�����Ƕ�����еģ����Ա�����������ó�Ա����ָ�롣
	 */
	Compare compare;
	bool (Compare::*pfun)(double,double) = &Compare::less;
	cout<<"5 < 8 = "<<(compare.*pfun)(5,8)<<endl;
	
	pfun = &Compare::greater;
	cout<<"8 > 5 = "<<(&compare->*pfun)(8,5)<<endl;
	
	auto isNegative = std::bind(&Compare::less,&compare,_1,0);
	function<bool(double)> greaterThan_5 = bind(&Compare::greater,&compare,_1,5);
	
	cout<<"isNegative(-3.14) ="<<isNegative(-3.14)<<endl;
	cout<<"greaterThan_5(9.8) ="<<greaterThan_5(9.8)<<endl<<endl;
	
	//std::bindĬ��ʹ�õ��ǲ����Ŀ������������á������Ҫʹ�����ô��Σ�����std::ref���ɡ�
	int x = 1,y = 2,z = 3;
	function<void()> bar = bind(foo,x,std::ref(y),std::cref(z));
	
	x = 10;
	y = 11;
	z = 12;
	cout<<"before bar(): "<<x<<" "<<y<<" "<<z<<endl;
	bar();
	cout<<"after bar(): "<<x<<" "<<y<<" "<<z<<endl;
	
	char ch = ' ';
	ostringstream os;
	vector<string> words{"hello","world","this","is","c++11"};
	for_each(words.begin(),words.end(),[&os,ch](const string& str){os<<str<<ch;});
	cout<<os.str()<<endl;
	
	/*��ϣ�����ݸ�bindһ�����󣬶������������ͱ���ʹ�ñ�׼���ṩ��std::ref()������
	 *��Ϊostream���ܿ��������Դ��ݸ�bind()����ʱ��ֻ��ʹ�����ô��ݡ�
	 */
	ostringstream os1;
	for_each(words.begin(),words.end(),bind(print,std::ref(os1),placeholders::_1,ch));
	cout<<os1.str()<<endl<<endl;
	
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
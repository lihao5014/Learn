/*C++Ԫ��̵ĳ�����һ�����Ĳ�����żȻ�����Ƿ���C++�����ṩ��ģ�������ƣ�
 *�ܺܺõı�Ӧ����Ԫ����ϡ�����Ԫ��̣�����д�����Ͱ�ȫ������ʱ��Ч�Ĵ��롣
 *���ǹ��ȵ�ʹ��Ԫ��̣�һ��������ӱ���ʱ�䣬��һ����ή�ͳ���Ŀɶ��ԡ�
 *������C++���ϵ��ݻ��У��µ��������Ա����������ΪԪ����ṩ����Ŀ��ܡ�
 */

/*1.Ԫ��̵Ļ���Ӧ�ã�
 *��1������Ԫ��̿��Ժܷ������Ƴ����Ͱ�ȫ������ʱ��Ч�ĳ�������Ԫ����ѱ��㷺��Ӧ����C++�ı��ʵ���С�
 *     ����Ԫ��̵�Ӧ�ó���������ͬ���������������Ӧ�õ���ϣ���ֵ���㡢�����Ƶ��ʹ������ɡ�
 *��2����ֵ���㣺��ΪԪ��̵������Ӧ�ã���ֵ����������ڱ���ʱ����������Ż�����ʱ����ʽ���㡣
 *     ����ʱ�����������ó���Աд����ʱȷ���ĳ�����������ֱ��д������������ʱ������Щ������
 *��3�������Ƶ������˻�������ֵ����֮�⣬����������Ԫ��̽�����������֮����໥�Ƶ���
 *��4���������ɣ��ͷ��ͱ��һ����Ԫ���Ҳ���������ڴ�������ɡ����Ǻͼ򵥵ķ��ͱ�̲�ͬ��
 *     Ԫ������ɵĴ���������ͨ������ʱ���Ժͱ���ʱ�����������Ƶ������ġ�
 */

/*2.Ԫ��̵���Ҫ�ѵ㣺
 *��1������C++������Ʋ�����û��ר�ſ���Ԫ��̵�������⣬����ʵ��Ԫ����ѶȽϴ�
 *     Ԫ��̵��ѵ���Ҫ�����ࣺ�����ԡ�ʵ�������󡢴������͡�����ģ�塣
 *��2�������ԣ�����Ԫ��̵����Բ����ϵ����ƽϴ����������Ԫ��̴���ʹ���˺ܶ��
 *     ����ʱ���Ժͱ���ʱ�������ɣ��ɶ��Զ��Ƚϲ���������������Ƴ�����ʱ����ɵ�
 *     ����Ҳ�Ǻ����ѵģ������һ���C++����Ԫ��̵Ŀ�д��Ҳ���Ǻܺá�
 *��3��ʵ��������ģ���ʵ�����ͺ����İ󶨲�ͬ���ڱ���ǰģ���ʵ�����Դ���Ĳ�����ʲô��
 *     û��̫������ƣ��������İ�����ݺ�����������ȷ����Ӧ�ô�����������͡�
 *     ������ģ��ʵ�����ݵļ�飬������ʵ�����Ĺ�������ɵġ����Գ����������ڱ���ǰ��
 *     ���ѷ���ʵ����ʱ���ܲ����Ĵ���Ϊ�˼��ٿ��ܲ����Ĵ���C++֮������������Բ����ϣ�
 *     ��ģ�������������ø�����ԶԴ���Ĳ����������ƣ���ֻ�������ض����Ƶ����Ͳ���
 *     ��Ϊ��������ģ�塣�������ڸ���ԭ�������������һֱû������ʽ����C++��׼��������ˣ�
 *     ����ʱ�Կ���ͨ������ʱ���Ժ;�̬���Եȷ���ʵ�ּ�顣�������ʱģ���ʵ��������λ�ã�
 *     �ڵ��ò������ʱ������������ʾÿһ��ʵ������״̬����ʹ�ñ�����Ϣ�����˺ܶ��������Ϣ��
 *     �������˽Ͽ�ķ����������ڡ�
 *��4���������ͣ�����ģ�������в�ͬģ��ʵ�ζ�����һ��ʵ���������Ե���������Ϻܶ��ʱ��
 *     �ܿ��ܻᷢ���������ͣ�����������޴�Ĵ��롣��Щ������Է�Ϊ���������Ч����2�֡�
 *     ��Ԫ����У��ܶ�ʱ��ֻ�����Ƶ��Ľ�������ǹ��̡�����Ҫ�м�����в�������ʱģ�塣
 *     ��Щ��ʱģ���������룬������ִ�еĴ��롣���Ա��������Զ��Ż����յĴ������ɣ�������ʱ��
 *     ����Щ���ô��룬ʹ�����յ�Ŀ����벻��������ǡ���һ������£�չ���Ĵ��붼����Ч���룬
 *     �����Ǳ�ִ�еģ�������������Ҫ�Ĳ��������ͷ��࣬���Ĵ��������Ȼ�ܴ󡣱����������Ż�
 *     ��Щ���룬���Գ���ԱӦ�������ʱ��ֹ�������͡�
 *��5������ģ�壺Ԫ���������ʱ��Ҫ���ѵ����ڶ�ģ�����ĵ��ԡ������Ҫ���Ե���һ��ͨ���ܶ�ε�
 *     ����ʱ���Ժͱ���ʱ����չ���Ĵ��룬����δ����Ǹ���ģ���ƴ�����ɵģ�����չ���Ĳ����ܶ࣬
 *     ��ô����ʱ��Ҫ���ϵ��ڸ���ģ���ʵ���������л��������龰�£�������Ա���ѰѾ�������ⶨλ
 *     ��չ����Ĵ����ϡ� ����һЩ������Ŀ����ʹ�ø��ӵĴ������ɼ��ɣ�����ͨ����ͳ�Ĵ���������
 *     �����ظ��Ĵ��룬���ڵ��ԡ�
 */

/*3.�ִ�C++Ҳ���ϵ��������Ե����ԣ������ڽ���Ԫ��̵ĸ����ԣ�
 *��1��C++11�ı���ģ���ṩ�˶�ģ���е����͵ļ�Ƿ�����
 *��2��C++14�ı���ģ���ṩ�˶�ģ���г����ļ�Ƿ�����
 *��3��C++17��constexpr-if�ṩ�˱���ʱ���� ����д����
 *��4��C++17���۵�����ʽ�����˱���ʱ���� �ı�д�Ѷȡ�
 *��5������C++14�ķ���lambda����ʽ��Ԫ��̿�Boost.Hana����˲���ģ�����Ԫ��̵����
 *     �����ģ��Ԫ���ʱ�������ִ�Ԫ���ʱ���������˼����ֻ��Ҫʹ��C++14�ķ���lambda
 *     ����ʽ��C++11��constexpr/decltype�Ϳ��Կ���ʵ��Ԫ��̵Ļ��������ˡ�
 */

#include <iostream>
#include <string>         //std::to_string()
#include <type_traits>    //is_arithmetic(),is_same(),enable_if<>,enable_if_t<>

#if defined(__GNUC__) || defined(__clang__)
	#define CPP_STANDARD __cplusplus
#elif defined(_MSC_VER)
	#define CPP_STANDARD _MSVC_LANG
#endif

#if CPP_STANDARD < 201402L
	#error c++ version is less than c++14
#endif

#define _ERROR_
#undef _ERROR_

using namespace std;

/*ʹ��Ԫ��̼��ɣ�ʵ�ֽ�C���ԵĻ����������ݣ�ת��Ϊstd::string�ĺ���ToString()��
 *��1�����ȶ�����������ģ�壺isNum/isStr/isBad���ֱ��Ӧ����������������ν�ʡ�
 */
template <typename T>
constexpr bool isNumber = is_arithmetic<T>::value;   //����ʱ����һ�������Ƿ�Ϊ�ض������͡�

template <typename T>
constexpr bool isString = is_same<T,const char*>::value;

template <typename T>
constexpr bool isBad = !isNumber<T> && !isString<T>;

//��2��Ȼ�����SFINAE����ʹ��std::enable_if���غ���ToString���ֱ��Ӧ����ֵ��C����ַ����ͷǷ����͡�
template <typename T>
typename enable_if<isNumber<T>,string>::type ToString(T num)   //����ʱ����һ������ �Ƿ�����ĳЩ������
{
	return to_string(num);
}

//enable_if<>ģ��C++11���Ѿ��ṩ�ˣ���enable_if_t<>����ģ�嵽C++14���ṩ��
template <typename T>
enable_if_t<isString<T>,string> ToString(T str)    //����ʱ����һ������ �Ƿ�����ĳЩ������
{
	return string(str);
}

/*��3����ǰ���������У��ֱ����std::to_string��std::string���캯���������һ�������У�
 *     ͨ������������false����ʽsizeof(T) == 0��̬����ֱ�ӱ������������׶����Ʋ��ҵĹ涨��
 *     ���ֱ��ʹ��static_assert(false)���ԣ�����ģ�廹ûʵ�����ĵ�һ�׶ξ��޷�ͨ�����롣
 */
template <typename T>
enable_if_t<isBad<T>,string> ToString(T bad)
{
	static_assert(sizeof(T) == 0,"neither number nor string");
}

#ifdef _ERROR_
/*1.����ʱ�������͵Ĵ����÷�:
 *��1�����ڳ��νӴ�Ԫ��̵��ˣ�������ʹ��if�����б���ʱ���ԡ�����δ�����һ�ִ����д����
 *     �ܴ����Ե�������Ԫ��̺���ͨ��̵Ĳ�֮ͬ����
 *��2������To_String()����ʱ�����ڸ���������T����Ҫ�������κ����󶨣���val��Ϊ�����ֱ����
 *     std::to_string(val)��std::string(val)���ٽ���һ�ξ�̬���ԣ����ж�!isBad<T>�Ƿ�Ϊtrue��
 *     ��ᵼ�����ΰ�����һ�λ�ʧ�ܡ��������To_String("hello world")���ڱ�����δ���ʱ��
 *     string(const char*)������ȷ�����أ�����to_string(const char*)�������ҵ���ȷ�����أ�
 *     ���±���ʧ�ܡ�
 *��3���ڽű���������δ�����û������ġ���Ϊ�ű�����û�б���ĸ�����к����İ󶨶�������ʱ��ɣ�
 *     ����̬���Եĺ��������ڱ���ʱ��ɵġ�Ϊ��ʹ�ô���ķ������Ԫ��̣�C++17������constexpr if��
 *     Ϊ�����ṩ�˰���������Ĺ��ܡ�ֻ��Ҫ�����ϴ����е�if��Ϊif constexpr �Ϳ��Ա����ˡ�
 */
template <typename T>
string To_String(T val)   //��������ԭ���ǣ�һ��ģ������޷��ṩ�����������ͣ�ͬʱ����to_string()��string()�Ĵ���Ҫ��
{
	if(isNumber<T>)
	{
		return to_string(val);    //std::to_string()����Ҫ����Ĳ���������C���ԵĻ����������ݡ�
	}
	else if(isString<T>)
	{
		return string(val);       //std::string()���캯��Ҫ����Ĳ���������const char*��string��
	}
	else
	{
		static_assert(!isBad<T>,"neither number nor string");
	}
}
#else
/*2.����ʱ�������͵���ȷ�÷���
 *��1��constexpr if��������ģ����Ը���ֱ�ۣ������ģ�����Ŀɶ��ԡ�����ʹ��constexpr if�������ʱѡ������⣻
 *     �������Ķ�����䣬����ʹ������������false����ʽsizeof(T) == 0���о�̬���ԣ�������ҪisBad<T>ν��ģ�塣
 *     ��Ҳ����ֱ��ʹ��static_assert(false)���ԡ�
 *��2��constexpr if�����˼·����Visual Studio 2012�ѳ����ˡ���������__if_exists��䣬���ڱ���ʱ���Ա�ʶ���Ƿ���ڡ�
 */
template <typename T>
string To_String(T val)
{
	if constexpr(isNumber<T>)    //C++17��������constexpr ifΪ�����ṩ�˰���������Ĺ��ܡ�
	{
		return to_string(val);
	}
	else if constexpr(isString<T>)
	{
		return string(val);
	}
	else
	{
		static_assert(sizeof(T) == 0,"neither number nor string");
	}
}
#endif

int main(void)
{
	string a = ToString(5);	
	string b = ToString(3.14);
	string c = ToString("hello world");
	
	cout<<"a ="<<a<<" , "<<typeid(a).name()<<endl;
	cout<<"b ="<<b<<" , "<<typeid(b).name()<<endl;
	cout<<"c ="<<c<<" , "<<typeid(c).name()<<endl;
	
#ifdef _ERROR_
	// string d = ToString(string("hello c++"));
	// cout<<"d ="<<d<<" , "<<typeid(d).name()<<endl;
#endif
	
	string x = To_String(10);
	string y = To_String(2.718);
	string z = To_String("welcome qt");
	cout<<"x ="<<x<<" , y ="<<y<<" , z ="<<z<<endl;
	
	return 0;
}
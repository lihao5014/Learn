//ʹ��Ԫ��̼��ɣ�ʵ�ֽ�C���ԵĻ����������ݣ�ת��Ϊstd::string�ĺ���ToString()��

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

//��1�����ȶ�����������ģ�壺isNum/isStr/isBad���ֱ��Ӧ����������������ν�ʡ�
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
 *     ͨ������������false���ʽsizeof(T) == 0��̬����ֱ�ӱ����������׶����Ʋ��ҵĹ涨��
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
 *     �������Ķ�����䣬����ʹ������������false���ʽsizeof(T) == 0���о�̬���ԣ�������ҪisBad<T>ν��ģ�塣
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
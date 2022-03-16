/*1.unary_function/binary_function���ܣ�
 *��1��unary_function������Ϊһ��һԪ��������Ļ��࣬��ֻ�����˲����ͷ���ֵ�����ͣ�
 *     ���������أ������������������Ӧ�ý���������ȥ��ɡ�
 *��2��binary_function������Ϊһ����Ԫ��������Ļ��࣬��ֻ�����˲����ͷ���ֵ�����ͣ�
 *    ���������أ������������������Ӧ�ý���������ȥ��ɡ�
 *��3���ڶ���һ����ͨ�ķº���ʱ������ʹ��unary_function��binary_function���������
 *     ��Ҫ����������������Ҫʹ����ʵ�֡�
 *��4����׼���е�һЩ������������Ҫ����������ĺ��������Ѷ���ĳЩ���͡�����std::not1
 *     Ҫ��Ҫ����ĺ�������ӵ����Ϊargument_type�����͡���unary_function������������
 *     ������������Щ���������ݵļ��׷�ʽ��
 *��5����C++��׼�����ṩ�˺���������bind2nd���ѵڶ�����������һ����Ԫ�������һԪ�ġ� 
 *     ��һ��ķº�������ֱ��ʹ����bind2nd�ϣ���Ϊ��bind2nd��concept�����ϣ���Ҫ�̳���
 *     binary_function�ķº������С�
 *��6����C++98��unary_function��binary_functionʹ�õĺ�Ƶ��������C++11�����߶��������ˡ�
 */

/*1.unary_functionһԪ�º�������Դ�룺
 *	template <class Arg, class Result>
 *  struct unary_function
 *  {
 *  	typedef Arg argument_type;    //argument_type�ǵ�һ��ģ�����Arg�ı���������()��������صĲ������͡�
 *      typedef Result result_type;   //result_type�ǵڶ���ģ�����Result�ı���������()���������صķ���ֵ���͡�
 *  };
 */

/*2.binary_function��Ԫ�����������Դ�룺
 *	template <class Arg1, class Arg2, class Result>
 *	struct binary_function 
 *  {
 *  	typedef Arg1 first_argument_type;    //first_argument_type�ǵ�һ��ģ�����Arg1�ı���������()��������صĵ�һ���������͡�
 *      typedef Arg2 second_argument_type;   //second_argument_type�ǵڶ���ģ�����Arg2�ı���������()��������صĵڶ����������͡�
 *      typedef Result result_type;          //return_type�ǵ�����ģ�����Result�ı���������()���������صķ���ֵ���͡�
 *  };
 **/

/*4.std::not1��std::not2��
 *��1��not1�ǹ���һ����ν�ʽ���෴��һԪ��������
 *��2��not2�ǹ���һ����ν�ʽ���෴�Ķ�Ԫ��������
 */

/*5.std::bind1st��std::bind2nd��
 *��1��std::bind1st��std::bind2nd�������ڽ�һ����Ԫ����ת����һԪ���ӡ�bind����˼�ǡ��󶨡���
 *     1st����first��2nd����second��
 *��2��bind1st��bind2nd�������ǽ���Ԫ����ת��ΪһԪ����������ĳЩ�����������Ҫ�̶���Ԫ����
 *     �ĵ�һ��������ڶ�����������ʹ������һԪ������
 *��3��bind1st�൱���������Ĳ�����x op value��
 *��4��bind2nd�൱���������Ĳ�����value op x��
 */

#include <iostream>
#include <functional>   //std::not1,std::not2,bind1st,bind2nd,unary_function,binary_function
#include <algorithm>    //std::less,std::greater,for_each(),all_of(),any_of()

using namespace std;

//std::not1Ҫ������ĺ�������ӵ����Ϊargument_type�����ͣ���()��������ر���Ϊconst���͡�
template <typename T>
struct IsNegative:public unary_function<T,bool>
{
	typename unary_function<T,bool>::result_type operator ()(const typename unary_function<T,bool>::argument_type& num)const
	{
		return num < 0 ? true : false;
	}
};

struct IsEven:public unary_function<int,bool>
{
	result_type operator ()(const argument_type& num)const
	{
		return num%2 == 0;
	}
};



int main(void)
{
	int arr[] = {2,4,5,8,9};
	int len = sizeof(arr)/sizeof(arr[0]);
	for_each(arr,arr + len,[](int num){cout<<num<<" ";});
	cout<<endl;
	
	if(all_of(arr,arr + len,IsNegative<int>()))
	{
		cout<<"all the elements are negative numbers"<<endl;
	}
	
	if(all_of(arr,arr + len,std::not1(IsNegative<int>())))
	{
		cout<<"all the elements are not negative numbers"<<endl;
	}

	if(any_of(arr,arr + len,IsEven()))
	{
		cout<<"There are even elements in the range.\n";
	}
	
	if(any_of(arr,arr + len,std::not1(IsEven())))
	{
		cout<<"There are odd elements in the range.\n";
	}
	
	int ret = count_if(arr,arr + len,IsEven());
	cout<<"There are " << ret << " elements with even values.\n";
	
	ret = count_if(arr,arr + len,not1(IsEven()));
	cout<<"There are " << ret << " elements with odd values.\n";

	return 0;
}
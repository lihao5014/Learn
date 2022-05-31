#include <iostream>
#include <vector>

using namespace std;

//���õ���������ʵ�ֺܶ�ͨ���㷨�����������������㷨֮����һ��������
template <typename Iterator>
typename Iterator::value_type sum(Iterator begin,Iterator end)
{
	typename Iterator::value_type result(0);
	for(Iterator iter=begin;iter != end;++iter)
	{
		result += *iter;
	}
	
	return result;
}

/*�������sum()������ָ�����Ҳ�ܹ������Ͼ�����������ģ��ָ�룬��ָ��û��Ƕ������value_type��
 *���Զ���sum()��ָ�����͵������������õİ취���ں���������value_type֮����һ������traits��
 */
template <typename T>
T sum(T* begin,T* end)
{
	T result = 0;
	for(T* p=begin;p != end;++p)
	{
		result += *p;
	}
	
	return result;
}

/*��ʵC++��׼��������Traits���Ƶ�std::iterator_trait����һ������������std::numeric_limits����
 *���Զ����͵���Ϣ����value_type��reference�����а�װ��ʹ���ϲ���������ͳһ�Ľӿڷ�����Щ��Ϣ��
 *C++ģ��Ԫ��̻��漰���������ͼ��㣬�ܶ�ʱ��Ҫ��ȡ���͵���Ϣ��typedef������ֵ�ȣ��������Щ����
 *��Ϣ�ķ��ʷ�ʽ��һ�£�������ĵ�������ָ�룩�����ǽ����ò�������������ᵼ�´����ظ�����ĳ��֣�
 *�Ӷ����´������ͣ���ͨ����һ�����Կ��ԺܺõĽ����һ���⡣�������Բ������Զ����͵���Ϣ���а�װ��
 *�������ṩ������Ϣ����Ȼ��Ϊ����һ��Ҳ���������ԡ�������һ���ṩԪ��Ϣ���ֶΡ�
 */
template <typename Iter>
struct Traits
{
	using value_type = typename Iter::value_type;
};

template <typename T>
struct Traits<T*>
{
	typedef T value_type;
};

template <typename Iter>
typename Traits<Iter>::value_type total(Iter begin,Iter end)
{
	typename Traits<Iter>::value_type result(0);
	for(Iter i=begin;i != end;++i)
	{
		result += *i;
	}
	
	return result;
}

int main(void)
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int ret = sum(arr,arr + sizeof(arr)/sizeof(arr[0]));
	cout<<"sum 0~9: "<<ret<<endl;
	
	vector<double> vec = {0.5,1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5};
	double result = sum(vec.begin(),vec.end());
	cout<<"sum 0.5~9.5: "<<result<<endl;
	
	ret = total(arr,arr + sizeof(arr)/sizeof(arr[0]));
	cout<<"total 0~9: "<<ret<<endl;
	
	result = total(vec.begin(),vec.end());
	cout<<"total 0.5~9.5: "<<result<<endl;
	
	return 0;
}
/*1.STL�����������������㷨ֱ�ӵĹ�ϵ��
 *��1����STL����У��������㷨�Ƕ�����Ƶģ������ݽṹ���㷨�Ƕ�����Ƶģ������������㷨������
 *     ���ǵ������ˣ�������ʹ�������Ƴ�Ϊ���ܡ�
 *��2��STL��׼���Ŀ�����Ҫ�����ݺ��㷨�ֿ����ֱ���������ƣ�֮��ͨ��һ����Ϊiterator�Ķ�����
 *     ���������ճ�ӵ�һ��
 */

/*2.STL��׼�����ṩ���㷨���е�������
 *��1����������һ�����������iterator��
 *��2��Ҫ����iterator�������iterator��װ��Ԫ�ص����͵���Ϣ��������ʹ�����Ż����㷨��
 *     �����vector��iterator����ô�Ϳ���ʹ��+��-��+=��-=�����������list��iterator��
 *     ��ô�Ͳ�����ʹ��+��-��+=��-=������ֻ��ʹ��++��--���������֮�㷨����֪��һЩ
 *     ����iterator����Ϣ��
 *��3����һЩ������Ӧ��iterator��һ���࣬���ڸ����ж�����5��������Ϣ��������5������
 *     ��Ϣ�Ķ��壬�㷨���ܹ�֪��iterator�Ļ���������������������ˡ�
 *     template<typename T>
 *     struct __list_iterator
 *     { 
 *         typedef bidirectional_iterator_tag    iterator_category;
 *         typedef T                             value_type;
 *         typedef T*                            pointer;
 *         typedef T&                            reference;
 *         typedef ptrdiff_t                     difference_type;
 *     };
 *
 *��4����vector��array�ĵ�����iterator�������࣬����C++�����õ�ָ�롣����ԭʼָ����Ϊ�������ݸ��㷨��
 *     �㷨�޷���֪iterator�ж����iterator_category��value_type��pointer��reference��difference_type
 *     ����Ϣ���㷨���޷�������Ϊ�˽��������⣬����Ҫ���һ���м�㣬Ҳ���Ǵ���һ��iterator_traits�࣬
 *     ����װ��iterator����ʹ��ģ��ֲ��ػ�������
 *��5��traits����ȡ������˼��Ҳ������ȡiterator�����Ϣ�������㷨���㷨��iterator_traits��Ҫ����Ҫ����Ϣ��
 *     iterator_traits����iteratorҪ�����Ҫ���˾�ʹ�ã����û��Ҫ������ʹ��iterator_traits�ṩ��������Ϣ��
 */

/*3.������ȡ����traits�ڵ��������㷨����е�Ӧ�ã�
 *��1�����ģʽ�й���iterator������Ϊ��һ���ܹ�˳�����������ÿ��Ԫ�صķ�����ʹ�ø÷������ܱ�¶
 *     �����ڲ��ı�﷽ʽ����������ȡ��������Ϊ��Ҫ�����iterator�йص�����ġ�
 *��2����������for_each()��find()��count()�ȷ����㷨����ĳ�������У�����Ҫ����Ҫ���㷨�ṩһ������
 *     ������Ԫ�صĹ��ߣ�iterator�Ͱ����������Ҫ�Ľ�ɫ�������㷨�����ǿ��ܻᶨ��򵥵��м��������
 *     �趨�㷨�ķ��ر������ͣ���ʱ����Ҫ֪����������ָԪ�ص�������ʲô����������û��typeof�����ж�
 *     ���͵ĺ��������������޷�ֱ�ӻ�ȡ����ʱ�����Ҫʹ��traits������ȡ������
 *��3����������һ�ֲ������ڴ������ָ�룬��ӵ��һ��ָ��������ص㣬���ܹ��������*�����ú�->ָ�������
 *     �����ڱ���������ʱ�򣬲��ɱ����Ҫ�Ա����������ڲ������˽⣬���Ըɴ�ѵ������Ŀ���������������
 *     ������ߺ��ˡ����һ������ʵ��ϸ�ڣ��������Է�װ��������ʹ���߿�����������Ϊʲôÿһ��STL����
 *     ���ṩ��ר����������Ե�ʡ�
 *��4���ܶ���֮����������ָ������Ԫ�ص�ָ���һ�ֳ���ͨ��ʹ�õ����������ǿ��Է��������е�ĳ��Ԫ�ء�
 *     �ı������е�ĳ��Ԫ�ص�ֵ��ʹ��������ǰ��������ߵȡ�
 */

/*�������ж�����5���������ͣ�����value_type, difference_type, reference_type, pointer_type��4�����Ͷ��Ƚ�
 *������traits����Ӧƫ�ػ�����ȡ������iterator_categoryһ��Ҳ��5���������ͻ������ϴ��ģ��д���빤�̡�
 */

#include <assert.h>
#include <iostream>
#include <iterator>       //iterator_traits,input_iterator_tag,bidirectional_iterator_tag,random_access_iterator_tag
#include <forward_list>
#include <list>
#include <array>

#define _ERROR_
#undef _ERROR_

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define _DEBUG_
#undef _DEBUG_

#ifdef _DEBUG_
#define Debug(str) std::cout<<"["<<__TIME__<<" "<<__FILE__<<"] "<<__func__<<" (line:"<<__LINE__<<") -- "<<(str)<<std::endl;
#else
#define Debug(str) (void)0
#endif

#define UNUSED(x) (void)x;

using namespace std;

template <typename Iterator>
bool is_random_access_iterator(Iterator iter)
{
	typedef typename iterator_traits<Iterator>::iterator_category category;
	return is_same<category,std::random_access_iterator_tag>::value;
}

template <typename Iterator>
bool is_bidirectional_iterator(Iterator iter)
{
	typedef typename iterator_traits<Iterator>::iterator_category category;
	return is_same<category,std::bidirectional_iterator_tag>::value;	
}

template <typename InputIterator>
int distance_input_iterator(InputIterator first,InputIterator last)
{
	Debug("input iterator");
	
	int ret = 0;
	while(first != last)
	{
		first++;
		ret++;
	}
	return ret;
}

template <typename BidirectionalIterator>
int distance_bidirectional_iterator(BidirectionalIterator first,BidirectionalIterator last)
{
	Debug("bidirectional iterator");
	
	int result = 0;
	for(;last-- != first;++result);
	return result;
}

template <typename RandomAccessIterator>
int distance_random_access_iterator(RandomAccessIterator first,RandomAccessIterator last)
{
	Debug("random access iterator");
	return last - first;
}

template <typename InputIterator>
int __distance(InputIterator first,InputIterator last,std::input_iterator_tag)
{
	Debug("input iterator");
	
	int ret = 0;
	while(first != last)
	{
		first++;
		ret++;
	}
	return ret;
}

template <typename BidirectionalIterator>
int __distance(BidirectionalIterator first,BidirectionalIterator last,std::bidirectional_iterator_tag)
{
	Debug("bidirectional iterator");
	
	int result = 0;
	for(;last-- != first;++result);
	return result;
}

template <typename RandomAccessIterator>
int __distance(RandomAccessIterator first,RandomAccessIterator last,std::random_access_iterator_tag)
{
	Debug("random access iterator");
	return last - first;
}

template <typename Iterator>
typename iterator_traits<Iterator>::iterator_category iterator_category(Iterator)
{
	typedef typename iterator_traits<Iterator>::iterator_category category;
	return category();
}

#ifdef _ERROR_
/*��1����Ϊif-else������������ڵ������жϣ��������ڱ����ڷ�֧ѡ�����е�if������֧���ᱻ���롣
 *     ����ֻ��ͬʱ֧��-��--��++������������ʵ��������ܱ���ͨ����
 *��2��û��ʹ��trais����������ȡ�����������н׶β���ȷ�����������ֵ��������͵�distance_*_iterator()������
 */
template <typename Iterator>
int distance(Iterator first,Iterator last)
{
	if(is_random_access_iterator(first))
	{
		return distance_random_access_iterator(first,last);    //��Ҫ������֧��-�����
	}
	else if(is_bidirectional_iterator(first))
	{
		return distance_bidirectional_iterator(first,last);    //��Ҫ������֧��--�����
	}
	else
	{
		return distance_input_iterator(first,last);            //��Ҫ������֧��++�����
	}
}
#else  //_ERROR_
#ifndef _CHANGE_WAY_
//C++17��constexpr if����ṩ�˱���ʱ���Ե���д������ģ����Ը���ֱ�ۣ������ģ�����Ŀɶ��ԡ�
template <typename Iterator>
int distance(Iterator first,Iterator last)
{
	typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
	
	if constexpr(is_same<iterator_category,std::random_access_iterator_tag>::value)
	{
		return distance_random_access_iterator(first,last);
	}
	else if constexpr(is_same<iterator_category,std::bidirectional_iterator_tag>::value)
	{
		return distance_bidirectional_iterator(first,last);
	}
	else
	{
		return distance_input_iterator(first,last);
	}
}
#else  //_CHANGE_WAY_
/*distance()�㷨��������ȡ��iterator_traitsҪiterator_category����Ϣ�����iterator���ṩ����ʹ��iterator���
 *iterator_category�����iterator�����ṩ����ʹ��iterator_traits���iterator_category���õ�iterator_category��
 *�Ϳ����ڱ���׶�ȷ��������һ��__distance()�����ˡ��ڱ���׶ξͿ���ȷ�����������н׶�ȷ�������ĸ�__distance()
 *������Ч��Ҫ�ߡ�
 */
template <typename Iterator>
int distance(Iterator first,Iterator last)
{
	return ::__distance(first,last,iterator_category(first));
}
#endif  //_CHANGE_WAY_
#endif  //_ERROR_

auto main(int argc,char* argv[]) -> int
{
	UNUSED(argc);
	UNUSED(argv);
	
	//ԭʼָ������������ʵ�����
	int seq[] = {0,1,2,3,4,5,6,7,8,9};
	int *p = seq;
	int num = ::distance(p,p + sizeof(seq)/sizeof(int));
	cout<<"raw pointer: num ="<<num<<endl;

#ifndef _ERROR_
	//����ǰ�������
	forward_list<double> forwardList = {3.14,2.718,0.618,1.414,9.78};
	forward_list<double>::iterator forward_iter = forwardList.begin();
	
	for(int i=0;i<2;i++,forward_iter++);
	num = ::distance(forward_iter,forwardList.end());
	cout<<"*forward_iter ="<<*forward_iter<<" ,num ="<<num<<endl;
	
	//����˫�������
	list<int> myList = {20,21,22,23,24,25,26,27,28,29};
	list<int>::iterator bidirectional_iter = myList.end();
	
	for(int i=0;i<3;i++,bidirectional_iter--);
	num = ::distance(myList.begin(),bidirectional_iter);
	cout<<"*bidirectional_iter ="<<*bidirectional_iter<<" ,num ="<<num<<endl;
#endif

	//����������ʵ�����
	array<char,5> arr = {'a','b','c','d','e'};
	array<char,5>::iterator random_access_iter = arr.begin();
	
	num = ::distance(random_access_iter,random_access_iter + 3);
	cout<<"*random_access_iter ="<<*random_access_iter<<" ,num ="<<num<<endl;
	
	return 0;
}
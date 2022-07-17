/*type_traits������ȡԪ�����͵����ԡ����Ԫ�ؾ���ĳ�����ʣ������ǵ���ĳ��������
 *���������ĳ�����ʣ��������һ�������������������C++ģ���̺ͱ������Ĳ���
 *�Ƶ����ܣ�������ֻ����������Ͳ����Ż���в����Ƶ�����STL�д���������traits
 *��̼��ɣ�ͨ��ģ���ػ������������ñ�����ѡ����ȷ�Ĵ���ʽ���ڱ����ھ������
 *�����ַ�����������������ԡ�
 */

/*1.traits����������ԭ��
 *��1������C++��ģ�弼��Ϊ���ͱ���ṩ��֧�֣����Ա�д����ͨ�õĴ��롣����ģ���������
 *     �Ĳ�ͬ�����������һЩ���⣬��ʱ��traits����һ�ֺܺõĽ��������
 *��2����Ϊģ����������Ͳ�ͬ�����ܻ�Ӱ�쵽ģ���о�����㷨ʵ�֣���ô���Ǿ���Ҫ����Щ
 *     ��ģ��������ķ�����ģ������ȡ�������Ӷ���֤�㷨��һ�²��ܲ������Ͳ�ͬ��Ӱ�졣
 *     ��traitsģ�弴�ǰ���ģ��������ķ�������װ�����ˡ�
 */

/*2.traits������ȡ������
 *��1��C++��traits������һ��Լ���׳Ƶļ�������������Ϊͬһ�����ݣ������Զ������ͺ��������ͣ�
 *     �ṩͳһ�Ĳ���������
 *��2��traits�����Ĺؼ����ڣ�ʹ�������ģ����type_traits�����治ͬ�������͵�type�������Ϳ���
 *     �����Զ����������ͺ������������͡�
 *��3��traits������ȡ�����ı����Ǽ���һ�����ԣ�����һ��������ԡ�
 */

/*3.iterator_traits��������ȡ��Դ�룺
 *  template<typename Iterator>
 *  struct iterator_traits         //ʹ��iterator�ṩ����Ϣ
 *  {
 *    typedef typename Iterator::iterator_category iterator_category;
 *    typedef typename Iterator::value_type        value_typep;
 *    typedef typename Iterator::difference_type   difference_type;
 *    typedef typename Iterator::pointer           pointer;
 *    typedef typename Iterator::reference         reference;
 *  };
 *  
 *  template<typename T>
 *  struct iterator_traits<T*>           //�����޷�ʹ��iterator����Ϣ������traits�Լ��ṩ�ˡ����ԭ��ָ�����Ƶ�"ƫ�ػ���"
 *  {
 *    typedef random_access_iterator_tag iterator_category;
 *    typedef T                          value_type;
 *    typedef ptrdiff_t                  difference_type;
 *    typedef T*                         pointer;
 *    typedef T&                         reference;
 *  };
 *    
 *  template<typename T>
 *  struct iterator_traits<const T*>     //�����޷�ʹ��iterator����Ϣ������traits�Լ��ṩ�ˡ����ԭ����pointer-to-const����Ƶ�"ƫ�ػ�"
 *  {
 *    typedef random_access_iterator_tag iterator_category;
 *    typedef T                          value_type;          //ע�����ﲻ��const T�������const T���㷨�õ�������ͣ��ø����Ͷ��������ȴ�޷��ı���ֵ���Ǿ�û�������ˣ�������T��
 *    typedef ptrdiff_t                  difference_type;
 *    typedef const T*                   pointer;
 *    typedef const T&                   reference;
 *  };
 */

/*4.STL��������5�ֱ�ǩtag��
 *��1��struct input_iterator_tag {};
 *��2��struct output_iterator_tag {};
 *��3��struct forward_iterator_tag : public input_iterator_tag {};
 *��4��struct bidirectional_iterator_tag : public forward_iterator_tag {};
 *��5��struct random_access_iterator_tag : public bidirectional_iterator_tag {};
 *
 *��6��ʹ�ü̳еĺô��ǣ���������Ҫ��input_iterator_tag��ʱ�򣬼����㴫��һ��forward_iterator_tag��
 *     �����ؼ̳������ң�֪������������
 */

#include <cassert>
#include <iostream>
#include <forward_list>
#include <list>
#include <vector>
#include <iterator>

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#define _ERROR_
#undef _ERROR_

#define _DEBUG_
#undef _DEBUG_

#ifdef _DEBUG_
#define Debug(str) std::cout<<"["<<__TIME__<<" "<<__FILE__<<"] "<<__func__<<" (line:"<<__LINE__<<") -- "<<(str)<<std::endl;
#else
#define Debug(str) (void)0
#endif

#define UNUSED(x) (void)x;

using std::forward_list;
using std::list;
using std::vector;

using std::input_iterator_tag;
using std::bidirectional_iterator_tag;
using std::random_access_iterator_tag;

using std::cout;
using std::endl;

template <typename Iterator>
struct Is_RandomAccessIterator
{
	static const bool value = false; 
};

template <>
struct Is_RandomAccessIterator<std::random_access_iterator_tag>
{
	static const bool value = true; 
};

//ʹ��C++14�еı���ģ���Ԫ�����ĵ���
template <typename Iterator>
constexpr bool isRandomAccessIterator = Is_RandomAccessIterator<Iterator>::value;

template <typename Iterator>
struct Is_BidirectionalIterator
{
	enum{value = false};
};

template <>
struct Is_BidirectionalIterator<std::bidirectional_iterator_tag>
{
	enum{value = true};
};

//ʹ��C++14�еı���ģ���Ԫ�����ĵ���
template <typename Iterator>
constexpr bool isBidirectionalIterator = Is_BidirectionalIterator<Iterator>::value;

/*using��typedef����C++�ı������﷨�������ڴ������������ִ�С����Կ��������ӵ�ȫ��������
 *���ֿռ䡢�����塢�ࡢ�ṹ���������Ĵ�����С�
 */
template <typename Iterator>
bool is_random_access_iterator(Iterator iter)
{
	using std::iterator_traits;
	typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
	return Is_RandomAccessIterator<iterator_category>::value;
}

template <typename Iterator>
bool is_bidirectional_iterator(Iterator iter)
{
	using std::iterator_traits;
	typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
	return Is_BidirectionalIterator<iterator_category>::value;	
}

template <typename InputIterator,typename Distance>
void advance_input_iterator(InputIterator& iter,Distance n)
{
	Debug("input iterator");
	
	assert(n >= 0);
	for(int i=0;i<n;++i,++iter);
}

template <typename BidirectionalIterator,typename Distance>
void advance_bidirectional_iterator(BidirectionalIterator& iter,Distance n)
{
	Debug("bidirectional iterator");
	
	if(n >= 0)
	{
		while(n-->0) ++iter;
	}
	else
	{
		for(int i=n;i<0;++i) --iter;
	}
}

template <typename RandomAccessIterator,typename Distance>
void advance_random_access_iterator(RandomAccessIterator& iter,Distance n)
{
	Debug("random access iterator");
	
	iter += n;
}

/*__advance()�еĵ�3�����������Ǽ������ء������ǻ���Ҫһ���ṩ�ϲ�ͳһ�Ľӿ�advance()��
 *����һ����ͨ��traits���ƣ��������������Ƶ�������
 */
template <typename InputIterator,typename Distance>
void __advance(InputIterator& iter,Distance n,input_iterator_tag)
{
	Debug("input iterator");
	
	assert(n >= 0);
	for(int i=0;i<n;++i,++iter);
}

template <typename BidirectionalIterator,typename Distance>
void __advance(BidirectionalIterator& iter,Distance n,bidirectional_iterator_tag)
{
	Debug("bidirectional iterator");
	
	if(n >= 0)
	{
		while(n-->0) ++iter;
	}
	else
	{
		for(int i=n;i<0;++i) --iter;
	}
}

template <typename RandomAccessIterator,typename Distance>
void __advance(RandomAccessIterator& iter,Distance n,random_access_iterator_tag)
{
	Debug("random access iterator");
	
	iter += n;
}

#ifdef _ERROR_
/*��1��ģ�庯����ʵ�������ڱ����ڽ��еģ���if-else������������ڵ������жϣ����Բ������ڱ����ڵı����֧ѡ��
 *     ��������ʵ����advance()ģ�庯��ʱ���Ὣ���е�������֧����������б��롣����ֻ�д���ĵ���������iter��
 *     ͬʱ֧��++��--��+=��-=����������ܱ���ͨ������Ϊ������ʵ�����֧������������������������ǰ���������
 *     ˫������������в�������֧���������ĵ�����������ֻ�д���������ʵ�����ʱ��advance()�����Ų�����뱨��
 *��2��������advance()ʱ��Ҫ��һ��if-else�жϣ�������ִ��ʱ�ڲž���ʹ����һ���汾�ĵ������ƶ���������Ӱ�����Ч�ʡ�
 *     ����ܹ��ڱ����ھ�ѡ����ȷ�İ汾������__advance()�������ƿ��Դ�����Ŀ�ꡣ
 */
template <typename Iterator,typename Distance>
void advance(Iterator& iter,Distance n)
{
	if(is_random_access_iterator(iter))
	{
		advance_random_access_iterator(iter,n);     //��Ҫ������֧��+=��-=�����
	}
	else if(is_bidirectional_iterator(iter))
	{
		advance_bidirectional_iterator(iter,n);     //��Ҫ������֧��++��--�����
	}
	else
	{
		advance_input_iterator(iter,n);             //ֻ����Ҫ������֧��++���������
	}
}
#else  //_ERROR_
#ifndef _CHANGE_WAY_
/*��1��advanced()������������ʹ��������ǰ�ƶ�n������advance()�����У�ͨ���жϲ�ͬ������������
 *     ���ò�ͬ�ĺ������Դﵽ����Ч�ʡ�
 *��2���жϳ�������ͬ���͵�2�ַ�����
 *  �� ��һ�ַ����Ƕ�̬���������ڲ�ȷ��δ��ɱ�̫�ߣ�ͬʱ���Ҽ̳ж�̬Ҳ�ǰ����⸴�ӻ���
 *  �� �ڶ��־��Ǻ������أ����ǿ������ȱ�ǲ�ͬ���������ͣ���������Ϊ��3����������__advance()��
 */
template <typename Iterator,typename Distance>
void advance(Iterator& iter,Distance n)
{
	using std::iterator_traits;
	typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
	
	if constexpr(isRandomAccessIterator<iterator_category>)  //C++17��constexpr if�ṩ�˱���ʱ���Ե���д������ģ����Ը���ֱ�ۣ������ģ�����Ŀɶ��ԡ�
	{
		advance_random_access_iterator(iter,n);
	}
	else if constexpr(isBidirectionalIterator<iterator_category>)
	{
		advance_bidirectional_iterator(iter,n);
	}
	else
	{
		static_assert(!isRandomAccessIterator<iterator_category>,"iter is random access iterator");
		static_assert(!isBidirectionalIterator<iterator_category>,"iter is bidirectional iterator");
		
		advance_input_iterator(iter,n);
	}
}
#else
/*��1����Ϊgcc�ı�׼����Ҳ������ͬ����__advance()������Ϊ�˱��⺯�����õ����壬�ڵ����Զ���
 *     ��__advance()��������Ҫ�ӡ�::��ȫ�������������gcc�������н���׼��˽�е�__advance()����
 *     ��¶�˳�������msvc�������ı�׼������û�С�
 *��2������__advance()�������ƿ���ʵ�ֱ����ڵĺ���ѡ�񡣸������������͵ľ�������ʵ���Ѿ�д�ã�
 *     ������Ҫһ��ͳһ��advance()�ӿڣ���ʱ��traits�Ϳ��Գ����ˡ�traits����Բ�ͬ��������ʱ��
 *     ���ҵ����ʵķ������͡��������Ͷ�Ӧ�в�ͬ�ĺ�������ʱ������һ����ȡ����Ȼ����������á�
 */
template <typename Iterator,typename Distance>
void advance(Iterator& iter,Distance n)
{
	typedef typename std::iterator_traits<Iterator>::iterator_category category;
	::__advance(iter,n,category());    //���ø����͵�__advance()�������ء�gcc��������Ҳ���Ը�Ϊstd::__advance()���Ӷ�����Ϊ���ñ�׼�����ͬ��������
}
#endif  //_CHANGE_WAY_
#endif  //_ERROR_

auto main(int argc,char* argv[]) -> int
{
	UNUSED(argc);
	UNUSED(argv);

	//����ǰ�������
	forward_list<int> forwardList = {0,1,2,3,4,5,6,7,8,9};
	forward_list<int>::iterator forward_iter = forwardList.begin();
	::advance(forward_iter,5);
	cout<<"*forward_iter ="<<*forward_iter<<endl;
	
	::advance(forward_iter,2);
	cout<<"*forward_iter ="<<*forward_iter<<endl;
	
	//����˫�������
	list<double> myList = {3.14,2.718,0.618,1.414,9.78};
	list<double>::iterator bidirectional_iter = myList.begin();
	::advance(bidirectional_iter,4);
	cout<<"*bidirectional_iter ="<<*bidirectional_iter<<endl;
	
	::advance(bidirectional_iter,-2);
	cout<<"*bidirectional_iter ="<<*bidirectional_iter<<endl;
	
	//����������ʵ�����
	vector<char> vec = {'a','b','c','d','e'};
	vector<char>::iterator random_access_iter = vec.begin();
	::advance(random_access_iter,3);
	cout<<"*random_access_iter ="<<*random_access_iter<<endl;
	
	::advance(random_access_iter,2);
	cout<<"*random_access_iter ="<<*random_access_iter<<endl;
	
	//ԭʼָ��Ҳ����������ʵ�����
	int arr[] = {20,21,22,23,24,25,26,27,28,29};
	int *ptr = arr;
	::advance(ptr,5);
	cout<<"arr[5] ="<<*ptr<<endl;
	
	::advance(ptr,-2);
	cout<<"arr[3] ="<<*ptr<<endl;
	
	return 0;
}
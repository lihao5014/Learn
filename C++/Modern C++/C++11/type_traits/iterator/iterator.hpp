/*1.ptrdiff_t�Ķ��壺
 *��1��ptrdiff_t������stddef.h��cstddef������ļ��ڡ�ptrdiff_tͨ��������Ϊlong int���͡�
 *     ptrdiff_t������C99��׼�С�
 *��2��ptrdiff_t��C/C++��׼���ж����һ���������ص��������͡�ptrdiff_t���ͱ���ͨ������
 *     ��������ָ����������Ľ����
 */

/*2.ptrdiff_t��size_t������
 *��1����׼������ptrdiff_t��size_t����һ����ptrdiff_tҲ��һ���������ص����ͣ���cstddefͷ�ļ��ж��塣
 *��2��size_t��unsigned����,��ptrdiff_t����signed���͡�
 *��3��size_t��������ָ�����鳤�ȣ���������һ��������ptrdiff_t������Ӧ��֤���Դ��ͬһ����������ָ��
 *     ֮��Ĳ�࣬���п����Ǹ�����
 */

/*1.std::iterator����������ģ�壺
 *��1��STL������std::iterator������ģ�壬���������������Լ��ĵ��������а���Ҫ������ͱ�����iterator��һ��
 *     �ṹ��ģ�壬��������5��������iterator_traitsģ������ͱ�����
 *��2��std::iteratorģ�嶨����STL�Ե�������Ҫ���ȫ�����͡������һ��δ֪���͵ĵ�����ģ�����MyIterator��
 *     ����Ҫ����һ��ָ�룬��ָ��һ��������������ʱ�ṩ�����ͣ���ʱ���ǿ���д��MyIterator::pointer��������
 *     iterator_category��ֵ�ض���5��tag��ǩ���е�һ����
 *��3��������һ����ʾ����������ʱ������ʹ����std::iteratorΪ�������ɵ�ʵ�����������������Ҫ�����ͱ�����
 *     ע����ҪΪ����������STLҪ���ȫ�����͡�ģ��ĵ�1������ָ������Ϊ��ȫ������ʵ������ĵ��������͡�
 *     ��2�������ǵ�������ָ���������͡�����3��������Ĭ��ֵ����˵�3�������������������������Ͳ�ͬ��
 *     ��ptrdiff_t����4��������һ��ָ������ָ�����͡����һ��ģ�����ָ�������õ����͡��������������
 *     �����κ��£���Ȼ��Ҫ�������ȫ����Ա��
 */

/*2.STL��������Ա������Ҫ��
 *��1��STL������һ����Ҫ����������֧�ֲ����������������ĳ�Ա���������е������඼��Ҫ�ṩ�ĳ�Ա������
 *     Ĭ�Ϲ��캯���������������������캯���Լ���ֵ�������
 *��2������������ʵ������࣬STL��Ҫһ���׵Ĺ�ϵ�����������ͨ��ʹ��<utility>��׼��ͷ�ļ��еĺ���ģ��
 *     ����ɹ�ϵ������Ķ��塣
 *��3��������������������������������ÿ�ֵ��������ṩ���ض�������������Ϊ���������ۼ����ԣ��������
 *     ����������֧��ȫ��������
 */
 
#ifndef _ITERATOR_HPP_
#define _ITERATOR_HPP_

#include <cassert>
#include <cstddef>
#include "iterator_traits.hpp"

namespace Learn {

template <typename Category,
		  typename T,
		  typename Distance = ptrdiff_t,
		  typename Pointer = T*,
		  typename Reference = T&>
struct iterator
{
	typedef Category iterator_category;
	typedef T value_type;
	typedef Distance difference_type;
	typedef Pointer pointer;
	typedef Reference reference;
};

template <class InputIterator, class Distance>
void __advance(InputIterator& iter,Distance n,input_iterator_tag)
{
	assert(n >= 0);
	for(int i=0;i<n;++i,++iter);
}

template <typename BidirectionalIterator,typename Distance>
void __advance(BidirectionalIterator& iter,Distance n,bidirectional_iterator_tag)
{
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
	iter += n;
}

template <class InputIterator, class Distance>
void advance(InputIterator& iter,Distance n)
{
	typedef typename iterator_traits<InputIterator>::iterator_category category;
	__advance(iter,n,category());
}

template <typename InputIterator>
int __distance(InputIterator first,InputIterator last,input_iterator_tag)
{
	int result = 0;
	while(first != last)
	{
		first++;
		result++;
	}
	return result;
}

template <typename BidirectionalIterator>
int __distance(BidirectionalIterator first,BidirectionalIterator last,bidirectional_iterator_tag)
{
	int result = 0;
	for(;last-- != first;++result);
	return result;
}

template <typename RandomAccessIterator>
int __distance(RandomAccessIterator first,RandomAccessIterator last,random_access_iterator_tag)
{
	return last - first;
}

template <typename Iterator>
int distance(Iterator first,Iterator last)
{
	typedef typename iterator_traits<Iterator>::iterator_category category;
	return __distance(first,last,category());
}

}   // namespace Learn

#endif  //_ITERATOR_HPP_
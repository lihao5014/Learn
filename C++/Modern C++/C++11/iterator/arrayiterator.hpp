/*1.�����������ã�
 *�����������κ��Զ���������ж���һ��ǿ��ĸ��ӹ��ߡ����������ǽ��㷨���õ���
 *�Զ�����Ԫ�ص������ϡ����ܻ����һ�����Σ�û�п�������������Ҫ�ı�׼STL������
 *��ʱ�����Ҫ����һ���Լ������������ǵ������������Ҫ��������ͨ���������ʲô
 *�����ࣨ�����˵����������ܱ�STL�����ܣ������������˽⵽STL�ڲ�������Щʲô��
 */

/*2.STL��������Ҫ��
 *��1��STL�Զ����˵���������������һЩ�ض���Ҫ������Ϊ�˱�֤���н������ֵ��������㷨
 *     �����������������㷨����Ҫ֪����Ҳ���ں����������Ԫ�����Ժ���������������������
 *     ����������Ϊ�����ĵ����������ԡ���ͬ���㷨Ҫ��ͬ���ܵĵ�������STL����5���������
 *     ����������������������ǰ���������˫���������������ʵ��������������ǿ�������Ҫ
 *     �ͼ���������ĵط�ʹ�ø߼����������
 *��2�������㷨��ģ����Ҫ�����ɴ�������������������֤������ĵ������Ĺ����Ƿ��㹻��
 *     ֪�������������������Ϊ�㷨��Ӧ���ṩǱ�ڵ����ƣ����Գ�������κ����ٵĶ��⹦��
 *     ���㷨���Ӹ�Ч��
 *��3��һ����˵�������ñ�׼�ķ�ʽȷ�ϵ������Ĺ��ܡ���ͬ���ĵ�������ζ����ҪΪ��������
 *     ���岻ͬ�ĳ�Ա������������֪�������������й��ܵ����ԣ��⵱ȻҲ�ᷴӳ��ÿ�����
 *     �ĳ�Ա�������ϡ�
 *��4�������Ҫ�����Լ������ĵ�����������ͨ������������STL���㷨�����Ļ������ȼ̳�iteroter��
 *     Ȼ��ʵ�ֱ�Ҫ�Ĳ��������ɡ�����������㷨�����Ե�������������Ҫ��ģ������Ҫ�Լ����ա�
 */

/*3.ʹ��STL���������ڵ����⣺
 *��1������һ���������е������ĺ���ģ������һ�����⣬���ǲ�������֪���ں���ģ����Ҫ�õ�
 *     ��Щ���͵ĵ���������Ϊ��ͬ������֧�ֵ����������ͬ��
 *��2������ģ�����Ϊ����������ʱ������ں���������Ҫ����һ����������ָ��������͵���ʱ������
 *     ��ʹ����֪��������ָ��ֵ������ȴ�޼ƿ�ʩ����Ϊֱ��ģ������ʵ��ʱ������ȷ����������͡�
 *     �ڲ�֪�����������ʱ�������޷����������ʱ��������C++11�п���ʹ��auto/decltype�ؼ���
 *     �����Զ������Ƶ���
 */

#ifndef _ARRAY_ITERATOR_HPP_
#define _ARRAY_ITERATOR_HPP_

#ifndef _ARRAY_PRIVATE_HEADER_
	#error "arrayiterator.h can only be included by array.h"
#endif

#include <iterator>

namespace Study {

template <typename T,int N>
class Array;

/*������ʵ�����֧������������������������ǰ���������˫������������в�����
 *��֧���������ĵ�������
 */
template <typename U>
class ArrayIterator:public std::iterator<std::random_access_iterator_tag,U>
{
	template <typename T,int N>
	friend class Array;
	
	/*��Ϊ�Զ����ģ��������̳�std::iterator����������ʱ������������Ϊ���̳���std::iterator
	 *�����������һ��������std::iterator<std::random_access_iterator_tag,U>�����������汾��
	 *������ʹ��typedef�����5�����ͱ����������Զ����ģ��������̳в���value_type��pointer��
	 *reference��difference_type��iterator_category��5���Զ������͡��������ԭ��C++17���Ѿ�
	 *������<iterator>ͷ�ļ���
	 */
	// using base = std::iterator<std::random_access_iterator_tag, U>;
	// using typename base::iterator_category;
	// using typename base::value_type;
	// using typename base::difference_type;
    // using typename base::pointer;
    // using typename base::reference;
public:
	/*****�������͵ĵ�������֧������4�ֲ���*****/
	ArrayIterator(const ArrayIterator& other);
	ArrayIterator& operator =(const ArrayIterator& other);
	
	ArrayIterator& operator ++();              //����ǰ׺�����������++a��
	ArrayIterator operator ++(int);     //���غ�׺�����������a++��
	
	/*****������������в�����ֻ�������������֧������2�ֲ���*****/
	bool operator ==(const ArrayIterator& other)const;
	bool operator !=(const ArrayIterator& other)const;
	
	/*****����2�ֲ��������������������������еĶ��岻��ͬ*****/
	U& operator *()const;         //����������ж���Ϊ: const U& operator *()const;
	U* operator ->()const;        //����������ж���Ϊ: const U* operator ->()const;
	
	/*****˫����������в�����ֻ������������������������ǰ���������֧������3�ֲ���*****/
	ArrayIterator& operator --();              //����ǰ׺�����������++a��
	ArrayIterator operator --(int);   
	
	/*****������������в���������������������������ǰ���������˫�����������֧�����²���*****/
	bool operator <(const ArrayIterator& other)const;
	bool operator >(const ArrayIterator& other)const;
	
	bool operator <=(const ArrayIterator& other)const;
	bool operator >=(const ArrayIterator& other)const;
	
	ArrayIterator& operator +=(int n);
	ArrayIterator& operator -=(int n);

	U& operator [](int index)const;
	
	/*��1���Լ̳���std::iterator�ĵ���������ģ�廯ʱ����Ϊ�����������ų��������ṩstd::iterator�����⻯��
	 *     ���Ա���������Ϊ�����ڶԼ̳е�std::iteratorģ���������������difference_type�������������Ͷ��壬
	 *     ������ģ�嶨��ʱ������������Զ���ܽ���Ϊtypedef��
	 *��2��ʹ��typename ArrayIterator<U>::difference_type�������ָʾdifference_type�ǳ�Ա���͡�
	 *��3����Ȼÿ�ζ�����ʹ��typename��ʽ�޶����ǣ�����������������������һ�Σ�����ArrayIterator���������
	 *     ������������������
	 *     using base = std::iterator<std::random_access_iterator_tag, U>;
	 *     using typename base::iterator_category;
	 *     using typename base::value_type;
     *     using typename base::pointer;
     *     using typename base::reference;
     *     using typename base::difference_type;
	 */
	typename ArrayIterator<U>::difference_type operator -(const ArrayIterator<U>& iter)const;
	
	template <typename T>
	friend ArrayIterator<T> operator +(const ArrayIterator<T>& iter,int n);
	
	template <typename T>
	friend ArrayIterator<T> operator +(int n,const ArrayIterator<T>& iter);
	
	template <typename T>
	friend ArrayIterator<T> operator -(const ArrayIterator<T>& iter,int n);
	
private:
	ArrayIterator(U* p);    //������ʽ�Ĺ���ArrayIterator��������ֻ��ͨ��Array��Ԫ��򿽱����캯��������ArrayIterator��������
	
	U* m_ptr;   //ʵ�ʵ�����ָ�룬ͨ����ָ�����������
};

template <typename U>
ArrayIterator<U>::ArrayIterator(U* p)
	:m_ptr(p)
{
	
}

template <typename U>
ArrayIterator<U>::ArrayIterator(const ArrayIterator<U>& other)
	:m_ptr(other.m_ptr)
{
	
}

template <typename U>
ArrayIterator<U>& ArrayIterator<U>::operator =(const ArrayIterator<U>& other)
{
	m_ptr = other.m_ptr;
	return *this;
}

template <typename U>
ArrayIterator<U>& ArrayIterator<U>::operator ++()
{
	m_ptr++;
	return *this;
}

template <typename U>
ArrayIterator<U> ArrayIterator<U>::operator ++(int)
{
	ArrayIterator<U> temp = *this;
	
	m_ptr++;
	return temp;
}

template <typename U>
bool ArrayIterator<U>::operator ==(const ArrayIterator<U>& other)const
{
	return m_ptr == other.m_ptr;
}

template <typename U>
bool ArrayIterator<U>::operator !=(const ArrayIterator<U>& other)const
{
	return m_ptr != other.m_ptr;
}

template <typename U>
U& ArrayIterator<U>::operator *()const
{
	return *m_ptr;
}

template <typename U>
U* ArrayIterator<U>::operator ->()const
{
	return m_ptr;
}

template <typename U>
ArrayIterator<U>& ArrayIterator<U>::operator --()
{
	m_ptr--;
	return *this;
}

template <typename U>
ArrayIterator<U> ArrayIterator<U>::operator --(int)
{
	ArrayIterator<U> temp(m_ptr);
	
	m_ptr--;
	return temp;
}

template <typename U>
bool ArrayIterator<U>::operator <(const ArrayIterator<U>& other)const
{
	return m_ptr < other.m_ptr;
}

template <typename U>
bool ArrayIterator<U>::operator >(const ArrayIterator<U>& other)const
{
	return m_ptr > other.m_ptr;
}

template <typename U>
bool ArrayIterator<U>::operator <=(const ArrayIterator<U>& other)const
{
	return m_ptr <= other.m_ptr;
}

template <typename U>
bool ArrayIterator<U>::operator >=(const ArrayIterator<U>& other)const
{
	return m_ptr >= other.m_ptr;
}

template <typename U>
ArrayIterator<U>& ArrayIterator<U>::operator +=(int n)
{
	m_ptr += n;
	return *this;
}

template <typename U>
ArrayIterator<U>& ArrayIterator<U>::operator -=(int n)
{
	m_ptr -= n;
	return *this;	
}

template <typename U>
U& ArrayIterator<U>::operator [](int index)const
{
	return m_ptr[index];
}

template <typename T>
typename ArrayIterator<T>::difference_type ArrayIterator<T>::operator -(const ArrayIterator<T>& iter)const
{
	return m_ptr - iter.m_ptr;
}

template <typename T>
ArrayIterator<T> operator +(const ArrayIterator<T>& iter,int n)
{
	ArrayIterator<T> temp = iter;
	
	temp.m_ptr += n;
	return temp;
}

template <typename T>
ArrayIterator<T> operator +(int n,const ArrayIterator<T>& iter)
{
	return iter + n;
}

template <typename T>
ArrayIterator<T> operator -(const ArrayIterator<T>& iter,int n)
{
	ArrayIterator<T> temp= iter;
	
	temp.m_ptr -= n;
	return temp;	
}

}  //namespace Study

#endif  //_ARRAY_ITERATOR_HPP_
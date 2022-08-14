#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include <cassert>
#include <initializer_list>
#include "iterator.hpp"

namespace Learn {

template <typename T,int N>
class Array
{
public:
	//����ʹ��typedef��using�������ͱ����ķ�ʽ��������ģ�������ģ�������
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef ptrdiff_t difference_type;
	
	//����ʹ��enum��const��constexpr��������ڳ����ķ�ʽ��������ģ���ֵģ�������
	enum{SIZE = N};
	
	typedef T* iterator;               //���Զ���ĵ�������Ϊ�������ͣ��������͵�������ͬһ�����֣�����д����ͨ�õĴ��롣
	typedef const T* const_iterator;   //std::array����ĵ�����������ԭʼָ�롣
	
	Array(const T& init = 0):m_arr{0}
	{
		static_assert(N > 0,"Array() error: array size is less than zero!");
		
		for(int i=0;i<N;++i)
		{
			m_arr[i] = init;
		}
	}
	
	/*for(int index=0,auto iter = ls.begin();iter != ls.end();++iter,index++)���÷���
	 *��Ϊforѭ���ĳ�ʼ������У�ֻ�ܶ��岢��ʼ�����ͬ���͵�ѭ�����������ܶ�����
	 *��ͬ���͵�ѭ��������
	 */
	Array(const std::initializer_list<T>& ls):m_arr{0}
	{
		assert(ls.size() <= N);
		
		int index = 0;
		for(auto iter = ls.begin();iter != ls.end();++iter)
		{
			m_arr[index++] = *iter;
		}
	}
	
	Array(const Array& other):m_arr{0}
	{
		for(int i=0;i<N;++i)
		{
			m_arr[i] = other.m_arr[i];
		}
	}
	
	iterator begin(){return iterator(m_arr);}
	iterator end(){return iterator(m_arr + N);}
	
	const_iterator cbegin(){return const_iterator(m_arr);}
	const_iterator cend(){return const_iterator(m_arr + N);}
	
	bool empty()const {return N == 0;}
	int size()const {return N;}
	
	const T& at(int index)const
	{
		assert(0 <= index && index < SIZE);
		return m_arr[index];
	}
	
	Array& operator =(const Array& other)
	{
		for(int i=0;i<N;++i)
		{
			m_arr[i] = other.m_arr[i];
		}
		
		return *this;
	}
	
	bool operator ==(const Array& other)
	{
		for(int i=0;i<N;++i)
		{
			if(m_arr[i] != other.m_arr[i])
			{
				return false;
			}
		}
		
		return true;
	}
	
	bool operator !=(const Array& other){return !(*this == other);}
	
	T& operator [](int index)
	{
		assert(0 <= index && index < SIZE);
		return m_arr[index];
	}
private:
	T m_arr[N];
};
	
}  // namespace Learn

#endif  //_ARRAY_HPP_
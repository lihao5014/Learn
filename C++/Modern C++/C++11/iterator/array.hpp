#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

#include <assert.h>
#include <initializer_list>

#define _ARRAY_PRIVATE_HEADER_
#include "arrayiterator.hpp"

namespace Study {

template <typename T,int N = 10>
class Array
{
public:
	typedef T data_type;     //可以使用typedef或using定义类型别名的方式，来保存模板的类型模板参数。
	enum{SIZE = N};          //可以使用enum、const或constexpr定义编译期常量的方式，来保存模板的值模板参数。
	
	typedef ArrayIterator<T> iterator;       //将自定义的迭代器作为内置类型，所有类型迭代器用同一个名字，便于写出更通用的代码。
	typedef ArrayIterator<const T> const_iterator;
	
	Array(const data_type& init = 0);
	Array(const std::initializer_list<T>& ls);
	Array(const Array& other);
	
	iterator begin();
	iterator end();
	
	const_iterator cbegin();
	const_iterator cend();
	
	bool empty()const;
	int size()const;
	
	void fill(const T& val);
	const T& at(int index)const;
	
	data_type& front();
	const T& front()const;
	
	data_type& back();
	const T& back()const;
	
	Array& operator =(const Array& other);
	bool operator ==(const Array& other);
	
	T& operator [](int index);
private:
	T m_arr[N];
};

template <typename T,int N>
Array<T,N>::Array(const typename Array<T,N>::data_type& init)
	:m_arr{0}
{
	for(int i=0;i<SIZE;++i)
	{
		m_arr[i] = init;
	}
}

template <typename T,int N>
Array<T,N>::Array(const std::initializer_list<T>& ls)
{
	if(ls.size() > N)
	{
		throw "Array constructor error: initializer list is too long!";
	}
	
	auto iter = ls.begin();
	for(int i=0;iter != ls.end();iter++,i++)
	{
		m_arr[i] = *iter;
	}
}

template <typename T,int N>
Array<T,N>::Array(const Array<T,N>& other)
{
	for(int i=0;i<N;++i)
	{
		m_arr[i] = other.m_arr[i];
	}
}

template <typename T,int N>
typename Array<T,N>::iterator Array<T,N>::begin()
{
	return iterator(m_arr);
}

template <typename T,int N>
typename Array<T,N>::iterator Array<T,N>::end()
{
	return iterator(m_arr + sizeof(m_arr)/sizeof(m_arr[0]));
}

template <typename T,int N>
typename Array<T,N>::const_iterator Array<T,N>::cbegin()
{
	return const_iterator(m_arr);
}

template <typename T,int N>
typename Array<T,N>::const_iterator Array<T,N>::cend()
{
	return const_iterator(m_arr + sizeof(m_arr)/sizeof(m_arr[0]));
}

template <typename T,int N>
bool Array<T,N>::empty()const
{
	return N == 0;
}

template <typename T,int N>
int Array<T,N>::size()const
{
	return SIZE;
}

template <typename T,int N>
void Array<T,N>::fill(const T& val)
{
	for(int i=0;i<N;++i)
	{
		m_arr[i] = val;
	}	
}

template <typename T,int N>
const T& Array<T,N>::at(int index)const
{
	assert(0 <= index && index < SIZE);
	return m_arr[index]	;
}

template <typename T,int N>
typename Array<T,N>::data_type& Array<T,N>::front()
{
	return m_arr[0];
}

template <typename T,int N>
const T& Array<T,N>::front()const
{
	return m_arr[0];
}

template <typename T,int N>
typename Array<T,N>::data_type& Array<T,N>::back()
{
	return m_arr[N - 1];
}

template <typename T,int N>
const T& Array<T,N>::back()const
{
	return m_arr[SIZE - 1];
}

template <typename T,int N>
Array<T,N>& Array<T,N>::operator =(const Array<T,N>& other)
{
	for(int i=0;i<SIZE;++i)
	{
		m_arr[i] = other.m_arr[i];
	}	
}

template <typename T,int N>
bool Array<T,N>::operator ==(const Array<T,N>& other)
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

template <typename T,int N>
T& Array<T,N>::operator [](int index)
{
	if(index < 0 || index >= SIZE)
	{
		throw "Array::operator [] error: index is illegal!";
	}
	
	return m_arr[index];
}

}  //namespace Study

#endif  //_ARRAY_HPP_
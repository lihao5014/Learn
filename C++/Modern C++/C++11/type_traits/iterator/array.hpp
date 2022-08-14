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
	//可以使用typedef或using定义类型别名的方式，来保存模板的类型模板参数。
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef ptrdiff_t difference_type;
	
	//可以使用enum、const或constexpr定义编译期常量的方式，来保存模板的值模板参数。
	enum{SIZE = N};
	
	typedef T* iterator;               //将自定义的迭代器作为内置类型，所有类型迭代器用同一个名字，便于写出更通用的代码。
	typedef const T* const_iterator;   //std::array数组的迭代器，就是原始指针。
	
	Array(const T& init = 0):m_arr{0}
	{
		static_assert(N > 0,"Array() error: array size is less than zero!");
		
		for(int i=0;i<N;++i)
		{
			m_arr[i] = init;
		}
	}
	
	/*for(int index=0,auto iter = ls.begin();iter != ls.end();++iter,index++)是用法。
	 *因为for循环的初始化语句中，只能定义并初始化多个同类型的循环变量。不能定义多个
	 *不同类型的循环变量。
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
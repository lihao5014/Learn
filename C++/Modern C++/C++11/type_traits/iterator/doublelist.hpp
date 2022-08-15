#ifndef _DOUBLE_LIST_HPP_
#define _DOUBLE_LIST_HPP_

#include <cassert>
#include <initializer_list>
#include "iterator.hpp"

namespace Learn {

template <typename T>
struct DoubleListNode
{
	DoubleListNode* m_pPrev;
	T m_data;
	DoubleListNode* m_pNext;
	
	DoubleListNode():m_data(0),m_pPrev(nullptr),m_pNext(nullptr){}
	explicit DoubleListNode(const T& val):m_data(val),m_pPrev(nullptr),m_pNext(nullptr){}
	DoubleListNode(const T& val,DoubleListNode* pPrev,DoubleListNode* pNext):m_data(val),m_pPrev(pPrev),m_pNext(pNext){}
};

template <typename T>
class DoubleListIterator:public iterator<bidirectional_iterator_tag,T>
{
public:
	using base = iterator<bidirectional_iterator_tag,T>;
	using typename base::iterator_category;
	using typename base::value_type;
	using typename base::difference_type;
    using typename base::pointer;
    using typename base::reference;
	
	explicit DoubleListIterator(DoubleListNode<T>* pNode):m_pNode(pNode){}
	DoubleListIterator(const DoubleListIterator& other):m_pNode(other.m_pNode){}
	
	DoubleListIterator& operator =(const DoubleListIterator& other)
	{
		m_pNode = other.m_pNode;
		return *this;
	}
	
	DoubleListIterator& operator ++()
	{
		m_pNode = m_pNode->m_pNext;
		return *this;
	}
	
	DoubleListIterator operator ++(int)
	{
		DoubleListIterator retIter(*this);
		m_pNode = m_pNode->m_pNext;
		return retIter;
	}
	
	bool operator ==(const DoubleListIterator& other)const {return m_pNode == other.m_pNode;}
	bool operator !=(const DoubleListIterator& other)const {return !(*this == other);}
	
	reference operator *()const
	{
		return m_pNode->m_data;
	}
	
	pointer operator ->()const
	{
		return &(m_pNode->m_data);
	}
	
	DoubleListIterator& operator --()
	{
		m_pNode = m_pNode->m_pPrev;
		return *this;
	}
	
	DoubleListIterator operator --(int)
	{
		DoubleListIterator resultIter(m_pNode);
		m_pNode = m_pNode->m_pPrev;
		return resultIter;
	}
	
	DoubleListNode<T>* getNode(){return m_pNode;}
	
	/*模板类的成员函数，只有在被调用的时候才会进行编译，执行语法分析和词法分析。
	 *模板类实例化过程中，其成员方法不会被实例化。假如模板参数为T = const int时，
	 *由于DoubleListIterator<const int>迭代器不会调用toConstIterator()成员函数，
	 *所以就不会出现返回值为DoubleListIterator<const const int>不合法类型的情况。
	 */
	DoubleListIterator<const T> toConstIterator()
	{
		DoubleListNode<const T>* m_pcNode = reinterpret_cast<DoubleListNode<const T>*>(m_pNode);
		return DoubleListIterator<const T>(m_pcNode);
	}
	
private:
	DoubleListNode<T>* m_pNode;
};

template <typename T>
class DoubleList
{
public:
	typedef T value_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef ptrdiff_t difference_type;
	
	typedef DoubleListIterator<T> iterator;
	typedef DoubleListIterator<const T> const_iterator;
	
	DoubleList():m_pHead(new DoubleListNode<T>),m_length(0)
	{
		m_pTail = m_pHead;
	}
	
	DoubleList(const std::initializer_list<T>& ls):m_pHead(new DoubleListNode<T>),m_length(ls.size())
	{
		DoubleListNode<T>* pNode = m_pHead;
		for(const T& n : ls)
		{
			pNode->m_pNext = new DoubleListNode<T>(n,pNode,nullptr);
			pNode = pNode->m_pNext;
		}
		
		m_pTail = pNode;
	}
	
	DoubleList(const DoubleList& other):m_pHead(new DoubleListNode<T>),m_length(other.m_length)
	{
		DoubleListNode<T>* pNode = m_pHead;
		DoubleListNode<T>* pTempNode = other.m_pHead->m_pNext;
		while(pTempNode != nullptr)
		{
			pNode->m_pNext = new DoubleListNode<T>(pTempNode->m_data,pNode,nullptr);
			pNode = pNode->m_pNext;
			pTempNode = pTempNode->m_pNext;
		}
		
		m_pTail = pNode;
	}
	
	DoubleList(DoubleList&& other):m_pHead(new DoubleListNode<T>),m_pTail(other.m_pTail),m_length(other.m_length)
	{
		m_pHead->m_pNext = other.m_pHead->m_pNext;
		
		other.m_pHead->m_pNext = nullptr;
		other.m_pTail = other.m_pHead;
		other.m_length = 0;
	}
	
	~DoubleList()
	{
		m_length = 0;
		m_pTail = nullptr;
		
		DoubleListNode<T>* pNode = nullptr;
		while(m_pHead != nullptr)
		{
			pNode = m_pHead->m_pNext;
			delete m_pHead;
			m_pHead = pNode;
		}
		m_pHead = nullptr;
	}
	
	DoubleList& operator =(const DoubleList& other)
	{
		clear();
		m_length = other.m_length;
		
		DoubleListNode<T>* pNode = m_pHead;
		DoubleListNode<T>* pTempNode = other.m_pHead->m_pNext;
		while(pTempNode != nullptr)
		{
			pNode->m_pNext = new DoubleListNode<T>(pTempNode->m_data,pNode,nullptr);
			pNode = pNode->m_pNext;
			pTempNode = pTempNode->m_pNext;
		}
		m_pTail = pNode;
		
		return *this;
	}

	DoubleList& operator =(DoubleList&& other)
	{
		clear();
		m_pHead->m_pNext = other.m_pHead->m_pNext;
		m_pTail = other.m_pTail;
		m_length = other.m_length;
		
		other.m_pHead->m_pNext = nullptr;
		other.m_pTail = other.m_pHead;
		other.m_length = 0;
		return *this;
	}
	
	iterator begin(){return iterator(m_pHead->m_pNext);}
	iterator end(){return iterator(m_pTail->m_pNext);}
	
	const_iterator cbegin(){return begin().toConstIterator();}
	const_iterator cend(){return end().toConstIterator();}
	
	bool empty()const {return m_length == 0;}
	int size()const {return m_length;}
	
	reference front()
	{
		assert(m_pHead->m_pNext != nullptr);
		return m_pHead->m_pNext->m_data;
	}
	
	const_reference front() const
	{
		assert(m_length != 0);
		return m_pHead->m_pNext->m_data;
	}
	
	reference back()
	{
		assert(m_pTail != m_pHead);
		return m_pTail->m_data;
	}
	
	const_reference back() const
	{
		assert(m_length != 0);
		return m_pTail->m_data;
	}
	
	void push_front(const_reference val)
	{
		DoubleListNode<T>* pTempNode = m_pHead->m_pNext;
		m_pHead->m_pNext = new DoubleListNode<T>(val,m_pHead,m_pHead->m_pNext);	
		if(pTempNode != nullptr)
		{
			pTempNode->m_pPrev = m_pHead->m_pNext;
		}
		else
		{
			m_pTail = m_pHead->m_pNext;
		}
		
		m_length++;
	}
	
	void pop_front()
	{
		if(empty()) return;
		
		DoubleListNode<T>* pNode = m_pHead->m_pNext;
		m_pHead->m_pNext = pNode->m_pNext;
		if(pNode->m_pNext != nullptr)
		{
			pNode->m_pNext->m_pPrev = m_pHead;
		}
		else
		{
			m_pTail = m_pHead;
		}
		
		delete pNode;
		pNode = nullptr;
		m_length--;
	}
	
	void push_back(const_reference val)
	{
		m_pTail->m_pNext = new DoubleListNode<T>(val,m_pTail,nullptr);
		m_pTail = m_pTail->m_pNext;
		m_length++;
	}
	
	void pop_back()
	{
		if(m_pTail == m_pHead) return;
		
		DoubleListNode<T>* pNode = m_pTail->m_pPrev;
		pNode->m_pNext = nullptr;
		
		delete m_pTail;
		m_pTail = pNode;
		m_length--;
	}
	
	void clear()
	{
		if(m_length == 0) return;
		
		m_length = 0;
		m_pTail = m_pHead;
		
		DoubleListNode<T>* pNode = m_pHead->m_pNext;
		DoubleListNode<T>* pTempNode = pNode->m_pNext;
		while(pNode != nullptr)
		{
			delete pNode;
			pNode = pTempNode;
			
			if(pTempNode != nullptr)
			{
				pTempNode = pTempNode->m_pNext;
			}
		}
		m_pHead->m_pNext = nullptr;
	}
	
	void remove(const_reference val)
	{
		if(m_pHead->m_pNext == nullptr) return;
		
		DoubleListNode<T>* pNode = m_pHead;
		DoubleListNode<T>* pTempNode = pNode->m_pNext;
		while(pTempNode != nullptr)
		{
			if(pTempNode->m_data == val)
			{
				pNode->m_pNext = pTempNode->m_pNext;
				if(pTempNode->m_pNext != nullptr)
				{
					pTempNode->m_pNext->m_pPrev = pNode;
				}
				else
				{
					m_pTail = pNode;
				}
				
				delete pTempNode;
				pTempNode = pNode->m_pNext;
				m_length--;
			}
			else
			{
				pNode = pNode->m_pNext;
				pTempNode = pNode->m_pNext;
			}
		}
	}
	
	iterator insert(iterator posIter,const_reference val)
	{
		if(posIter == begin())
		{
			m_pHead->m_pNext = new DoubleListNode<T>(val,m_pHead,m_pHead->m_pNext);
			if(m_pTail == m_pHead)
			{
				m_pTail = m_pHead->m_pNext;
			}
			
			m_length++;
			return iterator(m_pHead->m_pNext);
		}
		
		DoubleListNode<T>* pNode = posIter.getNode();
		DoubleListNode<T>* pTempNode = pNode->m_pNext;
		pNode->m_pNext = new DoubleListNode<T>(val,pNode,pNode->m_pNext);
		if(pTempNode != nullptr)
		{
			pTempNode->m_pPrev = pNode->m_pNext;
		}
		else
		{
			m_pTail = pNode->m_pNext;
		}
		
		m_length++;
		return iterator(pNode->m_pNext);
	}
	
	iterator erase(iterator posIter)
	{
		DoubleListNode<T>* pNode = posIter.getNode();
		DoubleListNode<T>* pTempNode = pNode->m_pPrev;
		pTempNode->m_pNext = pNode->m_pNext;
		if(pNode->m_pNext != nullptr)
		{
			pNode->m_pNext->m_pPrev = pTempNode;
		}
		else
		{
			m_pTail = pTempNode;
		}
		
		delete pNode;
		m_length--;
		return iterator(pTempNode->m_pNext);
	}
	
private:
	DoubleListNode<T>* m_pHead;
	DoubleListNode<T>* m_pTail;
	int m_length;
};
	
}  // namespace Learn

#endif  //_DOUBLE_LIST_HPP_
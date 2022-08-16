#ifndef _CIRCULAR_LIST_HPP_
#define _CIRCULAR_LIST_HPP_

#include <cassert>
#include <initializer_list>
#include "iterator.hpp"

namespace Learn {
	
struct CircularListNodeBase
{
	CircularListNodeBase* m_pPrev;
	CircularListNodeBase* m_pNext;
	
	CircularListNodeBase(CircularListNodeBase* pPrev,CircularListNodeBase* pNext):m_pPrev(pPrev),m_pNext(pNext){}
	virtual ~CircularListNodeBase(){}
};

struct CircularListHeadNode:public CircularListNodeBase
{
	int m_size;
	
	explicit CircularListHeadNode(const int& size = 0):CircularListNodeBase(this,this),m_size(size){}
};

template <typename T>
struct CircularListNode:public CircularListNodeBase
{
	T m_data;
	
	CircularListNode(const T& val,CircularListNodeBase* pPrev,CircularListNodeBase* pNext):CircularListNodeBase(pPrev,pNext),m_data(val){}
};

template <typename T>
class CircularListIterator:public iterator<bidirectional_iterator_tag,T>
{
public:
	using base = iterator<bidirectional_iterator_tag,T>;
	using typename base::iterator_category;
	using typename base::value_type;
	using typename base::difference_type;
    using typename base::pointer;
    using typename base::reference;
	
	explicit CircularListIterator(CircularListNodeBase* pNode):m_pNode(pNode){}
	CircularListIterator(const CircularListIterator& other):m_pNode(other.m_pNode){}
	
	CircularListIterator& operator =(const CircularListIterator& other)
	{
		m_pNode = other.m_pNode;
		return *this;
	}
	
	CircularListIterator& operator ++()
	{
		m_pNode = m_pNode->m_pNext;
		return *this;
	}
	
	CircularListIterator operator ++(int)
	{
		CircularListIterator retIter(*this);
		m_pNode = m_pNode->m_pNext;
		return retIter;
	}
	
	bool operator ==(const CircularListIterator& other)const {return m_pNode == other.m_pNode;}
	bool operator !=(const CircularListIterator& other)const {return !(*this == other);}
	
	reference operator *()const
	{
		CircularListNode<T>* pTempNode = static_cast<CircularListNode<T>*>(m_pNode);
		return pTempNode->m_data;
	}
	
	pointer operator ->()const
	{
		CircularListNode<T>* pTempNode = static_cast<CircularListNode<T>*>(m_pNode);
		return &(pTempNode->m_data);
	}
	
	CircularListIterator& operator --()
	{
		m_pNode = m_pNode->m_pPrev;
		return *this;
	}
	
	CircularListIterator operator --(int)
	{
		CircularListIterator resultIter(m_pNode);
		m_pNode = m_pNode->m_pPrev;
		return resultIter;
	}
	
	CircularListNodeBase* getNode(){return m_pNode;}
	
	/*模板类的成员函数，只有在被调用的时候才会进行编译，执行语法分析和词法分析。
	 *模板类实例化过程中，其成员方法不会被实例化。假如模板参数为T = const int时，
	 *由于CircularListIterator<const int>迭代器不会调用toConstIterator()成员函数，
	 *所以就不会出现返回值为CircularListIterator<const const int>不合法类型的情况。
	 */
	CircularListIterator<const T> toConstIterator()
	{
		return CircularListIterator<const T>(m_pNode);
	}
	
private:
	CircularListNodeBase* m_pNode;
};

template <typename T>
class CircularList
{
public:
	typedef T value_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef ptrdiff_t difference_type;
	
	typedef CircularListIterator<T> iterator;
	typedef CircularListIterator<const T> const_iterator;
	
	CircularList():m_pHead(new CircularListHeadNode){}
	
	CircularList(const std::initializer_list<T>& ls):m_pHead(new CircularListHeadNode(ls.size()))
	{
		CircularListNodeBase* pNode = m_pHead;
		for(const T& n : ls)
		{
			pNode->m_pNext = new CircularListNode<T>(n,pNode,m_pHead);
			pNode = pNode->m_pNext;
		}
		m_pHead->m_pPrev = pNode;
	}
	
	CircularList(const CircularList& other):m_pHead(new CircularListHeadNode(other.size()))
	{
		CircularListNodeBase* pNode = m_pHead;
		CircularListNodeBase* pTempNode = other.m_pHead->m_pNext;
		while(pTempNode != other.m_pHead)
		{
			CircularListNode<T>* tempNodePtr = static_cast<CircularListNode<T>*>(pTempNode);
			pNode->m_pNext = new CircularListNode<T>(tempNodePtr->m_data,pNode,m_pHead);
			pNode = pNode->m_pNext;
			pTempNode = pTempNode->m_pNext;
		}
		m_pHead->m_pPrev = pNode;
	}
	
	CircularList(CircularList&& other):m_pHead(new CircularListHeadNode(other.size()))
	{
		if(other.size() != 0)
		{
			m_pHead->m_pNext = other.m_pHead->m_pNext;
			m_pHead->m_pNext->m_pPrev = m_pHead;
			m_pHead->m_pPrev = other.m_pHead->m_pPrev;
			m_pHead->m_pPrev->m_pNext = m_pHead;
		
			other.m_pHead->m_pNext = other.m_pHead;
			other.m_pHead->m_size = 0;
			other.m_pHead->m_pPrev = other.m_pHead;	
		}
	}
	
	~CircularList()
	{
		clear();		
		delete m_pHead;
	}
	
	CircularList& operator =(const CircularList& other)
	{
		clear();
		m_pHead->m_size = other.m_pHead->m_size;
		
		CircularListNodeBase* pNode = m_pHead;
		CircularListNodeBase* pTempNode = other.m_pHead->m_pNext;
		while(pTempNode != other.m_pHead)
		{
			CircularListNode<T>* tempNodePtr = static_cast<CircularListNode<T>*>(pTempNode);
			pNode->m_pNext = new CircularListNode<T>(tempNodePtr->m_data,pNode,m_pHead);
			pNode = pNode->m_pNext;
			pTempNode = pTempNode->m_pNext;
		}
		m_pHead->m_pPrev = pNode;
		
		return *this;
	}

	CircularList& operator =(CircularList&& other)
	{
		clear();
		
		if(!other.empty())
		{
			m_pHead->m_pNext = other.m_pHead->m_pNext;
			m_pHead->m_pNext->m_pPrev = m_pHead;
			m_pHead->m_pPrev = other.m_pHead->m_pPrev;
			m_pHead->m_pPrev->m_pNext = m_pHead;
			m_pHead->m_size = other.m_pHead->m_size;
			
			other.m_pHead->m_pNext = other.m_pHead;
			other.m_pHead->m_size = 0;
			other.m_pHead->m_pPrev = other.m_pHead;
		}		
		return *this;
	}
	
	iterator begin(){return iterator(m_pHead->m_pNext);}
	iterator end(){return iterator(m_pHead);}
	
	const_iterator cbegin(){return begin().toConstIterator();}
	const_iterator cend(){return end().toConstIterator();}

	iterator rbegin(){return iterator(m_pHead->m_pPrev);}
	iterator rend(){return iterator(m_pHead);}
	
	const_iterator rcbegin(){return rbegin().toConstIterator();}
	const_iterator rcend(){return rend().toConstIterator();}
	
	bool empty()const {return m_pHead->m_size == 0;}
	int size()const {return m_pHead->m_size;}
	
	reference front()
	{
		assert(m_pHead->m_pNext != m_pHead);
		CircularListNode<T>* pTempNode = static_cast<CircularListNode<T>*>(m_pHead->m_pNext);
		return pTempNode->m_data;
	}
	
	const_reference front() const
	{
		assert(m_pHead->m_size != 0);
		CircularListNode<T>* pTempNode = static_cast<CircularListNode<T>*>(m_pHead->m_pNext);
		return pTempNode->m_data;
	}
	
	reference back()
	{
		assert(m_pHead->m_pPrev != m_pHead);
		CircularListNode<T>* pTempNode = static_cast<CircularListNode<T>*>(m_pHead->m_pPrev);
		return pTempNode->m_data;
	}
	
	const_reference back() const
	{
		assert(m_pHead->m_size != 0);
		CircularListNode<T>* pTempNode = static_cast<CircularListNode<T>*>(m_pHead->m_pPrev);
		return pTempNode->m_data;
	}
	
	void push_front(const_reference val)
	{
		CircularListNodeBase* pNode = m_pHead->m_pNext;
		m_pHead->m_pNext = new CircularListNode<T>(val,m_pHead,pNode);	
		pNode->m_pPrev = m_pHead->m_pNext;
		
		m_pHead->m_size++;
	}
	
	void pop_front()
	{
		if(empty()) return;
		
		CircularListNodeBase* pNode = m_pHead->m_pNext;
		m_pHead->m_pNext = pNode->m_pNext;
		if(pNode->m_pNext != m_pHead)
		{
			pNode->m_pNext->m_pPrev = m_pHead;
		}
		else
		{
			m_pHead->m_pPrev = m_pHead;
		}
		
		delete pNode;
		m_pHead->m_size--;
	}
	
	void push_back(const_reference val)
	{
		CircularListNodeBase* pTail = m_pHead->m_pPrev;
		pTail->m_pNext = new CircularListNode<T>(val,pTail,m_pHead);
		m_pHead->m_pPrev = pTail->m_pNext;
		m_pHead->m_size++;
	}
	
	void pop_back()
	{
		if(m_pHead->m_pPrev == m_pHead) return;
		
		CircularListNodeBase* pTail = m_pHead->m_pPrev;
		CircularListNodeBase* pNode = pTail->m_pPrev;
		pNode->m_pNext = m_pHead;
		m_pHead->m_pPrev = pNode;

		delete pTail;
		m_pHead->m_size--;
	}
	
	void clear()
	{
		if(m_pHead->m_size == 0) return;
		
		CircularListNodeBase* pNode = m_pHead->m_pNext;
		CircularListNodeBase* pTempNode = nullptr;
		while(pNode != m_pHead)
		{
			pTempNode = pNode->m_pNext;
			delete pNode;
			pNode = pTempNode;
		}
		
		m_pHead->m_pPrev = m_pHead;
		m_pHead->m_size = 0;
	}
	
	void remove(const_reference val)
	{
		if(m_pHead->m_pNext == m_pHead) return;
		
		CircularListNodeBase* pNode = m_pHead;
		CircularListNode<T>* pTempNode = nullptr;
		while(pNode->m_pNext != m_pHead)
		{
			pTempNode = static_cast<CircularListNode<T>*>(pNode->m_pNext);
			if(pTempNode->m_data == val)
			{
				pNode->m_pNext = pTempNode->m_pNext;
				if(pTempNode->m_pNext != m_pHead)
				{
					pTempNode->m_pNext->m_pPrev = pNode;
				}
				
				delete pTempNode;
				m_pHead->m_size--;
			}
			else
			{
				pNode = pNode->m_pNext;
			}
		}
	}
	
	iterator insert(iterator posIter,const_reference val)
	{	
		CircularListNodeBase* pNode = posIter.getNode();
		CircularListNodeBase* pTempNode = pNode->m_pNext;
		pNode->m_pNext = new CircularListNode<T>(val,pNode,pNode->m_pNext);
		pTempNode->m_pPrev = pNode->m_pNext;
		
		m_pHead->m_size++;
		return iterator(pNode->m_pNext);
	}
	
	iterator erase(iterator posIter)
	{
		CircularListNodeBase* pNode = posIter.getNode();
		CircularListNodeBase* pTempNode = pNode->m_pPrev;
		pTempNode->m_pNext = pNode->m_pNext;
		if(pNode->m_pNext != m_pHead)
		{
			pNode->m_pNext->m_pPrev = pTempNode;
		}
		
		delete pNode;
		m_pHead->m_size--;
		return iterator(pTempNode->m_pNext);
	}
	
private:
	CircularListHeadNode* m_pHead;
};
	
}  // namespace Learn

#endif  //_CIRCULAR_LIST_HPP_
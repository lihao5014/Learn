#ifndef _LINK_LIST_HPP_
#define _LINK_LIST_HPP_

#include <cassert>
#include <memory>
#include <initializer_list>
#include "iterator.hpp"

namespace Learn {

template <class T>
struct LinkListNode
{
	T m_data;
	std::shared_ptr<LinkListNode> m_nextPtr;
	
	LinkListNode():m_data(0),m_nextPtr(nullptr){}
	explicit LinkListNode(const T& val):m_data(val),m_nextPtr(nullptr){}
	LinkListNode(const T& val,std::shared_ptr<LinkListNode> nextPtr):m_data(val),m_nextPtr(nextPtr){}
};

template <typename T>
class LinkListIterator:public iterator<forward_iterator_tag,T>
{
public:
	using base = iterator<forward_iterator_tag,T>;
	using typename base::iterator_category;
	using typename base::value_type;
	using typename base::difference_type;
    using typename base::pointer;
    using typename base::reference;

	explicit LinkListIterator(std::shared_ptr<LinkListNode<T>> nodePtr):m_nodePtr(nodePtr){}
	LinkListIterator(const LinkListIterator& other):m_nodePtr(other.m_nodePtr){}
	
	LinkListIterator& operator =(const LinkListIterator& other)
	{
		m_nodePtr = other.m_nodePtr;
		return *this;
	}
	
	LinkListIterator& operator ++()
	{
		std::shared_ptr<LinkListNode<T>> tempPtr = m_nodePtr.lock();
		m_nodePtr = tempPtr->m_nextPtr;
		return *this;
	}
	
	LinkListIterator operator ++(int)
	{
		LinkListIterator resultIter(*this);
		
		std::shared_ptr<LinkListNode<T>> tempPtr = m_nodePtr.lock();
		m_nodePtr = tempPtr->m_nextPtr;
		return resultIter;
	}
	
	bool operator ==(const LinkListIterator& other)const
	{
		return !m_nodePtr.owner_before(other.m_nodePtr) && !other.m_nodePtr.owner_before(m_nodePtr);
	}
	
	bool operator !=(const LinkListIterator& other)const
	{
		return !(*this == other);
	}
	
	T& operator *()const
	{
		return m_nodePtr.lock()->m_data;
	}
	
	T* operator ->()const
	{
		std::shared_ptr<LinkListNode<T>> tempPtr = m_nodePtr.lock();
		return &(tempPtr->m_data);
	}
	
	std::weak_ptr<LinkListNode<T>> getNode(){return m_nodePtr;}
	
protected:
	std::weak_ptr<LinkListNode<T>> m_nodePtr;
};

template <typename T>
class LinkList
{
public:
	typedef T value_type;
	typedef T* pointer;
	typedef T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef ptrdiff_t difference_type;
	
	typedef LinkListIterator<T> iterator;
	typedef LinkListIterator<const T> const_iterator;
	
	LinkList():m_headPtr(std::shared_ptr<LinkListNode<T>>(new LinkListNode<T>)){}
	
	LinkList(const std::initializer_list<T> ls):m_headPtr(std::make_shared<LinkListNode<T>>())
	{
		std::shared_ptr<LinkListNode<T>> nodePtr = m_headPtr;
		for(const auto& n : ls)
		{
			nodePtr->m_nextPtr = std::make_shared<LinkListNode<T>>(n,nullptr);
			nodePtr = nodePtr->m_nextPtr;
		}
	}
	
	LinkList(const LinkList& other):m_headPtr(std::make_shared<LinkListNode<T>>())
	{
		std::shared_ptr<LinkListNode<T>> tempPtr = m_headPtr;
		std::shared_ptr<LinkListNode<T>> nodePtr = other.m_headPtr->m_nextPtr;
		while(nodePtr != nullptr)
		{
			tempPtr->m_nextPtr = std::make_shared<LinkListNode<T>>(nodePtr->m_data);
			nodePtr = nodePtr->m_nextPtr;
			tempPtr = tempPtr->m_nextPtr;
		}
	}
	
	LinkList(LinkList&& other):m_headPtr(std::make_shared<LinkListNode<T>>())
	{
		m_headPtr->m_nextPtr = other.m_headPtr->m_nextPtr;
		other.m_headPtr->m_nextPtr = nullptr;
	}
	
	LinkList& operator =(const LinkList& other)
	{
		clear();
		
		std::shared_ptr<LinkListNode<T>> tempPtr = m_headPtr;
		std::shared_ptr<LinkListNode<T>> nodePtr = other.m_headPtr->m_nextPtr;
		while(nodePtr != nullptr)
		{
			tempPtr->m_nextPtr = std::make_shared<LinkListNode<T>>(nodePtr->m_data);
			nodePtr = nodePtr->m_nextPtr;
			tempPtr = tempPtr->m_nextPtr;
		}
		
		return *this;
	}
	
	LinkList& operator =(LinkList&& other)
	{
		clear();
		
		m_headPtr->m_nextPtr = other.m_headPtr->m_nextPtr;
		other.m_headPtr->m_nextPtr = nullptr;
		return *this;
	}
	
	iterator begin(){return iterator(m_headPtr->m_nextPtr);}
	iterator end(){return iterator(nullptr);}
	
	/*在不特例化LinkListIterator<const T>模板类或重新设计一个新类LinkListConstIterator作为
	 *const_iterator的类型别名外，没有办法实现从iterator迭代器构造一个const_iterator迭代器，
	 *即不能实现LinkListIterator<T>类型转化为LinkListIterator<const T>。所以LinkList暂时先
	 *不支持cbegin()和cend()方法。
	 */
	// const_iterator cbegin(){return const_iterator(m_headPtr->m_nextPtr);}
	// const_iterator cend(){return const_iterator(nullptr);}
	
	bool empty()const {return m_headPtr->m_nextPtr == nullptr;}
	
	int size()const 
	{
		int count = 0;
		std::shared_ptr<LinkListNode<T>> nodePtr = m_headPtr->m_nextPtr;
		while(nodePtr != nullptr)
		{
			count++;
			nodePtr = nodePtr->m_nextPtr;
		}
		
		return count;
	}
	
	void clear(){m_headPtr->m_nextPtr = nullptr;}
	
	void remove(const_reference val)
	{
		std::shared_ptr<LinkListNode<T>> tempPtr = m_headPtr;
		std::shared_ptr<LinkListNode<T>> nodePtr = m_headPtr->m_nextPtr;
		while(nodePtr != nullptr)
		{
			if(nodePtr->m_data == val)
			{
				tempPtr->m_nextPtr = nodePtr->m_nextPtr;
				nodePtr = nodePtr->m_nextPtr;
			}
			else
			{
				tempPtr = nodePtr;
				nodePtr = nodePtr->m_nextPtr;
			}
		}
	}
	
	reference front()
	{
		assert(m_headPtr->m_nextPtr != nullptr);
		return m_headPtr->m_nextPtr->m_data;
	}
	
	const_reference front() const
	{
		assert(!empty());
		return m_headPtr->m_nextPtr->m_data;
	}
	
	void push_front(const_reference val)
	{
		std::shared_ptr<LinkListNode<T>> nodePtr = m_headPtr->m_nextPtr;
		m_headPtr->m_nextPtr = std::make_shared<LinkListNode<T>>(val,nodePtr);
	}
	
	void pop_front()
	{
		if(empty())
		{
			return;
		}
		
		std::shared_ptr<LinkListNode<T>> nodePtr = m_headPtr->m_nextPtr->m_nextPtr;
		m_headPtr->m_nextPtr = nodePtr;
	}
	
	iterator insert_after(iterator posIter,const_reference val)
	{
		if(posIter == begin())
		{
			m_headPtr->m_nextPtr = std::make_shared<LinkListNode<T>>(val,m_headPtr->m_nextPtr);
			return iterator(m_headPtr->m_nextPtr);
		}
		
		std::shared_ptr<LinkListNode<T>> nodePtr = posIter.getNode().lock();
		nodePtr->m_nextPtr = std::make_shared<LinkListNode<T>>(val,nodePtr->m_nextPtr);
		return iterator(nodePtr->m_nextPtr);
	}
	
	iterator erase_after(iterator posIter)
	{
		std::shared_ptr<LinkListNode<T>> nodePtr = posIter.getNode().lock();
		std::shared_ptr<LinkListNode<T>> tempPtr = nodePtr->m_nextPtr;
		nodePtr->m_nextPtr = tempPtr->m_nextPtr;
		return iterator(nodePtr->m_nextPtr);
	}
	
private:
	std::shared_ptr<LinkListNode<T>> m_headPtr;
};

}  // namespace Learn

#endif  //_LINK_LIST_HPP_
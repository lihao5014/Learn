#ifndef _DOUBLE_LIST_H
#define _DOUBLE_LIST_H

#include "node.h"

typedef enum SortType_t
{
	INCREASE,
	DECREASE
}SortType;

class DoubleList
{
public:
	DoubleList();
	DoubleList(const DoubleList& other);
	virtual ~DoubleList();
	
	DoubleList& operator =(const DoubleList& other);
	data_t& operator [](int index);
	
	void init(int size,const data_t data);
	
	bool empty();
	int length();
	
	void append(const data_t data);
	void prepend(const data_t data);
	bool insert(int pos,const data_t data);
	
	bool remove(int pos);
	bool remove(const data_t data);
	void popFront();
	void popBack();
	void clear();
	
	data_t& front();
	data_t& back();
	data_t at(int index);
	
	int find(const data_t data);
	bool replace(int pos,const data_t data);
	bool replace(const data_t src,const data_t dst);
	
	void reverse();
	void sort(SortType sortType);
	
	void show()const;
	void rshow()const;
private:
	Node *m_pheadNode;      //双向链表的头结点的前驱都为空，而尾节点的后续都为空。
	Node *m_ptailNode;       //为了提高双向链表反向遍历的速度，双向链表中实时保存尾节点的位置。
	int m_length;
};

#endif  //_DOUBLE_LIST_H
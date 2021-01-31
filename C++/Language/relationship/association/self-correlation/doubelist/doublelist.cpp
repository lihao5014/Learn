#include "doublelist.h"
#include <new>
#include <iostream>
#include <assert.h>
#include <stdlib.h>

#define _DEBUG_
// #undef _DEBUG_

#define _CHANGE_WAY_
// #undef _CHANGE_WAY_

#ifdef _DEBUG_
#define BreakPoint(index)   \
	cout<<"---["<<__func__<<": line ="<<__LINE__<<"] break point: "<<index<<" ---"<<endl
#else
#define BreakPoint(index)
#endif

using std::cout;
using std::endl;
using std::cerr;

template <typename T>
static void swap(T& x,T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

DoubleList::DoubleList()
	:m_length(0)
{
	try{
		m_pheadNode = new Node;      //创建双向链表的头结点，并将其初始化
		m_pheadNode->prev = nullptr;     //使用new操作符申请堆内存空间时，可以不用对new运算符的返回值做判空处理。因为new运算符申请内存空间失败时，
		m_pheadNode->data = 0;           //会直接抛出std::bad_alloc异常。但使用malloc函数申请堆内存时，需要对malloc函数的返回值做判空处理。
		m_pheadNode->next = nullptr;  //C++中使用new运算符申请堆内存空间时，一般不做异常捕获处理。
	}
	catch(const std::bad_alloc& e)
	{
		cerr<<"bad_alloc caught: "<< e.what() <<endl;
		throw e;     //打印异常信息后，继续往函数外层抛。如果外层函数没有处理内部函数抛出的异常，那么程序会被直接中断。
	}
}

DoubleList::DoubleList(const DoubleList& other)
	:m_length(other.m_length)
{
	m_pheadNode = new Node;         //调用拷贝构造函数时，当前链表的头结点内存还没有被申请。
	m_pheadNode->prev = nullptr;    //所以需求先为头结点开辟内存空间。
	m_pheadNode->data = 0;
	m_pheadNode->next = nullptr;
	
	Node *pnode = m_pheadNode;         //创建当前链表的节点指针
	Node *qnode = other.m_pheadNode;   //创建other链表的节点指针
	while(qnode->next != nullptr)      //如果还没有到达other链表的尾节点，那么就继续节点复制操作。
	{                                  //如果到达了other链表的尾节点，那么就停止节点拷贝操作。
		qnode = qnode->next;           //让other链表的节点指针向下一个节点位置移动
		
		Node *pnewNode = new Node;     //创建新的链表节点
		pnewNode->prev = pnode;        //新节点的前驱指向链表中最后一个节点
		pnewNode->data = qnode->data;  //将other链表中对应节点数据域中的值，拷贝到新节点的数据域中
		pnewNode->next = nullptr;      //新节点的后续设置为空
		
		pnode->next = pnewNode;        //链表中的最后一个节点指向新创建的节点
		pnode = pnode->next;           //让当前链表的节点指针向下一个节点移动，即移向刚刚插入的新节点
	}
}

DoubleList::~DoubleList()
{
	clear();           //将双向链表中的节点清空，只保留头结点。
	delete m_pheadNode;    //释放头结点内存
}

DoubleList& DoubleList::operator =(const DoubleList& other)
{
	clear();
	m_length = other.m_length;
	
	Node *pnode = m_pheadNode;         //创建当前链表的节点指针
	Node *qnode = other.m_pheadNode;   //创建other链表的节点指针
	while(qnode->next != nullptr)      //如果还没有到达other链表的尾节点，那么就继续节点复制操作。
	{                                  //如果到达了other链表的尾节点，那么就停止节点拷贝操作。
		qnode = qnode->next;           //让other链表的节点指针向下一个节点位置移动
		
		Node *pnewNode = new Node;     //创建新的链表节点
		pnewNode->prev = pnode;        //新节点的前驱指向链表中最后一个节点
		pnewNode->data = qnode->data;  //将other链表中对应节点数据域中的值，拷贝到新节点的数据域中
		pnewNode->next = nullptr;      //新节点的后续设置为空
		
		pnode->next = pnewNode;        //链表中的最后一个节点指向新创建的节点
		pnode = pnode->next;           //让当前链表的节点指针向下一个节点移动，即移向刚刚插入的新节点
	}
	
	return *this;
}

#ifndef _CHANGE_WAY_
data_t& DoubleList::operator [](int index)
{
	assert(index >= 0 && index < m_length);
	
	Node *pnode = m_pheadNode->next;
	while(index--)
	{
		pnode = pnode->next;
	}
	
	return pnode->data;
}
#else
data_t& DoubleList::operator [](int index)
{
	assert(index >= 0 && index < m_length);
	
	Node *pnode = m_pheadNode;      //如果只是更新或查找链表中节点的内容，那么节点指针即可以从头结点位置开始遍历，也可以从头结点后的第一个
	while(pnode->next != nullptr)   //节点位置开始遍历。因为头结点数据域中的内容没有意义，所以一般从头结点后的第一个节点位置开始遍历。
	{
		pnode = pnode->next;
		if(index-- == 0)
		{
			break;
		}
	}
	
	return pnode->data;
}
#endif

#ifndef _CHANGE_WAY_
void DoubleList::init(int size,const data_t data)
{
	if(size < 1)
	{
		cout<<"init warn: size is less than one"<<endl;
		return ;
	}
	
	clear();            //将双向链表中的节点清空，只保留头结点。
	m_length = size;
	
	while(size--)       //每次插入新的节点时，从头结点后一个位置插入
	{
		Node *pnewNode = new Node;
		pnewNode->prev = m_pheadNode;       //新创建节点的前驱指向头结点
		pnewNode->data = data;
		pnewNode->next = m_pheadNode->next;   //新创建节点的后续保存，头结点后续的连接
		
		if(m_pheadNode->next != nullptr)
		{
			m_pheadNode->next->prev = pnewNode;
		}
		m_pheadNode->next = pnewNode;      //头结点的后续指向新创建的节点
	}
}
#else
void DoubleList::init(int size,const data_t data)
{
	if(size < 1)
	{
		cout<<"init warn: size is less than one"<<endl;
		return ;
	}
	
	clear();            //将双向链表中的节点清空，只保留头结点。
	m_length = size;
	
	Node *pnode = m_pheadNode;     //如果要增删链表中的节点，那么节点指针必须从头结点位置开始遍历。
	while(size--)           //每次插入新的节点时，从链表最后一个节点后面插入
	{
		Node *pnewNode = new Node;
		pnewNode->prev = pnode;      //新创建节点的前驱指向链表中最后一个节点
		pnewNode->data = data;
		pnewNode->next = nullptr;   //新创建的节点没有后续，只有前驱
		
		pnode->next = pnewNode;      //链表中最后一个节点的后续指向新创建的节点
		pnode = pnode->next;        //让链表的节点指针向链表中的下一个节点移动，即移向刚刚插入的新节点
	}
}
#endif

bool DoubleList::empty()
{
#ifndef _CHANGE_WAY_
	return m_pheadNode->next == nullptr ? true : false;
#else
	return m_pheadNode->next == nullptr;      //因为构造函数中一定会给m_phead指针申请内存空间，所以使用m_phead指针前不需要再判空处理。
#endif
}

int DoubleList::length()
{
	return m_length;
}

void DoubleList::append(const data_t data)
{
	Node *pnode = m_pheadNode;
	while(pnode->next != nullptr)    //将pnode节点指针移动到链表中最后一个节点的位置上
	{
		pnode = pnode->next;
	}
	
	Node *pnewNode = new Node;       //创建新的节点，并将其初始化
	pnewNode->prev = pnode;
	pnewNode->data = data;
	pnewNode->next = nullptr;
	
	pnode->next = pnewNode;      //将新创建的节点接入原来的链表中
	m_length++;
}

void DoubleList::prepend(const data_t data)
{
	Node *pnewNode = new Node;
	pnewNode->prev = m_pheadNode;
	pnewNode->data = data;
	pnewNode->next = m_pheadNode->next;
	
	if(m_pheadNode->next != nullptr)
	{
		m_pheadNode->next->prev = pnewNode;
	}
	m_pheadNode->next = pnewNode;
	++m_length;
}

bool DoubleList::insert(int pos,const data_t data)
{
	if(pos < 0 || pos > m_length)
		return false;
	
	Node *pnode = m_pheadNode;   //如果要增删链表中的节点，那么节点指针必须从头结点位置开始遍历。
	while(pos--)
	{
		pnode = pnode->next;      //将节点指针移动到要插入位置的前一个节点上。
	}
	
	Node *pnewNode = new Node;
	pnewNode->prev = pnode;
	pnewNode->data = data;
	pnewNode->next = pnode->next;
	
	if(pnode->next != nullptr)
	{
		pnode->next->prev = pnewNode;    //双向链表与单向链表不同，增删节点时，不仅要处理后续连接问题，也需要处理前驱连接问题。
	}
	pnode->next = pnewNode;
	m_length++;
	return true;
}

#ifndef _CHANGE_WAY_
bool DoubleList::remove(int pos)
{
	if(pos < 0 || pos >= m_length)
		return false;
	
	Node *pnode = m_pheadNode;
	while(pos--)
	{
		pnode = pnode->next;     //将节点指针移动到要删除位置的前一个节点上
	}
	
	Node *qnode = pnode->next;    //获取要删除的节点;
	pnode->next = qnode->next;    //将要删除的节点从链表中断开
	if(qnode->next != nullptr)    //双向链表与单向链表不同，增删节点时，不仅要处理后续连接问题，也需要处理前驱连接问题。
	{
		qnode->next->prev = pnode;
	}
	
	delete qnode;
	qnode = nullptr;   //将qnode指针置不置为空指针都可以，因为函数马上就要return了，qnode指针自然也不可能再继续被访问了。
	
	m_length--;
	return true;
}
#else
bool DoubleList::remove(int pos)
{
	if(pos < 0 || pos >= m_length)
		return false;
	
	Node *pnode = m_pheadNode;
	while(pos--)
	{
		pnode = pnode->next;     //将节点指针移动到要删除位置的前一个节点上
	}
	
	Node *qnode = pnode->next->next;    //保存要删除节点的后续
	if(qnode != nullptr)
	{
		qnode->prev = pnode;   //双向链表与单向链表不同，增删节点时，不仅要处理后续连接问题，也需要处理前驱连接问题。
	}
	
	delete pnode->next;
	pnode->next = qnode;      
	
	--m_length;
	return true;
}
#endif

#ifndef _CHANGE_WAY_
bool DoubleList::remove(const data_t data)
{
	if(m_length < 1)
		return false;
	
	bool ret = false;
	Node *pnode = m_pheadNode;
	while(pnode->next != nullptr)     //将链表中所有数据域等于date的节点都删除掉。
	{
		if(pnode->next->data != data)
		{
			Node *qnode = pnode->next->next;     //保存需要删除节点的后续
			if(qnode != nullptr)
			{
				qnode->prev = pnode;  //移除节点时，处理链表中节点的前驱连接问题
			}
			
			delete pnode->next;
			pnode->next = qnode;
			
			--m_length;
			ret = true;
		}
		else
		{
			pnode = pnode->next;
		}
	}

	return ret;
}
#else
bool DoubleList::remove(const data_t data)
{
	if(m_length < 1)
		return false;
	
	Node *pnode = m_pheadNode;
	Node *qnode = nullptr;
	while(pnode->next != nullptr)    //只删除数据域值等于date的第一个节点。
	{
		qnode = pnode->next;     //获取pnode节点指针当前位置的下一个节点位置。
		if(qnode->data != data)
		{
			pnode = pnode->next;
			continue;
		}
		
		pnode->next = qnode->next;
		if(qnode->next != nullptr)
		{
			qnode->next->prev = pnode;     //移除节点时，处理链表中节点的前驱连接问题
		}
		
		delete qnode;
		// qnode = nullptr;    //将qnode指针置不置为空指针都可以，因为函数马上就要return了，qnode指针自然也不可能再继续被访问了。
		
		m_length--;
		return true;
	}
	
	return false;
}
#endif

#ifndef _CHANGE_WAY_
void DoubleList::popFront()
{
	if(m_length < 1)   //链表中没有内容，自然也不能再弹出节点了
		return ;
	
	Node* pnode = m_pheadNode->next;   //获取要弹出的节点
	m_pheadNode->next = pnode->next;
	
	if(pnode->next != nullptr)
	{
		pnode->next->prev = m_pheadNode;     //移除节点时，处理链表中节点的前驱连接问题
	}
	
	delete pnode;
	m_length--;
}
#else
void DoubleList::popFront()
{
	if(m_length < 1)   //链表中没有内容，自然也不能再弹出节点了
		return ;
	
	Node* pnode = m_pheadNode->next->next;   //获取要弹出节点的后续
	if(pnode != nullptr)
	{
		pnode->prev = m_pheadNode;     //移除节点时，处理链表中节点的前驱连接问题
	}
	
	delete m_pheadNode->next;
	m_pheadNode->next = pnode;
	--m_length;
}
#endif

#ifndef _CHANGE_WAY_
void DoubleList::popBack()
{
	if(m_length < 1)   //链表中没有内容，自然也不能再弹出节点了
		return ;
	
	Node *pnode = m_pheadNode;
	while(pnode->next->next != nullptr)
	{
		pnode = pnode->next;     //将节点指针移动到尾节点的前一个节点上
	}
	
	delete pnode->next;
	pnode->next = nullptr;   //将尾节点移除以后，以前的倒数第二个节点就变为了尾节点，所以不需要再处理尾节点的前驱连接问题。
	m_length--;
}
#else
void DoubleList::popBack()
{
	if(m_length < 1)   //链表中没有内容，自然也不能再弹出节点了
		return ;
	
	Node *pnode = m_pheadNode;
	while(pnode->next!= nullptr)
	{
		pnode = pnode->next;     //将节点指针移动到尾节点上
	}
	
	pnode->prev->next = nullptr;
	delete pnode;
	--m_length;
}
#endif

#ifndef _CHANGE_WAY_
void DoubleList::clear()       //clear()清空链表方法中，可以不用每删除一个节点，处理后续节点的前驱问题。，
{                              //因为清空后链表中就没有节点了，也就不存在节点前驱访问的问题了。
	if(m_length < 1)
		return ;
	
	Node *pnode = m_pheadNode->next;
	Node *qnode = nullptr;
	while(pnode != nullptr)    //从前往后依次销毁双向链表中保存的节点
	{
		qnode = pnode->next;    //在pnode指针指向的节点被销毁前，将pnode节点的后续地址保存到qnode节点指针中。
		delete qnode;
		pnode = qnode;
	}
	
	m_pheadNode->next = nullptr;
	m_length = 0;
}
#else
void DoubleList::clear()     //clear()清空链表方法中，可以不用每删除一个节点，处理后续节点的前
{                            //因为清空后链表中就没有节点了，也就不存在节点前驱访问的问题了。
	if(m_length == 0)
		return ;
	
	Node *pnode = m_pheadNode;       //如果要增删链表中的节点，那么节点指针必须从头结点位置开始遍历。
	while(pnode->next != nullptr)
	{
		pnode = pnode->next;
	}
	
	Node *qnode = nullptr;
	while(pnode->prev != nullptr)       //从后往前依次销毁双向链表中保存的节点
	{
		qnode = pnode->prev;
		delete pnode;
		pnode = qnode;
	}
	
	m_pheadNode->next = nullptr;
	m_length = 0;
}
#endif

data_t& DoubleList::front()
{
	Node *pnode = m_pheadNode->next;   //如果只是更新或查找链表中节点的内容，那么节点指针即可以从头结点位置开始遍历，也可以从头结点后的第
	if(pnode == nullptr)               //节点位置开始遍历。因为头结点数据域中的内容没有意义，所以一般从头结点后的第一个节点位置开始遍历。
	{
		cout<<"front error: double link list is empty"<<endl;
		exit(-1);
	}
	
	return pnode->data;
}

data_t& DoubleList::back()
{
	if(m_length == 0)
	{
		cout<<"back error: double link list is empty"<<endl;
		exit(-1);
	}
	
	Node *pnode = m_pheadNode->next;
	for(int i=1;i<m_length;++i)
	{
		pnode = pnode->next;
	}
	
	return pnode->data;
}

//函数设计的三段式：输入参数检测，函数输入处理和返回值输出。
data_t DoubleList::at(int index)
{
	assert(index >= 0 && index < m_length);
	
	Node *pnode = m_pheadNode->next;   //如果只是更新或查找链表中节点的内容，那么节点指针即可以从头结点位置开始遍历，也可以从头结点后的第
	while(index--)                     //节点位置开始遍历。因为头结点数据域中的内容没有意义，所以一般从头结点后的第一个节点位置开始遍历。
	{
		pnode = pnode->next;
	}
	
	return pnode->data;
}

#ifndef _CHANGE_WAY_
int DoubleList::find(const data_t data)
{
	if(m_length == 0)    //如果链表为空就不用再查找了
		return -1;
	
	int index = 0;
	Node *pnode = m_pheadNode->next;
	while(pnode != nullptr)
	{
		if(pnode->data == data)
		{
			return index;
		}
		++index;
		pnode = pnode->next;
	}
	
	return -1;
}
#else
int DoubleList::find(const data_t data)
{
	if(m_length == 0)    //如果链表为空就不用再查找了
		return -1;
	
	Node *pnode = m_pheadNode->next;
	for(int index=0;pnode != nullptr;++index)
	{
		if(pnode->data == data)
		{
			return index;         //获取链表中第一个查找到的数据域等于data的节点位置
		}
		pnode = pnode->next;
	}
	
	return -1;
}
#endif

bool DoubleList::replace(int pos,const data_t data)
{
	if(pos < 0 || pos >= m_length)
	{
		return false;
	}
	
	Node *pnode = m_pheadNode->next;
	while(pos--)
	{
		pnode = pnode->next;
	}
	
	pnode->data = data;
	return true;
}

bool DoubleList::replace(const data_t src,const data_t dst)
{
	if(m_length < 1)
		return false;
	
	bool result = false;
	Node *pnode = m_pheadNode->next;
	for(;pnode != nullptr;pnode = pnode->next)
	{
		if(pnode->data == src)
		{
			pnode->data = dst;
			result = true;
		}
	}
	
	return result;
}

#ifndef _CHANGE_WAY_
void DoubleList::reverse()   //尾节点往头结点方向依次移动，从而实现倒序排列
{
	if(m_length < 2)
		return ;
	
	Node *pnode = m_pheadNode;
	while(pnode->next != nullptr)
	{
		pnode = pnode->next;        //将pnode节点指针移动到尾节点上
	}
	
	Node *qnode = pnode->prev;      //将qnode节点指针指向尾节点的前一个节点上
	Node *rnode = m_pheadNode;
	for(int i=m_length -1;i>0;--i)
	{
		pnode->next = rnode->next;
		pnode->prev = rnode;
		qnode->next = nullptr;     //尾节点往链表头方向插入了以后，qnode就变为了尾节点
		
		if(rnode->next != nullptr)
		{
			rnode->next->prev = pnode;
		}
		rnode->next = pnode;       //将尾节点移动到头结点后的一个节点位置上
		rnode = rnode->next;       //将rnode节点指针移动到刚插入的节点上
		
		pnode = qnode;
		qnode = qnode->prev;
	}
}
#elif 0
void DoubleList::reverse()     //头结点后的第一个节点往尾节点方向移动从而实现倒序排列
{
	if(m_length < 2)     //链表中小于2个节点，就不用倒序了。因为只有一个节点的话倒序了以后还是原样
		return ;
	
	Node *pnode = m_pheadNode;
	while(pnode->next != nullptr)
	{
		pnode = pnode->next;       //获取尾节点指针的位置
	}
	
	Node* const qnode = pnode;     //qnode节点指针永远标记倒序以前，尾节点位置
	while(qnode->prev != m_pheadNode)
	{
		pnode = m_pheadNode->next;
		m_pheadNode->next = pnode->next;
		if(pnode->next != nullptr)
		{
			pnode->next->prev = m_pheadNode;
		}
		
		pnode->next = qnode->next;
		pnode->prev = qnode;
		
		if(qnode->next != nullptr)
		{
			qnode->next->prev = pnode;
		}
		qnode->next = pnode;
	}
}
#else
void DoubleList::reverse()    //只交换链表中前后节点中的数据域，但是不做移动节点操作。这个算法只有双向链表可以完成，
{                             //单向由于没有前驱指针，所以无法实现该算法。这里就体现了出双向链表相对于单向链表多一个前驱指针的优势。
	if(m_length < 2)
		return ;
	
	Node *pnode = m_pheadNode;
	while(pnode->next != nullptr)
	{
		pnode = pnode->next;     //获取尾节点的位置
	}
	
	Node *qnode = m_pheadNode->next;
	for(int i = m_length/2;i>0;--i)
	{
		swap(qnode->data,pnode->data);
		qnode = qnode->next;
		pnode = pnode->prev;
	}
}
#endif

#ifndef _CHANGE_WAY_
void DoubleList::sort(SortType sortType)   //冒泡排序
{
	if(m_length < 2)    //链表中小于2个节点，就不用排序了。因为只有一个节点的话排序了以后还是原样
		return ;
	
	if(sortType != INCREASE && sortType != DECREASE)
	{
		fputs("sort warn: sortType is illegal\n",stdout);
		return ;
	}
	
	Node *pnode = nullptr;
	Node *qnode = nullptr;
	for(int i=0;i<m_length;++i)
	{
		pnode = m_pheadNode->next;
		qnode = pnode->next;
		for(int j=1;j<m_length - i;++j)
		{
			if(sortType == INCREASE)
			{
				if(pnode->data > qnode->data)
				{
					swap(pnode->data,qnode->data);  //冒泡排序时，只交换相邻两个节点数据域中的内容，而不需要整个交换相邻的两个节点
				}
			}
			else
			{
				if(pnode->data < qnode->data)
				{
					swap(pnode->data,qnode->data);
				}
			}
			qnode = qnode->next;
			pnode = pnode->next;
		}
	}
}
#else
void DoubleList::sort(SortType sortType)    //选择排序
{
	if(m_length < 2)    //链表中小于2个节点，就不用排序了。因为只有一个节点的话排序了以后还是原样
		return ;
	
	if(sortType != INCREASE && sortType != DECREASE)
	{
		fputs("sort warn: sortType is illegal\n",stdout);
		return ;
	}
	
	Node *pnode = nullptr;
	Node *qnode = nullptr;     //qnode节点指针用于指向链表中，数据域值最大或者最小的节点
	for(int i=0;i<m_length-1;++i)
	{
		qnode = m_pheadNode->next;      //每次遍历链表时，都默认数据域最大或者最小的节点位置为头结点后第一个节点的位置
		pnode = qnode->next;
		for(int j =1;j<m_length - i;++j)
		{
			if(sortType == INCREASE)
			{
				if(qnode->data < pnode->data)
				{
					qnode = pnode;        //获取数据域中值最大的节点位置
				}
			}
			else
			{
				if(qnode->data > pnode->data)
				{
					qnode = pnode;        //获取数据域中值最小的节点位置
				}
			}
			
			if(j < m_length - i -1)
				pnode = pnode->next;
		}
		swap(qnode->data,pnode->data);
	}
}
#endif

#ifndef _CHANGE_WAY_
void DoubleList::display()const
{
	if(m_length < 1)     //如果链表中一个节点也没有，那么就没有需要显示的内容了，直接退出
		return ;
	
	Node *pnode = m_pheadNode->next;
	for(;pnode != nullptr;pnode = pnode->next)
	{
		cout<<pnode->data<<" ";
	}
	cout<<endl;
}
#else
void DoubleList::display()const
{
	if(m_length < 1)     //如果链表中一个节点也没有，那么就没有需要显示的内容了，直接退出
		return ;
	
	Node *pnode = m_pheadNode;
	for(int i=0;i<m_length;++i)
	{
		pnode = pnode->next;
		cout<<pnode->data<<" ";
	}
	cout<<endl;
}
#endif

void DoubleList::rdisplay()const
{
	if(m_length < 1)
		return ;
	
	Node *pnode = m_pheadNode;
	while(pnode->next != nullptr)
	{
		pnode = pnode->next;
	}
	
	BreakPoint(1);
	for(;pnode->prev != nullptr;pnode = pnode->prev)
	{
		cout<<pnode->data<<" ";
	}
	cout<<endl;
}
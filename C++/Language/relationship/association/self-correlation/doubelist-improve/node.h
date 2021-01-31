#ifndef _NODE_H
#define _NODE_H

typedef double data_t;       //data_t类型不能设置为int类型，因为这会造成DoubleList中的remove和replace方法重载失败

typedef struct Node_t        //由于Node_t拥有自己类型的指针，所以属于自身关联关系，简称自关联。
{
	struct Node_t *prev;     //指向直接前趋
	data_t data;
	struct Node_t *next;     //指向直接后继
}Node;

#endif //_NODE_H
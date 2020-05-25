/*句柄handle本质上就是一个为了隐藏结构体的实现而创建的指针。handle句柄指向隐藏结构体对象的首地址,
 *在库代码中通过对句柄的强制类型，就可以访问隐藏的结构体对象。一般使用void*指针作为通用句柄的定义。
 */

#ifndef _POINT_H
#define _POINT_H

typedef int data_t;

void* createPoint(data_t x,data_t y);
void destroyPoint(void** handle);

void setX(void* handle,const data_t x);
data_t getX(const void* handle);

void setY(void* handle,const data_t y);
data_t getY(const void* handle);

void display(const void* handle);

#endif //_POINT_H
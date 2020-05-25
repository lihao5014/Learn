/*句柄handle本质上就是一个为了隐藏结构体的实现而创建的指针。handle句柄指向隐藏结构体对象的首地址,
 *在库代码中通过对句柄的强制类型，就可以访问隐藏的结构体对象。一般使用void*指针作为通用句柄的定义。
 *理论上以隐藏结构体内部实现为目的，任何类型的指针都可以作为句柄使用。
 */

#ifndef _POINT_H
#define _POINT_H

typedef int data_t;
typedef void* handle_t;                       //通用handle句柄可以使用void*指针表示，本程序中handle_t用于标记Point对象的首地址
                                              //使用handle_t句柄，可以实现Point结构体信息的隐藏。

handle_t createPoint(data_t x,data_t y);      //获取Point对象的操作句柄。
void destroyPoint(handle_t* handle);          //销毁句柄指向的Point对象。

void setX(handle_t handle,const data_t x);
data_t getX(const handle_t handle);

void setY(handle_t handle,const data_t y);
data_t getY(const handle_t handle);

void display(const handle_t handle);

#endif //_POINT_H
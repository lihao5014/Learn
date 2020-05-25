//使用数字作为Employee结构体的句柄，类型于Linux的文件描述符fp

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

int createEmployee(const char* name,int num);        //创建雇员对象，返回雇员结构体句柄
void destroyEmployee(int handle);                    //通过雇员句柄，销毁雇员对象

void setName(int handle,const char* name);           //通过雇员句柄，设置雇员名字
const char* getName(int handle);                     //通过雇员句柄，获取雇员名字

void setNum(int handle,int num);
int getNum(int handle);

void showEmployee(int handle);

#endif //_EMPLOYEE_H
#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include "handle.h"

DECLARE_HANDLE(HEmployee);

HEmployee createEmployee(const char* name,int num);            //创建雇员对象，返回雇员结构体句柄
void destroyEmployee(HEmployee *hemployee);                    //通过雇员句柄，销毁雇员对象

void setName(HEmployee hemployee,const char* name);            //通过雇员句柄，设置雇员名字
const char* getName(HEmployee hemployee);                      //通过雇员句柄，获取雇员名字

void setNum(HEmployee hemployee,int num);
int getNum(HEmployee hemployee);

void showEmployee(HEmployee hemployee);

#endif //_EMPLOYEE_H
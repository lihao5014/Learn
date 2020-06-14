#ifndef _MAX_H
#define _MAX_H

typedef char BOOL;
#define TRUE 1
#define FALSE 0

extern const char* strBool[];

typedef int data_t;

extern BOOL isMax(data_t x,data_t y);                  //判断x是否比y大
extern data_t max(data_t x,data_t y);                  //获取两个数中的最大值
extern data_t Max(data_t x,data_t y,data_t z);         //获取三个数中的最大值

extern BOOL isMin(data_t x,data_t y);                  //判断x是否比y小
extern data_t min(data_t x,data_t y);                  //获取两个数中的最小值       
extern data_t Min(data_t x,data_t y,data_t z);         //获取三个数中的最小值

#endif //_MAX_H
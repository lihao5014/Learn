#ifndef _VECTOR_H
#define _VECTOR_H

#define SIZE 2
#define EPS 0.000001

typedef enum BOOL
{
	FALSE = 0,
	TRUE = 1
}BOOL;

typedef int data_t;
typedef data_t vector_t[SIZE];

extern BOOL vectorInit(vector_t *pvector,data_t x,data_t y);
extern data_t vectorX(const vector_t vector);
extern data_t vectorY(const vector_t vector);

extern BOOL vectorAdd(const vector_t vector1,const vector_t vector2,vector_t *ret);
extern BOOL vectorSub(const vector_t vector1,const vector_t vector2,vector_t *ret);
extern data_t vectorMult(const vector_t vector1,const vector_t vector2);

extern void printVector(const vector_t vector);

#endif //_VECTOR_H
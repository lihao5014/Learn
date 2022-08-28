#ifndef _POINT_H_
#define _POINT_H_

#include "common.h"

//�����Point�ṹ���൱��һ��handle�������������struct��ʵ�֡�
typedef struct
{
	void* m_placeholder;
}Point;

extern Point* createPoint(data_t x,data_t y);
extern void destroyPoint(Point** pPointPtr);

extern void setPointX(Point* pointPtr,const data_t x);
extern data_t getPointX(const Point* pointPtr);

extern void setPointY(Point* pointPtr,const data_t y);
extern data_t getPointY(const Point* pointPtr);

extern void displayPoint(const Point* pointPtr);

#endif //_POINT_H_
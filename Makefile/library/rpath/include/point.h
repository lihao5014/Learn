#ifndef _POINT_H_
#define _POINT_H_

typedef struct Point_t
{
	int m_x;
	int m_y;
}Point,*PointPtr;

PointPtr createPoint(data_t x,data_t y);
void destroyPoint(PointPtr* pppoint);

void setPointX(PointPtr ppoint,const data_t x);
data_t getPointX(const PointPtr ppoint);

void setPointY(PointPtr ppoint,const data_t y);
data_t getPointY(const PointPtr ppoint);

void showPoint(const PointPtr ppoint);

#endif //_POINT_H_
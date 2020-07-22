#include "point.h"
#include "line.h"
#include "plane.h"
#include "cube.h"

int main(void)
{
	Point point(4,5);
	std::cout<<point<<std::endl;
	
	cout<<"please input a point:"<<endl;
	std::cin>>point;
	point.print();
	
	Line line(Point(1,1),Point(3,3));
	line.display();
	
	line.setPoint(Point(5,5),LINE_POINT_END);
	line.display();
	cout<<line.getPoint(LINE_POINT_START)<<endl;
	
	Plane plane(Point(0,0),Point(0,1),Point(1,0));
	plane.show();
	
	plane.setPoint(Point(0,2),PLANE_POINT_B);
	plane.show();
	
	const Point pointArr[PLANE_POINT_COUNT] = {Point(1,1),Point(2,2),Point(3,3)};
	plane.setAllPoints(pointArr,sizeof(pointArr) / sizeof(Point));
	plane.show();
	
	vector<Point> points = plane.allPoints();
	for(auto& tempPoint: points)
	{
		cout<<tempPoint<<" , ";
	}
	cout<<endl;
	
	Cube cube;
	cube.detail();
	
	cube.setPoint(Point(3,3),CUBE_POINT_B);
	cube.setPoint(Point(4,4),CUBE_POINT_C);
	cube.detail();
	
	array<Point,CUBE_POINT_COUNT> pointArray = {Point(1,6),Point(2,7),Point(3,8),Point(4,9)};
	cube.setAllPoints(pointArray);
	cube.detail();
	
	return 0;
}
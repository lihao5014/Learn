#include "common.h"

int main(void)
{
	Vector2D vec2d_x = {4,5};
	displayVector2D(vec2d_x);
	
	Vector2D vec2d_y = {3,2};
	Vector2D vec2d_ret = {0,0};
	addVector2D(vec2d_x,vec2d_y,vec2d_ret);
	displayVector2D(vec2d_ret);
	
	subVector2D(vec2d_x,vec2d_y,vec2d_ret);
	displayVector2D(vec2d_ret);
	
	int num = dotProductVector2D(vec2d_x,vec2d_y);
	printf("num =%d\n",num);
	
	puts("");
	
	Vector3D vec3d_x = {7,8,9};
	displayVector3D(vec3d_x);
	
	Vector3D vec3d_y = {3,2,1};
	Vector3D vec3d_ret = {0,0,0};
	addVector3D(vec3d_x,vec3d_y,vec3d_ret);
	displayVector3D(vec3d_ret);
	
	subVector3D(vec3d_x,vec3d_y,vec3d_ret);
	displayVector3D(vec3d_ret);
	
	num = dotProductVector3D(vec3d_x,vec3d_y);
	printf("num =%d\n",num);
	
	return 0;
}
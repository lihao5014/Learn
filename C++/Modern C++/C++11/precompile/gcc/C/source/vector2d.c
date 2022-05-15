#include <stdio.h>
#include <assert.h>
#include "vector2d.h"

void displayVector2D(const Vector2D vec)
{
	if(vec == NULL)
	{
		return;
	}
	printf("(%d,%d)\n",vec[0],vec[1]);
}

bool addVector2D(const Vector2D vec1,const Vector2D vec2,Vector2D retVec)
{
	if(vec1 == NULL || vec2 == NULL || retVec == NULL)
	{
		return false;
	}
	
	retVec[0] = vec1[0] + vec2[0];
	retVec[1] = vec1[1] + vec2[1];
	return true;
}

bool subVector2D(const Vector2D vec1,const Vector2D vec2,Vector2D retVec)
{
	if(vec1 == NULL || vec2 == NULL || retVec == NULL)
	{
		return false;
	}
	
	retVec[0] = vec1[0] - vec2[0];
	retVec[1] = vec1[1] - vec2[1];
	return true;
}

int dotProductVector2D(const Vector2D vec1,const Vector2D vec2)
{
	assert(vec1 != NULL && vec2 != NULL);
	return vec1[0] * vec2[0] + vec1[1] * vec2[1];
}

bool crossProductVector2D(const Vector2D vec1,const Vector2D vec2,Vector3D retVec)
{
	if(vec1 == NULL || vec2 == NULL || retVec == NULL)
	{
		return false;
	}
	
	retVec[0] = 0;
	retVec[1] = 0;
	retVec[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
}
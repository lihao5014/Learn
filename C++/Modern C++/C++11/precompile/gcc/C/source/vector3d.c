#include <stdio.h>
#include <assert.h>
#include "vector3d.h"

void displayVector3D(const Vector3D vec)
{
	if(vec == NULL)
	{
		return;
	}
	printf("(%d,%d,%d)\n",vec[0],vec[1],vec[2]);
}

bool addVector3D(const Vector3D vec1,const Vector3D vec2,Vector3D retVec)
{
	if(vec1 == NULL || vec2 == NULL || retVec == NULL)
	{
		return false;
	}
	
	for(int i=0;i<THREE_DIM;++i)
	{
		retVec[i] = vec1[i] + vec2[i];
	}
	return true;
}

bool subVector3D(const Vector3D vec1,const Vector3D vec2,Vector3D retVec)
{
	if(vec1 == NULL || vec2 == NULL || retVec == NULL)
	{
		return false;
	}
	
	for(int i=0;i<THREE_DIM;++i)
	{
		retVec[i] = vec1[i] - vec2[i];
	}
	return true;
}

int dotProductVector3D(const Vector3D vec1,const Vector3D vec2)
{
	assert(vec1 != NULL && vec2 != NULL);
	
	int ret = 0;
	for(int i=0;i<THREE_DIM;++i)
	{
		ret += vec1[i] * vec2[i];
	}
	return ret;
}

bool crossProductVector3D(const Vector3D vec1,const Vector3D vec2,Vector3D retVec)
{
	if(vec1 == NULL || vec2 == NULL || retVec == NULL)
	{
		return false;
	}
	
	retVec[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
	retVec[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
	retVec[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
}

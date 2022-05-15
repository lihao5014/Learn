#ifndef _VECTOR_3D_H_
#define _VECTOR_3D_H_

#include <stdbool.h>

#define THREE_DIM 3

typedef int Vector3D[THREE_DIM];

void displayVector3D(const Vector3D vec);

bool addVector3D(const Vector3D vec1,const Vector3D vec2,Vector3D retVec);
bool subVector3D(const Vector3D vec1,const Vector3D vec2,Vector3D retVec);

int dotProductVector3D(const Vector3D vec1,const Vector3D vec2);
bool crossProductVector3D(const Vector3D vec1,const Vector3D vec2,Vector3D retVec);

#endif  //_VECTOR_3D_H_
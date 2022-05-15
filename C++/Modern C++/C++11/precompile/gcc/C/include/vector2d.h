#ifndef _VECTOR_2D_H_
#define _VECTOR_2D_H_

#include <stdbool.h>
#include "vector3d.h"

#define TWO_DIM 2

typedef int Vector2D[TWO_DIM];

void displayVector2D(const Vector2D vec);

bool addVector2D(const Vector2D vec1,const Vector2D vec2,Vector2D retVec);
bool subVector2D(const Vector2D vec1,const Vector2D vec2,Vector2D retVec);

int dotProductVector2D(const Vector2D vec1,const Vector2D vec2);
bool crossProductVector2D(const Vector2D vec1,const Vector2D vec2,Vector3D retVec);

#endif  //_VECTOR_2D_H_

#include "vector.h"
#include <stdio.h>

int main(void)
{
	vector_t vec1 = {1,2};
	printVector(vec1);
	
	vector_t vec2;
	vectorInit(&vec2,3,4);
	printVector(vec2);
	
	vector_t vec3;
	vectorAdd(vec1,vec2,&vec3);
	printVector(vec3);
	
	vectorSub(vec1,vec2,&vec3);
	printVector(vec3);
	
	data_t ret = vectorMult(vec1,vec2);
	fprintf(stdout,"ret =%d\n",ret);
	
	printf("(%d,%d)\n",vectorX(vec3),vectorY(vec3));

	return 0;
}
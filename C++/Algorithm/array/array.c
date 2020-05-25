#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.H>
#include <string.h>

Array* Array_Ctor(Array* array,const int size)
{
	if(array == NULL || size <= 0){
		printf("Array_Ctor error: array = NULL or size is illegal\n");
		return NULL;
	}
	
	data_t *addr = (data_t*)malloc(sizeof(data_t)*size);
	if(addr == NULL){
		printf("Array_Ctor warn: malloc addr failed\n");
		return NULL;
	}
	memset(addr,0,sizeof(data_t)*size);
	array->size = size;
	array->addr = addr;
	
	return array;
}

void Array_Dtor(Array* array)
{
	if(array == NULL || array->addr == NULL){
		printf("Array_Dtor warn; array = NULL or array->addr = NULL\n");
		return ;
	}
	
	free(array->addr);
	array->addr = NULL;
}

Array* initArray(Array* array,const data_t n)
{
	if(array == NULL || array->addr == NULL){
		printf("initArray warn: array = NULL or array->addr = NULL\n");
		return NULL;
	}
	
	for(int i=0;i<array->size;++i){
		*(array->addr+i) = n;
	}
	return array;
}

void clearArray(Array* array)
{
	if(array == NULL || array->addr == NULL){
		printf("initArray warn: array = NULL or array->addr = NULL\n");
		return ;
	}
	
	memset(array->addr,0,sizeof(data_t)*array->size);
}

int getSize(const Array* array)
{
	if(array == NULL){
		printf("getSize warn; array = NULL\n");
		return -1;
	}
	
	return array->size;
}

Array* reSize(Array* array,const int size)
{
	if(array == NULL || size <= 0){
		printf("reSize warn; array = NULL or size <= 0\n");
		return NULL;
	}
	
	if(size == array->size){
		return array;
	}
	
	data_t* addr = (data_t*)malloc(sizeof(data_t)*size);
	if(addr == NULL){
		printf("reSize warn: malloc addr failed\n");
		return NULL;	
	}
	memset(addr,0,sizeof(data_t)*size);
	
	if(array->addr != NULL){
		if(size >= array->size){
			memcpy(addr,array->addr,sizeof(data_t)*array->size);
		}else{
			memcpy(addr,array->addr,sizeof(data_t)*array->size);
		}

		free(array->addr);
		array->addr = NULL;
	}
	array->size = size;
	array->addr = addr;

	return array;
}

data_t at(const Array* array,const int index)
{
	assert(array != NULL && array->addr != NULL 
		&& index >= 0 && index < array->size);
	
	return *(array->addr+index);
}

bool setData(Array* array,const int index,const data_t data)
{
	if(array == NULL || array->addr == NULL || index < 0 ||index >= array->size){
		printf("setData warn; array = NULL or array->addr = NULL or index is illegal\n");
		return false;
	}
	
	*(array->addr+index) = data;
	return true;
}

int findData_L(const Array* array,const data_t data)
{
	if(array == NULL || array->addr == NULL){
		printf("findData_L warn; array = NULL or array->addr = NULL\n");
		return -1;
	}
	
	for(int i=0;i<array->size;++i){
		if(*(array->addr+i) == data){
			return i;
		}
	}
	
	return -1;
}

int findData_R(const Array* array,const data_t data)
{
	if(array == NULL || array->addr == NULL){
		printf("findData_R warn; array = NULL or array->addr = NULL\n");
		return -1;
	}
	
	for(int i=array->size-1;i>=0;--i){
		if(*(array->addr+i) == data){
			return i;
		}		
	}
	
	return -1;
}

bool deleteData(Array* array,const data_t data)
{
	if(array == NULL || array->addr == NULL){
		printf("deleteData warn; array = NULL or array->addr = NULL\n");
		return false;
	}
	
	if(0 == data){
		return true;
	}
	
	int index = 0;
	bool flag = false;
	for(int i=0;i<array->size;++i){
		index = findData_L(array,data);
		if(index != -1){
			setData(array,index,0);
			flag = true;
			continue;
		}
		return flag;
	}
	
	return flag;
}

bool changeData(Array* array,const data_t n,const data_t data)
{
	if(array == NULL || array->addr == NULL){
		printf("deleteData warn; array = NULL or array->addr = NULL\n");
		return false;
	}
	
	int index = 0;
	bool flag = false;
	for(int i=0;i<array->size;++i){
		index = findData_L(array,n);
		if(index != -1){
			setData(array,index,data);
			flag = true;
			continue;
		}
		return flag;
	}
	
	return flag;
}

void displayArray(const Array* array)
{
	if(array == NULL || array->addr == NULL){
		printf("displayArray warn; array = NULL or array->addr = NULL\n");
		return ;
	}
	
	for(int i=0;i<array->size;++i){
		printf("%d ",*(array->addr+i));
	}
	printf("\n");
}

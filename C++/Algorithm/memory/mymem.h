#ifndef _MYMEM_H
#define _MYMEM_H

typedef int data_t;

void* myMemset(void* dst,data_t data,unsigned int size);
void* myMemcpy(void* dst,const void* src,unsigned int size);				
void* myMemccpy(void* dst,const void* src,data_t data,unsigned int size);
void* myMemmove(void* dst,const void* src,unsigned int size);
void* myMemchr(const void* src,data_t data,unsigned int size);
int myMemcmp(const void* src1,const void* src2,unsigned int size);

void* getMemory(void** dst,unsigned int size);
void myFree(void** dst);

#endif  //_MEM_H
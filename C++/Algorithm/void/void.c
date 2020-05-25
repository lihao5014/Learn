/* 
1. void即“无类型”，void*则为“无类型指针”，可以指向任何数据类型。
2. void指针可以指向任意类型的数据，即可用任意数据类型的指针对void指针赋值。
3. void指针可以赋值给任何类型的变量，但是需要进行强制转换。void*在转换为其他数据类型时，
   赋值给void*的类型和目标类型必须保持一致。
4. 在ANSIC标准中，不允许对void指针进行算术运算如pvoid++或pvoid+=1等，
   而在GNU中则允许，因为在缺省情况下GNU认为void*与char*一样。sizeof(*pvoid)==sizeof(char)。
*/

/*
void的作用：
①对函数返回的限定。当函数不需要返回值时，必须使用void限定。例如：void func(int, int)。
②对函数参数的限定。当函数不允许接受参数时，必须使用void限定，缺省是默认值也是void。例如：int func(void)。
③由于void指针可以指向任意类型的数据，亦即可用任意数据类型的指针对void指针赋值，因此还可以用void指针来作为函数形参，
  这样函数就可以接受任意数据类型的指针作为参数。例如：void* memcpy( void *dest, const void *src, size_t len)。
*/

#include <stdio.h>

int main(void)
{
	char chr = 'a';
	int num = 10;
	double val = 3.14;
	
	void *p = NULL;
	
	p = &chr;
	printf("chr =%d, *(char*)p =%d\n",chr,*(char*)p);
	printf("sizeof(char) =%d, sizeof(p) =%d, sizeof(*(char*)p) =%d\n",
		sizeof(char),sizeof(p),sizeof(*(char*)p));
	
	printf("chr =%d, *(int*)p =%d\n",chr,*(int*)p);
	printf("sizeof(int) =%d, sizeof(p) =%d, sizeof(*(int*)p) =%d\n",
		sizeof(char),sizeof(p),sizeof(*(int*)p));
	
	p = &num;
	printf("num =%d, *(int*)p =%d\n",num,*(int*)p);
	printf("sizeof(int) =%d, sizeof(p) =%d, sizeof(*(int*)p) =%d\n",
		sizeof(int),sizeof(p),sizeof(*(int*)p));
	
	printf("num =%d, *(char*)p =%d\n",num,*(char*)p);
	printf("sizeof(int) =%d, sizeof(p) =%d, sizeof(*(char*)p) =%d\n",
		sizeof(int),sizeof(p),sizeof(*(char*)p));

	
	p = &val;
	printf("val =%f, *(double*)p =%f\n",val,*(double*)p);
	printf("sizeof(double) =%d, sizeof(p) =%d, sizeof(*(double*)p) =%d\n",
		sizeof(double),sizeof(p),sizeof(*(double*)p));
		
	printf("val =%f, *(int*))p =%f\n",val,*(int*)p);
	printf("sizeof(double) =%d, sizeof(p) =%d, sizeof(*(int*)p) =%d\n",
		sizeof(double),sizeof(p),sizeof(*(int*)p));	
		
	char *q = NULL;
	
	q = &chr;
	printf("chr =%d, *q =%d\n",chr,*q);
	
/*	q = &num;
	printf("num =%d, *q =%d\n",num,*q);
	
	q = &val;
	printf("num =%d, *q =%f\n",val,*q);
*/
	return 0;
}
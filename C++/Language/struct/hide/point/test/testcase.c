#include "point.h"
#include "minunit.h"
#include <stdlib.h>

#define _ERROR_
#undef _ERROR_

#define FREE(ptr)                 \
	do{                           \
		if((ptr) != NULL)         \
		{                         \
			free(ptr);            \
			ptr = NULL;           \
		}                         \
	}while(0)

int tests_run = 0;

static char* test_point_ctor()
{
	Point* ppoint = point_ctor(3,4);
	mu_assert("error, point_ctor can't create point handle",ppoint != NULL);
	
	FREE(ppoint);
	return NULL;
}

static char* test_point_dtor()
{
	Point* ppoint = point_ctor(3,4);
	point_dtor(&ppoint);
	mu_assert("error, point_dtor can't destroy point object",ppoint == NULL);
	
	FREE(ppoint);
	return NULL;
}

static char* test_getX()
{
	Point* ppoint = point_ctor(3,4);
	data_t x = getX(ppoint);
	mu_assert("error getX(ppoint), x and 3 is unequal",x == 3);
	
	FREE(ppoint);
	return NULL;		
}

static char* test_setX()
{
	Point* ppoint = point_ctor(3,4);
	setX(ppoint,10);

    //因为point.h头文件中隐藏了Point结构体的实现，所以不能直接使用Point类型指针，访问Point结构体成员
#ifdef _ERROR_
	mu_assert("error setX(ppoint,10), x and 10 is unequal",ppoint->x == 10);
#else
	mu_assert("error setX(ppoint,10), x and 10 is unequal",getX(ppoint) == 10);
#endif
	
	FREE(ppoint);
	return NULL;	
}

static char* test_getY()
{
	Point* ppoint = point_ctor(3,4);
	data_t y = getY(ppoint);
	mu_assert("error getY(ppoint), y and 4 is unequal",y == 4);
	
	FREE(ppoint);
	return NULL;		
}

static char* test_setY()
{
	Point* ppoint = point_ctor(3,4);
	setY(ppoint,20);

    //因为point.h头文件中隐藏了Point结构体的实现，所以不能直接使用Point类型指针，访问Point结构体成员
#ifdef _ERROR_
	mu_assert("error setX(ppoint,20), y and 20 is unequal",ppoint->y == 20);
#else
	mu_assert("error setX(ppoint,20), y and 20 is unequal",getY(ppoint) == 20);
#endif
	
	FREE(ppoint);
	return NULL;	
}


static char* all_tests()
{
	mu_run_test(test_point_ctor);
	mu_run_test(test_point_dtor);
	mu_run_test(test_setX);
	mu_run_test(test_getX);
	mu_run_test(test_setY);
	mu_run_test(test_getY);
	
	return NULL;
}

int main(void)
{
	const char* result = all_tests();
	if(result != NULL)
	{
		printf("%s\n",result);
	}
	else
	{
		puts("all tests passed");
	}
	printf("tests run: %d\n",tests_run);
	
	return 0;
}
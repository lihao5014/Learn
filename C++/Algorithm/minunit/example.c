#include "minunit.h"

int tests_run = 0;

static int foo = 7;
static int bar = 4;

static char* test_foo()
{
	mu_assert("error, foo != 7",foo == 7);
	return NULL;
}

static char* test_bar()
{
	mu_assert("error, bar != 7",bar == 5);
	return NULL;
}

static char* all_tests()
{
	mu_run_test(test_foo);
	mu_run_test(test_bar);
	return NULL;
}

int main(void)
{
	char* result = all_tests();
	if(result != NULL)
	{
		printf("%s\n",result);
	}
	else
	{
		puts("all tests passed");
	}
	printf("tests run: %d\n",tests_run);
	
	return result != NULL;
}
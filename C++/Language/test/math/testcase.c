#include "math.h"
#include "minunit.h"

int tests_run = 0;

static char* test_add()
{
	mu_assert("error, 1 + 2 != 3",add(1,2) == 3);
	return NULL;
}

static char* test_sub()
{
	mu_assert("error, 7 + 5 != 2",sub(7,5) == 2);
	return NULL;
}

static char* test_mult()
{
	double ret = mult(4,5);
	mu_assert("error, 4 * 5 != 20",ret == 20);
	return NULL;
}

static char* test_divi()
{
	double ret = divi(16,4);
	mu_assert("error, 16 / 4 != 4",ret == 4);
	return NULL;
}

static char* all_tests()
{
	mu_run_test(test_add);
	mu_run_test(test_sub);
	mu_run_test(test_mult);
	mu_run_test(test_divi);
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
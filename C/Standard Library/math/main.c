#include <stdio.h>
#include <stdlib.h>    //abs()
#include <math.h>      //fabs(),sin(),cos(),tan(),sqrt(),pow(),log10(),log(),exp()

#define PI 3.14159

//abs()函数在stdlib.h头文件中，而fabs()函数在math.h头文件中
static void abs_test();
static void fabs_test();

static void sin_test();
static void cos_test();
static void tan_test();

static void sqrt_test();
static void pow_test();

static void log10_test();
static void log_test();

static void modf_test();

int main(void)
{
	abs_test();
	fabs_test();

	sin_test();
	cos_test();	
	tan_test();
	
	sqrt_test();
	pow_test();
	
	log10_test();
	log_test();
	
	modf_test();
}

void abs_test()
{
	fprintf(stdout,"abs(-2) =%d\n",abs(-2));
	fprintf(stdout,"abs(-5) =%d\n",abs(-5));
}

void fabs_test()
{
	fprintf(stdout,"fabs(-0.618) =%f\n",fabs(-0.618));
	fprintf(stdout,"fabs(-2.71828) =%f\n",fabs(-2.71828));
}

void sin_test()
{
	printf("sin(PI/6) = %f\n",sin(PI/6));
	printf("sin(PI/4) = %f\n",sin(PI/4));
	printf("sin(PI/3) = %f\n",sin(PI/3));
}

void cos_test()
{
	printf("cos(PI/6) = %f\n",cos(PI/6));
	printf("cos(PI/4) = %f\n",cos(PI/4));
	printf("cos(PI/3) = %f\n",cos(PI/3));
}

void tan_test()
{
	printf("tan(PI/6) = %f\n",tan(PI/6));
	printf("tan(PI/4) = %f\n",tan(PI/4));
	printf("tan(PI/3) = %f\n",tan(PI/3));
}

void sqrt_test()
{
	printf("sqrt(2) = %f\n",sqrt(2));
	printf("sqrt(4) = %f\n",sqrt(4));
	printf("sqrt(9) = %f\n",sqrt(9));
}

void pow_test()
{
	printf("pow(2,3) = %f\n",pow(2,3));
	printf("pow(4,0.5) = %f\n",pow(4,0.5));
	printf("pow(3,2) = %f\n",pow(3,2));
}

void log10_test()
{
	fprintf(stdout,"log10(10) =%f\n",log10(10));
	fprintf(stdout,"log10(100) =%f\n",log10(100));
	fprintf(stdout,"log10(1000) =%f\n",log10(100));
}

void log_test()
{
	fprintf(stdout,"log(2.17828) =%f\n",log(2.17828));
}

void modf_test()
{
	double intpart = 0;
	double fractpart = modf(3.1415,&intpart);
	printf("3.1415: intpart =%f ,fractpart =%f\n",intpart,fractpart);
}
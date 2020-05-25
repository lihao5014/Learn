#ifndef _MATH_H
#define _MATH_H

#define EPS 0.000001

typedef enum BOOL
{
	FALSE,
	TRUE
}BOOL;

typedef enum Option_t
{
	ADD = '+',
	SUB = '-',
	MULT = '*',
	DIVI = '/',
	MAX = '<',
	MIN = '>'
}Option;

double add(double x,double y);
double sub(double x,double y);
double mult(double x,double y);
double divi(double x,double y);
double max(double x,double y);
double min(double x,double y);

#endif //_MATH_H
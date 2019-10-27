#include <stdio.h> // printf
#include <stdlib.h> // atof
#include <math.h> // fabs
#include <stdbool.h> // bool

#define EPSILON 0.000001

double f(double x, double a)
{
	return x*x - a;
}

bool too_big(double x)
{
	return fabs(x) > EPSILON;
}

bool too_far(double x, double y)
{
	return fabs( (x-y)/y ) > EPSILON;
}

int main(int argc, char *argv[])
{
	double a = atof(argv[1]);
	double prev = 1.0;
	double nxt = 1.0;
	int i;
	for (i=0 ; i<50 && ( too_big(f(nxt, a)) || too_far(nxt, prev) ) ; ++i)
	{
		prev = nxt;
		nxt = (prev + a/prev)/2;
		printf("x_%d: %.40f\n", i, prev);
	}
	printf("-------------------------------\n"
		"x_%d: %.40f\n", i, nxt);
}

#include <stdio.h> // printf
#include <stdbool.h>
#include <math.h> // fabs, pow

#define EPSILON 0.0000001

bool too_big(double x)
{
	return fabs(x) > EPSILON;
}

bool too_far(double x, double y)
{
	return fabs( (x-y)/y ) > EPSILON;
}

double f1(double x) // (x+3)(x-2)(x-4)^3
{
	return (x+3)*(x-2)*pow(x-4, 3.0);
}

double f1_prime(double x)
{
	return pow(x-4, 2.0)*(5*x*x - 4*x - 22);
}

double f2(double x) // (x-1)^2(x-2)^4(x-3)
{
	return pow(x-1, 2.0)*pow(x-2, 4.0)*(x-3);
}

double f2_prime(double x)
{
	return pow(x-2, 3.0)*(7*pow(x, 3.0) - 36*pow(x, 2.0) + 55*x - 26);
}
int main()
{
	double (*f)(double) = f2;
        double (*f_prime)(double) = f2_prime;
        const int r = 3;
	double nxt = 1.0;
	double prev = nxt;
	int i;
	for (i=0 ; i<50 && (too_big(f(nxt)) || too_far(nxt, prev)) ; ++i)
	{
		prev = nxt;
		nxt = prev - r*f(prev)/f_prime(prev);
		printf("x_%d: %.40f\n", i, prev);
	}
	printf("--------------------------\n"
		"x_%d: %.40f\n", i, nxt);
}

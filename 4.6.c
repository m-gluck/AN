#include <stdio.h> // printf
#include <stdlib.h> // atof
#include <math.h> // fabs

#define EPSILON 0.000001

double f(double x, double a)
{
	return 1.0/(x*x) - a;
}

int main(int argc, char *argv[])
{
	const double a = atof(argv[1]);
	double prev = 0.25;
	double nxt = 0.25;
	int i;
	for (
		i=0;

		i<50 &&
		(fabs(f(nxt, a)) > EPSILON
		||
		fabs( (nxt-prev)/prev ) > EPSILON);

		++i
	)
	{
		prev = nxt;
		nxt = 0.5*prev*(3 - a*prev*prev);
		printf("nxt: %.40f\n", nxt);
	}
	printf("--------------------------\n"
		"x_%d = %.40f\n", i, nxt);
}

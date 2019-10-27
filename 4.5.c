#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	double r = atof(argv[1]);
	double x_n = atof(argv[2]);
	double real = 1.0/r;
	long i;
	for (i=0 ; x_n != real ; ++i)
		x_n = x_n*(2 - x_n*r);
	printf(
		"result: %.20f\n"
		"i: %ld\n",
		x_n, i
	);
}

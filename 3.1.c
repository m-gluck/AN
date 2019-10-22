#include <stdio.h>
#include <math.h>

float f1(float x)
{
	float cosx = cosf(x);
	return 4*(cosx*cosx) - 3;
}

float f2(float x)
{ return 2*cos(2*x) - 1; }

int main()
{
	for (float x = M_PI/6-50.0/2097152.0 ; x<=M_PI/6+5.0/2097152.0 ; x += 1.0/2097152.0)
		printf("%e\t%e\n", f1(x), f2(x));
}

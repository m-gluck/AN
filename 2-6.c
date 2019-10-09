#include <stdio.h>
#include <math.h>

double f(double x)
{
	double x11 = pow(x, 11.0);
	return 4038*( (sqrt(x11 + 1) - 1)/x11 );
}

double f2(double x)
{ return 4038.0/( sqrt( pow(x, 11.0)+1 )+1 ); }
int main()
{
	double fx = f(0.01);
	printf("f(0.01)=%.308f\n%d\nf2(0.01)=%.308f\n", fx, fx==0.0, f2(0.01));
}

#include <stdio.h>
#include <math.h>

#define P 0.22533347738339494

double f(double x)
{
	return x*x - 2*x - atan(7*x-2);
}

int main()
{
	double a_n = 0.0;
	double b_n = 1.0;
	for (int n=0 ; n<16 ; ++n)
	{
		printf("[%.20f ; %.20f]\n", a_n, b_n);
		double m_n = (b_n+a_n)/2.0;
		if (f(m_n) > 0)
			a_n = m_n;
		else
			b_n = m_n;
	}
	puts("--------------------------------------------");
	double result = (a_n+b_n)/2.0;
	printf(
		"result: %.30f\n"
		"P: %.30f\n"
		"fabs(result-P)<=pow(10.0, -5.0): %d\n"
		"f(result): %.30f\n"
		"f(P): %.30f\n",
		result, P, fabs(result-P)<=pow(10.0, -5.0), f(result), f(P)
	);
	
}

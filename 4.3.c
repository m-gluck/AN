#include <stdio.h>
#include <math.h>

#define A 0.0646926359947960

double f(double x)
{
	return x*exp(-x) - 0.06064;
}

int main()
{
	
	double a_n=0.0, b_n=1.0;
	for (int n=0 ; n<=15 ; ++n)
	{
		double m_n = (b_n+a_n)/2;
		double err_est = pow(2.0, -n-1);
		double err_real = A-m_n;
		printf("real: %+.56f\testimate: %.18f\testimating error: %.20f\n",
			err_real, err_est, err_est/err_real - 1);
		if (f(m_n) > 0)
			b_n = m_n;
		else
			a_n = m_n;
	}
}

#include <stdio.h>
#include <math.h>

double f(double x)
{
	return (
		sin(x) - x + pow(x, 3.0)/6.0 - pow(x, 5.0)/120.0
		) / pow(x, 7.0);
}

int main()
{  
	for (double x=1.0 ; x > pow(2, -50.0) ; x/=2)
	{
		printf("%e\n", f(x)*5040.0+1.0); // błąd względny granicy w 0
	}
}

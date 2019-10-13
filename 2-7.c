#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328

int main()
{
	double x = 2.0;
	double y = 2.0;
	double p = 2.0;
	for (int i=1 ; i<=50 ; ++i)
	{
		printf("%e\t%e\n", x/PI-1, y/PI-1);
		x = p*sqrt(2*(1-sqrt(1-pow(x/p, 2.0))));
		y = p*sqrt(2*(pow(y/p, 2.0)/(1+sqrt(1-pow(y/p,2.0)))));
		p *= 2.0;
	}
}

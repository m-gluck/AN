#include <stdio.h>
#include <math.h>

int main()
{
	double x = 2.0;
	double y = 2.0;
	long pot = 2; // 2^k
	for (int i=1 ; i<50 ; ++i) // wyrazy x_2-x_50
	{
		double tx = x/pot;
		tx *= tx; // t = (x / 2^k)^2
		x = pot*sqrt(
			2.0*(
				1.0 - sqrt(1.0 - tx)
			)
		);

		double ty = y/pot;
		ty *= ty;
		y = pot*sqrt(
			2.0*(
				ty
				/
				(1 + sqrt(1-ty))
			)
		);
		pot *= 2;
		printf("x_%d: %f | y_%d: %f\n\n", i+1, x, i+1, y);
	}
}

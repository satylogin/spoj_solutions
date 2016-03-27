#include <stdio.h>
#include <cmath>

int main()
{
	float a, b, x, y;
	scanf("%f%f", &a, &b);
	x = ((a - 4) + sqrt((a-4) * (a-4) - 16 * b)) / 4;
	x = x + 2;
	y = (a + b) / x;
	if (x >= y) {
		printf("%.0f %.0f\n", x, y);
	} else {
		printf("%.0f %.0f\n", y, x);
	}
	return 0;
}

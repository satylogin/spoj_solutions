#include <stdio.h>
#include <cmath>

int main()
{
	int t, n, i; scanf("%d", &t);
	float result;
	for ( ; t; t--) {
		scanf("%d", &n);
		result = n;
		for (i = 2; i*i <= n; i++) {
			if ((n % i) == 0) {
				result = result - result/i;
			}
			while((n % i) == 0) {
				n = n / i;
			}
		}
		if (n > 1) {
			result = result - result/n;
		}
		printf("%.0f\n", result);
	}
	return 0;
}

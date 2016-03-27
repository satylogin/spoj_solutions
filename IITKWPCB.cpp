#include <stdio.h>

int main()
{
	int t, i; scanf("%d", &t);
	long long int n, x;

	for (i = 0; i < t; i++) {
		scanf("%lld", &n);
		if (n % 2 == 0) {
			x = n / 2;
			if (x % 2 == 0) {
				x = x - 1;
			} else {
				x = x - 2;
			}
			printf("%lld\n",x);
		} else {
			printf("%lld\n",n/2);
		}
	}

	return 0;
}

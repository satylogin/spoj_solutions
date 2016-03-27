#include <stdio.h>

int main()
{
	int t, n, i, j, tmp, k, count;
	scanf("%d", &t);
	for (; t; t--) {
		scanf("%d", &n);
		printf("%d\n", (n+1)/2);
	}
	return 0;
}

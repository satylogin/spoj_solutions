#include <stdio.h>
#include <stdlib.h>

int comp1(const void *a, const void *b)
{
	if (*((long long int*)a) > *((long long int*)b)){
	    return 1;
	} else {
	    return 0;
	}
}

int comp2(const void*a, const void *b)
{
	if (*((long long int*)b) > *((long long int*)a)){
	    return 1;
	} else {
	    return 0;
	}
}

int main()
{
	int n, i;
	long long int ans;
	scanf("%d", &n);
	while (n != 0) {
		long long int a[n], b[n];
		for (i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
		}
		for (i = 0; i < n; i++) {
			scanf("%lld", &b[i]);
		}
		qsort(a, n, sizeof(long long int), comp1);
		qsort(b, n, sizeof(long long int), comp2);
		ans = 0;
		for (i = 0; i < n; i++) {
			ans = ans + a[i]*b[i];
		}
		printf("%lld\n", ans);
		scanf("%d", &n);
	}
}

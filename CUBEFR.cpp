#include <stdio.h>

#define MAX 1000001

int cfn[MAX], set[MAX], m = 1;

void p()
{
	int i, j, k;
	for (i = 2; i*i*i < MAX; i++) {
		k = 1;
		for (j = i*i*i; j < MAX; j = i*i*i*k) {
			set[j] = 1;
			k++;
		}
	}

	for (i = 1; i < MAX; i++) {
		if (set[i] == 0) {
			cfn[i] = m++;
		}
	}
}

int main()
{
	p();
	int n, t, i;
	scanf("%d", &t);

	for (i = 1; i <= t; i++) {
		scanf("%d", &n);
		if (cfn[n] == 0) {
			printf("Case %d: Not Cube Free\n", i);
		} else {
			printf("Case %d: %d\n", i, cfn[n]);
		}
	}	

	return 0;
}

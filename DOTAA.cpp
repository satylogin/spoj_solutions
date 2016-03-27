#include <stdio.h>

int main()
{
	int t, n, m, i, j, d;
	scanf("%d", &t);

	for (; t; t--) {
		scanf("%d%d%d", &n, &m, &d);
		int hero[n];
		for (i = 0; i < n; i++) {
			scanf("%d", &hero[i]);
		}
		for (i = 0; i < n; i++) {
			while (hero[i] - d > 0) {
				hero[i] = hero[i] - d;
				m--;
			}
			if (m <= 0) break;
		}
		if (m <= 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}

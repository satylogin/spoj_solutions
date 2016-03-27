#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t; scanf("%d",&t);

	for (int i = 0; i < t; i++) {
		int n; scanf("%d",&n);
		int x, y = 1, flag = 0;

		while ((n - 5 * y) > 0) {
			if ((n - 5 * y) % 3 == 0) {
				flag = 1;
				break;
			}
			y++;
		}

		if (flag == 0) {
			printf("Case %d: -1\n\n", i + 1); 
		} else {
			printf("Case %d: %d\n\n", i + 1, n - 5 * y);
		}
	}
	
	return 0;
}

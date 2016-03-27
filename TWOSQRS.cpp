#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
	int t, flag;
	long long int n, x, y, tmp;
	scanf("%d", &t);
	for (; t; t--) {
		flag = 0;
		scanf("%lld", &n);
		for (x = 0; (n - x*x) > 0; x++) {
			tmp = n - (x*x);
			y = sqrt(tmp);
			if ((y*y) == tmp) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
int main()
{
	int t, num, len;
	long long int b, tmp;
	scanf("%d", &t);
	char x[1010];
	while (t--) {
		scanf("%s%lld", x, &b);
		len = strlen(x);
		num = x[len-1] - '0';
		if (x[0] == '0' && b == 0) {
			printf("0\n");
		} else if (b == 0) {
			printf("1\n");
		} else {
			tmp = b % 4;
			if (tmp == 0) {
				tmp = 4;
			}
			len = 1;
			while (tmp--) {
				len = len * num;
			}
			printf("%d\n", len % 10);
		}
	}
	return 0;
}

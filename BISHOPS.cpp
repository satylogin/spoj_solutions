#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	char str[2000];
	int num[2000], i, j, k;

	while (scanf("%s", str)	!= EOF) {
		if (str[0] == '0' && str[1] == '\0') {
			cout << 0 << endl;
		} else if (str[0] == '1' && str[1] == '\0') {
			cout << 1 << endl;
		} else {
			num[0] = 0;
			for (i = 0; str[i] != '\0'; ++i) {
				num[i+1] = str[i] - '0';
			}

			j = i; k = 0;
			while (j >= 0) {
				k = k + num[j] * 2;
				num[j--] = k % 10;
				k /= 10;
			}
			
			j = i;
			if (num[i] < 2) {
				while (1) {
					num[j] = num[j] + 10;
					num[j-1] = num[j-1] - 1;
					--j;
					if (num[j] >= 0) break;
				}
				num[i] = num[i] - 2;
			} else {
				num[i] = num[i] - 2;
			}

			if (num[0]) cout << num[0];
			for (j = 1; j <= i; ++j) {
				cout << num[j];
			}
			cout << endl;
		}
	}

	return 0;
}

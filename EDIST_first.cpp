#include <iostream>
#include <cstring>

using namespace std;

int ans[2101][2101];

int min(int a, int b, int c)
{
	int m = a;
	if (b < m) m = b;
	if (c < m) m = c;

	return m;
}

int main()
{
	int t, n, m, i, j, len1, len2;
	char str1[2101], str2[2102];

	cin >> t;

	for (; t; --t) {
		cin >> str1 >> str2;
		len1 = strlen(str1);
		len2 = strlen(str2);

		for (i = 0; i <= len1; ++i) {
			ans[i][0] = i;
		}

		for (j = 0; j <= len2; ++j) {
			ans[0][j] = j;
		}

		for (i = 1; i <= len1; ++i) {
			for (j = 1; j <= len2; ++j) {
				if (str1[i-1] == str2[j-1]) {
					ans[i][j] = ans[i-1][j-1];
				} else {
					ans[i][j] = min(1 + ans[i-1][j-1], 1 + ans[i-1][j], 1 + ans[i][j-1]);
				}
			}
		}

		cout << ans[len1][len2] << endl;
	}

	return 0;
}

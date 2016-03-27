#include <iostream>
#include <cstring>

using namespace std;

char str1[2101], str2[2101];
int ans[2101][2101];

int min(int a, int b, int c)
{
	if (b < a) a = b;
	if (c < a) a = c;

	return a;
}

int calc(int len1, int len2)
{
	int x, y, z, cost;

	if (ans[len1][len2] != -1) return ans[len1][len2];

	if (len1 == 0) {
		return len2;
	} else if (len2 == 0) {
		return len1;
	}

	if (str1[len1 - 1] == str2[len2 - 1]) {
		cost = 0;
	} else {
		cost = 1;
	}

	x = 1 + calc(len1 - 1, len2); 		// delete
	y = 1 + calc(len1, len2 - 1);		// insert
	z = cost + calc(len1 - 1, len2 - 1);	// modify

	return (ans[len1][len2] = min(x, y, z));
	
}

int main()
{
	int t, i, j, k, len1, len2;
	cin >> t;

	for (; t; --t) {
		cin >> str1 >> str2;
		len1 = strlen(str1);
		len2 = strlen(str2);

		for (i = 0; i <= len1; ++i) {
			for (j = 0; j <= len2; ++j) {
				ans[i][j] = -1;
			}
		}

		cout << calc(len1, len2) << endl;
	}

	return 0;
}

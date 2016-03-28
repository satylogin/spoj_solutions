#include <iostream>

using namespace std;

int main()
{
	int s, n, i, j;
	cin >> s >> n;

	int size[n], value[n];

	for (i = 0; i < n; ++i) {
		cin >> size[i] >> value[i];
	}
	
	int ks[n+1][s+1];

	for (i = 0; i <= n; ++i) {
		for (j = 0; j <= s; ++j) {
			if (i == 0 || j == 0) {
				ks[i][j] = 0;
			} else if (size[i-1] <= j) {
				if (ks[i-1][j] >= ks[i-1][j-size[i-1]] + value[i-1]) {
					ks[i][j] = ks[i-1][j];
				} else {
					ks[i][j] = ks[i-1][j-size[i-1]] + value[i-1];
				}
			} else {
				ks[i][j] = ks[i-1][j];
			}
		}
	}

	cout << ks[n][s] << endl;

	return 0;
}

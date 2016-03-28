#include <iostream>

using namespace std;

int main()
{
	int b, n, i, j;
	cin >> b >> n;

	while (b != 0 || n != 0) {
		int cost[n], fun[n];

		for (i = 0; i < n; ++i) {
			cin >> cost[i] >> fun[i];
		}

		// implement knapsack
		int ks[n+1][b+1];

		for (i = 0; i <= n; ++i) {
			for (j = 0; j <= b; ++j) {
				if (i == 0 || j == 0) {
					ks[i][j] = 0;
				} else if (cost[i-1] <= j) {
					if (ks[i-1][j] >= ks[i-1][j-cost[i-1]] + fun[i-1]) {
						ks[i][j] = ks[i-1][j];
					} else {
						ks[i][j] = ks[i-1][j-cost[i-1]] + fun[i-1];
					}
				} else {
					ks[i][j] = ks[i-1][j];
				}
			}
		}

		for (i = 0; i <= b; ++i) {
			if (ks[n][i] == ks[n][b]) break;
		}

		cout << i << " " << ks[n][b] << endl;

		cin >> b >> n;
	}

	return 0;
}

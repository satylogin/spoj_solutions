#include <iostream>

using namespace std;

int main()
{
	int t, w, n, i, j;
	cin >> t;

	for (; t; --t) {
		cin >> w >> n;
		int cost[n], val[n];

		for (i = 0; i < n; ++i) {
			cin >> cost[i] >> val[i];
		}

		int ks[n+1][w+1];
		for (i = 0; i <= n; ++i) {
			for (j = 0; j <= w; ++j) {
				if (i == 0 || j == 0) {
					ks[i][j] = 0;
				} else if (cost[i-1] <= j) {
					if (ks[i-1][j] >= ks[i-1][j-cost[i-1]] + val[i-1]) {
						ks[i][j] = ks[i-1][j];
					} else {
						ks[i][j] = ks[i-1][j-cost[i-1]] + val[i-1];
					}
				} else {
					ks[i][j] = ks[i-1][j];
				}
			}
		}

		cout << "Hey stupid robber, you can get " << ks[n][w] << "." << endl;
	}

	return 0;
}

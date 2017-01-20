#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int par[1001], cost[1001], ans[1001][1001], fun[1001], size[1001];

int find_par(int x)
{
	if (par[x] == x) return x;
	return (par[x] = find_par(par[x]));
}

void uni(int x, int y)
{
	int px = find_par(x);
	int py = find_par(y);
	if (px != py) {
		par[px] = py;
		cost[py] += cost[px];
		size[py] += size[px];
	}
}

int main()
{
	int t, n, m, i, j, k, a, b, c, x, y, z;

	while (cin >> a >> m) {
		if (a == 0 && m == 0) break;

		for (i = 0; i < a; ++i) {
			cin >> cost[i+1];
			par[i+1] = i+1;
			size[i+1] = 1;
		}

		for (i = 1; i <= a; ++i) {
			cin >> b;
			while (b--) {
				cin >> c;
				uni(i, c);
			}
		}

		n = 0;
		for (i = 1; i <= a; ++i) {
			if (par[i] == i) {
				cost[n] = cost[i];	
				fun[n++] = size[i];
			}
		}

		for (i = 0; i <= n; ++i) {
			for (j = 0; j <= m; ++j) {
				if (i == 0 || j == 0) {
					ans[i][j] = 0;
				} else if (cost[i-1] > j) {
					ans[i][j] = ans[i-1][j];
				} else {
					ans[i][j] = max(fun[i-1] + ans[i-1][j-cost[i-1]], ans[i-1][j]);
				}
			}
		}

		cout << ans[n][m] << endl;
	}

	return 0;
}

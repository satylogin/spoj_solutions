#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int BIT[1001][1001], n, m;

void insert(int x, int y)
{
	int i, j;
	for (i = x; i <= n; i += (i&-i))
		for (j = y; j <= m; j += (j&-j))
			BIT[i][j] += 1;
}

int query(int x, int y)
{
	int i, j, ret = 0;
	for (i = x; i > 0; i -= (i&-i))
		for (j = y; j > 0; j -= (j&-j))
			ret += BIT[i][j];
	return ret;
}

int query1(int x, int y)
{
	int i, j, ret = 0;
	ret = query(x-1, m) + query(x, y) - query(x-1, y);
	return ret;
}

int main()
{
	int xi, t, i, j, k, a, b, x, y, z;
	ll c;
	scan(t);

	for (xi = 1; xi <= t; ++xi) {
		c = 0;
		scanf("%d %d %d", &n, &m, &k);

		for (i = 0; i <= n; ++i) {
			for (j = 0; j <= m; ++j) {
				BIT[i][j] = 0;
			}
		}

		while (k--) {
			scanf("%d %d", &x, &y);
			a = query(n, y-1) - query(x, y-1);
			b = query(x-1, m) - query(x-1, y);
			c += (a+b);
			//cout << a << " " << b << endl;
			insert(x, y);
		}
		printf("Test case %d: %lld\n", xi, c);
	}

	return 0;
}

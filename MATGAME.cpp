#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<ll, ll>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)

int grundy(int arr[50][50], int n)
{
	int x, i, j, k, a, b, c;
	set <int> se;

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (arr[i][j] == 0) continue;
			for (k = 1; k < arr[i][j]; ++k) {
				arr[i][j] -= k;
				se.insert(grundy(arr, n));
				arr[i][j] += k;
			}
		}
	}

	x = 0;
	while (se.find(x) != se.end()) x++;
	return x;
}

int main()
{
	int t, n, x, m, i, j, arr[51][51], gr[51][51], g[51];
	sci(t);
	while (t--) {
		sci(n); sci(m);
		for (i = 0; i < n; ++i) {
			for (j = 0; j < m; ++j) {
				sci(arr[i][j]);
			}
		}
		memset (gr, 0, sizeof(gr));
		for (i = 0; i < n; ++i) {
			for (j = m-1; j >= 0; --j) {
				if (arr[i][j] == 0) {
					gr[i][j] = gr[i][j+1];
				} else if (arr[i][j] <= gr[i][j+1]) {
					gr[i][j] = arr[i][j]-1;
				} else {
					gr[i][j] = arr[i][j];
				}
			}
		}
		x = 0;
		for (i = 0; i < n; ++i) {
			x ^= gr[i][0];
		}
		if (x) {
			printf("FIRST\n");
		} else {
			printf("SECOND\n");
		}
	}

	return 0;
}

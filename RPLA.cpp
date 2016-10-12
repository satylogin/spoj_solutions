#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

vector <int> v[20001];
vector <int> rank[20001];
int mark[20001];

int dfs(int x)
{
	mark[x] = 1;
	int r = 1;
	for (int i = 0; i < v[x].size(); ++i) {
		if (!mark[v[x][i]]) {
			r = max(r, 1 + dfs(v[x][i]));
		} else {
			r = max(r, 1 + mark[v[x][i]]);	
		}
	}
	mark[x] = r;
	rank[r].pb(x);
	return r;
}

int main()
{
	int t, n, m, i, j, k, x, y;
	cin >> t;
	for (k = 1; k <= t; ++k) {
		scanf("%d %d", &n, &m);
		while (m--) {
			scanf("%d %d", &x, &y);
			v[x+1].pb(y+1);
		}
		for (i = 1; i <= n; ++i) {
			if (!mark[i]) dfs(i);
		}
		printf("Scenario #%d:\n", k);
		for (i = 1; i <= n; ++i) {
			sort(rank[i].begin(), rank[i].end());
			for (j = 0; j < rank[i].size(); ++j) {
				printf("%d %d\n", i, rank[i][j]-1);
			}
			rank[i].clear();
			v[i].clear();
			mark[i] = 0;
		}
	}

	return 0;
}

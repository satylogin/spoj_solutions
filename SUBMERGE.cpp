#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

vector <int> v[10001];
int mark[10001], par[10001], low[10001], disc[10001], ap[10001];
int tim;

void dfs(int x)
{
	mark[x] = 1;
	disc[x] = low[x] = ++tim;
	int i, child = 0;

	for (i = 0; i < v[x].size(); ++i) {
		if (mark[v[x][i]] == 0) {
			child++;
			par[v[x][i]] = x;
			dfs(v[x][i]);

			low[x] = min(low[x], low[v[x][i]]);

			if (par[x] == 0 && child > 1) {
				ap[x] = 1;
			} else if (par[x] != 0 && low[v[x][i]] >= disc[x]) {
				ap[x] = 1;
			}
		} else {
			if (v[x][i] != par[x]) {
				low[x] = min(low[x], disc[v[x][i]]);
			}
		}
	}
}

int main()
{
	int n, m, i, x, y, ans;
	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) {
			break;
		}
		for (i = 1; i <= n; ++i) {
			v[i].clear();
			mark[i] = par[i] = ap[i] = 0;
		}
		while (m--) {
			scanf("%d %d", &x, &y);
			v[x].pb(y);
			v[y].pb(x);
		}
		tim = 0;
		dfs(1);
		ans = 0;
		for (i = 1; i <= n; ++i) {
			if (ap[i]) ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<long long int, long long int>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define fi first
#define sc second
#define deb 0

vector <int> v[1001];
set <pii > se;
set <pii > :: iterator it;
int low[1000], disc[1000];
int timer;

void dfs(int x, int p)
{
	low[x] = disc[x] = ++timer;
	for (int i = 0; i < v[x].size(); ++i) {
		if (disc[v[x][i]] == 0) {
			dfs(v[x][i], x);
			low[x] = min(low[x], low[v[x][i]]);
			if (low[v[x][i]] > disc[x]) {
				se.insert(mkp(min(x, v[x][i]), max(x, v[x][i])));
			}
		} else if (v[x][i] != p) {
			low[x] = min(low[x], disc[v[x][i]]);
		}
	}
}

int main()
{
	int t, i, j, k, x, y, z, a, b, c, n, m;
	sci(t);
	for (int xi = 1; xi <= t; ++xi) {
		printf("Caso #%d\n", xi);
		scanf("%d %d", &n, &m);
		se.clear();
		timer = 0;
		for (i = 1; i <= n; ++i) v[i].clear(), disc[i] = low[i] = 0;
		for (i = 1; i <= m; ++i) {
			scanf("%d %d", &x, &y);
			v[x].pb(y);
			v[y].pb(x);
		}
		for (i = 1; i <= n; ++i) if (!disc[i]) dfs(i, 0);
		if (se.size() == 0) {
			printf("Sin bloqueos\n");
			continue;
		}
		printf("%lu\n", se.size());
		for (it = se.begin(); it != se.end(); ++it) {
			printf("%d %d\n", it->fi, it->sc);
		}
	}

	return 0;
}

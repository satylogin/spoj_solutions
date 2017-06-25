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

stack <int> st;
int par[100001], low[100001], disc[100001];
int timer, mark[100001];
vector <int> v[100001];
int X[200001], Y[200001], outdeg[100001];
queue <int> q;

void scc(int x)
{
	disc[x] = low[x] = ++timer;
	mark[x] = 1;
	st.push(x);

	for (int i = 0; i < v[x].size(); ++i) {
		if (!disc[v[x][i]]) scc(v[x][i]);
		if (mark[v[x][i]]) low[x] = min(low[x], low[v[x][i]]);
	}

	int y;
	if (low[x] == disc[x]) {
		while (1) {
			y = st.top(); st.pop(); mark[y] = 0;
			par[y] = x;
			if (y == x) break;
		}
	}
}

int main()
{
	int n, m, i, j, k, x, y, z, a, b, c;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		v[x].pb(y);
		X[i] = x; Y[i] = y;
	}

	for (i = 1; i <= n; ++i) {
		if (!disc[i]) scc(i);
	}

	for (i = 0; i < m; ++i) {
		if (par[X[i]] == par[Y[i]]) continue;
		++outdeg[par[X[i]]];
	}

	int cnt = 0;
	for (i = 1; i <= n; ++i) {
		if (par[i] == i && outdeg[i] == 0) cnt++, y = i;
	}

	if (cnt != 1) {
		cout << 0 << endl;
		return 0;
	}

	cnt = 0;
	for (i = 1; i <= n; ++i) {
		if (par[i] == y) cnt++;
	}

	printf("%d\n", cnt);
	if (!cnt) return 0;
	for (i = 1; i <= n; ++i) {
		if (par[i] == y) printf("%d ", i);
	} printf("\n");

	return 0;
}

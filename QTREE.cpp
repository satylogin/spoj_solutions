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

#define N 11000

int tree[4*N];
int next_free, pos[N+5];
int chain_head[N+5], main_child[N+5];

int par[N+5], size[N+5], cost[N+5];
int depth[N+5], arr[N+5];

vector <pii > v[N+5];

void dfs(int x, int p, int d)
{
	depth[x] = d;
	par[x] = p;
	size[x] = 1;
	int w = 0, n = -1, y;
	for (int i = 0; i < v[x].size(); ++i) {
		y = v[x][i].fi;
		if (y == p) continue;
		dfs(y, x, d+1);
		cost[y] = v[x][i].sc;
		size[x] += size[y];
		if (size[y] > w) {
			w = size[y];
			n = y;
		}
	}
	
	if (n != -1) main_child[x] = n;
}

void hld(int x, int p)
{
	pos[x] = ++next_free;
	arr[pos[x]] = cost[x];

	if (main_child[x]) chain_head[main_child[x]] = chain_head[x];
	if (main_child[x]) hld(main_child[x], x);

	int y;
	for (int i = 0; i < v[x].size(); ++i) {
		y = v[x][i].fi;
		if (y == p || y == main_child[x]) continue;
		chain_head[y] = y;
		hld(y, x);
	}
}

void make(int n, int start, int end)
{
	if (start == end) {
		tree[n] = arr[start];
		return;
	}	
	int mid = (start + end) >> 1;
	make(n<<1, start, mid);
	make(n<<1|1, mid+1, end);
	tree[n] = max(tree[n<<1], tree[n<<1|1]);
}

void update(int n, int start, int end, int x, int y)
{
	if (start > end || start > x || end < x) return;
	if (start == x && end == x) {
		tree[n] = y;
		return;
	}
	int mid = (start + end) >> 1;
	update(n<<1, start, mid, x, y);
	update(n<<1|1, mid+1, end, x, y);
	tree[n] = max(tree[n<<1], tree[n<<1|1]);
}

int query(int n, int start, int end, int l, int r)
{
	if (start > end || start > r || end < l) return -MOD;
	if (start >= l && end <= r) return tree[n];
	int mid = (start + end) >> 1;
	return max(query(n<<1, start, mid, l, r), query(n<<1|1, mid+1, end, l, r));
}

int hld_query(int x, int y)
{
	int ret = -MOD;
	int a = chain_head[x];
	int b = chain_head[y];
	while (a != b) {
		if (depth[a] >= depth[b]) {
			ret = max(ret, query(1, 1, N, pos[a], pos[x]));
			x = par[a];
			a = chain_head[x];
		} else {
			ret = max(ret, query(1, 1, N, pos[b], pos[y]));
			y = par[b];
			b = chain_head[y];
		}
	}

	a = min(pos[x], pos[y]) + 1;
	b = max(pos[x], pos[y]);

	if (a > b) return ret;
	return max(ret, query(1, 1, N, a, b));
}

char str[20];

struct ed {
	int x, y, z;
} edge[N+5];

int main()
{
	int t, i, j, k, x, y, z, a, b, c, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		next_free = 0;
		for (i = 1; i <= N; ++i) {
			v[i].clear();
			main_child[i] = 0;
		}
		for (i = 1; i < n; ++i) {
			scanf("%d %d %d", &x, &y, &z);
			v[x].pb(mkp(y, z));
			v[y].pb(mkp(x, z));
			edge[i].x = x;
			edge[i].y = y;
			edge[i].z = z;
		}
		dfs(1, 0, 1);
		chain_head[1] = 1;
		cost[1] = -MOD;
		hld(1, 0);
		make(1, 1, N);
		while (true) {
			scanf("%s", str);
			if (str[0] == 'D') break;
		
			scanf("%d %d", &x, &y);
			if (str[0] == 'C') {
				a = edge[x].x;
				b = edge[x].y;

				if (a == par[b]) {
					update(1, 1, N, pos[b], y);
				} else {
					update(1, 1, N, pos[a], y);
				}
			} else {
				printf("%d\n", hld_query(x, y));
			}
		}
	}

	return 0;
}

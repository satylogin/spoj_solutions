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

int par[10000];

inline int find(int x)
{
	return (x == par[x] ? x : par[x] = find(par[x]));
}

void uni(int x, int y)
{
	if ((x = find(x)) != (y = find(y))) {
		par[x] = y;
	}
}

int orientation(pii a, pii b, pii c)
{
	int x = (b.sc - a.sc) * (c.fi - b.fi)-
		(b.fi - a.fi) * (c.sc - b.sc);
	if (x < 0) return -1;
	if (x > 0) return 1;
	return 0;
}

int on_segment(pii a, pii b, pii c)
{
	return (b.fi <= max(a.fi, c.fi) && 
		b.fi >= min(a.fi, c.fi) && 
		b.sc <= max(a.sc, c.sc) && 
		b.sc >= min(a.sc, c.sc));
}

int intersect(pii p1, pii q1, pii p2, pii q2)
{
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	if (o1 != o2 && o3 != o4) return 1;
	if (o1 == 0 && on_segment(p1, p2, q1)) return 1;
	if (o2 == 0 && on_segment(p1, q2, q1)) return 1;
	if (o3 == 0 && on_segment(p2, p1, q2)) return 1;
	if (o4 == 0 && on_segment(p2, q1, q2)) return 1;
	return 0;
}

pair<pii, pii > arr[10000];

int main()
{
	int t, n, m, i, j, k, x, y, z, a, b, c;
	sci(t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; ++i) {
			par[i] = i;
			scanf("%d %d %d %d", &arr[i].fi.fi, &arr[i].fi.sc, &arr[i].sc.fi, &arr[i].sc.sc);
		}

		for (i = 1; i <= n; ++i) {
			for (j = i+1; j <= n; ++j) {
				if (intersect(arr[i].fi, arr[i].sc, arr[j].fi, arr[j].sc)) {
					uni(i, j);
				}
			}
		}

		while (m--) {
			scanf("%d %d", &x, &y);
			puts(find(x) == find(y) ? "YES" : "NO");
		}
	}

	return 0;
}

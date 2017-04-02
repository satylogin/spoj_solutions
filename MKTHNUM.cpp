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

#define vi vector<int>

pii arr[100001];
vector <int> v[300001];
int val[100001];

void merge(vi &a, vi &b, vi &c)
{
	int i, j, n, m;
	n = b.size();
	m = c.size();
	i = j = 0;
	while (i < n && j < m) {
		if (b[i] <= c[j]) a.pb(b[i++]);
		else a.pb(c[j++]);
	}
	while (i < n) a.pb(b[i++]);
	while (j < m) a.pb(c[j++]);
}

void make(int n, int start, int end)
{
	if (start == end) {
		v[n].pb(arr[start].second);
		return;
	}

	int mid = (start + end) >> 1;
	make(n<<1, start, mid);
	make(n<<1|1, mid+1, end);
	merge(v[n], v[n<<1], v[n<<1|1]);
}

int query(int n, int start, int end, int l, int r, int k)
{
	if (start == end) return v[n][0];
	
	int mid = (start + end) >> 1;
	int a = upper_bound(v[n<<1].begin(), v[n<<1].end(), r) - 
			lower_bound(v[n<<1].begin(), v[n<<1].end(), l);
	if (k <= a) return query(n<<1, start, mid, l, r, k);
	else return query(n<<1|1, mid+1, end, l, r, k-a);
}

int main()
{
	int n, m, i, j, k, x, y;
	sci(n); sci(m);
	for (i = 1; i <= n; ++i) {
		sci(arr[i].first);
		arr[i].second = i;
		val[i] = arr[i].first;
	}

	sort(arr+1, arr+1+n);

	make(1, 1, n);

	while (m--) {
		scanf("%d %d %d", &x, &y, &k);
		printf("%d\n", val[query(1, 1, n, x, y, k)]);
	}

	return 0;
}

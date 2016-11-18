#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int BIT[30030], res[200010];

struct data {
	int x, pos;	
} arr[30030];

struct node {
	int l, r, k, pos;
} qry[200010];

void insert(int x)
{
	for (; x <= 30030; x += (x&-x))
		BIT[x] += 1;
}

int query(int x)
{
	int ret = 0;
	for (; x > 0; x -= (x&-x))
		ret += BIT[x];
	return ret;
}

int comp(const data &a, const data &b)
{
	return (a.x > b.x);
}

int cmp(const node &a, const node &b)
{
	return (a.k > b.k);
}

int main()
{
	int n, m, i, j, k, a, b, x, y, z;
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &arr[i].x);
		arr[i].pos = i+1;
	}
	sort(arr, arr+n, comp);

	scanf("%d", &m);
	for (i = 0; i < m; ++i) {
		scanf("%d %d %d", &qry[i].l, &qry[i].r, &qry[i].k);
		qry[i].pos = i;
	}
	sort(qry, qry+m, cmp);

	j = 0;
	for (i = 0; i < m; ++i) {
		while (j < n && arr[j].x > qry[i].k) {
			insert(arr[j++].pos);
		}
		res[qry[i].pos] = query(qry[i].r) - query(qry[i].l - 1);
	}

	for (i = 0; i < m; ++i) {
		printf("%d\n", res[i]);
	}

	return 0;
}

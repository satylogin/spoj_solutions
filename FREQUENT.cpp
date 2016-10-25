#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

struct node {
	int l, r, m, tot;
} tree[300000], x;

int arr[100001];

void make_tree(int n, int start, int end)
{
	if (start == end) {
		tree[n].l = tree[n].r = tree[n].m = tree[n].tot = 1;
		return;
	}

	int mid = (start + end) >> 1, y;
	make_tree(n<<1, start, mid);
	make_tree(n<<1|1, mid+1, end);
	x.tot = tree[n<<1].tot + tree[n<<1|1].tot;
	if (arr[start] == arr[mid+1]) x.l = tree[n<<1].tot + tree[n<<1|1].l;
	else x.l = tree[n<<1].l;
	if (arr[mid] == arr[end]) x.r = tree[n<<1].r + tree[n<<1|1].tot;
	else x.r = tree[n<<1|1].r;
	if (arr[mid] == arr[mid+1]) y = tree[n<<1].r + tree[n<<1|1].l;
	else y = 0;
	tree[n].l = x.l;
	tree[n].r = x.r;
	tree[n].tot = x.tot;
	tree[n].m = max(tree[n<<1].m, max(tree[n<<1|1].m, max(y, max(tree[n].l, tree[n].r))));
}

node query(int n, int start, int end, int l, int r)
{
	if (start > end || start > r || end < l) {
		x.l = x.r = x.m = x.tot = 0;
		return x;
	}
	if (start >= l && end <= r) return tree[n];
	node a, b;
	int mid = (start + end) >> 1, y;
	a = query(n<<1, start, mid, l, r);
	b = query(n<<1|1, mid+1, end, l, r);
	x.tot = a.tot + b.tot;
	if (arr[start] == arr[mid+1]) x.l = a.tot + b.l;
	else x.l = a.l;
	if (arr[mid] == arr[end]) x.r = a.r + b.tot;
	else x.r = b.r;
	if (arr[mid] == arr[mid+1]) y = a.r + b.l;
	else y = 0;
	x.m = max(a.m, max(b.m, max(y, max(x.l, x.r))));
	return x;
}

int main()
{
	int n, m, i, j, k;
	while (scan(n) && n) {
		scan(m);
		for (i = 1; i <= n; ++i) scan(arr[i]);
		make_tree(1, 1, n);
		while (m--) {
			scan(i); scan(j);
			printf("%d\n", query(1, 1, n, i, j).m);
		}
	}

	return 0;
}

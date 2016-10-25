#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int tree[300001], arr[100001], val, idx;

void make_tree(int n, int start, int end)
{
	if (start == end) {
		arr[start] = val;
		tree[n] = val;
		return;
	}
	int mid = (start + end) >> 1;
	make_tree(n<<1, start, mid);
	make_tree(n<<1|1, mid+1, end);
	tree[n] = val;
}	

void query(int n, int start, int end, int x)
{
	if (start == end) {
		arr[start] -= x;
		tree[n] -= x;
		if (start > idx) idx = start;
		return;
	}
	int mid = (start + end) >> 1;
	if (tree[n<<1] >= x) {
		query(n<<1, start, mid, x);
	} else {
		query(n<<1|1, mid+1, end, x);
	}
	tree[n] = max(tree[n<<1], tree[n<<1|1]);
}

char str[10];

int main()
{
	int t, n, k, i, j, a, b;
	ll c;
	scan(t);
	while (t--) {
		scan(val);
		make_tree(1, 1, 100000);
		idx = 0;
		scan(k);
		while (k) {
			scanf("%s", str);
			if (str[0] == 'b') {
				scan(b);
				scan(a);
				k -= b;
				while (b--) {
					query(1, 1, 100000, a);
				}
			} else {
				a = atoi(str);
				query(1, 1, 100000, a);
				k--;
			}
		}
		c = 0;
		for (i = 1; i <= idx; ++i) {
			c += arr[i];
		}
		printf("%d %lld\n", idx, c);
	}

	return 0;
}

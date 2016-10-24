#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int tree[100000], arr[100000];

void make_tree(int n, int start, int end)
{
	if (start == end) {
		tree[n] = arr[start];
		return;
	}
	int mid = (start + end) >> 1;
	make_tree(n<<1, start, mid);
	make_tree(n<<1|1, mid+1, end);
	tree[n] = tree[n<<1] & tree[n<<1|1];
}

int query(int n, int start, int end, int l, int r)
{
	if (start > end || start > r || end < l) return -1;
	if (start >= l && end <= r) return tree[n];
	int mid = (start + end) >> 1;
	return (query(n<<1, start, mid, l, r) & query(n<<1|1, mid+1, end, l, r));
}

int find(int a, int b, int n)
{
	if (a > b) {
		return (query(1, 1, n, 1, b) & query(1, 1, n, a, n));
	} else {
		return query(1, 1, n, a, b);
	}
}

int main()
{
	int n, t, m, i, j, k, a, b, c, x, y, z;	
	scan(t);
	while (t--) {
		scan(n); scan(k);
		for (i = 1; i <= n; ++i) {
			scan(arr[i]);
		}
		if (k >= n/2) {
			int ans = arr[1];
			for (i = 2; i <= n; ++i) ans &= arr[i];
			for (i = 0; i < n; ++i) printf("%d ", ans);
			printf("\n");
			continue;
		}
		make_tree(1, 1, n);
		for (i = 1; i <= n; ++i) {
			x = i - 1;
			a = (x - k + n) % n;
			b = (x + k) % n;
			a++;
			b++;
			//cout << "x = " << x << " a, b = ";
			//cout << a << " " << b << " " << find(a, b, n) << endl;
			printf("%d ", find(a, b, n));
		}
		printf("\n");
	}

	return 0;
}

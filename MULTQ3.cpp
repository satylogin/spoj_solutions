#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<ll, ll>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)

struct node {
	int z, o, t;
} tree[400001];

int lazy[400001];

void make_tree(int n, int start, int end)
{
	if (start == end) {
		tree[n].z = 1;
		tree[n].o = tree[n].t = 0;
		return;
	}

	int mid = (start + end) >> 1;
	make_tree(n<<1, start, mid);
	make_tree(n<<1|1, mid+1, end);
	tree[n].z = tree[n<<1].z + tree[n<<1|1].z;
	tree[n].o = tree[n<<1].o + tree[n<<1|1].o;
	tree[n].t = tree[n<<1].t + tree[n<<1|1].t;
}

void update(int n, int start, int end, int l, int r)
{
	if (lazy[n]) {
		if (lazy[n] == 1) {
			int x = tree[n].t;
			tree[n].t = tree[n].o;
			tree[n].o = tree[n].z;	
			tree[n].z = x;
			if (start != end) {
				lazy[n<<1] = (lazy[n<<1]+1)%3; 
				lazy[n<<1|1] = (lazy[n<<1|1]+1)%3; 
			}
		} else {
			int x = tree[n].z;
			tree[n].z = tree[n].o;
			tree[n].o = tree[n].t;	
			tree[n].t = x;
			if (start != end) {
				lazy[n<<1] = (lazy[n<<1]+2)%3; 
				lazy[n<<1|1] = (lazy[n<<1|1]+2)%3; 
			}
		}
		lazy[n] = 0;
	}

	if (start > end || start > r || end < l) return;

	if (start >= l && end <= r) {
		int x = tree[n].t;
		tree[n].t = tree[n].o;
		tree[n].o = tree[n].z;
		tree[n].z = x;
		if (start != end) {
			lazy[n<<1] = (lazy[n<<1]+1)%3;
			lazy[n<<1|1] = (lazy[n<<1|1]+1)%3;
		}
		return;
	}

	int mid = (start + end) >> 1;
	update(n<<1, start, mid, l, r);
	update(n<<1|1, mid+1, end, l, r);
	tree[n].z = tree[n<<1].z + tree[n<<1|1].z;
	tree[n].o = tree[n<<1].o + tree[n<<1|1].o;
	tree[n].t = tree[n<<1].t + tree[n<<1|1].t;
}

int query(int n, int start, int end, int l, int r)
{
	if (lazy[n]) {
		if (lazy[n] == 1) {
			int x = tree[n].t;
			tree[n].t = tree[n].o;
			tree[n].o = tree[n].z;	
			tree[n].z = x;
			if (start != end) {
				lazy[n<<1] = (lazy[n<<1]+1)%3; 
				lazy[n<<1|1] = (lazy[n<<1|1]+1)%3; 
			}
		} else {
			int x = tree[n].z;
			tree[n].z = tree[n].o;
			tree[n].o = tree[n].t;	
			tree[n].t = x;
			if (start != end) {
				lazy[n<<1] = (lazy[n<<1]+2)%3; 
				lazy[n<<1|1] = (lazy[n<<1|1]+2)%3; 
			}
		}
		lazy[n] = 0;
	}

	if (start > end || start > r || end < l) return 0;
	if (start >= l && end <= r) return tree[n].z;
	int mid = (start + end) >> 1;
	return query(n<<1, start, mid, l, r) + query(n<<1|1, mid+1, end, l, r);
}

int main()
{
	int n, m, a, b, c;
	sci(n); sci(m);
	make_tree(1, 1, n);
	while (m--) {
		sci(a); sci(b); sci(c);
		if (a == 0) {
			update(1, 1, n, b+1, c+1);
		} else {
			printf("%d\n", query(1, 1, n, b+1, c+1));
		}
	}

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int BIT[200001], arr[200001], rank[200001];

void insert(int x, int val)
{
	for (; x <= 200000; x += (x&-x))
		BIT[x] += val;
}

int query(int x)
{
	int ret = 0;
	for (; x > 0; x -= (x&-x))
		ret += BIT[x];
	return ret;
}	

int find(int x, int end)
{
	int start, k, mid, idx;
	start = 1;
	while (start <= end) {
		mid = (start + end) >> 1;
		k = query(mid);
		if (k >= x) {
			idx = mid;
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return idx;
}

int main()
{
	int a, t, n, m, i, j, k, x;
	scan(t);
	while (t--) {
		scan(n);
		for (i = 1; i <= n; ++i) {
			insert(i, 1);
		}
		for (i = 1; i <= n; ++i) {
			scan(arr[i]);
		}
		for (i = n; i > 0; --i) {
			a = find(arr[i] + 1, n);
			insert(a, -1);
			rank[i] = a;
		}
		for (i = 1; i <= n; ++i) {
			printf("%d ", n-rank[i]+1);
		}	
		printf("\n");
	}

	return 0;
}

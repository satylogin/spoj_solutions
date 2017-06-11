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

#define N 3000000

map <int, int> mp, mp1;

int root[111000], next_free;
int T[N], L[N], R[N];
int A[100111], B[100111];

void make(int id, int start, int end)
{
	if (start == end) return;
	L[id] = ++next_free;
	R[id] = ++next_free;
	int mid = (start + end) >> 1;
	make(L[id], start, mid);
	make(R[id], mid+1, end);
}

int update(int x, int id, int start, int end)
{
	int ID = ++next_free;
	if (start == end) {
		T[ID] = T[id] + 1; 
		return ID;
	}

	int mid = (start + end) >> 1;
	L[ID] = L[id]; R[ID] = R[id];

	if (x <= mid)
		L[ID] = update(x, L[ID], start, mid);
	else 
		R[ID] = update(x, R[ID], mid+1, end);
	T[ID] = T[L[ID]] + T[R[ID]];
	return ID;
}

int query(int lid, int rid, int kth, int start, int end)
{
	if (start == end) return start;
	int s = T[L[rid]] - T[L[lid]];
	int mid = (start + end) >> 1;
	if (kth <= s) {
		return query(L[lid], L[rid], kth, start, mid);
	} else {
		return query(R[lid], R[rid], kth - s, mid+1, end);
	}
}

int main()
{
	int n, m, i, j, k, x, y, z, l, r, a, b, c;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; ++i) sci(A[i]), B[i] = A[i];
	sort(B+1, B+1+n);
	
	int lim = 0;
	for (i = 1; i <= n; ++i) {
		if (B[i] != B[i-1]) {
			mp[B[i]] = ++lim;
			mp1[lim] = B[i];
		}
	}	

	root[0] = 0;
	make(0, 1, lim);
	for (i = 1; i <= n; ++i) {
		root[i] = update(mp[A[i]], root[i-1], 1, lim);
	}

	for (i = 0; i < m; ++i) {
		scanf("%d %d %d", &l, &r, &k);
		printf("%d\n", mp1[query(root[l-1], root[r], k, 1, lim)]);
	}

	return 0;
}

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

#define SIZE 1000000

int phi[SIZE+1], depth[SIZE+1];
vector <int> v[SIZE+1];

void phi_()
{
	int i, j;
	for (i = 1; i <= SIZE; ++i) {
		phi[i] = i;
	}

	for (i = 1; i <= SIZE; ++i) {
		for (j = i+i; j <= SIZE; j += i) {
			phi[j] -= phi[i];
		}
	}

	v[0].pb(1);	
	for (i = 2; i <= SIZE; ++i) {
		depth[i] = 1 + depth[phi[i]];
		v[depth[i]].pb(i);
	}
}

int main()
{
	phi_();

	int t, n, m, k, start, end, mid, a, b;

	sci(t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		b = v[k].size();
		
		if (m < v[k][0] || n > v[k][b-1]) {
			printf("0\n"); continue;
		}

		a = lower_bound(v[k].begin(), v[k].end(), n) - v[k].begin();
		b = upper_bound(v[k].begin(), v[k].end(), m) - v[k].begin();
		printf("%d\n", b-a);
	}

	return 0;
}

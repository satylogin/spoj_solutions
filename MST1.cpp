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

int ans[20000001];

int main()
{
	int i, j, k, t;
	for (i = 2; i <= 20000000; ++i) {
		ans[i] = 1 + ans[i-1];
		if (i%2 == 0) ans[i] = min(ans[i], 1 + ans[i>>1]);
		if (i%3 == 0) ans[i] = min(ans[i], 1 + ans[i/3]);
	}

	sci(t);
	i = 1;
	while (t--) {
		sci(k);
		printf("Case %d: %d\n", i++, ans[k]);
	}

	return 0;
}

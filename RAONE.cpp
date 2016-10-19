#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

char num[100];
ll dp[100][100][100], mem[100][100][100];

ll find(ll dig, ll even, ll odd, int f)
{
	if (dig == 0) {
		return ((even - odd) == 1);
	}
	if (mem[dig][even][odd]) return dp[dig][even][odd];

	mem[dig][even][odd] = 1;
	ll ret = 0;

	for (int i = 0; i < 10; ++i) {
		if (f) ret += find(dig-1, even+i, odd, 1-f);
		else ret += find(dig-1, even, odd+i, 1-f);
	}

	return (dp[dig][even][odd] = ret);
}

ll get_ans(ll x)
{
	sprintf(num, "%lld", x);
	ll a, b, c, even, odd, i, j, k, ret, len;
	
	len = strlen(num);
	j = len;
	ret = even = odd = c = 0;
	
	for (i = 0; i < len; ++i) {
		--j;
		a = num[i] - '0';
		for (k = 0; k < a; ++k) {
			if ((len-i)&1)  c += find(j, even, odd+k, 1);
			else c += find(j, even+k, odd, 0);
		}
		if ((len-i)&1) odd += a;
		else even += a;
	}

	return c;
}	

int main()
{
	ll t, a, b;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", get_ans(b+1) - get_ans(a));
	}

	return 0;
}

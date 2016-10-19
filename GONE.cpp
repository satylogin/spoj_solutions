#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

ll mem[100][400], dp[100][400], sieve[400];
vector <ll> prime;
char num[100];

void init()
{
	for (int i = 2; i < 400; ++i) {
		if (sieve[i] == 0) {
			prime.pb(i);
			for (int j = i*i; j < 400; j += i) sieve[j] = 1;
		}
	}
}

ll find(ll dig, ll sum)
{
	if (dig == 0) {
		for (int i = 0; i < prime.size(); ++i) {
			if (sum == prime[i]) return 1;
		}
		return 0;
	}

	if (mem[dig][sum]) return dp[dig][sum];
	mem[dig][sum] = 1;
	ll ret = 0;

	for (int i = 0; i < 10; ++i) {
		ret += find(dig-1, sum+i);
	}

	return (dp[dig][sum] = ret);
}	

ll get_ans(ll x)
{
	sprintf(num, "%lld", x);
	ll a, b, c, ret, i, j, k, len;
	
	len = strlen(num);	
	j = len;
	c = b = 0;

	for (i = 0; i < len; ++i) {
		--j;
		a = num[i] - '0';
		for (k = 0; k < a; ++k) {
			c += find(j, b+k);
		}
		b += a;
	}

	return c;
}

int main()
{
	init();
	ll a, b, t;
	cin >> t;
	while (t--) {
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", get_ans(b+1) - get_ans(a));
	}

	return 0;
}

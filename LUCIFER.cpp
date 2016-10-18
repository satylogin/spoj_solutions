#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

ll dp[100][100][100], mem[100][100][100];
char num[100];
int prms[29] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};

ll is_prime(ll x)
{
	for (int i = 0; i < 29; ++i) if (x == prms[i]) return 1;
	return 0;
}

ll find(ll dig, ll even, ll odd, int f)
{
	if (dig == 0) return is_prime(even-odd);
	if (mem[dig][even][odd]) return dp[dig][even][odd];
	mem[dig][even][odd] = 1;
	ll ret = 0;

	for (ll i = 0; i < 10; ++i) {
		if (f) ret += find(dig-1, even+i, odd, 1^f);
		else ret += find(dig-1, even, odd+i, 1^f);
	}

	return (dp[dig][even][odd] = ret);
}

ll get_ans(ll x)
{
	sprintf(num, "%lld", x);
	ll even, odd, i, j, len, k, a, b, c;
	
	even = odd = c = 0;
	len = strlen(num);
	j = len;

	for (i = 0; i < len; ++i) {
		j--;
		a = num[i] - '0';
		for (k = 0; k < a; ++k) {
			if ((len-i)&1) c += find(j, even, odd+k, 1);
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
	cin >> t;
	while (t--) {
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", get_ans(b+1) - get_ans(a));
	}

	return 0;
}

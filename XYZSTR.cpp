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

char str[1000010];
char s[10];
map <pii, ll> mp;

int main()
{
	int t, i, a, b, c;
	char A, B, C;
	ll ans;
	pii tmp;
	sci(t);
	while (t--) {
		scanf("%s %s", s, str);
		A = s[0];
		B = s[1];
		C = s[2];
		ans = 0;
		a = b = c = 0;
		mp.clear();
		mp[mkp(0, 0)] = 1;
		for (i = 0; str[i]; ++i) {
			if (str[i] == A) a++;
			else if (str[i] == B) b++;
			else if (str[i] == C) c++;
			tmp = mkp(a-b, a-c);
			ans += mp[tmp];
			mp[tmp]++;
		}
		printf("%lld\n", ans);
	}

	return 0;
}

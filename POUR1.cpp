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

int _count(int x, int y, int c)
{
	int cnt = 0, a = 0, b = 0;
	while (a != c && b != c) {
		if (a == 0) {
			a = x;
		} else if (b == y) {
			b = 0;
		} else {
			b += a;
			a = 0;
		}
		if (b > y) {
			a = b-y;
			b = y;
		}
		cnt++;
	}
	return cnt;
}

int main()
{
	int t, a, b, c, x, y, c1, c2, g;
	cin >> t;
	while (t--) {
		c1 = c2 = 0;
		cin >> a >> b >> c;
		g = __gcd(a, b);
		if (c > max(a, b) || (c%g)) {
			cout << -1 << endl;
			continue;
		}

		cout << min(_count(a, b, c), _count(b, a, c)) << endl;
	}

	return 0;
}

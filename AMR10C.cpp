#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int mark[1000001], sieve[1000001];
set <int> se;
set <int> :: iterator it;

int main()
{
	int t, n, i, j, k, a, b, c, x, y, z;

	for (i = 2; i <= 1000000; ++i) {
		if (sieve[i] == 0) {
			for (j = i; j <= 1000000; j += i) {
				sieve[j] = i;
			}
		}
	}

	scan(t);
	while (t--) {
		scan(n);
		while (n != 1) {
			mark[sieve[n]]++;
			se.insert(sieve[n]);
			n /= sieve[n];
		}

		c = 0;
		for (it = se.begin(); it != se.end(); ++it) {
			c = max(c, mark[*it]);
			mark[*it] = 0;
		}
		se.clear();
		printf("%d\n", c);
	}

	return 0;
}

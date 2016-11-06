#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int main()
{
	int t, n, i, j;
	ll k;
	int c;

	scan(t);
	while (t--) {
		scanf("%d %lld", &n, &k);
		c = 1;
		while (k != 1) {
			if (!(k&1)) {
				c ^= 1;
			}
			k = (k + 1) >> 1;
		}

		if (c == 1) {
			printf("Male\n");
		} else {
			printf("Female\n");
		}
	}

	return 0;
}

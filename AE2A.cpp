#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

ll n, k;

double dp[551][3301];

int main()
{
	int i, j, k, n, m, a, b, c;
	
	for (i = 1; i < 7; ++i) {
		dp[1][i] = 1.0 / 6.0;
	}

	for (i = 1; i <= 550; ++i) {
		for (j = 1; j <= 3300; ++j) {	
			if (dp[i][j] == 0) {
				for (k = 1; k <= 6; ++k) {
					if (j-k > 0) {
						dp[i][j] += dp[i-1][j-k] / 6.0;
					}
				}
			}
		}
	}

	scan(n);
	while (n--) {
		scan(a); scan(b);
		if (a > 550 || b > 3300) {
			printf("0\n");
		} else {
			printf("%lld\n", (ll)(dp[a][b] * 100));
		}	
	}

	return 0;
}

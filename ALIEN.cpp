#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int arr[1000000];

int main()
{
	int n, m, i, j, k, a, b, c, x, cur, y, z, val, t;
	scan(t);
	while (t--) {
		scanf("%d %d", &n, &k);
		for (i = 0; i < n; ++i) {
			scan(arr[i]);
		}
		cur = 0;
		val = MOD;
		x = 0;
		a = b = -1;
		for (i = 0; i < n; ++i) {
			cur += arr[i];	
			while (cur > k) {
				cur -= arr[x++];
			}
			if (x <= i) {
				if (i-x > b-a) {
					a = x;
					b = i;
					val = cur;
				} else if (i-x == b-a && cur < val) {
					a = x;
					b = i;
					val = cur;
				}
			}
		}
		if (a == -1) {
			val = 0;
			b--;
		}
		printf("%d %d\n", val, b-a+1);
	}

	return 0;
}

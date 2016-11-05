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
	int t, n, i, ans;
	char str[4];

	scan(t);
	while (t--) {
		scan(n);
		ans = 0;
		while (n--) {
			scanf("%s", str);
			if (str[0] == 'l') {
				ans ^= 1;
			}
		}
		if (ans == 1) {
			printf("lxh\n");
		} else {
			printf("hhb\n");
		}
	}

	return 0;
}

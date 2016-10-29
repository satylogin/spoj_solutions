#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%lld", &x)

ll arr[100], plu[100], minu[100], ans[100];

int main()
{
	ll i, j, n, m, x, y, a, b, c, z;

	arr[0] = 1;
	for (i = 1; i <= 40; ++i) {
		arr[i] = -2 * arr[i-1];
	}
	plu[0] = arr[0];
	minu[1] = arr[1];
	for (i = 2; i <= 40; i += 2) {
		plu[i] = arr[i] + plu[i-2];
		minu[i+1] = arr[i+1] + minu[i-1];
	}
	
	scan(n);
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}

	x = 40;
	j = 0;
	while (n != 0) {
		//cout << n << endl;
		if (n > 0) {
			i = 0;
			while (plu[i] < n) i += 2;
			a = x - i - 1;
			while (a--) {
				ans[j++] = 0;
			}
			ans[j++] = 1;
			n -= arr[i];
		} else {
			i = 1;
			while (minu[i] > n) i += 2;
			a = x - i - 1;
			while (a--) {
				ans[j++] = 0;
			}	
			ans[j++] = 1;
			n -= arr[i];
		}
		x = i;
	}
	//cout << "*" << endl;
	while (x--) {
		ans[j++] = 0;
	}
	i = 0;
	while (ans[i] == 0) i++;
	while (i < j) {
		printf("%lld", ans[i++]);
	}
	cout << endl;

	return 0;
}

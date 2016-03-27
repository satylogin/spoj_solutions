#include <iostream>

using namespace std;

unsigned long long int ncr(unsigned long long int, unsigned long long int);
//unsigned long long int ans[10000][10000];

int main()
{
	unsigned long long int t, n, r, i, k, ans;

	cin >> t;

	for (; t; --t) {
		cin >> n >> k;
		ans = 0;
		r = n - k;
		if (r == 0) {
			cout << 1 << endl;
			continue;
		}
		cout << ncr(n - 1, r) << endl;
	}

	return 0;
}

unsigned long long int ncr(unsigned long long int n, unsigned long long int k)
{
	long long int ans = 1, j = 1;
	k = (k > (n - k)) ? n - k : k;
	
	for (; j <= k; ++j, --n) {
		if ((n % j) == 0) {
			ans *= (n / j);
		} else if ((ans % j) == 0) {
			ans = (ans / j) * n;
		} else {
			ans = (ans * n) / j;
		}
	}
	
	return ans;
}

#include <iostream>
#include <cmath>

using namespace std;

long long int diff(long long int n, long long int k)
{
	long long int odd = 0, even = 0;
	long long int x = 1;
	if ((n & 1) != 0) odd++;
	while (n) {
		if ((n>>1 & 1) & x)
			even++;
		if ((n>>1 & 1) & !x)
			odd++;
		x = x^1;
		n = n>>1;
	}
	if (even-odd == k || even-odd == -k) return 1;
	else return 0;
}

int main()
{
	int t; cin>>t;

	while (t--) {
		long long int n, m, k, count = 0, i;
		cin>>n>>m>>k;
		for (i = n; i <= m; i++) {
			if (diff(i, k)) {
				count++;
			}
		}
		cout<<count<<endl;
	}

	return 0;
}

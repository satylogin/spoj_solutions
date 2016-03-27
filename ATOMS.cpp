#include <iostream>

using namespace std;

int main()
{
	int t; cin>>t;

	while (t--) {
		unsigned long long int n, k, m;
		cin>>n>>k>>m;
		int count = 0;
		if (m / k < n) {
			cout<<0<<endl;
		} else {
			while ((m / (k * n) ) >= 1) {
				n = k * n;
				count++;
				if (m / n < k) break;
			}
			cout<<count<<endl;
		}
	}

	return 0;
}

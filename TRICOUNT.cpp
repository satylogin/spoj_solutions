#include <iostream>

using namespace std;

int main()
{
	int t; cin>>t;
	
	while (t--) {
		long long int n, sum = 0;
		cin>>n;
		sum = sum + ((n+2)*(n+1)*n) / 6;
		if (n % 2 == 0) {
			sum = sum + (n*(n+2)*(2*n - 1)) / 24;
		} else {
			sum = sum + ((n*n - 1)*(2*n + 3)) / 24;
		}
		cout<<sum<<endl;
	}

	return 0;
}

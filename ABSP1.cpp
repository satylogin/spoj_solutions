#include <iostream>
using namespace std;

int main()
{
	int t, n, i;
	long long int ans;
	cin>>t;

	for ( ; t; t--) {
		cin>>n;
		long long int arr[n], total = 0;
		long long int ans[n];
		ans[0] = 0;
		for (i = 0; i < n; i++) {
			cin>>arr[i];
		}	
		for (i = 1; i < n; i++) {
			ans[i] = ans[i-1] + (i * (arr[i] - arr[i-1]));
		}
		for (i = 0; i < n; i++) {
			total = total + ans[i];
		}
		cout<<total<<endl;
	}

	return 0;
}

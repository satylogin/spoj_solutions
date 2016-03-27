#include <iostream>

using namespace std;

long long int gcd(long long int a, long long int b)
{
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int main()
{
	int t; cin>>t;

	while (t--) {
		long long int a, b;
		cin>>a>>b;
		long long int x = gcd(a, b);
		cout<<b/x<<" "<<a/x<<endl;
	}

	return 0;
}

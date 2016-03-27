#include <iostream>

using namespace std;

int main()
{
	long long int t,i,j;
	cin>>t;
	while (t--) {
		long long int x1, x2, x3, a, d;
		long long int n;
		cin>>x1>>x2>>x3;
		n = (2 * x3) / (x1 + x2);
		d = (x2 - x1) / (n - 5);
		a = x1 - (2 * d);
		cout<<n<<endl;
		for (i = 0; i < n; i++) {
			cout<< a + i*d<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}

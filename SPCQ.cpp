#include <iostream>

using namespace std;

int main()
{
	int t; cin>>t;
	
	while (t--) {
		long long int n;
		cin>>n;
		int x;
		long long int y;
		while (1) {
			y = n;
			x = 0;
			while (y > 0) {
				x = x + y % 10;
				y = y / 10;
			}
			if (n % x == 0) {
				break;
			} else {
				n++;
			}
		}
		cout<<n<<endl;
	}

	return 0;
}

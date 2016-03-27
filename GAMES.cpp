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
		char num[20];
		cin>>num;
		long long int x = 0, y = 1;
		int i = 0;
		while (num[i] != '.' && num[i] != '\0') {
			x = x*10 + (num[i] - '0');
			i++;
		}
		if (num[i] == '.'){
			i++;
			while (num[i] != '\0') {
				x = x*10 + (num[i] - '0');
				i++;
				y = y*10;
			}
		}
		long long int z = gcd(x, y);
		cout<<y/z<<endl;
	}

	return 0;
}

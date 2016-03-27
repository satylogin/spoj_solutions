#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;
int gcd(int, int);

int main()
{
	int t; cin>>t;
	
	while (t--) {
		char num1[260];
		int a;
		cin>>a;
		cin>>num1;
		if (a != 0) {
			int num[250], length = strlen(num1);
			int i, j, k;
			for (i = 0; i < length; i++) {
				num[i] = num1[i] - '0';
			}
			int count = 0;
			int b = 0;
			while (b < a) {
				b = b*10 + num[count++];
			} 
			while (count < length) {
				b = b % a;
				while ((b < a) && (count < length)) {
					b = b*10 + num[count++];
				}
			}
			if (b > a){
				b = b % a;
			}
			cout<<gcd(a,b)<<endl;
		} else {
			cout<<num1<<endl;
		}
	}

	return 0;
}

int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a%b);
	}
}

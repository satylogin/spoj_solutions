#include <iostream>
using namespace std;
#define MAX 1000001

long long int prime[MAX];
long long int sequence[MAX];

void p()
{
	int i, j;
	for (i = 2; i < MAX / 2; i++) {
		for (j = i*2; j < MAX; j+=i) {
			prime[j] = prime[j] + i;
		}
	}

	for (i = 2; i < MAX; i++) {
		if (prime[i] == 0) {
			sequence[i] = sequence[i-1] + 1;
		} else {
			sequence[i] = sequence[i-1] + prime[i] + 1;
		}
	}
}

int main()
{
	p();
	int t, n;
	cin>>t;

	for (; t; t--) {
		cin>>n;
		cout<<sequence[n]<<endl;
	}

	return 0;
}

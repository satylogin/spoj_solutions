#include <iostream>
using namespace std;
#define MAX 10000001

int prime[MAX];
long long int sequence[MAX];

void p()
{
	int i, j;
	for (i = 2; i*i < MAX; i++) {
		if (prime[i] == 0) {
			for (j = i*2; j < MAX; j+=i) {
				if (prime[j] == 0) {
					prime[j] = i;
				}
			}
		}
	}

	for (i = 2; i < MAX; i++) {
		if (prime[i] == 0) {
			sequence[i] = sequence[i-1] + i;
		} else {
			sequence[i] = sequence[i-1] + prime[i];
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

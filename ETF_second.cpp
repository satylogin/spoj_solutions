#include <iostream>
using namespace std;
#define MAX 1000001

int seive[MAX], prime[MAX], phi[MAX];

void set()
{
	int i, j, k = 0;
	for (i = 2; i*i < MAX; i++) {
		if (seive[i] == 0) {
			for (j = i*i; j < MAX; j+= i) {
				seive[j] = 1;
			}
		}
	}
	
	for (i = 2; i < MAX; i++) {
		if (seive[i] == 0) {
			phi[i] = i - 1;
			prime[k++] = i;
		}
		for (j = 0;j < k,i * prime[j] < MAX; j++) {
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
}

int main()
{
	set();
	int t, x;
	cin>>t;
	for (; t; t--) {
		cin>>x;
		if (x == 1) cout<<1<<endl;
		else cout<<phi[x]<<endl;
	}
	return 0;
}

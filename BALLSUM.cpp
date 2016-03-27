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
	long long int N, K, i, j, k;
	cin>>N>>K;

	while ((N != -1) || (K != -1)) {
		if (K < 3) {
			cout<<0<<endl;
		} else {
			long long int total;
			if (N % 2 == 0) {
				total = (N / 2) * (N - 1);
			} else {
				total = N * ((N-1) / 2);
			}
			long long int count = 0;
			if ((K % 2) == 0) {
				i = (K - 2) / 2;
				count = (i * (4 + (i - 1) * 2)) / 2;
			} else {
				j = K;
				K = K - 1;
				i = (K - 2) / 2;
				count = (i * (4 + (i - 1) * 2)) / 2;
				k = (j - 1) / 2;
				count = count + k;
			}
			if (count == total) {
				cout<<1<<endl;
			} else {
				long long int y = gcd(count, total);
				cout<<(count/y)<<"/"<<(total/y)<<endl;
			}
		}
		cin>>N>>K;
	}

	return 0;
}

#include <cstdio>

long long int arr[100000001];

long long int coin(long long int );

int main()
{
	long long int n;

	while (scanf("%lld", &n) == 1) {
		if (n < 12) {
			printf("%lld\n", n);
		} else {
			printf("%lld\n", coin(n));
		}
	}

	return 0;
}

long long int coin(long long int n)
{
	long long int sum;
	if (n < 12) {
		sum = n;
	} else if (n < 100000001){
		if (arr[n] == 0) {
			sum = coin(n / 2) + coin (n / 3) + coin(n / 4);
		} else {
			sum = arr[n];
		}
		arr[n] = sum;
		return sum;
	} else {
		sum = coin(n / 2) + coin(n / 3) + coin(n / 4);
		return sum;
	}
}

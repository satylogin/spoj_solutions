#include <iostream>
#include <stdio.h>

using namespace std;
#define MOD 1000000007
long long int fun(long long int r, long long int n);
int main()
{
	long long int n, l;
	scanf("%lld %lld", &n, &l);

	while ((n != 0) && (l != 0)) {
		printf("%lld\n", fun(n, l));
		scanf("%lld %lld", &n, &l);
	}

	return 0;
}

long long int fun(long long int r, long long int n)
{
	long long int i, ans1 = 1, total_ans = 0;
	for (i = 1; i <= n; i++) {
		ans1 =  (ans1 * r) % MOD;
		total_ans = (total_ans + ans1) % MOD;
		
	}
	return total_ans;
}
